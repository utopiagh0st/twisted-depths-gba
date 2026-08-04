#ifndef ROOM_H
#define ROOM_H

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_random.h"
#include "bn_fixed_point.h"
#include "room_data.h"
#include "bn_vector.h"
#include "obstacle.h"

class Room {
public:
    Room(int room_index);
    void put_bg_below();
    bn::fixed_point get_bg_position();
    void draw_bg(bn::fixed_point position);
    void generate_border(bn::vector<Obstacle, 50>& obstacles);
    void clear_borders(bn::vector<Obstacle, 50>& obstacles);
private:
    int _room_index;
    bn::optional<bn::regular_bg_ptr> _bg;
};

#endif