#ifndef ROOM_H
#define ROOM_H

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_bg_street_lr.h"

enum class RoomType {
    U,
    D,
    L,
    R,
    UD,
    LR,
    UL,
    UR,
    DL,
    DR,
    UDL,
    UDR,
    ULR,
    DLR,
    UDLR
};

enum class LevelType {
    STREET
};

// struct to link the enum with the asset
struct RoomData {
    LevelType level_type;
    RoomType room_type;
    bn::regular_bg_item bg;
    bool bg_flip_y;
    bool bg_flip_x;
};

// static look-up table, lives in the rom
constexpr RoomData ROOM_LOOKUP[] = {
    {   LevelType::STREET, RoomType::LR, bn::regular_bg_items::bg_street_lr, false, false},
};

class Room {
public:
    Room(RoomType room_type);
    void emplace_bgs(LevelType level_type, RoomType room_type);
private:
    bn::optional<bn::regular_bg_ptr> _bg;
};

#endif