#ifndef PLAYER_H
#define PLAYER_H

#include "bn_sprite_ptr.h"

enum class CharacterName {
    diabolus,
    dank,
    angel
};

class Player {
public:
    Player(int x, int y, CharacterName name);
    void update(int top_bound, int bottom_bound, int left_bound, int right_bound);//passing bounds to avoid circle relationships
private:
    bn::sprite_ptr _sprite;
    int _x;
    int _y;
    int _speed;
    void update_movement(int top_bound, int bottom_bound, int left_bound, int right_bound);
};

#endif