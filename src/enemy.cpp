#include "enemy.h"
#include "bn_sprite_items_enemy.h"
#include "bn_fixed_point.h"

static bn::sprite_ptr create_character_sprite(EnemyType type, int x, int y) { //Character sprite selector
    switch(type) {
        case EnemyType::LimeCat:
            return bn::sprite_items::enemy.create_sprite(x, y);
    }

    return bn::sprite_items::enemy.create_sprite(x, y);
}

Enemy::Enemy(EnemyType type, int x, int y) :
    _sprite(create_character_sprite(type,x,y))
{
    _position = bn::fixed_point(x,y);
    _type = type;
    _direction = 0;
    _speed = 1;
    _sprite.set_bg_priority(0);
}

void Enemy::update(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd, bn::fixed_point player_pos) {
    // switch (_type) {
    // case EnemyType::LimeCat:
    //     move_towards(player_position, _speed);
    //     break;
    
    // default:
    //     break;
    // }
}

// void Enemy::move_towards(bn::fixed_point final_pos, int speed) {
// }