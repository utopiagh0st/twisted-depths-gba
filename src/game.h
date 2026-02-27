#ifndef GAME_H
#define GAME_H

#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "player.h"
#include "bn_optional.h"

class Game {
public:
    Game();
    void update();

private:
    enum class State {
        Title,
        Playing
    };
    State _state;

    bn::optional<Player> _player;

    bn::optional<bn::regular_bg_ptr> _floor_bg;
    bn::optional<bn::regular_bg_ptr> _walls_bg;
    int _bounds[4];

    void update_title();
    void update_playing();
};

#endif