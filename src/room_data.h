#ifndef ROOM_DATA_H
#define ROOM_DATA_H

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_vector.h"
#include "bn_array.h"

#include "obstacle.h"

//to make room generation a lil clearer
constexpr int EMPTY = -1;
constexpr int UNSET = -2;

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

//obst struct to link em with a position
struct ObstacleSpawnData {
    ObstacleType obstacle_type;
    bn::fixed_point position;
};

//struct to link the enum with the asset
struct RoomData {
    LevelType level_type;
    RoomType room_type;
    bn::regular_bg_item bg;
    bn::array<ObstacleSpawnData, 63> obstacles_spawn_data;
    int obstacle_count;
};

// static look-up table that lives in cpp cuz it'll get big, don't ask me to explain this, I never understood c
extern const bn::array<RoomData, 15> ROOM_LOOKUP;

#endif