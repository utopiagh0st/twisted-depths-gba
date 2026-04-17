#include "environment.h"
//sprites, txt and bg
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
//backgrounds


Environment::Environment(bn::regular_bg_item current_floor, bn::regular_bg_item current_walls, bn::regular_bg_item current_border)
{
    create_env(current_floor, current_walls, current_border );
}

void Environment::create_env(bn::regular_bg_item floor, bn::regular_bg_item walls, bn::regular_bg_item border) {
    _floor_bg.emplace(floor.create_bg(0, 0));  //bg emplacement
    _walls_bg.emplace(walls.create_bg(0, 0));
    _border_bg.emplace(border.create_bg(0, 0));
    
    _border_bg->set_priority(0);
    _walls_bg->set_priority(1);
    _floor_bg->set_priority(2);  //priority (0 is the highest)
}
