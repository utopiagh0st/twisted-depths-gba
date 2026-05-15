#include "room.h"
#include "bn_vector.h"
#include "bn_random.h"
//sprites, txt and bg
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

Room::Room(int room_index) {
    _room_index
}

void Room::emplace_bgs(int room_index) {
    const RoomData& room = ROOM_LOOKUP[room_index];
    if(_bg) {
        _bg->set_item(room.bg);
    } else {
        _bg.emplace(room.bg.create_bg(0, 0));
        _bg->set_priority(3);
    }
}