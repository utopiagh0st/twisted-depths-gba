#ifndef PLAYER_H
#define PLAYER_H

#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_rect.h"
#include "bn_random.h"

#include "obstacle.h"
#include "projectile.h"

enum class CharacterName {
    diabolus,
    dank,
    angel
};
enum class Direction {
    Up,
    Down,
    Left,
    Right
};

class Player {
public:
    Player(CharacterName name, int x, int y, bn::random& rnd);
    bn::fixed_point get_position();
    void set_position(bn::fixed_point new_position);
    int get_hp();
    int get_hp_max();
    bn::rect get_hitbox();
    bn::fixed_point get_shot_velocity();
    bool is_movement_freezed();
    void set_freeze_movement(bool freeze_movement);

    void attack(bn::vector<Projectile, MAX_PROJECTILES>& projectiles);
    void take_damage(int damage);
    void apply_knockback(bn::fixed_point kb_velocity);
    void update(int top_bound, int bottom_bound, int left_bound, int right_bound, bn::vector<Obstacle,max_obstacles>& obstacles);  //passing bounds to avoid circle relationships
private:
    bn::sprite_ptr _sprite;
    bn::optional<bn::sprite_animate_action<4>> _walk_anim;

    bn::random _rnd;

    int _animation_cooldown;
    int _hp;
    int _hp_max;
    Direction _direction;
    bn::fixed_point _position;
    bn::fixed _friction;
    bn::fixed _acceleration;
    bn::fixed _max_speed;
    bn::fixed_point _velocity;
    bn::fixed_point _knockback_velocity;
    bn::fixed_point _last_input;
    bn::fixed _shot_speed;
    bool _freeze_movement;
    int _i_frames;
    int _i_frames_counter;
    bn::sprite_ptr _damage_sprite;
    bn::optional<bn::sprite_animate_action<10>> _damage_anim;

    void update_movement(int top_bound, int bottom_bound, int left_bound, int right_bound, bn::vector<Obstacle,max_obstacles>& obstacles);
};

#endif