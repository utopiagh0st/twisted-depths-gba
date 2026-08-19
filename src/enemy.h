#ifndef ENEMY_H
#define ENEMY_H

#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_fixed.h"
#include "bn_rect.h"
#include "bn_sprite_animate_actions.h"
#include "bn_optional.h"
#include "obstacle.h"
#include "bn_vector.h"


enum class EnemyType {
    LimeCat,
    PepperGum
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
    void apply_knockback(bn::fixed_point kb_velocity);
    void take_damage(bn::fixed damage);
    void update(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd, bn::fixed_point player_pos, bn::vector<Obstacle, max_obstacles>& obstacles);
private:
    //debug
    bn::optional<bn::sprite_ptr> _spr_hitbox;
    bool _debug;

    EnemyType _type;
    bool _alive;
    bn::optional<bn::sprite_animate_action<4>> _sprite_anim;
    bn::sprite_ptr _sprite;
    
    bool _dying;
    bn::fixed_point _position;
    bn::fixed_point _velocity;
    bn::fixed_point _knockback_velocity;
    bn::fixed_point _target;
    bn::fixed _friction;
    bn::fixed _acceleration;
    bn::fixed _max_speed;
    bn::fixed _hp;
    int _cooldown;
    int _step;
    int _i_frames;
    int _i_frames_counter;

    bn::sprite_ptr _damage_sprite;
    bn::optional<bn::sprite_animate_action<9>> _damage_anim;
    //Functions
    void initial_setup();
    bool bnd_collide(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd);
    void move_towards(bn::fixed_point final_pos);
    void deaccelerate();
};

#endif