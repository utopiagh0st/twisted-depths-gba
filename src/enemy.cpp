#include "enemy.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_rect.h"
#include "bn_sprite_items_enemy.h"
#include "bn_sprite_items_hitbox.h"

static bn::sprite_ptr create_character_sprite(EnemyType type, bn::fixed_point position) { //Character sprite selector
    switch(type) {
        case EnemyType::LimeCat:
            return bn::sprite_items::enemy.create_sprite(position);
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

    _type = type;
    _sprite.set_bg_priority(1);
    if (_debug) {
        _spr_hitbox.emplace(bn::sprite_items::hitbox.create_sprite(position));
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
    default:
        break;
    }

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
    
    _position += _velocity;
    _sprite.set_position(bn::fixed_point(_position.x().integer(), _position.y().integer()));
}

void Enemy::deaccelerate() {
    _velocity *= bn::fixed(1) - _friction;
    _position += _velocity;
    _sprite.set_position(bn::fixed_point(_position.x().integer(), _position.y().integer()));
}