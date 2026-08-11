#include "obstacle.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_rect.h"
#include "bn_sprite_items_hitbox.h"
#include "bn_sprite_items_wall.h"

bn::sprite_ptr Obstacle::create_obstacle_sprite_and_config(ObstacleType type, bn::fixed_point position) {
    switch (type){
        case ObstacleType::Rock:
            _visible = true;
            _hitbox_dimensions = bn::fixed_point(16,100);
            return bn::sprite_items::wall.create_sprite(position);
        case ObstacleType::RoomBorderHor:
            _visible = false;
            _hitbox_dimensions = bn::fixed_point(176,16);
            return bn::sprite_items::wall.create_sprite(position);
        case ObstacleType::RoomBorderVer:
            _visible = false;
            return bn::sprite_items::wall.create_sprite(position);; 
    }
    return bn::sprite_items::wall.create_sprite(position);
}

Obstacle::Obstacle(ObstacleType type, bn::fixed_point position) :
    _sprite(create_obstacle_sprite_and_config(type, position))
{
    //_hitbox_dimensions = bn::fixed_point(16,144);
    //set_hitbox(bn::fixed_point(16,144));
    _debug = false;
    _active = true;
    _position = position;
    _type = type;
    _sprite.set_bg_priority(1);
    auto_set_hitbox();
    if (_debug) {
        _spr_hitbox.emplace(bn::sprite_items::hitbox.create_sprite(position));
    }
    if (!_visible) {
        _sprite.set_visible(false);
    }
}

void Obstacle::auto_set_hitbox() {
    switch (_type) {
    case ObstacleType::RoomBorderHor:
        _hitbox_dimensions = bn::fixed_point(176,16);
        break;
    case ObstacleType::RoomBorderVer:
        _hitbox_dimensions = bn::fixed_point(16,144);
        break;
    case ObstacleType::RoomCornerHor:
        _hitbox_dimensions = bn::fixed_point(32,16);
        break;
    default:
        break;
    }
    
}

ObstacleType Obstacle::get_type() {
    return _type;
}

bn::fixed_point Obstacle::get_position() {
    return _position;
}

bn::rect Obstacle::get_hitbox() {
    return bn::rect(
    int(_position.x()),
    int(_position.y()),
    int(_hitbox_dimensions.x()),   // width
    int(_hitbox_dimensions.y())   // height
    );
}