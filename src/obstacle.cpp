#include "obstacle.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_rect.h"
#include "bn_sprite_items_hitbox.h"
#include "bn_sprite_items_wall.h"
#include "bn_sprite_items_obstacle_trashcan.h"
#include "bn_sprite_items_obstacle_trashbag.h"
#include "bn_sprite_items_obstacle_trashbox.h"
#include "bn_sprite_items_obstacle_street_door_left_top.h"
#include "bn_sprite_items_obstacle_street_door_left_bottom.h"
#include "bn_sprite_items_obstacle_street_door_up_leftside.h"
#include "bn_sprite_items_obstacle_street_door_up_rightside.h"
#include "bn_sprite_animate_actions.h"



bn::sprite_ptr Obstacle::create_obstacle_sprite_and_config(ObstacleType type, bn::fixed_point position) {
    switch (type){
        case ObstacleType::Trashcan:
            _visible = true;
            return bn::sprite_items::obstacle_trashcan.create_sprite(position);
        case ObstacleType::Trashbag:
            _visible = true;
            return bn::sprite_items::obstacle_trashbag.create_sprite(position);
        case ObstacleType::TrashBox:
            _visible = true;
            return bn::sprite_items::obstacle_trashbox.create_sprite(position);

        case ObstacleType::StreetConesUp:
            _visible = true;
            return bn::sprite_items::obstacle_street_door_left_top.create_sprite(position);
        case ObstacleType::StreetConesDown:
            _visible = true;
            return bn::sprite_items::obstacle_street_door_left_bottom.create_sprite(position);
        case ObstacleType::StreetConesLeft:
            _visible = true;
            return bn::sprite_items::obstacle_street_door_up_leftside.create_sprite(position);
        case ObstacleType::StreetConesRight:
            _visible = true;
            return bn::sprite_items::obstacle_street_door_up_rightside.create_sprite(position);
        
        case ObstacleType::RoomBorderHor:
            _visible = false;
            _hitbox_dimensions = bn::fixed_point(176,16);
            return bn::sprite_items::wall.create_sprite(position);
        case ObstacleType::RoomBorderVer:
            _visible = false;
            return bn::sprite_items::wall.create_sprite(position);
        default:
            _visible = false;
            return bn::sprite_items::wall.create_sprite(position);
    }
    
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
    _sprite.set_bg_priority(2);
    _sprite.set_z_order(3);
    _hitbox_offset = bn::fixed_point(0,0);
    _class = ObstacleClass::None;

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

    case ObstacleType::StreetConesUp:
        _class = ObstacleClass::Door;
        _hitbox_dimensions = bn::fixed_point(16,56);
        break;
    case ObstacleType::StreetConesDown:
        _class = ObstacleClass::Door;
        _hitbox_dimensions = bn::fixed_point(16,56);
        break;
    case ObstacleType::StreetConesLeft:
        _class = ObstacleClass::Door;
        _hitbox_dimensions = bn::fixed_point(56,16);
        break;
    case ObstacleType::StreetConesRight:
        _class = ObstacleClass::Door;
        _hitbox_dimensions = bn::fixed_point(56,16);
        break;

    default:
        _hitbox_dimensions = bn::fixed_point(16,16);
        break;
    }
    
}

ObstacleType Obstacle::get_type() {
    return _type;
}

ObstacleClass Obstacle::get_class() {
    return _class;
}

bn::fixed_point Obstacle::get_position() {
    return _position;
}

bn::rect Obstacle::get_hitbox() {
    return bn::rect(
    int(_position.x() + _hitbox_offset.x()),
    int(_position.y() + _hitbox_offset.y()),
    int(_hitbox_dimensions.x()),   // width
    int(_hitbox_dimensions.y())   // height
    );
}

bn::rect Obstacle::get_hitbox_for_projectile() {
    return bn::rect(
    int(_position.x() + _hitbox_offset.x()),
    int(_position.y() + _hitbox_offset.y() - 4),
    int(_hitbox_dimensions.x() - 2),   // width
    int(_hitbox_dimensions.y() - 4)   // height
    );
}

void Obstacle::open() {
    switch (_type) {
    case ObstacleType::StreetConesLeft:
        _hitbox_offset.set_x(-44);
        _sprite_anim.emplace(bn::sprite_animate_action<10>::once(
            _sprite,
            1,
            bn::sprite_items::obstacle_street_door_up_leftside.tiles_item(),
            bn::array<uint16_t, 10>{ 0,0,1,1,1,2,3,4,4,5 }
        )); 
        break;
    case ObstacleType::StreetConesRight:
        _hitbox_offset.set_x(44);
        _sprite_anim.emplace(bn::sprite_animate_action<10>::once(
            _sprite,
            1,
            bn::sprite_items::obstacle_street_door_up_rightside.tiles_item(),
            bn::array<uint16_t, 10>{ 0,0,1,1,1,2,3,4,4,5 }
        )); 
        break;
    case ObstacleType::StreetConesUp:
        _hitbox_offset.set_y(-44);
        _sprite_anim.emplace(bn::sprite_animate_action<10>::once(
            _sprite,
            1,
            bn::sprite_items::obstacle_street_door_left_top.tiles_item(),
            bn::array<uint16_t, 10>{ 0,0,1,1,1,2,3,4,4,5 }
        )); 
        break;
    case ObstacleType::StreetConesDown:
        _hitbox_offset.set_y(44);
        _sprite_anim.emplace(bn::sprite_animate_action<10>::once(
            _sprite,
            1,
            bn::sprite_items::obstacle_street_door_left_bottom.tiles_item(),
            bn::array<uint16_t, 10>{ 0,0,1,1,1,2,3,4,4,5 }
        )); 
        break;
    }
}

void Obstacle::update() {
    if (_sprite_anim && !_sprite_anim->done()) {
        _sprite_anim->update();
    }
}