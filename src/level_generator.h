#ifndef LEVEL_GENERATOR_H
#define LEVEL_GENERATOR_H

#include "bn_random.h"
#include "level.h"
#include "bn_fixed_point.h"

class Level_generator {
public:
    Level_generator(bn::random& rnd);
    Level generate_level(LevelType level_type);
    int get_random_room_index(LevelType level_type, RoomType required_entries);
private:
    bn::random& _rnd;
};

#endif