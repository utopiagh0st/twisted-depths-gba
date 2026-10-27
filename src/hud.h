#ifndef HUD_H
#define HUD_H

#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_vector.h"
#include "player.h"

class Hud {
public:
    Hud(bool visible);
    void set_pocket_changes(bool changes);
    void update(Player& player, bn::vector<Item, 6>& pocket);
private:
    bool _pocket_changes;
    int _last_hp_checked = -1;
    int _last_hp_max_checked = -1;
    bool _is_visible = false;
    bn::sprite_ptr _spr_hp_zipper;
    bn::vector<bn::sprite_ptr, 22> _hp_gauge;
    bn::optional<bn::regular_bg_ptr> _bg_border;
};

#endif