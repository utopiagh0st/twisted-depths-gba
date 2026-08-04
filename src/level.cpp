#include "level.h"
#include "room_data.h"

Level::Level(LevelType level_type, bn::array<bn::array<int, 5>, 5> level_map, bn::point starting_room_pos) {
    _doing_room_transition = false;
    _level_type = level_type;
    _level_map = level_map;
    _starting_room_pos = starting_room_pos;
    _current_room_pos = starting_room_pos;
}

bn::point Level::get_starting_room_pos() {
    return _starting_room_pos;
}

void Level::begin_room_transition(int next_room_dir) {
    _room_transition_dir = next_room_dir;
    int next_room_index;
    if(next_room_dir == UP) {
        next_room_index = _level_map[_current_room_pos.x() - 1][_current_room_pos.y()];
    } else if(next_room_dir == DOWN) {
        next_room_index = _level_map[_current_room_pos.x() + 1][_current_room_pos.y()];
    } else if(next_room_dir == LEFT) {
        next_room_index = _level_map[_current_room_pos.x()][_current_room_pos.y() - 1];
    } else if(next_room_dir == RIGHT) {
        next_room_index = _level_map[_current_room_pos.x()][_current_room_pos.y() + 1];
    }
    _next_room.emplace(next_room_index);
    _doing_room_transition = true;
}

void Level::load_room(bn::point map_index, bn::vector<Obstacle, 50>& obstacles) {
    _current_room.emplace( _level_map[map_index.x()][map_index.y()] );
    _current_room->draw_bg(bn::fixed_point(0,0));
    _current_room->generate_border(obstacles);
}

void Level::do_room_transition() {
    bn::point next_room_pos;
    bn::fixed_point next_room_bg_pos_diff;
    bn::fixed_point velocity;
    int speed = 20;
    if (_room_transition_dir == UP) {
        velocity = bn::fixed_point(0,speed);
        next_room_bg_pos_diff = bn::fixed_point(0,-144);
        next_room_pos = _current_room_pos + bn::point(-1,0);
    } else if (_room_transition_dir == DOWN) {
        velocity = bn::fixed_point(0,speed * -1);
        next_room_bg_pos_diff = bn::fixed_point(0,144);
        next_room_pos = _current_room_pos + bn::point(1,0);
    } else if (_room_transition_dir == LEFT) {
        velocity = bn::fixed_point(speed,0);
        next_room_bg_pos_diff = bn::fixed_point(-176,0);
        next_room_pos = _current_room_pos + bn::point(0,-1);
    } else if (_room_transition_dir == RIGHT) {
        velocity = bn::fixed_point(speed * -1,0);
        next_room_bg_pos_diff = bn::fixed_point(176,0);
        next_room_pos = _current_room_pos + bn::point(0,1);
    }
    bn::fixed_point next_pos = _current_room->get_bg_position() + velocity;
    
    bool finished = false;
    if(_room_transition_dir == LEFT || _room_transition_dir == RIGHT) { //fuckin genius
        finished = bn::abs(next_pos.x()) >= 176;
    } else {
        finished = bn::abs(next_pos.y()) >= 144;
    }

    if (!finished) {
        _next_room->draw_bg(next_pos + next_room_bg_pos_diff);
        _current_room->draw_bg(next_pos);
        if(_room_transition_dir == LEFT || _room_transition_dir == RIGHT) { //fuckin genius
            if (bn::abs(next_pos.x()) >= 95) {
                _current_room->put_bg_below();
            } else {
                _next_room->put_bg_below();
            }
        } else {
            if (bn::abs(next_pos.y()) >= 144/4) {
                _next_room->put_bg_below();
            } else {
                _current_room->put_bg_below();
            }
        }
    } else {
        _current_room.swap(_next_room);
        _next_room.reset();
        _current_room_pos = next_room_pos;
        _current_room->draw_bg(bn::fixed_point(0,0));
        _doing_room_transition = false;
    }
}

void Level::update(obstacles) {
    if (_doing_room_transition) {
        do_room_transition();
        _current_room->generate_border(obstacles);
    }
}