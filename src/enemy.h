#ifndef ENEMY_H
#define ENEMY_H

#include "bn_sprite_ptr.h"

enum class EnemyType
{
    LimeCat
};

class Enemy {
public:
    Enemy(EnemyType type, int x, int y);
    void update();
private:
    EnemyType _type;
    bn::sprite_ptr _sprite;
    int _x;
    int _y;
};

#endif