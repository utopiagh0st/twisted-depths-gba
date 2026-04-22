#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_fixed.h"
#include "bn_rect.h"

enum class ProjectileOwner {
    Enemy,
    Player
};

class Projectile {
public:
    Projectile(bn::fixed_point pos, bn::fixed_point velocity, ProjectileOwner owner);
    bn::rect get_hitbox();
    ProjectileOwner get_owner();
    void update();
private:
    bn::fixed_point _position;
    bn::fixed_point _velocity;
    ProjectileOwner _owner;
    bn::sprite_ptr _sprite;
};
#endif