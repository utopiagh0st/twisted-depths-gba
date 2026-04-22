#ifndef PLAYER_H
#define PLAYER_H

#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_rect.h"

enum class CharacterName {
    diabolus,
    dank,
    angel
};

class Player {
public:
    Player(CharacterName name, int x, int y);
    bn::fixed_point get_position();
    int get_hp();
    int get_hp_max();
    bn::rect get_hitbox();
    void take_damage(int damage);
    void apply_knockback(bn::fixed_point kb_velocity);
    void update(int top_bound, int bottom_bound, int left_bound, int right_bound);  //passing bounds to avoid circle relationships
private:
    bn::sprite_ptr _sprite;
    bn::optional<bn::sprite_animate_action<4>> walk_anim;

    int _hp;
    int _hp_max;
    bn::fixed_point _position;
    bn::fixed _friction;
    bn::fixed _acceleration;
    bn::fixed _max_speed;
    bn::fixed_point _velocity;
    bn::fixed_point _knockback_velocity;
    void update_movement(int top_bound, int bottom_bound, int left_bound, int right_bound);
};

#endif