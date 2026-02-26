//don't forget to execute the make command everytime u add a new asset

//all of these are the butano libraries
#include "bn_core.h" //core library!!
//music and sounds
#include "bn_music_items.h"
#include "bn_sound_items.h"
//input
#include "bn_keypad.h"
//sprites
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_vector.h"

#include "common_variable_8x8_sprite_font.h"
#include "bn_string_view.h"

//sprites themselves
#include "bn_sprite_items_bluhemoji.h"
#include "bn_sprite_items_fran_stand.h"
#include "bn_sprite_items_textbox_side.h"
#include "bn_sprite_items_textbox_mid.h"

int main()
{
    bn::core::init(); //initialization comes after this line

    bn::music_items::castlevania2.play(0.1); //the castlevania2 item is a sample made music file that was added to the music items file when the make command was executed

    bn::sprite_ptr bluhemoji = bn::sprite_items::fran_stand.create_sprite(0, 0); //creates a sprite

    //dialogue box sprites
    bn::vector<bn::sprite_ptr, 6> center_tiles;
    for (int x = -80; x <= 80; x += 32) {
        center_tiles.push_back(bn::sprite_items::textbox_mid.create_sprite(x, 64));
    }
    bn::sprite_ptr textbox_left = bn::sprite_items::textbox_side.create_sprite(-104, 64);
    bn::sprite_ptr textbox_right = bn::sprite_items::textbox_side.create_sprite(104, 64);
    textbox_right.set_horizontal_flip(true);

    //progressive dialogue!
    bn::sprite_text_generator text_gen(common::variable_8x8_sprite_font);
    bn::vector<bn::sprite_ptr, 16> text_sprites;

    bn::string_view dialogue = "text lineup test 12345678901010101010";
    int visible_chars = 0;
    int frame_counter = 0;

    bool dialogue_visible = false;

    while(true) //game loop
    {   
        frame_counter++;

        if (frame_counter >= 60 && visible_chars < dialogue.size()) {
            frame_counter = 0;
            visible_chars++;

            text_sprites.clear();
            bn::string_view partial_text(dialogue.data(), visible_chars);
            text_gen.generate(-112, 56, partial_text, text_sprites);
        }
        bn::core::update(); //this line always goes at the end
    }
}

class DialogueBox
{
public:
    DialogueBox():
        _text_gen(common::variable_8x8_sprite_font)
    {
    }
    void show() {

    }
private:
    bool _visible = false;
    bn::sprite_text_generator _text_gen;
    bn::vector<bn::sprite_ptr, 16> _text_sprites;
};