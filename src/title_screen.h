#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include "bn_regular_bg_ptr.h"
#include "bn_optional.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_ptr.h"
#include "player.h"

#include "bn_sprite_text_generator.h"
#include "bn_sprite_font.h"

class TitleScreen {
public:
    TitleScreen(bn::sprite_font& font_sprite, bn::sprite_text_generator& text_generator);
    CharacterName get_selected_character();
    bool is_ready_to_start_game();
    void update();
private:
    enum class TitleState {
        Main,
        Settings,
        CharacterSelect,
        Starting
    };

    enum class MainButtonOptions {
        NewGame,
        Settings
    };

    void update_main();
    void update_settings();
    void update_character_select();
    void update_starting();

    void load_next_screen(TitleState next_screen_state);

    bool _ready_to_start_game;

    TitleState _state;
    int _selection;

    int _counter;

    //main
    bn::optional<bn::sprite_ptr> _spr_button_new_game;
    bn::optional<bn::sprite_ptr> _spr_button_settings;

    //settings
    bn::optional<bn::sprite_ptr> _spr_brightness_icon;
    bn::optional<bn::sprite_ptr> _spr_music_vol_icon;
    bn::optional<bn::sprite_ptr> _spr_sfx_vol_icon;
    bn::vector<bn::sprite_ptr, 10> _brightness__bar;
    bn::vector<bn::sprite_ptr, 10> _music_vol_bar;
    bn::vector<bn::sprite_ptr, 10> _sfx_vol_bar;
    int _brightness;
    int _music_vol;
    int _sfx_vol;

    //otherss ig im tired rn
    bn::sprite_font _font_sprite;
    bn::sprite_text_generator _text_generator;
    bn::vector<bn::sprite_ptr,40> _text_sprites;

    bn::optional<bn::regular_bg_ptr> _bg_landscape;
    bn::optional<bn::regular_bg_ptr> _bg_black_overlay;

    CharacterName _selected_character;
    bn::optional<bn::sprite_ptr> _spr_selection_arrow;
    bn::optional<bn::sprite_ptr> _spr_player_head_1;
    bn::optional<bn::sprite_animate_action<4>> _spr_player_head_anim_1;

    bn::optional<bn::sprite_ptr> _spr_player_head_2;
    bn::optional<bn::sprite_animate_action<4>> _spr_player_head_anim_2;
};

#endif