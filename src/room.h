#ifndef ROOM_H
#define ROOM_H

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_bg_street_lr.h"

enum class RoomType {
    STREET_LR,
    DEBUG_CLOSED
};

// Estructura para asociar el Enum con el Asset
struct RoomData {
    RoomType type;
    bn::regular_bg_item bg;
    bool bg_flip_y;
    bool bg_flip_x;
};

// Tabla de consulta estática (vive en la ROM, no gasta RAM)
constexpr RoomData ROOM_LOOKUP[] = {
    {   RoomType::STREET_LR, bn::regular_bg_items::bg_street_lr, false, false},
    {   RoomType::DEBUG_CLOSED, bn::regular_bg_items::bg_street_lr, false, true}
};

class Room {
public:
    Room(RoomType room_type);
    void emplace_bgs(RoomType room_type);
private:
    bn::optional<bn::regular_bg_ptr> _bg;
};

#endif