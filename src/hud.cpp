#include "hud.h"
//sprites, txt and bg
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

#include "bn_sprite_items_hp_zipper.h"
#include "bn_sprite_items_hp_closed.h"
#include "bn_sprite_items_hp_open.h"
//backgrounds

Hud::Hud(bool visible) :
    _spr_hp_zipper(bn::sprite_items::hp_zipper.create_sprite(225, 101))
{
    _is_visible = visible;
    //initialization
}

void Hud::update(int player_hp, int player_hp_max) {
    if (_is_visible && (player_hp != _last_hp_checked || player_hp_max != _last_hp_max_checked)) {
        _hp_gauge.clear();
        int y_offset = 0;
        for (int i = 0; i < player_hp; i++) {
            bn::sprite_ptr hp_gauge_piece = bn::sprite_items::hp_open.create_sprite(0,y_offset);
            hp_gauge_piece.set_bg_priority(0);
            _hp_gauge.pushback(hp_gauge_piece);
        }
    }
        
}