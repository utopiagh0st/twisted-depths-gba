#ifndef CHARACTER_DATA_H
#define CHARACTER_DATA_H

#include "bn_sprite_item.h"

enum class CharacterName {
    diabolus,
    tobichu,
    angel
};

struct CharacterData {
    CharacterName name;
    std::string display_name;
    bn::sprite_item walk_sprite;
};

constexpr int CHARACTER_DATA_LOOKUP_SIZE = 2;
extern const bn::array<CharacterData, CHARACTER_DATA_LOOKUP_SIZE> CHARACTER_LOOKUP;

#endif