#include "item_data.h"
#include "bn_array.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_item.h"

const bn::array<ItemData, ITEM_LOOKUP_SIZE> ITEM_LOOKUP = {{
    { ItemRarity::Normie, ItemType::Hand, "HealTest" }
}}