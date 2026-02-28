#include "player.h"
#include "bn_keypad.h"

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_math.h"

#include "bn_sprite_items_fran_stand.h"

static bn::sprite_ptr create_character_sprite(CharacterName name, int x, int y) { //Character sprite selector
    switch(name) {
        case CharacterName::diabolus:
            return bn::sprite_items::fran_stand.create_sprite(x, y);
    }

    return bn::sprite_items::fran_stand.create_sprite(x, y);
}

Player::Player(CharacterName name, int x, int y) :
    _sprite(create_character_sprite(name, x, y))
{
    _position = bn::fixed_point(x,y);
    _friction = bn::fixed(0.05);
    _acceleration = bn::fixed(0.2);
    _max_speed = bn::fixed(3);
    _velocity = bn::fixed_point(0,0);

    _sprite.set_bg_priority(0); //sprite priority
}

bn::fixed_point Player::get_position() {
    return _position;
}

void Player::update_movement(int top_bound, int bottom_bound, int left_bound, int right_bound) { //player movement
    bn::fixed_point input(0, 0);

    if(bn::keypad::up_held())    input.set_y(-1);
    if(bn::keypad::down_held())  input.set_y(1);
    if(bn::keypad::left_held())  input.set_x(-1);
    if(bn::keypad::right_held()) input.set_x(1);

    if(input.x() != 0 && input.y() != 0) {
        input *= bn::fixed(0.70710678); //diagonal correction with precalculated sqrt(2) so the gba doesn't cry
    }

    if(input != bn::fixed_point(0, 0)) {    //acceleration if there's input
        _velocity += input * _acceleration;

        bn::fixed length_sq = _velocity.x()*_velocity.x() + _velocity.y()*_velocity.y();
        if(length_sq > _max_speed*_max_speed) {
            bn::fixed length = bn::sqrt(length_sq);
            _velocity = (_velocity / length) * _max_speed;
        }
    } else {
        _velocity *= (bn::fixed(1) - _friction);    //friction when there isn't
    }

    if(_velocity.x() > _max_speed) {  //makin sure nothing goes off the rails
        _velocity.set_x(_max_speed);
    }
    if(_velocity.x() < -_max_speed) {
        _velocity.set_x(-_max_speed);
    }
    if(_velocity.y() > _max_speed) {
        _velocity.set_y(_max_speed);
    }
    if(_velocity.y() < -_max_speed) {
        _velocity.set_y(-_max_speed);
    }

    _position += _velocity; //movin

    if (_position.y() < top_bound) {    //makin sure nothing goes off the rails but literally
        _position.set_y(top_bound);
    } else if (_position.y() > bottom_bound) {
        _position.set_y(bottom_bound);
    }
    if (_position.x() < left_bound) {
        _position.set_x(left_bound);
    } else if (_position.x() > right_bound) {
        _position.set_x(right_bound);
    }

    _sprite.set_position(bn::fixed_point(_position.x().integer(), _position.y().integer()));    //rounding to prevent jitteriness
}

void Player::update(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd) {
    update_movement(top_bnd, bottom_bnd, left_bnd, right_bnd);
}