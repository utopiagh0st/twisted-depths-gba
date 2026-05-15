#ifndef LEVEL_GENERATOR_H
#define LEVEL_GENERATOR_H

#include "bn_random.h"

class Level_generator {
public:
    Level_generator(bn::random rnd);
    generate_level(LevelType level_type);
private:
    bn::random _rnd;
}
#endif