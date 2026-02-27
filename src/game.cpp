#include "game.h"
//classes
#include "player.h"
#include "enemy.h"
//utilities and structures

//music and sounds
#include "bn_music.h"
#include "bn_music_items.h"
#include "bn_sound_items.h"
//input
#include "bn_keypad.h"
//sprites, txt and bg
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"

//sprites themselves
//bgs
#include "bn_regular_bg_items_floor_bg.h"
#include "bn_regular_bg_items_walls_bg.h"

Game::Game() :
    _state(State::Title)    //starts with title state
{
    _bounds[0] = -50;   //up
    _bounds[1] = 48;    //down
    _bounds[2] = -66;   //left
    _bounds[3] = 66;    //right
}

void Game::update_title() { //use this one as a template of a state change
    if (bn::keypad::start_pressed()) {  //game doesn't start till player presses start
        _player.emplace(0, 0, CharacterName::diabolus);   //replaces the empty player

        _enemy.emplace(EnemyType::LimeCat, 20,20);

        _floor_bg.emplace(bn::regular_bg_items::floor_bg.create_bg(0, 0));  //bg emplacement
        _walls_bg.emplace(bn::regular_bg_items::walls_bg.create_bg(0, 0));
        _walls_bg->set_priority(1);
        _floor_bg->set_priority(2);  //priority (0 is the highest)

        bn::music_items::castlevania2.play(1);    //banger starts

        _state = State::Playing;    //change of state
    }
}

void Game::update_pause() {
    if (bn::keypad::start_pressed()) {
        bn::music::resume();
        _state = State::Playing;  //pause button just stops running the game logic
    }  
}

void Game::update_playing() {
    if (bn::keypad::start_pressed()) {
        bn::music::pause();
        _state = State::Pause;  //pause button just stops running the game logic
    }
    _player->update(_bounds[0], _bounds[1], _bounds[2], _bounds[3]);    //cuz of bn::optional u gotta use the arrow -> to access an object's contents
}

void Game::update() {   //main update loop
    switch (_state) {   //switch to use different update thingys
        case State::Title:
            update_title();
            break;
        case State::Playing:
            update_playing();
            break;
        case State::Pause:
            update_pause();
            break;
    }
}