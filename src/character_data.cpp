#include "item_data.h"
#include "bn_array.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_item.h"
#include "bn_sprite_items_player_fran_walk.h"
#include "bn_sprite_items_player_tobichu_walk.h"

#include "character_data.h"

const bn::array<CharacterData, CHARACTER_DATA_LOOKUP_SIZE> CHARACTER_LOOKUP = {{
    { CharacterName::diabolus,
        5, //hpmax (1 - 20)
        5, //hp (1 - hpmax)
        bn::fixed(1.45), //maxspeed (1.2 - 3)
        20, //iframes (how much u wanna suffer)
        bn::fixed(0.5), //attackspeed (0.1- 4)
        bn::fixed(6), //attackrate (5-30) *7
        bn::fixed(4), //damage (whatever) *2
        bn::fixed(0.15), //attackknockback *0.15
        bn::fixed(20), //range (20 - 120)
        bn::fixed(0.1), //max offset (0.1, 0.5 hell > why)
        bn::sprite_items::player_fran_walk
    },
    { CharacterName::tobichu,
        10, //hpmax
        10, //hp
        bn::fixed(1.55), //maxspeed
        5, //iframes
        bn::fixed(3), //attackspeed
        bn::fixed(10), //attackrate
        bn::fixed(2),
        bn::fixed(0.1),
        bn::fixed(70),
        bn::fixed(0.4),
        bn::sprite_items::player_tobichu_walk
    }
}};