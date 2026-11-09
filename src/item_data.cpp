#include "item_data.h"
#include "bn_array.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_item.h"
#include "bn_sprite_items_item_healdeal.h"
#include "bn_sprite_items_item_wonster.h"
#include "bn_sprite_items_bluhemoji.h"


const bn::array<ItemData, ITEM_LOOKUP_SIZE> ITEM_LOOKUP = {{
    { "HealTest", ItemType::Hand, ItemRarity::Normie, bn::sprite_items::item_healdeal },
    { "WonsterEnergy", ItemType::Hand, ItemRarity::Normie, bn::sprite_items::item_wonster },
    { "BluhEmoji", ItemType::Hand, ItemRarity::Normie, bn::sprite_items::bluhemoji }
}};