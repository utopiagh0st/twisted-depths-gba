#ifndef ROOM_H
#define ROOM_H

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_random.h"

//background oh god
#include "bn_regular_bg_items_bg_street_u.h"
#include "bn_regular_bg_items_bg_street_d.h"
#include "bn_regular_bg_items_bg_street_l.h"
#include "bn_regular_bg_items_bg_street_r.h"
#include "bn_regular_bg_items_bg_street_ud.h"
#include "bn_regular_bg_items_bg_street_lr.h"
#include "bn_regular_bg_items_bg_street_ul.h"
#include "bn_regular_bg_items_bg_street_ur.h"
#include "bn_regular_bg_items_bg_street_dl.h"
#include "bn_regular_bg_items_bg_street_dr.h"
#include "bn_regular_bg_items_bg_street_ulr.h"
#include "bn_regular_bg_items_bg_street_dlr.h"
#include "bn_regular_bg_items_bg_street_udl.h"
#include "bn_regular_bg_items_bg_street_udr.h"
#include "bn_regular_bg_items_bg_street_udlr.h"

enum class LevelType {
    STREET
};

enum class RoomType { //represents entries with bitmasks
    U = 1 << 0,
    D = 1 << 1,
    L = 1 << 2,
    R = 1 << 3
};

constexpr RoomType operator|(RoomType a, RoomType b) {  //double holy fuckin cast
    return static_cast<RoomType>( static_cast<int>(a) | static_cast<int>(b) );
}

constexpr bool has_entries(RoomType room, RoomType entries) {
    return (static_cast<int>(room) & static_cast<int>(entries)) == static_cast<int>(entries);
}

// struct to link the enum with the asset
struct RoomData {
    LevelType level_type;
    RoomType room_type;
    bn::regular_bg_item bg;
};

// static look-up table, lives in the rom
constexpr RoomData ROOM_LOOKUP[] = {
    {   LevelType::STREET, RoomType::U, bn::regular_bg_items::bg_street_u},
    {   LevelType::STREET, RoomType::U | RoomType::R, bn::regular_bg_items::bg_street_ur},
    {   LevelType::STREET, RoomType::U | RoomType::L, bn::regular_bg_items::bg_street_ul}
};

class Room {
public:
    Room(bn::random& rnd, RoomType room_type);
    int get_random_room_index(LevelType level_type, RoomType required_entries);
    void emplace_bgs(int room_id);
private:
    bn::random& _rnd;
    bn::optional<bn::regular_bg_ptr> _bg;
};

#endif