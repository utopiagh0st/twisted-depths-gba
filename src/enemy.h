#ifndef ENEMY_H
#define ENEMY_H

#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_fixed.h"
#include "bn_rect.h"

enum class EnemyType
{
    LimeCat
};

class Enemy {
public:
    Enemy(EnemyType type, bn::fixed_point position);
    bn::rect get_hitbox();
    bn::fixed_point get_position();
    bn::fixed_point get_velocity();
    bool is_alive();
    void set_alive(bool alive);
    bn::fixed get_distance(bn::fixed_point final_pos);
    void update(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd, bn::fixed_point player_pos);
private:
    //debug
    bn::optional<bn::sprite_ptr> _spr_hitbox;
    bool _debug;

    EnemyType _type;
    bool _alive;
    bn::sprite_ptr _sprite;
    bn::fixed_point _position;
    bn::fixed_point _velocity;
    bn::fixed_point _target;
    bn::fixed _friction;
    bn::fixed _acceleration;
    bn::fixed _max_speed;
    int _cooldown;
    int _step;
    //Functions
    bool bnd_collide(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd);
    void move_towards(bn::fixed_point final_pos);
    void deaccelerate();
};

#endif