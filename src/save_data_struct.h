#ifndef SAVE_DATA_STRUCT_H
#define SAVE_DATA_STRUCT_H

#include "bn_fixed.h"
#include "bn_array.h"

struct SRAMSaveData {
    bn::array<char, 32> format_tag;
    bn::fixed music_volume;
};

#endif