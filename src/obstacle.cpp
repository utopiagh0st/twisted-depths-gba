#include "obstacle.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_rect.h"
#include "bn_sprite_items_hitbox.h"
#include "bn_sprite_items_wall.h"

bn::sprite_ptr Obstacle::create_obstacle_sprite(ObstacleType type, bn::fixed_point position) {
    switch (type){
        case ObstacleType::Rock:
            bn::sprite_ptr sprite = bn::sprite_items::wall.create_sprite(position);
            return sprite; 
    }
    return bn::sprite_items::wall.create_sprite(position);
}

Obstacle::Obstacle(ObstacleType type, bn::fixed_point position) :
    _sprite(create_obstacle_sprite(type, position))
{
    _debug = false;
    _active = true;
    _position = position;
    _type = type;
    _sprite.set_bg_priority(1);
    if (_debug) {
        _spr_hitbox.emplace(bn::sprite_items::hitbox.create_sprite(position));
    }
}

bn::fixed_point Obstacle::get_position() {
    return _position;
}

bn::rect Obstacle::get_hitbox() {
    return bn::rect(
    int(_position.x()),
    int(_position.y()),
    12,   // width
    12    // height
    );
}