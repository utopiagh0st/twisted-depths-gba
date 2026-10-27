#include "item_data.h"
#include "bn_array.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_item.h"

#include "bn_sprite_items_obstacle_trashcan.h"


const bn::array<ItemData, ITEM_LOOKUP_SIZE> ITEM_LOOKUP = {{
    { "HealTest", ItemType::Pocket, ItemRarity::Normie, bn::sprite_items::obstacle_trashcan }
}};