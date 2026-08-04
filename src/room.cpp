#include "room.h"
#include "bn_vector.h"
#include "bn_random.h"
#include "bn_fixed_point.h"
//sprites, txt and bg
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "room_data.h"

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

void Room::clear_borders(bn::vector<Obstacle, 50>& obstacles) {
    for(int i = 0; i < obstacles.size(); ) { //erasing lol
        if(obstacles[i].get_type() == ObstacleType::RoomBorderHor || obstacles[i].get_type() == ObstacleType::RoomBorderVer) {
            obstacles.erase(obstacles.begin() + i); //using pointers!!
        } else {
            ++i;
        }
    }
}

void Room::generate_border(bn::vector<Obstacle, 50>& obstacles) {
    clear_borders(obstacles);
    const RoomData& room_data = ROOM_LOOKUP[_room_index];
    if (!has_entries(room_data.room_type, RoomType::U)) {
        obstacles.push_back(Obstacle(ObstacleType::RoomBorderHor, bn::fixed_point(0,-64)));
    }
    if (!has_entries(room_data.room_type, RoomType::D)) {
        obstacles.push_back(Obstacle(ObstacleType::RoomBorderHor, bn::fixed_point(0,64)));
    }
    if (!has_entries(room_data.room_type, RoomType::L)) {
        obstacles.push_back(Obstacle(ObstacleType::RoomBorderVer, bn::fixed_point(-80,0)));
    }
    if (!has_entries(room_data.room_type, RoomType::R)) {
        obstacles.push_back(Obstacle(ObstacleType::RoomBorderVer, bn::fixed_point(80,0)));
    }
}