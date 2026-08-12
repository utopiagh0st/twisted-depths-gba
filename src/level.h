#ifndef LEVEL_H
#define LEVEL_H

#include "room_data.h"
#include "room.h"
#include "bn_point.h"
#include "bn_vector.h"
#include "obstacle.h"

constexpr int UP = 0;
constexpr int DOWN = 1;
constexpr int LEFT = 2;
constexpr int RIGHT = 3;
constexpr int map_size = 10;

class Level {
public:
    Level(LevelType level_type, bn::array<bn::array<int, 10>, 10> level_map, bn::point starting_room);
    bn::point get_starting_room_pos();
    bool is_doing_room_transition();
    void load_room(bn::point room_pos, bn::vector<Obstacle, max_obstacles>& obstacles);
    void begin_room_transition(int direction, bn::vector<Obstacle, max_obstacles>& obstacles);
    void update(bn::vector<Obstacle, max_obstacles>& obstacles);
    void toggle_map(bool showing);
private:
    LevelType _level_type;
    bn::array<bn::array<int, 10>, 10> _level_map;
    bn::optional<Room> _current_room;
    bn::optional<Room> _next_room;
    bn::point _starting_room_pos;
    bn::point _current_room_pos;
    int _room_transition_dir;
    bool _doing_room_transition;
    bn::vector<bn::sprite_ptr, 100> _minimap_tiles;
    void do_room_transition(bn::vector<Obstacle, max_obstacles>& obstacles);
};

#endif