#ifndef ITEM_STAND_H
#define ITEM_STAND_H

#include "bn_fixed_point.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_optional.h"

class Item_stand{
public:
    update();
private:
    int _item_id;
    bn::fixed_point _position;
    bn::sprite_ptr _sprite;
    bn::optional<bn::sprite_animate_action<8>> _sprite_anim;
}
#endif