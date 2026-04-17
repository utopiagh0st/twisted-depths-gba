#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"

class Environment {
public:
    Environment(bn::regular_bg_item current_floor, bn::regular_bg_item current_walls, bn::regular_bg_item current_border);
    void create_env(bn::regular_bg_item floor, bn::regular_bg_item walls, bn::regular_bg_item border);
private:
    bn::optional<bn::regular_bg_ptr> _floor_bg;
    bn::optional<bn::regular_bg_ptr> _walls_bg;
    bn::optional<bn::regular_bg_ptr> _border_bg;
};

#endif