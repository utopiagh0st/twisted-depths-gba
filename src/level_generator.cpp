#include "level_generator.h"
#include "level.h"
#include "room.h"
#include "room_data.h"

#include "bn_vector.h"
#include "bn_random.h"
#include "bn_array.h"

//sprites, txt and bg
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

Level_generator::Level_generator(bn::random rnd) :
    _rnd(rnd)
{}

Level Level_generator::generate_level(LevelType level_type) {
    int map_size = 5; //min 5
    bn::array<bn::array<int, map_size>, map_size> level_map;
    //fill map with empty
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            level_map[i][j] = EMPTY;
        }
    }
    //generate random starting room
    bn::point starting_room = bn::point(_rnd.get_int(map_size),_rnd.get_int(map_size));
    level_map[starting_room.x()][starting_room.y()] = UNSET;
    //generate from starting room with no branches
    int main_branch_size = (map_size / 3) + _rnd.get_int((map_size/9)*(-1), map_size/9);
    int turn_direction;
    bn::point current_room = starting_room;
    for (int i = 0; i < main_branch_size; i++) { //turn randomly to a free direction
        turn_direction = _rnd.get_int(3);
        if (turn_direction == UP &&
            current_room.x() > 0 &&
            level_map[current_room.x()-1][current_room.y()] == EMPTY) {

        } else if (turn_direction == DOWN) {

        }
    
    }
    //throw the dice to get n of branches
    
    /*
    int branches = 1 << _rnd.get_int(1,16); //each bit represents a direction Up,Down,Left,Right
    if(starting_room.x() == 0) { //Upper limit
    
    }
    if (branches | 1 << 8 == branches) {
        
    }
    */

    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            level_map[i][j] = EMPTY;
        }
    }
    /*
    bn::array<bn::array<int, map_size>, map_size> level_map = {{
        {{EMPTY,EMPTY,UNSET,UNSET,UNSET}},
        {{EMPTY,EMPTY,EMPTY,EMPTY,UNSET}},
        {{EMPTY,UNSET,UNSET,UNSET,UNSET}},
        {{EMPTY,UNSET,EMPTY,UNSET,UNSET}},
        {{EMPTY,UNSET,EMPTY,EMPTY,EMPTY}}
    }};
    */

    RoomType required_entries;
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (level_map[i][j] == UNSET) {
                required_entries = RoomType::NONE;
                if (i > 0 && level_map[i-1][j] != EMPTY) {
                    required_entries = required_entries | RoomType::U;
                }
                if (i < map_size-1 && level_map[i+1][j] != EMPTY) {
                    required_entries = required_entries | RoomType::D;
                }
                if (j > 0 && level_map[i][j-1] != EMPTY) {
                    required_entries = required_entries | RoomType::L;
                }
                if (j < map_size-1 && level_map[i][j+1] != EMPTY) {
                    required_entries = required_entries | RoomType::R;
                }
                level_map[i][j] = get_random_room_index(level_type, required_entries);
            }
        }
    }

    return Level(level_type, level_map, starting_room); //y,x
}

int Level_generator::get_random_room_index(LevelType level_type, RoomType required_entries) {
    bn::vector<int, 32> room_candidates;
    for(const RoomData& room : ROOM_LOOKUP) {
        if(level_type == room.level_type && match_entries(room.room_type, required_entries)) {
            int room_id = &room - ROOM_LOOKUP.data(); //pointer to first element of the array
            room_candidates.push_back(room_id);
        }
    }
    return room_candidates[_rnd.get_int(room_candidates.size())];
}