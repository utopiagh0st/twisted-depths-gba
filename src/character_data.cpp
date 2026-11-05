#include "item_data.h"
#include "bn_array.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_item.h"
#include "bn_sprite_items_player_fran_walk.h"
#include "bn_sprite_items_player_tobichu_walk.h"

#include "character_data.h"

const bn::array<CharacterData, CHARACTER_DATA_LOOKUP_SIZE> CHARACTER_LOOKUP = {{
    { CharacterName::diabolus , "Diabolus", bn::sprite_items::player_fran_walk },
    { CharacterName::tobichu , "Tobichu", bn::sprite_items::player_tobichu_walk }
}};