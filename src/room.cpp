#include "room.h"
#include "bn_vector.h"
#include "bn_random.h"
#include "bn_fixed_point.h"
//sprites, txt and bg
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "room_data.h"

Room::Room(int room_index, bn::random& rnd) {
    _rnd = rnd;
    _room_index = room_index;
}

bn::fixed_point Room::get_bg_position() {
    return _bg->position();
}
void Room::put_bg_below() {
    _bg->put_below();
}

void Room::safe_push_back_obstacle(bn::vector<Obstacle, max_obstacles>& obstacles, ObstacleType type, bn::fixed_point position) {
    if(obstacles.size() < max_obstacles) {
        obstacles.push_back(Obstacle(type, position));
    }
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

void Room::clear_borders(bn::vector<Obstacle, max_obstacles>& obstacles) {
    for(int i = 0; i < obstacles.size(); ) { //erasing lol
        if(obstacles[i].get_type() == ObstacleType::RoomBorderHor || obstacles[i].get_type() == ObstacleType::RoomBorderVer || obstacles[i].get_type() == ObstacleType::RoomCornerHor) {
            obstacles.erase(obstacles.begin() + i); //using pointers!!
        } else {
            ++i;
        }
    }
}

void Room::generate_obstacles(bn::vector<Obstacle, max_obstacles>& obstacles) {
    generate_border(obstacles);
    const RoomData& room_data = ROOM_LOOKUP[_room_index];
    for(int i = 0; i < room_data.obstacle_count; ++i) {
        const ObstacleSpawnData& obstacle_data = room_data.obstacles_spawn_data[i];
        safe_push_back_obstacle(obstacles, obstacle_data.obstacle_type, obstacle_data.position);
    }
}

void Room::generate_border(bn::vector<Obstacle, max_obstacles>& obstacles) {
    const RoomData& room_data = ROOM_LOOKUP[_room_index];
    if (!has_entries(room_data.room_type, RoomType::U)) {
        safe_push_back_obstacle(obstacles, ObstacleType::RoomBorderHor, bn::fixed_point(0,-64));
    }
    if (!has_entries(room_data.room_type, RoomType::D)) {
        safe_push_back_obstacle(obstacles, ObstacleType::RoomBorderHor, bn::fixed_point(0,64));
    }
    if (!has_entries(room_data.room_type, RoomType::L)) {
        safe_push_back_obstacle(obstacles, ObstacleType::RoomBorderVer, bn::fixed_point(-80,0));
    }
    if (!has_entries(room_data.room_type, RoomType::R)) {
        safe_push_back_obstacle(obstacles, ObstacleType::RoomBorderVer, bn::fixed_point(80,0));
    }
    if (has_entries(room_data.room_type, RoomType::U)) {
        safe_push_back_obstacle(obstacles, ObstacleType::RoomCornerHor, bn::fixed_point(-72,-64));
        safe_push_back_obstacle(obstacles, ObstacleType::RoomCornerHor, bn::fixed_point(72,-64));
    }
    if (has_entries(room_data.room_type, RoomType::D)) {
        safe_push_back_obstacle(obstacles, ObstacleType::RoomCornerHor, bn::fixed_point(-72,64));
        safe_push_back_obstacle(obstacles, ObstacleType::RoomCornerHor, bn::fixed_point(72,64));
    }
    
}

void Room::generate_enemies(bn::vector<Enemy, max_enemies>& enemies) {
    const RoomData& room_data = ROOM_LOOKUP[_room_index];
    for(int i = 0; i < room_data.enemy_count; ++i) {
        const EnemySpawnData& enemy_data = room_data.enemies_spawn_data[i];
        enemies.push_back(Enemy(enemy_data.enemy_type, enemy_data.position, _rnd));
    }
}

void Room::close(bn::vector<Obstacle, max_obstacles>& obstacles) {
    const RoomData& room_data = ROOM_LOOKUP[_room_index];
    if (has_entries(room_data.room_type, RoomType::U)) {
        safe_push_back_obstacle(obstacles, ObstacleType::StreetConesLeft, bn::fixed_point(-24,-64));
        safe_push_back_obstacle(obstacles, ObstacleType::StreetConesRight, bn::fixed_point(24,-64));
    }
    if (has_entries(room_data.room_type, RoomType::D)) {
        safe_push_back_obstacle(obstacles, ObstacleType::StreetConesLeft, bn::fixed_point(-24,64));
        safe_push_back_obstacle(obstacles, ObstacleType::StreetConesRight, bn::fixed_point(24,64));
    }
    if (has_entries(room_data.room_type, RoomType::L)) {
        safe_push_back_obstacle(obstacles, ObstacleType::StreetConesUp, bn::fixed_point(-80,-24));
        safe_push_back_obstacle(obstacles, ObstacleType::StreetConesDown, bn::fixed_point(-80,24));
    }
    if (has_entries(room_data.room_type, RoomType::R)) {
        safe_push_back_obstacle(obstacles, ObstacleType::StreetConesUp, bn::fixed_point(80,-24));
        safe_push_back_obstacle(obstacles, ObstacleType::StreetConesDown, bn::fixed_point(80,24));
    }
}

void Room::open(bn::vector<Obstacle, max_obstacles>& obstacles) {
    for(int i = 0; i < obstacles.size(); i++) { //erasing lol
        if(obstacles[i].get_class() == ObstacleClass::Door) {
            obstacles[i].open(); //using pointers!!
        }
    }
}
