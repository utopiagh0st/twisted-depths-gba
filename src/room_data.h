#ifndef ROOM_DATA_H
#define ROOM_DATA_H

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

enum class LevelType {
    STREET
};

enum class RoomType { //represents entries with bitmasks
    NONE = 0,
    
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
constexpr bool match_entries(RoomType room, RoomType required) {
    return room == required;
}

// struct to link the enum with the asset
struct RoomData {
    LevelType level_type;
    RoomType room_type;
    bn::regular_bg_item bg;
};

// static look-up table that lives in cpp cuz it'll get big
extern RoomData ROOM_LOOKUP[];

#endif