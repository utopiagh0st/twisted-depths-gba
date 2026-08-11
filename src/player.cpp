#include "player.h"
#include "bn_keypad.h"

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_array.h"
#include "bn_rect.h" //hitboxes

#include "bn_sprite_items_hitbox.h"
#include "bn_sprite_items_player_fran_walk_up.h"
#include "bn_sprite_items_player_fran_walk_down.h"
#include "bn_sprite_items_player_fran_walk_left.h"
#include "bn_sprite_items_player_fran_walk_right.h"
#include "bn_sprite_items_player_fran_attack_left.h"
#include "bn_sprite_items_player_fran_attack_up.h"
#include "bn_sprite_items_player_fran_attack_down.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sound_items.h"

static bn::sprite_ptr create_character_sprite(CharacterName name, int x, int y) { //Character sprite selector
    switch(name) {
        case CharacterName::diabolus:
            return bn::sprite_items::player_fran_walk_up.create_sprite(x, y);
    }

    return bn::sprite_items::player_fran_walk_up.create_sprite(x, y);
}

Player::Player(CharacterName name, int x, int y, bn::random& rnd) :
    _sprite(create_character_sprite(name, x, y)),
    _rnd(rnd)
{
    _hp_max = 20;
    _hp = 20;

    _animation_cooldown = 0;
    _direction = Direction::Down;
    _position = bn::fixed_point(x,y);
    _friction = bn::fixed(0.4);
    _acceleration = bn::fixed(0.3);
    _max_speed = bn::fixed(2);
    _velocity = bn::fixed_point(0,0);
    _knockback_velocity = bn::fixed_point(0,0);
    _last_input = bn::fixed_point(0,0);
    _shot_speed = bn::fixed(8);

    _sprite.set_bg_priority(2); //sprite priority
}


//Getters and Setters
int Player::get_hp() {
    return _hp;
}
int Player::get_hp_max() {
    return _hp_max;
}
bn::fixed_point Player::get_position() {
    return _position;
}
void Player::set_position(bn::fixed_point new_position) {
    _sprite.set_position(new_position);
    _position = new_position;
}
bn::rect Player::get_hitbox() {
    return bn::rect(
    int(_position.x()),
    int(_position.y()),
    6,   // width
    13    // height
    );
}
bn::fixed_point Player::get_shot_velocity() {
    bn::fixed_point shot_velocity_modifier = _velocity;
    switch (_direction) {
        case Direction::Up:
            return bn::fixed_point(0, _shot_speed * -1) + shot_velocity_modifier;
        case Direction::Down:
            return bn::fixed_point(0, _shot_speed) + shot_velocity_modifier;
        case Direction::Left:
            return bn::fixed_point(_shot_speed * -1, 0) + shot_velocity_modifier;
        case Direction::Right:
            return bn::fixed_point(_shot_speed, 0) + shot_velocity_modifier;
    }
    return bn::fixed_point(0, _shot_speed * -1);
}


//Functions
void Player::take_damage(int damage) {
    _hp -= damage;
    if (_hp < 0) {
        _hp = 0;
    }
}
void Player::attack() {
    int atk_knockback = 4;
    if (_walk_anim) {
        _walk_anim.reset();
    }
    switch (_direction) {
        case Direction::Left :
            _sprite.set_tiles(bn::sprite_items::player_fran_attack_left.tiles_item(), 0);
            _sprite.set_horizontal_flip(false);
            _velocity += bn::fixed_point(atk_knockback, 0);
            break;
        case Direction::Right :
            _sprite.set_tiles(bn::sprite_items::player_fran_attack_left.tiles_item(), 0);
            _sprite.set_horizontal_flip(true);
            _velocity -= bn::fixed_point(atk_knockback, 0);
            break;
        case Direction::Up :
            _sprite.set_tiles(bn::sprite_items::player_fran_attack_up.tiles_item(), 0);
            _sprite.set_horizontal_flip(false);
            _velocity += bn::fixed_point(0, atk_knockback);
            break;
        case Direction::Down :
            _sprite.set_tiles(bn::sprite_items::player_fran_attack_down.tiles_item(), 0);
            _sprite.set_horizontal_flip(false);
            _velocity -= bn::fixed_point(0, atk_knockback);
            break;
        default:
            _sprite.set_tiles(bn::sprite_items::player_fran_attack_left.tiles_item(), 0);
            break;
    }

    bn::sound_items::honk.play(0.3, _rnd.get_fixed(0.5,2), 0);
    _animation_cooldown = 20;
    
}

void Player::apply_knockback(bn::fixed_point kb_velocity) {
    bn::fixed speed = bn::sqrt(kb_velocity.x() * kb_velocity.x() + kb_velocity.y() * kb_velocity.y());

    if (speed > 0) {
        bn::fixed_point direction = kb_velocity / speed;

        //optional upward bias
        direction.set_y(direction.y() - 0.3);

        bn::fixed strength = bn::min(speed * 2, bn::fixed(6)); //speed times multiplier OR the threshold

        _knockback_velocity = direction * strength;
    }
}

void Player::update_movement(int top_bound, int bottom_bound, int left_bound, int right_bound, bn::vector<Obstacle,50>& obstacles) { //player movement
    bool moving = false;    //turn this to false before input check
    bn::fixed_point input(0, 0);

    //TODO: remove these _hp related instructions after debugging the hp bar!!!!
    if(bn::keypad::b_pressed() && _hp < _hp_max)    _hp++;
    //if(bn::keypad::down_held())    _hp--;
    //if(_hp < 0) {
    //    _hp = 0;
    //} else if (_hp > _hp_max) {
    //    _hp = _hp_max;
    //}

    if(bn::keypad::left_held()) {
        input.set_x(-1);
        _direction = Direction::Left;
    }
    if(bn::keypad::right_held()) {
        input.set_x(1);
        _direction = Direction::Right;
    }
    if(bn::keypad::up_held()) {
        input.set_y(-1);
        _direction = Direction::Up;
    }
    if(bn::keypad::down_held()) {
        input.set_y(1);
        _direction = Direction::Down;
    }

    if(input != bn::fixed_point(0, 0)) {    //acceleration if there's input
        moving = true;
        _velocity += input * _acceleration;

        bn::fixed length_sq = _velocity.x()*_velocity.x() + _velocity.y()*_velocity.y();
        if(length_sq > _max_speed*_max_speed) {
            bn::fixed length = bn::sqrt(length_sq);
            _velocity = (_velocity / length) * _max_speed;
        }
    } else {
        _velocity *= (bn::fixed(1) - _friction);    //friction when there isn't
    }

    bn::fixed_point total_velocity = _velocity + _knockback_velocity;
    //_position += total_velocity; //movin

    _position.set_x(_position.x() + total_velocity.x()); //x collision check (FUCK THERE MUST BE A BETTER WAY TO DO THIS)
    for (Obstacle& obstacle : obstacles) {
        // Colission checks
        if (get_hitbox().intersects(obstacle.get_hitbox())) {
            _position.set_x(_position.x() - total_velocity.x());
        }
    }

    _position.set_y(_position.y() + total_velocity.y()); //y collision checkkkkk
    for (Obstacle& obstacle : obstacles) {
        // Colission checks
        if (get_hitbox().intersects(obstacle.get_hitbox())) {
            _position.set_y(_position.y() - total_velocity.y());
        }
    }

    /*
    if (_position.y() <top_bound) {    //makin sure nothing goes off the rails but literally
        _position.set_y(top_bound);
    } else if (_position.y() > bottom_bound) {
        _position.set_y(bottom_bound);
    }
    if (_position.x() <left_bound) {
        _position.set_x(left_bound);
    } else if (_position.x() > right_bound) {
        _position.set_x(right_bound);
    }
    */



    _knockback_velocity *= (bn::fixed(1) - _friction);   //apply friction to the knockback so it doesn't go on forever

    //mark

    //animation
    if(moving && _animation_cooldown == 0) {
        if (_last_input != input || !_walk_anim) {
            int walk_animation_speed = int(_max_speed * 3);
            if (_direction == Direction::Up) {
                _walk_anim.emplace(
                    bn::sprite_animate_action<4>::forever(
                        _sprite,
                        walk_animation_speed,
                        bn::sprite_items::player_fran_walk_up.tiles_item(),
                        bn::array<uint16_t, 4>{ 0, 1, 2, 3 }
                    )
                );
            } else if (_direction == Direction::Down) {
                _walk_anim.emplace(
                    bn::sprite_animate_action<4>::forever(
                        _sprite,
                        walk_animation_speed,
                        bn::sprite_items::player_fran_walk_down.tiles_item(),
                        bn::array<uint16_t, 4>{ 0, 1, 2, 3 }
                    )
                );
            } else if (_direction == Direction::Left) {
                _walk_anim.emplace(
                    bn::sprite_animate_action<4>::forever(
                        _sprite,
                        walk_animation_speed,
                        bn::sprite_items::player_fran_walk_left.tiles_item(),
                        bn::array<uint16_t, 4>{ 0, 1, 2, 3 }
                    )
                );
            } else if (_direction == Direction::Right) {
                _walk_anim.emplace(
                    bn::sprite_animate_action<4>::forever(
                        _sprite,
                        walk_animation_speed,
                        bn::sprite_items::player_fran_walk_right.tiles_item(),
                        bn::array<uint16_t, 4>{ 0, 1, 2, 3 }
                    )
                );
            }
        }
        if(_walk_anim) {
            _walk_anim->update();
        }
        
    } else if (_animation_cooldown == 0){
        //stop animation
        _walk_anim.reset();
        //standing frame
        if (_direction == Direction::Up) {
            _sprite.set_tiles(bn::sprite_items::player_fran_walk_up.tiles_item(), 1);
        } else if (_direction == Direction::Down) {
            _sprite.set_tiles(bn::sprite_items::player_fran_walk_down.tiles_item(), 1);
        } else if (_direction == Direction::Left) {
            _sprite.set_tiles(bn::sprite_items::player_fran_walk_left.tiles_item(), 1);
        } else if (_direction == Direction::Right) {
            _sprite.set_tiles(bn::sprite_items::player_fran_walk_right.tiles_item(), 1);
        } else {
            _sprite.set_tiles(bn::sprite_items::player_fran_walk_down.tiles_item(), 1);
        }
    }

    _last_input = input;
    
    _sprite.set_position(bn::fixed_point(_position.x().integer(), _position.y().integer()));    //rounding to prevent jitteriness
}

void Player::update(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd, bn::vector<Obstacle,50>& obstacles) {
    if (_animation_cooldown > 0) {
        _animation_cooldown--;
    }
    if(_animation_cooldown == 0) {
        _sprite.set_horizontal_flip(false);
    }
    update_movement(top_bnd, bottom_bnd, left_bnd, right_bnd, obstacles);
}