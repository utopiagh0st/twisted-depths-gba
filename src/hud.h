#ifndef HUD_H
#define HUD_H

#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_vector.h"

class Hud {
public:
    Hud(bool visible);
    void update(int player_hp, int player_hp_max);
private:
    int _last_hp_checked = -1;
    int _last_hp_max_checked = -1;
    bool _is_visible = false;
    bn::sprite_ptr _spr_hp_zipper;
    bn::vector<bn::sprite_ptr, 20> _hp_gauge;
};

#endif