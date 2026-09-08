#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_fixed.h"
#include "bn_rect.h"
#include "bn_optional.h"
#include "bn_sprite_animate_actions.h"


constexpr int max_obstacles = 63;

enum class ObstacleType {
    Trashcan,
    Trashbag,
    TrashBox,
    RoomBorderHor,
    RoomBorderVer,
    RoomCornerHor,
    StreetConesLeft,
    StreetConesRight,
    StreetConesUp,
    StreetConesDown
};

enum class ObstacleClass {
    None,
    Door
};

class Obstacle {
public:
    Obstacle(ObstacleType type, bn::fixed_point position);
    void auto_set_hitbox();
    ObstacleType get_type();
    ObstacleClass get_class();
    bn::rect get_hitbox();
    bn::rect get_hitbox_for_projectile();

    bn::fixed_point get_position();
    void open();
    void update();
private:
    bn::optional<bn::sprite_animate_action<10>> _sprite_anim;
    bool _debug;
    bn::fixed_point _position;
    ObstacleType _type;
    ObstacleClass _class;
    bn::sprite_ptr _sprite;
    bn::fixed_point _hitbox_offset;
    bn::optional<bn::sprite_ptr> _spr_hitbox;
    bool _active;
    bool _visible;
    bn::fixed_point _hitbox_dimensions;
    bn::sprite_ptr create_obstacle_sprite_and_config(ObstacleType type, bn::fixed_point position);
};
#endif