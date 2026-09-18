#include "item_data.h"
#include "bn_array.h"
#include "bn_sprite_item_healdeal.h"

const bn::array<ItemData, ITEM_LOOKUP_SIZE> ITEM_LOOKUP = {{ //Leveltype, roomtype (entrances), background, array of obstacle data, obstacle num (adding enemies next!!)
    { 1, "HealDeal", ItemQuality::USUAL, bn::sprite_items::healdeal}
}};