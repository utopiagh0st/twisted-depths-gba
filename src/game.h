#ifndef GAME_H
#define GAME_H

//classes
#include "bn_regular_bg_ptr.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "hud.h"
#include "room.h"
#include "level.h"
#include "obstacle.h"
#include "level_generator.h"

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

    bn::random _rnd;
    bn::optional<Level> _level;
    Level_generator _level_generator;

    //interface management
    bn::optional<Hud> _hud;
    bn::optional<Room> _room;

    //entity management
    bn::optional<Player> _player;
    
    bn::vector<Enemy, max_enemies> _enemies;
    bn::vector<Obstacle, max_obstacles> _obstacles;
    bn::vector<Projectile, MAX_PROJECTILES> _projectiles;

    int _bounds[4];
    int _frame;
    void game_over();
    void update_title();
    void update_pause();
    void update_playing();
};

#endif