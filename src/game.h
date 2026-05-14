#ifndef GAME_H
#define GAME_H

//classes
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "hud.h"
#include "room.h"
//utilities and structures
#include "bn_optional.h"
#include "bn_vector.h"
#include "bn_random.h"
//sprites, txt and bg

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
    //interface management
    bn::optional<Hud> _hud;
    bn::optional<Room> _room;

    //entity management
    bn::optional<Player> _player;
    static constexpr int MAX_ENEMIES = 50;
    static constexpr int MAX_PROJECTILES = 50;
    bn::vector<Enemy, MAX_ENEMIES> _enemies;
    bn::vector<Projectile, MAX_PROJECTILES> _projectiles;

    //sprites & backgrounds
    bn::optional<bn::regular_bg_ptr> _floor_bg;
    bn::optional<bn::regular_bg_ptr> _walls_bg;
    int _bounds[4];

    void update_title();
    void update_pause();
    void update_playing();
};

#endif