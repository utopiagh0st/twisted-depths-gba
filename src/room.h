#ifndef ROOM_H
#define ROOM_H

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_random.h"


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