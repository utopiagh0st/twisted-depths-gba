#include "title_screen.h"
#include "bn_sprite_items_common_fixed_8x8_font.h"
#include "bn_sprite_items_icon_player_head_fran.h"
#include "bn_sprite_items_icon_player_head_tobichu.h"
#include "bn_sprite_items_icon_small_up_arrow.h"
#include "bn_regular_bg_items_bg_title_city.h"
#include "bn_regular_bg_items_bg_title_black_overlay.h"

#include "bn_keypad.h"
#include "bn_sprite_items_button_new_game.h"
#include "bn_sprite_items_button_settings.h"
#include "bn_sprite_items_icon_settings_various.h"
#include "bn_music.h"
#include "bn_sound.h"
#include "bn_music_items.h"
#include "bn_sound_items.h"
#include "bn_optional.h"
#include "bn_sram.h"


TitleScreen::TitleScreen(
    bn::sprite_font& font_sprite,
    bn::sprite_text_generator& text_generator,
    SRAMSaveData& save_data
):
    _font_sprite(font_sprite),
    _text_generator(text_generator),
    _save_data(save_data)
{   
    _counter = 0;
    _ready_to_start_game = false;
    _bg_landscape.emplace(bn::regular_bg_items::bg_title_city.create_bg(0, 0));
    _bg_black_overlay.emplace(bn::regular_bg_items::bg_title_black_overlay.create_bg(0, 0));
    _bg_landscape->set_priority(3);
    _bg_black_overlay->set_priority(2);

    _selected_character = CharacterName::diabolus;  //default character selection

    _text_generator.generate(-120,75,"dev-9.11.26",_text_sprites);
    for (bn::sprite_ptr sprite : _text_sprites) {
        sprite.set_bg_priority(0);
    }

    load_next_screen(TitleState::Main);
    bn::music_items::bloody_tears.play(_save_data.music_volume);
}

bool TitleScreen::is_ready_to_start_game() {
    return _ready_to_start_game;
}

CharacterName TitleScreen::get_selected_character() {
    return _selected_character;
}

void TitleScreen::load_next_screen(TitleState next_screen_state) {
    switch (next_screen_state) {
        case TitleState::Main:
            _spr_button_new_game.emplace(bn::sprite_items::button_new_game.create_sprite(-50,0,1));
            _spr_button_settings.emplace(bn::sprite_items::button_settings.create_sprite(-50,40,0));
            _spr_button_new_game->set_bg_priority(0);
            _spr_button_settings->set_bg_priority(0);
        break;
        case TitleState::Settings:
            _spr_music_vol_icon.emplace(bn::sprite_items::icon_settings_various.create_sprite(-103,-50,2));
            _spr_music_vol_icon->set_bg_priority(0);

            for (int i = 1; i <= 10; i++) {
                if (i <= (int)(bn::music::volume()*10)) {
                    _music_vol_bar.push_back(bn::sprite_items::icon_settings_various.create_sprite(-80 + (i*8), -50, 0));
                } else {
                    _music_vol_bar.push_back(bn::sprite_items::icon_settings_various.create_sprite(-80 + (i*8), -50, 1));
                }
                _music_vol_bar[i-1].set_bg_priority(0);
            }

        break;
        case TitleState::CharacterSelect:
            _spr_selection_arrow.emplace(bn::sprite_items::icon_small_up_arrow.create_sprite(-80, 30));
            _spr_selection_arrow->set_bg_priority(0);
            
            _spr_player_head_1.emplace(bn::sprite_items::icon_player_head_fran.create_sprite(-80, 20));
            _spr_player_head_anim_1.emplace(
                bn::sprite_animate_action<4>::forever(
                    _spr_player_head_1.value(),
                    10,
                    bn::sprite_items::icon_player_head_fran.tiles_item(),
                    bn::array<uint16_t, 4>{ 0, 1, 2, 1 }
                )
            );
            _spr_player_head_1->set_bg_priority(0);
            
            
            _spr_player_head_2.emplace(bn::sprite_items::icon_player_head_tobichu.create_sprite(-40, 20));
            _spr_player_head_anim_2.emplace(
                bn::sprite_animate_action<4>::forever(
                    _spr_player_head_2.value(),
                    10,
                    bn::sprite_items::icon_player_head_tobichu.tiles_item(),
                    bn::array<uint16_t, 4>{ 0, 1, 2, 1 }
                )
            );
            _spr_player_head_2->set_bg_priority(0);
            break;
        case TitleState::Starting:
            _text_sprites.clear();
            _text_generator.generate(-30,0,"bello...",_text_sprites);
            break;
        default:
        break;
    }
    _state = next_screen_state;
    _selection = 0;
}

void TitleScreen::update_main() {
    if (bn::keypad::a_pressed() || bn::keypad::start_pressed()) {
        bn::sound_items::select.play(1, 1, 0);
        _spr_button_new_game.reset();
        _spr_button_settings.reset();
        switch (_selection) {
            case (int)MainButtonOptions::NewGame:
                load_next_screen(TitleState::CharacterSelect);
            break;
            case (int)MainButtonOptions::Settings:
                load_next_screen(TitleState::Settings);
                break;
            default:
            break;
        }
    } else if (bn::keypad::up_pressed() && _selection > 0) {
        _selection--;
    } else if (bn::keypad::down_pressed() && _selection < (int)MainButtonOptions::Settings) {
        _selection++;
    }
    
    if (bn::keypad::up_pressed() || bn::keypad::down_pressed()) {
        bn::sound_items::change_selection.play(1, 1, 0);
        switch (_selection) {
            case (int)MainButtonOptions::NewGame:
                _spr_button_new_game->set_tiles(bn::sprite_items::button_new_game.tiles_item(), 1);
                _spr_button_settings->set_tiles(bn::sprite_items::button_settings.tiles_item(), 0);
                break;
            case (int)MainButtonOptions::Settings:
                _spr_button_new_game->set_tiles(bn::sprite_items::button_new_game.tiles_item(), 0);
                _spr_button_settings->set_tiles(bn::sprite_items::button_settings.tiles_item(), 1);
                break;
            default:
            break;
        }
    }
}

void TitleScreen::update_settings() {
    if (bn::keypad::left_pressed() && bn::music::volume() > 0) {
        bn::fixed new_volume = bn::music::volume() - 0.1;
        if (new_volume < 0) {
            new_volume = 0;
        }
        bn::music::set_volume(new_volume);
        bn::sound_items::change_selection.play(new_volume);
        _music_vol_bar[(int)(new_volume*10)].set_tiles(bn::sprite_items::icon_settings_various.tiles_item(),1);
        _save_data.music_volume = new_volume;
    } else if (bn::keypad::right_pressed() && bn::music::volume() < 1) {
        bn::fixed new_volume = bn::music::volume() + 0.1;
        if (new_volume > 1) {
            new_volume = 1;
        }
        bn::music::set_volume(new_volume);
        bn::sound_items::change_selection.play(new_volume);
        _music_vol_bar[(int)((new_volume*10)-1)].set_tiles(bn::sprite_items::icon_settings_various.tiles_item(),0);
        _save_data.music_volume = new_volume;
    }  
    if (bn::keypad::b_pressed()) {
        bn::sound_items::select.play(1, 1, 0);
        _spr_music_vol_icon.reset();
        _music_vol_bar.clear();
        bn::sram::write(_save_data);
        load_next_screen(TitleState::Main);
    }

}

void TitleScreen::update_character_select() {
    _spr_player_head_anim_1->update();
    _spr_player_head_anim_2->update();

    switch(_selected_character) {
        case CharacterName::diabolus:
            _spr_selection_arrow->set_position(-80, 30);
            break;
        case CharacterName::tobichu:
            _spr_selection_arrow->set_position(-40, 30);
            break;
        default:
            _spr_selection_arrow->set_position(0, 30);
            break;
    }

    
    if (bn::keypad::a_pressed() || bn::keypad::start_pressed()) {
        bn::sound_items::select.play(1, 1, 0);
        bn::music::stop();
        _spr_player_head_1.reset();
        _spr_player_head_anim_1.reset();
        _spr_player_head_2.reset();
        _spr_player_head_anim_2.reset();
        _spr_selection_arrow.reset();
        _bg_black_overlay.reset();
        _bg_landscape.reset();
        load_next_screen(TitleState::Starting);
    } else if (bn::keypad::select_pressed() || bn::keypad::right_pressed()) {
        bn::sound_items::change_selection.play(1, 1, 0);
        _selected_character = (CharacterName)((int)_selected_character+1); //cast heaven lol
        if (_selected_character > CharacterName::tobichu) {
            _selected_character = (CharacterName)0;
        }
    } else if (bn::keypad::left_pressed()) {
        bn::sound_items::change_selection.play(1, 1, 0);
        _selected_character = (CharacterName)((int)_selected_character-1); //cast heaven lol
        if (_selected_character < (CharacterName)0) {
            _selected_character = CharacterName::tobichu;
        }
    } else if (bn::keypad::b_pressed()) {
        bn::sound_items::change_selection.play(1, 1, 0);
        _spr_player_head_1.reset();
        _spr_player_head_anim_1.reset();
        _spr_player_head_2.reset();
        _spr_player_head_anim_2.reset();
        _spr_selection_arrow.reset();
        load_next_screen(TitleState::Main);
    }
}

void TitleScreen::update_starting() {
    _counter++;
    if(_counter >= 240) {
        _counter = 0;
        _ready_to_start_game = true;
    }
}

void TitleScreen::update() {
    switch (_state)
    {
    case TitleState::Main:
        update_main();
        break;
    case TitleState::CharacterSelect:
        update_character_select();
        break;
    case TitleState::Settings:
        update_settings();
        break;
    case TitleState::Starting:
        update_starting();
        break;
    default:
        break;
    }
    if (_bg_landscape) {
        _bg_landscape->set_position(bn::fixed_point((_bg_landscape->x() + 0.1), 0));
        if (_bg_landscape->x() > 256) {
            _bg_landscape->set_x(0);
        }
    }
    if (_bg_black_overlay) {
        _bg_black_overlay->set_position(bn::fixed_point(0, (_bg_black_overlay->y() + 1)));
        if (_bg_black_overlay->y() > 256) {
            _bg_black_overlay->set_y(0);
        }
    }
}