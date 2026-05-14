#ifndef LEVEL_H
#define LEVEL_H

#include "room.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_bg_street_lr.h"

enum class LevelType {
    STREET
};

// Estructura para asociar el Enum con el Asset
struct LevelData {
    LevelType type;
    int min_size;
    int max_size;
};

// Tabla de consulta estática (vive en la ROM, no gasta RAM)
constexpr LevelData LEVEL_LOOKUP[] = {
    {   LevelType::STREET_LR, bn::regular_bg_items::bg_street_lr, false, false}
};

class Level {
public:
    Room(RoomType room_type);
    void emplace_bgs(RoomType room_type);
private:
    bn::optional<bn::regular_bg_ptr> _bg;
};

#endif