#ifndef ENEMY_H
#define ENEMY_H

#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"

enum class EnemyType
{
    LimeCat
};

class Enemy {
public:
    Enemy(EnemyType type, int x, int y);
    void update(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd, bn::fixed_point player_pos);
private:
    EnemyType _type;
    bn::sprite_ptr _sprite;
    bn::fixed_point _position;
    int _direction;
    int _speed;
};

#endif