#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_floor_horizontal_street.h"
#include "bn_regular_bg_items_wall_vertical_street.h"
#include "bn_regular_bg_items_wall_horizontal_street.h"

enum class RoomType {
    STREET_H,
    DEBUG_CLOSED
};

// Estructura para asociar el Enum con el Asset
struct RoomData {
    RoomType type;
    bn::regular_bg_item bg_;
    bn::regular_bg_item bg_left_wall;
    bn::regular_bg_item bg_right_wall;
    bn::regular_bg_item bg_up_wall;
    bn::regular_bg_item bg_down_wall;
};

// Tabla de consulta estática (vive en la ROM, no gasta RAM)
constexpr RoomData ROOM_LOOKUP[] = {
    {   RoomType::STREET_H, bn::regular_bg_items::floor_horizontal_street,
        bn::regular_bg_items::wall_vertical_street, bn::regular_bg_items::wall_vertical_street,
        bn::regular_bg_items::wall_horizontal_street, bn::regular_bg_items::wall_horizontal_street },
    {   RoomType::DEBUG_CLOSED, bn::regular_bg_items::floor_horizontal_street,
        bn::regular_bg_items::wall_vertical_street, bn::regular_bg_items::wall_vertical_street,
        bn::regular_bg_items::wall_horizontal_street, bn::regular_bg_items::wall_horizontal_street }
};

class Environment {
public:
    Environment(RoomType room_type);
    void emplace_bgs(RoomType room_type);
private:
    bn::optional<bn::regular_bg_ptr> _border;
    bn::optional<bn::regular_bg_ptr> _floor;
    bn::optional<bn::regular_bg_ptr> _left_wall;
    bn::optional<bn::regular_bg_ptr> _right_wall;
    bn::optional<bn::regular_bg_ptr> _up_wall;
    bn::optional<bn::regular_bg_ptr> _down_wall;
};

#endif