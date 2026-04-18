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
    if (_is_visible) {
        //HP ZIPPER
        if (player_hp != _last_hp_checked || player_hp_max != _last_hp_max_checked) {
            _hp_gauge.clear();
            int y_offset = -78;
            for (int i = 0; i < player_hp; i++) {
                bn::sprite_ptr hp_open_piece = bn::sprite_items::hp_open.create_sprite(104,y_offset);
                hp_open_piece.set_bg_priority(0);
                _hp_gauge.push_back(hp_open_piece);
                y_offset += 4;
            }
            int hp_closed_amount = player_hp_max - player_hp;
            for (int i = 0; i < hp_closed_amount; i++) {
                bn::sprite_ptr hp_closed_piece = bn::sprite_items::hp_closed.create_sprite(104,y_offset);
                hp_closed_piece.set_bg_priority(0);
                _hp_gauge.push_back(hp_closed_piece);
                y_offset += 4;
            }
            if (player_hp == 0) {
                _spr_hp_zipper = bn::sprite_items::hp_zipper.create_sprite(105, -64);
            } else {
                _spr_hp_zipper = bn::sprite_items::hp_zipper.create_sprite(105, (player_hp*4)-62);
            }
            _spr_hp_zipper.set_bg_priority(0);
        }
    }    
}