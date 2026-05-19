/*
#include "collisionable.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_rect.h"
#include "bn_sprite_items_hitbox.h"

Collisionable::Collisionable(bn::fixed_point position) :
{
    if (_debug) {
        _spr_hitbox.emplace(bn::sprite_items::hitbox.create_sprite(position));
    }
}

bn::fixed_point Enemy::get_position() {
    return _position;
}

bn::rect Enemy::get_hitbox() {
    return bn::rect(
    int(_position.x()-1),
    int(_position.y()+1),
    8,   // width8
    9    // height9
    );
}

bn::fixed Collisionable::get_distance(bn::fixed_point final_pos) {
    bn::fixed_point direction = final_pos - _position;
    return bn::sqrt(direction.x() * direction.x() + direction.y() * direction.y());
} 
*/