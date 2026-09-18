#include "item.h"
#include "bn_fixed_point.h"
#include "bn_sprite_animate_actions.h"

Item::Item(int id)
{
    _id = id;
    const ItemData& item_data = ITEM_LOOKUP[id];
    _radicality = item_data.radicality;
}

void Item::update() {
    if (_sprite_anim && !_sprite_anim->done()) {
        _sprite_anim->update();
    }
}