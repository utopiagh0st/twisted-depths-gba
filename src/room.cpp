#include "room.h"
#include "bn_vector.h"
#include "bn_random.h"
#include "bn_fixed_point.h"
//sprites, txt and bg
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

Room::Room(int room_index) {
    _room_index = room_index;
}

bn::fixed_point Room::get_bg_position() {
    return _bg->position();
}
void Room::put_bg_below() {
    _bg->put_below();
}

void Room::draw_bg(bn::fixed_point position) {
    if(_bg) {
        _bg->set_position(position);
    } else {
        const RoomData& room_data = ROOM_LOOKUP[_room_index];
        _bg.emplace(room_data.bg.create_bg(position));
        _bg->set_priority(3);
    }
}