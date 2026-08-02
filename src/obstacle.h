#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_fixed.h"
#include "bn_rect.h"

enum class ObstacleType {
    Rock
};

class Obstacle {
public:
    Obstacle(ObstacleType type, bn::fixed_point position);
    bn::rect get_hitbox();
    bn::fixed_point get_position();
private:
    bool _debug;
    bn::fixed_point _position;
    ObstacleType _type;
    bn::sprite_ptr _sprite;
    bn::optional<bn::sprite_ptr> _spr_hitbox;
    bool _active;
    bn::sprite_ptr create_obstacle_sprite(ObstacleType type, bn::fixed_point position);
};
#endif