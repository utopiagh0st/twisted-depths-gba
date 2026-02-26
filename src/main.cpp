//don't forget to execute the make command everytime u add a new asset

//all of these are the butano libraries
#include "bn_core.h" //core library!!
//utilities and structures
#include "bn_unordered_map.h"
//music and sounds
#include "bn_music_items.h"
#include "bn_sound_items.h"
//input
#include "bn_keypad.h"
//sprites, txt and bg
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_bg_palette_ptr.h"

#include "bn_sprite_text_generator.h"
#include "bn_vector.h"

#include "common_variable_8x8_sprite_font.h"
#include "bn_string_view.h"

//sprites themselves
#include "bn_sprite_items_bluhemoji.h"
#include "bn_sprite_items_fran_stand.h"
#include "bn_sprite_items_textbox_side.h"
#include "bn_sprite_items_textbox_mid.h"
//bgs
#include "bn_regular_bg_items_floor_bg.h"
#include "bn_regular_bg_items_walls_bg.h"

int main()
{
    bn::core::init(); //initialization comes after this line

    bn::music_items::castlevania2.play(0.1); //the castlevania2 item is a sample made music file that was added to the music items file when the make command was executed

    bn::regular_bg_ptr floor = bn::regular_bg_items::floor_bg.create_bg(0, 0);
    bn::regular_bg_ptr walls = bn::regular_bg_items::walls_bg.create_bg(0, 0); //bg creation
    walls.set_priority(1);
    floor.set_priority(2);//priority(0 is higher)
    //bn::bg_palette_ptr palette = floor.palette();
    //palette.set_color(1, bn::color(31, 0, 0)); // bright red

    bn::unordered_map<int, int, 4> bounds; //colission bounds based from 0,0
    bounds[1] = -50; //up
    bounds[2] = 48; //down
    bounds[3] = -66; //left
    bounds[4] = 66; //right

    bn::sprite_ptr player = bn::sprite_items::fran_stand.create_sprite(0, 0); //creates a sprite
    player.set_bg_priority(0); //fran sprite

    //dialogue box sprites
    if (false) { //Ignore for now
        bn::vector<bn::sprite_ptr, 6> center_tiles;
        for (int x = -80; x <= 80; x += 32) {
            center_tiles.push_back(bn::sprite_items::textbox_mid.create_sprite(x, 64));
        }
        bn::sprite_ptr textbox_left = bn::sprite_items::textbox_side.create_sprite(-104, 64);
        bn::sprite_ptr textbox_right = bn::sprite_items::textbox_side.create_sprite(104, 64);
        textbox_right.set_horizontal_flip(true);
    }

    //progressive dialogue! also ignore for now
    bn::sprite_text_generator text_gen(common::variable_8x8_sprite_font);
    bn::vector<bn::sprite_ptr, 16> text_sprites;

    while(true) //game loop
    {   
        if(bn::keypad::up_held()) { //player movement
            player.set_y(player.y() - 1);
            if (player.y() < bounds[1]) { player.set_y(bounds[1]); }
        }
        if(bn::keypad::down_held()) { //player movement
            player.set_y(player.y() + 1);
            if (player.y() > bounds[2]) { player.set_y(bounds[2]); }
        }
        if(bn::keypad::left_held()) { //player movement
            player.set_x(player.x() - 1);
            if (player.x() < bounds[3]) { player.set_x(bounds[3]); }
        }
        if(bn::keypad::right_held()) { //player movement
            player.set_x(player.x() + 1);
            if (player.x() > bounds[4]) { player.set_x(bounds[4]); }
        }

        bn::core::update(); //this line always goes at the end
    }
}