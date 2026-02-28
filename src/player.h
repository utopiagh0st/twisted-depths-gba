#ifndef PLAYER_H
#define PLAYER_H

#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"


enum class CharacterName {
    diabolus,
    dank,
    angel
};

class Player {
public:
    Player(CharacterName name, int x, int y);
    bn::fixed_point get_position();
    void update(int top_bound, int bottom_bound, int left_bound, int right_bound);  //passing bounds to avoid circle relationships
private:
    bn::sprite_ptr _sprite;
    bn::fixed_point _position;
    bn::fixed _friction;
    bn::fixed _acceleration;
    bn::fixed _max_speed;
    bn::fixed_point _velocity;
    void update_movement(int top_bound, int bottom_bound, int left_bound, int right_bound);
};

#endif