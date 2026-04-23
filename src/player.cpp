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
#include "bn_sprite_animate_actions.h"

static bn::sprite_ptr create_character_sprite(CharacterName name, int x, int y) { //Character sprite selector
    switch(name) {
        case CharacterName::diabolus:
            return bn::sprite_items::player_fran_walk_up.create_sprite(x, y);
    }

    return bn::sprite_items::player_fran_walk_up.create_sprite(x, y);
}

Player::Player(CharacterName name, int x, int y) :
    _sprite(create_character_sprite(name, x, y))
{
    _hp_max = 20;
    _hp = 20;

    _direction = Direction::Down;
    _position = bn::fixed_point(x,y);
    _friction = bn::fixed(0.2);
    _acceleration = bn::fixed(0.2);
    _max_speed = bn::fixed(2);
    _velocity = bn::fixed_point(0,0);
    _knockback_velocity = bn::fixed_point(0,0);
    _last_input = bn::fixed_point(0,0);

    _sprite.set_bg_priority(1); //sprite priority
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
bn::rect Player::get_hitbox() {
    return bn::rect(
    int(_position.x()),
    int(_position.y()),
    6,   // width
    13    // height
    );
}


//Functions
void Player::take_damage(int damage) {
    _hp -= damage;
    if (_hp < 0) {
        _hp = 0;
    }
}

void Player::apply_knockback(bn::fixed_point kb_velocity)
{
    bn::fixed speed = bn::sqrt(kb_velocity.x() * kb_velocity.x() + kb_velocity.y() * kb_velocity.y());

    if (speed > 0) {
        bn::fixed_point direction = kb_velocity / speed;

        //optional upward bias
        direction.set_y(direction.y() - 0.3);

        bn::fixed strength = bn::min(speed * 2, bn::fixed(6)); //speed times multiplier OR the threshold

        _knockback_velocity = direction * strength;
    }
}

void Player::update_movement(int top_bound, int bottom_bound, int left_bound, int right_bound) { //player movement
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

    _position += _velocity + _knockback_velocity; //movin
    _knockback_velocity *= (bn::fixed(1) - _friction);   //apply friction to the knockback so it doesn't go on forever

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

    //animation
    if(moving) {
        if (_last_input != input) {
            int walk_animation_speed = int(_max_speed * 3);
            if (_direction == Direction::Up) {
                walk_anim.emplace(
                    bn::sprite_animate_action<4>::forever(
                        _sprite,
                        walk_animation_speed,
                        bn::sprite_items::player_fran_walk_up.tiles_item(),
                        bn::array<uint16_t, 4>{ 0, 1, 2, 3 }
                    )
                );
            } else if (_direction == Direction::Down) {
                walk_anim.emplace(
                    bn::sprite_animate_action<4>::forever(
                        _sprite,
                        walk_animation_speed,
                        bn::sprite_items::player_fran_walk_down.tiles_item(),
                        bn::array<uint16_t, 4>{ 0, 1, 2, 3 }
                    )
                );
            } else if (_direction == Direction::Left) {
                walk_anim.emplace(
                    bn::sprite_animate_action<4>::forever(
                        _sprite,
                        walk_animation_speed,
                        bn::sprite_items::player_fran_walk_left.tiles_item(),
                        bn::array<uint16_t, 4>{ 0, 1, 2, 3 }
                    )
                );
            } else if (_direction == Direction::Right) {
                walk_anim.emplace(
                    bn::sprite_animate_action<4>::forever(
                        _sprite,
                        walk_animation_speed,
                        bn::sprite_items::player_fran_walk_right.tiles_item(),
                        bn::array<uint16_t, 4>{ 0, 1, 2, 3 }
                    )
                );
            }
        }
        walk_anim->update();
    } else {
        //stop animation
        walk_anim.reset();
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

void Player::update(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd) {
    update_movement(top_bnd, bottom_bnd, left_bnd, right_bnd);
}