#include "enemy.h"
#include "bn_sprite_items_enemy.h"
#include "bn_fixed_point.h"
#include "bn_math.h"

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
    _velocity = bn::fixed_point(0,0);
    _friction = bn::fixed(0.05);
    _acceleration = bn::fixed(0.2);
    _max_speed = bn::fixed(3);
    _cooldown = 0;
    _step = 0;

    _type = type;
    _sprite.set_bg_priority(0);
}

void Enemy::update(int top_bnd, int bottom_bnd, int left_bnd, int right_bnd, bn::fixed_point player_pos) {
    switch (_type) {
    case EnemyType::LimeCat:
        switch (_step) {
        case 0:
            _target = player_pos;
            _step++;
        case 1:
            move_towards(_target);
        case 2:
            deaccelerate();
            if (_velocity == bn::fixed_point(0,0)) {
                _cooldown = 0;
                _step++;
            }
        case 3:
            _cooldown--;
            if (!_cooldown) {
                _step = 0;
            }
        break;
        }
    default:
        break;
    }
}

void Enemy::move_towards(bn::fixed_point final_pos) {
    bn::fixed_point direction = final_pos - _position;

    bn::fixed length_sq = direction.x() * direction.x() + direction.y() * direction.y();

    if(length_sq > 1) {
        bn::fixed length = bn::sqrt(length_sq);
        direction /= length;
        _velocity += direction * _acceleration;
    } else {
        _step++;
    }

    _position += _velocity;
    _sprite.set_position(bn::fixed_point(_position.x().integer(), _position.y().integer()));
}

void Enemy::deaccelerate() {
    _velocity *= bn::fixed(1) - _friction;
    _position += _velocity;
    _sprite.set_position(bn::fixed_point(_position.x().integer(), _position.y().integer()));
}