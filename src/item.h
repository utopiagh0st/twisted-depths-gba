#ifndef ITEM_H
#define ITEM_H

#include "item_data.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_fixed.h"
#include "bn_rect.h"
#include "bn_optional.h"
#include "bn_sprite_animate_actions.h"

class Item {
public:
    Item(int id);
    void update();
private:
    int _id;
    bn::string _name;
    ItemRadicality _radicality;
    bn::sprite_ptr _sprite;
    bn::optional<bn::sprite_animate_action<10>> _sprite_anim;
    bn::optional<bn::sprite_ptr> _spr_hitbox;
};
#endif