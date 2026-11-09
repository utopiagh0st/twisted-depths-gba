#ifndef ITEM_DATA_H
#define ITEM_DATA_H

#include "bn_sprite_item.h"
#include "item.h"

struct ItemData {
    std::string name;
    ItemType type;
    ItemRarity rarity;
    bn::sprite_item sprite;
};

constexpr int ITEM_LOOKUP_SIZE = 3;
extern const bn::array<ItemData, ITEM_LOOKUP_SIZE> ITEM_LOOKUP;

#endif