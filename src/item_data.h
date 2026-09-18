#ifndef ITEM_DATA_H
#define ITEM_DATA_H

enum class ItemRadicality {
    USUAL,
    UNUSUAL,
    RADICAL
};

struct ItemData {
    int id,
    bn::string name,
    ItemRadicality radicality,
    bn::sprite_item sprite;
};

constexpr int ITEM_LOOKUP_SIZE = 1;
extern const bn::array<ItemData, ITEM_LOOKUP_SIZE> ITEM_LOOKUP;

#endif