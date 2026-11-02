#include "hud.h"
//sprites, txt and bg
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

#include "bn_sprite_items_hp_zipper.h"
#include "bn_sprite_items_hp_closed.h"
#include "bn_sprite_items_hp_open.h"
#include "bn_sprite_items_itemselect.h"

//backgrounds
#include "bn_regular_bg_items_border_blue.h"

Hud::Hud(bool visible) :
    _spr_hp_zipper(bn::sprite_items::hp_zipper.create_sprite(225, 101)),
    _bg_border(bn::regular_bg_items::border_blue.create_bg(0, 0))
{
    _bg_border->set_priority(0);
    _is_visible = visible;
}

void Hud::update(Player& player, bn::vector<Item, 6>& pocket, int selected_pocket_item) {
    if (_is_visible) {
        //HP ZIPPER
        if (player.get_hp() != _last_hp_checked || player.get_hp_max() != _last_hp_max_checked) {
            _hp_gauge.clear(); //resets the gauge to draw it from scratch, there must be a better way to achieve this but I wanna sleep
            int y_offset = -78;
            for (int i = 0; i < player.get_hp(); i++) {
                bn::sprite_ptr hp_open_piece = bn::sprite_items::hp_open.create_sprite(104,y_offset);
                hp_open_piece.set_bg_priority(0);
                _hp_gauge.push_back(hp_open_piece);
                y_offset += 4;
            }
            int hp_closed_amount = player.get_hp_max() - player.get_hp() + 2;
            for (int i = 0; i < hp_closed_amount; i++) {
                bn::sprite_ptr hp_closed_piece = bn::sprite_items::hp_closed.create_sprite(104,y_offset);
                hp_closed_piece.set_bg_priority(0);
                _hp_gauge.push_back(hp_closed_piece);
                y_offset += 4;
            }
            if (player.get_hp() == 0) {
                _spr_hp_zipper = bn::sprite_items::hp_zipper.create_sprite(105, -64);
            } else {
                _spr_hp_zipper = bn::sprite_items::hp_zipper.create_sprite(105, (player.get_hp()*4)-58);
            }
            _spr_hp_zipper.set_bg_priority(0);
        }

        //POCKET
        for (int i = 0; i < pocket.size(); i++) {
            pocket[i].show_in_pocket(i);
            pocket[i].update(player);
        }


        //pocket selection
        if (pocket.size() == 0) {
            _spr_itemselect.reset();
        } else {
            if (!_spr_itemselect.has_value()) {
                _spr_itemselect.emplace(bn::sprite_items::itemselect.create_sprite(-107.5, -48));
                _spr_itemselect->set_bg_priority(0);
            }
            switch (selected_pocket_item) {
                case 0:
                    _spr_itemselect->set_position(-108, -51);
                    break;
                case 1:
                    _spr_itemselect->set_position(-104, -30);
                    break;
                case 2:
                    _spr_itemselect->set_position(-103, -7);
                    break;
                case 3:
                    _spr_itemselect->set_position(-107, 15);
                    break;
                case 4:
                    _spr_itemselect->set_position(-102, 37);
                    break;
                case 5:
                    _spr_itemselect->set_position(-106, 61);
                    break;
                default:
                    break;
            }
        }
    }    
}