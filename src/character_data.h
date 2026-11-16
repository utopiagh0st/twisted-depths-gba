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
    int hp_max;
    int hp;
    bn::fixed max_speed; //1.2 low, 1.35 common, 3 max?
    int i_frames;
    bn::fixed attack_speed; // 4?
    bn::fixed attack_rate; // 5 - 30, base 7
    bn::fixed damage;
    bn::fixed attack_knockback; //0.1
    bn::fixed range;   // max 120
    bn::fixed max_offset; //base: 0.1, 0.5 is already punishing
    bn::sprite_item walk_sprite;
};

constexpr int CHARACTER_DATA_LOOKUP_SIZE = 2;
extern const bn::array<CharacterData, CHARACTER_DATA_LOOKUP_SIZE> CHARACTER_LOOKUP;

#endif