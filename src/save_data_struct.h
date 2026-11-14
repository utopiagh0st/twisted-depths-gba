#ifndef SAVE_DATA_STRUCT_H
#define SAVE_DATA_STRUCT_H

#include "bn_fixed.h"
#include "bn_array.h"
#include "level.h"
#include "player.h"

struct SRAMSaveData {
    bn::array<char, 32> format_tag;
    bn::fixed music_volume;
    bool has_run_save;
    PlayerData player_data;
};

#endif