#ifndef LEVEL_GENERATOR_H
#define LEVEL_GENERATOR_H

#include "bn_random.h"

class Level_generator {
public:
    Level_generator(bn::random rnd);
    generate_level(LevelType level_type);
    get_random_room_index(LevelType level_type, RoomType required_entries)
private:
    bn::random _rnd;
}

#endif