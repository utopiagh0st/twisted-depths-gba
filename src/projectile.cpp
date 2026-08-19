#include "projectile.h"
#include "bn_fixed_point.h"
#include "bn_math.h"

//sprites
#include "bn_sprite_items_projectile_honk.h"
#include "bn_sprite_items_projectile.h"
#include "bn_sprite_items_hitbox.h"


bn::sprite_ptr Projectile::create_projectile_sprite(ProjectileType type, bn::fixed_point position) {
    switch (type){
        case ProjectileType::Honk:
            bn::sprite_ptr sprite = bn::sprite_items::projectile_honk.create_sprite(position);
            _size = 0.1;
            return sprite; 
    }
    _size = 1;
    return bn::sprite_items::projectile.create_sprite(position);
}

Projectile::Projectile(ProjectileType type, ProjectileOwner owner, bn::fixed_point position, bn::fixed_point velocity, bn::fixed damage, bn::fixed range, bn::fixed knockback) :
    _sprite(create_projectile_sprite(type, position))
{   
    _debug = false;
    _sprite.set_scale(_size);
    _alive = true;

    _velocity = velocity;
    _position = position;
    _range = range;
    _damage = damage;
    _knockback = knockback;

    _distance_traveled = bn::fixed(0);
    _piercing = true;
    //_friction = bn::fixed(0.2);
    _friction = bn::fixed(0.2);
    _type = type;
    _owner = owner;
    _sprite.set_bg_priority(2);
    _sprite.set_z_order(0);

    if (_debug) {
        _spr_hitbox.emplace(bn::sprite_items::hitbox.create_sprite(position));
    }
}

bool Projectile::is_alive() {
    return _alive;
}

bool Projectile::is_piercing() {
    return _piercing;
}

bn::rect Projectile::get_hitbox() {
    return bn::rect(
    int(_position.x()),
    int(_position.y()),
    15,   // width8
    12    // height9
    );
}

bn::fixed Projectile::get_damage() {
    return _damage;
}

bn::fixed Projectile::get_knockback() {
    return _knockback;
}

ProjectileOwner Projectile::get_owner() {
    return _owner;
}

bn::fixed_point Projectile::get_velocity() {
    return _velocity;
}

bn::fixed Projectile::get_speed() {
    return sqrt(_velocity.x() * _velocity.x() + _velocity.y() * _velocity.y());
}

bn::fixed_point Projectile::get_unit_velocity_vector() {
    bn::fixed speed = get_speed();
    if (speed == 0) {
        return bn::fixed_point(0,0);
    }
    return _velocity / speed;
}

void Projectile::set_alive(bool alive) {
    _alive = alive;
}

void Projectile::update_movement() {
    
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

void Projectile::update() {
    switch (_type) {
        case ProjectileType::Honk :
            if (_size < 1) {
                _size += 0.1;
                _sprite.set_scale(_size);
            }
            update_movement();
            break;
        case ProjectileType::Bullet :
            if (_distance_traveled <= _range) {
                _position += _velocity;
                _distance_traveled += get_speed();
            } else {
                _velocity *= bn::fixed(1) - _friction;
                _position += _velocity;
            }
            _sprite.set_position(bn::fixed_point(_position.x().integer(), _position.y().integer()));

            break;
            
    }
    if(_velocity == bn::fixed_point(0,0)) {
        _alive = false;
    }
}