#ifndef LEVEL_H
#define LEVEL_H

#include "room_data.h"
#include "room.h"
#include "bn_point.h"

constexpr int UP = 0;
constexpr int DOWN = 1;
constexpr int LEFT = 2;
constexpr int RIGHT = 3;

class Level {
public:
    Level(LevelType level_type, bn::array<bn::array<int, 5>, 5> level_map, bn::point starting_room);
    bn::point get_starting_room_pos();
    void load_room(bn::point room_pos);
    void begin_room_transition(int direction);
    void update();
private:
    LevelType _level_type;
    bn::array<bn::array<int, 5>, 5> _level_map;
    bn::optional<Room> _current_room;
    bn::optional<Room> _next_room;
    bn::point _starting_room_pos;
    bn::point _current_room_pos;
    int _room_transition_dir;
    bool _doing_room_transition;
    void do_room_transition();
};

#endif