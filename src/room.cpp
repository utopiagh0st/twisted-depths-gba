#include "room.h"
#include "bn_vector.h"
#include "bn_random.h"
//sprites, txt and bg
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

Room::Room(bn::random& rnd, RoomType required_entries) :
    _rnd(rnd)
{
    emplace_bgs( get_random_room_index(LevelType::STREET, required_entries) );
}

int Room::get_random_room_index(LevelType level_type, RoomType required_entries) {
    bn::vector<int, 32> room_candidates;
    for(const RoomData& room : ROOM_LOOKUP) {
        if(level_type == room.level_type && has_entries(room.room_type, required_entries)) {
            int room_id = &room - ROOM_LOOKUP;
            room_candidates.push_back(room_id);
        }
    }
    return room_candidates[_rnd.get_int(room_candidates.size())];
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
