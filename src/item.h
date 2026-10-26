#ifndef ITEM_H
#define ITEM_H

#include "bn_sprite_ptr.h"
#include "bn_fixed_point.h"
#include "bn_fixed.h"
#include "bn_rect.h"
#include "bn_optional.h"
#include "bn_sprite_animate_actions.h"

enum class ItemRarity {
    Normie,
    Cool,
    Under,
    True
};

enum class ItemType {
    Pocket, //goes on the left, u can have multiple if u want, bombs, boomerangs that kinda stuff
    Hand, // powerful enough by itself, needs the blood of ur innocent victims to charge
    Relic // "permanent" item that stays w you, what the youngins call a passive effect
};

class Item {
public:
    Item(int itemId);
private:
    bn::fixed_point _position;
    ItemRarity _rarity;
    bn::optional<bn::sprite_ptr> _sprite;
};
#endif
