#ifndef GAME_H
#define GAME_H

#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "player.h"
#include "enemy.h"
#include "bn_optional.h"

class Game {
public:
    Game();
    void update();

private:
    enum class State {
        Title,
        Pause,
        Playing
    };
    State _state;

    bn::optional<Player> _player;
    bn::optional<Enemy> _enemy;

    bn::optional<bn::regular_bg_ptr> _floor_bg;
    bn::optional<bn::regular_bg_ptr> _walls_bg;
    int _bounds[4];

    void update_title();
    void update_pause();
    void update_playing();
};

#endif