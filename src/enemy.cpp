#include "enemy.h"
#include "bn_sprite_items_enemy.h"

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
    _x = x;
    _y = y;
    _type = type;
    _sprite.set_bg_priority(0);
}

void Enemy::update() {
    
}