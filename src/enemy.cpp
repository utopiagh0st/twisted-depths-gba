#include "enemy.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_rect.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_enemy.h"
#include "bn_sprite_items_enemy_peppergum.h"

#include "bn_sprite_items_hitbox.h"

static bn::sprite_ptr create_character_sprite(EnemyType type, bn::fixed_point position) { //Character sprite selector
    switch(type) {
        case EnemyType::LimeCat:
            return bn::sprite_items::enemy.create_sprite(position);
        case EnemyType::PepperGum:
            return bn::sprite_items::enemy_peppergum.create_sprite(position);
    }

    return bn::sprite_items::enemy.create_sprite(position);
}

Enemy::Enemy(EnemyType type, bn::fixed_point position) :
    _sprite(create_character_sprite(type, position))
{
    _debug = false;
    _alive = true;
    _position = position;
    _velocity = bn::fixed_point(0,0);
    _friction = bn::fixed(0.07);
    _acceleration = bn::fixed(0.3);
    _max_speed = bn::fixed(5);
    _cooldown = 0;
    _step = 0;
    _knockback_velocity = bn::fixed_point(0,0);
    _hp = bn::fixed(50);

    //optional attributes
    

    _type = type;
    _sprite.set_bg_priority(1);

    initial_setup();
    if (_debug) {
        _spr_hitbox.emplace(bn::sprite_items::hitbox.create_sprite(position));
    }
}

void Enemy::initial_setup() {
    switch(_type) {
    case EnemyType::PepperGum:
        _friction = bn::fixed(0.4);
        _acceleration = bn::fixed(0.3);
        _max_speed = bn::fixed(2);

        _sprite_anim.emplace(
            bn::sprite_animate_action<4>::forever(
                _sprite,
                5,
                bn::sprite_items::enemy_peppergum.tiles_item(),
                bn::array<uint16_t, 4>{ 0, 1, 2, 3}
            )
        );
    break;
    }
}

bool Enemy::is_alive() {
    return _alive;
}
bn::fixed_point Enemy::get_position() {
    return _position;
}
bn::fixed_point Enemy::get_velocity() {
    return _velocity;
}
bn::rect Enemy::get_hitbox() {
    return bn::rect(
    int(_position.x()-1),
    int(_position.y()+1),
    8,   // width8
    9    // height9
    );
}
void Enemy::set_alive(bool alive) {
    _alive = alive;
}
void Enemy::take_damage(bn::fixed damage) {
    if(_hp>0) {
    _hp -= damage;
    if (_hp <= 0) {
        _step = 0;
        _cooldown = 0;
    }
    }
}

void Enemy::apply_knockback(bn::fixed_point kb_velocity) {
    bn::fixed speed = bn::sqrt(kb_velocity.x() * kb_velocity.x() + kb_velocity.y() * kb_velocity.y());

    if (speed > 0) {
        bn::fixed_point direction = kb_velocity / speed;

        //optional upward bias
        direction.set_y(direction.y() - 0.3);

        bn::fixed strength = bn::min(speed * 2, bn::fixed(6)); //speed times multiplier OR the threshold

        _knockback_velocity = direction * strength;
    }
}

void Enemy::update(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd, bn::fixed_point player_pos) {
    switch (_type) {
    case EnemyType::LimeCat:
        switch (_step) {
        case 0:
            _target = player_pos;
            _step++;
        break;
        case 1:
            if (get_distance(_target) > _max_speed) {
                move_towards(_target);
                if (bnd_collide(top_bnd, bottom_bnd, left_bnd, right_bnd)) {
                    _step++;
                }
            } else {
                _step++;
            }
        break;
        case 2:
            deaccelerate();
            bnd_collide(top_bnd, bottom_bnd, left_bnd, right_bnd);
            if (_velocity == bn::fixed_point(0,0)) {
                _cooldown = 50;
                _step++;
            }
        break;
        case 3:
            _cooldown--;
            if (_cooldown <= 0) {
                _step = 0;
            }
        break;
        }
        break;
    case EnemyType::PepperGum:
        
        if(_hp > 0) {
            if (_target.x() < _position.x()) {
                _sprite.set_horizontal_flip(true);
            } else {
                _sprite.set_horizontal_flip(false);
            }
            switch (_step) {
            case 0:
                deaccelerate();
                if(_cooldown == 0) {
                    _cooldown = 40;
                    _step++;
                }
                _cooldown--;
                break;
            case 1:
                _target = player_pos;
                move_towards(_target);
                if(_cooldown == 0) {
                    _cooldown=15;
                    _step=0;
                }
                _cooldown--;
                break;
            }
            _sprite_anim->update();
        } else {
            switch (_step) {
            case 0:
                _sprite_anim.emplace(
                    bn::sprite_animate_action<4>::once(
                        _sprite,
                        10,
                        bn::sprite_items::enemy_peppergum.tiles_item(),
                        bn::array<uint16_t, 3>{3, 4, 5}
                    )
                );
                _cooldown = 30;
                _step++;
            break;
            case 1:
                _cooldown--;
                if(_cooldown == 0) {
                    _alive = false;
                }
            break;
            }
            deaccelerate();
            if (!_sprite_anim->done()) {
                _sprite_anim->update();
            }
        }
        break;
        
    default:
        break;
    }
    _velocity += _knockback_velocity;
    _knockback_velocity *= (bn::fixed(1) - _friction);
    _position += _velocity;
    _sprite.set_position(bn::fixed_point(_position.x().integer(), _position.y().integer()));

    if (_debug) {
        bn::rect hitbox = get_hitbox();
        _spr_hitbox->set_position(hitbox.x(), hitbox.y());
        bn::fixed scale_x = bn::fixed(hitbox.width()) / 16;
        bn::fixed scale_y = bn::fixed(hitbox.height()) / 16;

        scale_x = bn::max(scale_x, bn::fixed(0.01));
        scale_y = bn::max(scale_y, bn::fixed(0.01));

        _spr_hitbox->set_horizontal_scale(scale_x);
        _spr_hitbox->set_vertical_scale(scale_y);
        _spr_hitbox->set_bg_priority(0);
    }
}


bool Enemy::bnd_collide(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd) {
    bool collided = false;
    if (_position.y() < top_bnd) {
        _position.set_y(top_bnd);
        collided = true;
    } else if (_position.y() > bottom_bnd) {
        _position.set_y(bottom_bnd);
        collided = true;
    }
    if (_position.x() < left_bnd) {
        _position.set_x(left_bnd);
        collided = true;
    } else if (_position.x() > right_bnd) {
        _position.set_x(right_bnd);
        collided = true;
    }
    return collided;
}

bn::fixed Enemy::get_distance(bn::fixed_point final_pos) {
    bn::fixed_point direction = final_pos - _position;
    return bn::sqrt(direction.x() * direction.x() + direction.y() * direction.y());
}

void Enemy::move_towards(bn::fixed_point final_pos) {   //if it's done returns true
    bn::fixed_point direction = final_pos - _position;
    bn::fixed length = get_distance(final_pos);
    if(length > _max_speed + 1) {
        direction /= length;
        _velocity += direction * _acceleration;
    }   

    bn::fixed speed_sq = _velocity.x()*_velocity.x() + _velocity.y()*_velocity.y();
    if (speed_sq > _max_speed*_max_speed) {
        _velocity = (_velocity / bn::sqrt(speed_sq)) * _max_speed;
    }
    
}

void Enemy::deaccelerate() {
    _velocity *= bn::fixed(1) - _friction;
    _position += _velocity;
}