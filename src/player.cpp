#include "player.h"
#include "bn_keypad.h"
#include "bn_sprite_items_fran_stand.h"

static bn::sprite_ptr create_character_sprite(CharacterName name, int x, int y) { //Character sprite selector
    switch(name) {
        case CharacterName::diabolus:
            return bn::sprite_items::fran_stand.create_sprite(x, y);
    }

    return bn::sprite_items::fran_stand.create_sprite(x, y);
}

Player::Player(int x, int y, CharacterName name) :
    _sprite(create_character_sprite(name,x,y))
{   
    _x = x;
    _y = y;
    _speed = 2;
    _sprite.set_bg_priority(0); //sprite priority
}

void Player::update_movement(int top_bound, int bottom_bound, int left_bound, int right_bound) { //player movement
    if(bn::keypad::up_held()) {
        _y -= _speed;
        if (_y < top_bound) { _y = top_bound; }
    }
    if(bn::keypad::down_held()) { 
        _y += _speed;
        if (_y > bottom_bound) { _y = bottom_bound; }
    }
    if(bn::keypad::left_held()) { 
        _x -= _speed;
        if (_x < left_bound) { _x = left_bound; }
    }
    if(bn::keypad::right_held()) { 
        _x += _speed;
        if (_x > right_bound) { _x = right_bound; }
    }
    _sprite.set_position(_x,_y);
}

void Player::update(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd) {
    Player::update_movement(top_bnd, bottom_bnd, left_bnd, right_bnd);
}