#ifndef GAME_H
#define GAME_H

#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "player.h"

class Game {
public:
    Game();
    int getBound(int n);
    void update();

private:
    Player _player;
    bn::regular_bg_ptr _floor_bg;
    bn::regular_bg_ptr _walls_bg;
    int _bounds[4];
};

#endif