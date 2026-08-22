#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_fixed.h"
#include "bn_rect.h"
#include "bn_sprite_animate_actions.h"


static constexpr int MAX_PROJECTILES = 20;

enum class ProjectileType {
    Honk,
    Bullet
};
enum class ProjectileOwner {
    Enemy,
    Player
};

class Projectile {
public:
    Projectile(ProjectileType type, ProjectileOwner owner, bn::fixed_point position, bn::fixed_point velocity, bn::fixed damage, bn::fixed range, bn::fixed knockback);
    bn::rect get_hitbox();
    ProjectileOwner get_owner();
    bn::fixed_point get_velocity();
    bn::fixed_point get_unit_velocity_vector();
    bn::fixed get_speed();
    bn::fixed get_damage();
    bn::fixed get_knockback();

    bool is_piercing();
    void set_alive(bool alive);
    bool is_alive();
    void update();
private:
    bool _debug;
    bn::fixed _size;
    bn::fixed_point _position;
    bn::fixed_point _velocity;
    bn::fixed _friction;
    ProjectileType _type;
    ProjectileOwner _owner;
    bn::fixed _range;
    bn::fixed _distance_traveled;
    bn::fixed _damage;
    bn::fixed _knockback;
    bn::sprite_ptr _sprite;
    bn::optional<bn::sprite_animate_action<2>> _sprite_anim;

    bn::optional<bn::sprite_ptr> _spr_hitbox;
    bool _alive;
    bool _piercing;

    bn::sprite_ptr create_projectile_sprite(ProjectileType type, bn::fixed_point position);
    void update_movement();
};
#endif