#ifndef BN_SOUND_ITEMS_INFO_H
#define BN_SOUND_ITEMS_INFO_H

#include "bn_span.h"
#include "bn_sound_item.h"
#include "bn_string_view.h"

namespace bn::sound_items_info
{
    constexpr inline pair<sound_item, string_view> array[] = {
        make_pair(sound_item(47), string_view("change_selection")),
        make_pair(sound_item(59), string_view("healdoo")),
        make_pair(sound_item(60), string_view("honk")),
        make_pair(sound_item(82), string_view("monsterboostdoo")),
        make_pair(sound_item(83), string_view("mute")),
        make_pair(sound_item(84), string_view("player_hurt")),
        make_pair(sound_item(94), string_view("select")),
    };

    constexpr inline span<const pair<sound_item, string_view>> span(array);
}

#endif

