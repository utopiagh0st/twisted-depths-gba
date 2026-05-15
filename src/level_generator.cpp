#include "level_generator.h"
#include "level.h"
#include "room.h"
#include "room_data.h"

#include "bn_vector.h"
#include "bn_random.h"
//sprites, txt and bg
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

LevelGenerator::LevelGenerator(bn::random rnd) :
    _rnd(rnd)
;

Level Level_generator::generate_level(LevelType level_type) {
    int level_map[5][5] = {
        {-1,-1,-1,-2,-2},
        {-1,-1,-1,-1,-2},
        {-1,-2,-2,-2,-2},
        {-1,-2,-1,-2,-2},
        {-1,-2,-1,-1,-1}
    };
    RoomType required_entries;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (level_map[i][j] == -2) {
                required_entries = RoomType::NONE;
                if (i > 0 && level_map[i-1][j] != -1) {
                    required_entries = required_entries | RoomType::U;
                }
                if (i < 4 && level_map[i+1][j] != -1) {
                    required_entries = required_entries | RoomType::D;
                }
                if (j > 0 && level_map[i][j-1] != -1) {
                    required_entries = required_entries | RoomType::L;
                }
                if (j < 4 && level_map[i][j+1] != -1) {
                    required_entries = required_entries | RoomType::R;
                }
                level_map[i][j] = get_random_room_index(level_type, required_entries);
            }
        }
    }

    return Level(level_type, level_map, bn::fixed_point(4, 1)); //y,x
}

int Level_generator::get_random_room_index(LevelType level_type, RoomType required_entries) {
    bn::vector<int, 32> room_candidates;
    for(const RoomData& room : ROOM_LOOKUP) {
        if(level_type == room.level_type && has_entries(room.room_type, required_entries)) {
            int room_id = &room - ROOM_LOOKUP;
            room_candidates.push_back(room_id);
        }
    }
    return room_candidates[_rnd.get_int(room_candidates.size())];
}