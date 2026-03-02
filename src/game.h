#ifndef GAME_H
#define GAME_H

//classes
#include "player.h"
#include "enemy.h"
//utilities and structures
#include "bn_optional.h"
#include "bn_vector.h"
#include "bn_random.h"
//sprites, txt and bg
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"

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

    bn::random random;

    bn::optional<Player> _player;
    static constexpr int MAX_ENEMIES = 64;
    bn::vector<Enemy, MAX_ENEMIES> _enemies;

    bn::optional<bn::regular_bg_ptr> _floor_bg;
    bn::optional<bn::regular_bg_ptr> _walls_bg;
    int _bounds[4];

    void update_title();
    void update_pause();
    void update_playing();
};

#endif