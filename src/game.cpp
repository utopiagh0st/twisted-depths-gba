#include "game.h"
//classes
#include "player.h"
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
#include "bn_sprite_items_textbox_side.h"
#include "bn_sprite_items_textbox_mid.h"
//bgs
#include "bn_regular_bg_items_floor_bg.h"
#include "bn_regular_bg_items_walls_bg.h"

Game::Game() :
    _player(0,0,CharacterName::diabolus),
    _floor_bg(bn::regular_bg_items::floor_bg.create_bg(0, 0)),
    _walls_bg(bn::regular_bg_items::walls_bg.create_bg(0, 0))
{
    bn::music_items::castlevania2.play(0.1);
    _walls_bg.set_priority(1);
    _floor_bg.set_priority(2);//priority(0 is higher)

    _bounds[0] = -50; //up
    _bounds[1] = 48; //down
    _bounds[2] = -66; //left
    _bounds[3] = 66; //right
}

int Game::getBound(int n) {
    return _bounds[n];
}

void Game::update()
{
    _player.update(_bounds[0], _bounds[1], _bounds[2], _bounds[3]);
}