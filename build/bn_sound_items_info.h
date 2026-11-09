#ifndef BN_SOUND_ITEMS_INFO_H
#define BN_SOUND_ITEMS_INFO_H

#include "bn_span.h"
#include "bn_sound_item.h"
#include "bn_string_view.h"

namespace bn::sound_items_info
{
    constexpr inline pair<sound_item, string_view> array[] = {
        make_pair(sound_item(58), string_view("healdoo")),
        make_pair(sound_item(59), string_view("honk")),
        make_pair(sound_item(60), string_view("monsterboostdoo")),
        make_pair(sound_item(61), string_view("mute")),
        make_pair(sound_item(62), string_view("player_hurt")),
    };

    constexpr inline span<const pair<sound_item, string_view>> span(array);
}

#endif

