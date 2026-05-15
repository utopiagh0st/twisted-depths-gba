//classes
#include "game.h"
#include "room_data.h"
#include "hud.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
//utilities and structures
#include "bn_vector.h"
#include "bn_random.h"
//music and sounds
#include "bn_music.h"
#include "bn_music_items.h"
#include "bn_sound_items.h"
//input
#include "bn_keypad.h"
//sprites themselves
//bgs
#include "bn_regular_bg_items_floor_bg.h"
#include "bn_regular_bg_items_walls_bg.h"
#include "bn_regular_bg_items_border_blue.h"

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
        _level = level_generator.generate_level(LevelType::STREET);
        //_room.emplace(random, RoomType::U);

        _player.emplace(CharacterName::diabolus, 0, 0);   //replaces the empty player
        _hud.emplace(true);

        bn::music_items::dark_experience.play(1);    //banger starts

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
    //Player
    _player->update(_bounds[0], _bounds[1], _bounds[2], _bounds[3]);    //cuz of bn::optional u gotta use the arrow -> to access an object's contents

    //Miscelaneous inputs
    if (bn::keypad::a_pressed() && _enemies.size() < MAX_ENEMIES) {
        _enemies.push_back(Enemy(EnemyType::LimeCat, bn::fixed_point(random.get_int(-66,66), random.get_int(-50,48)) ));
    }
    if (bn::keypad::b_pressed() && _projectiles.size() < MAX_PROJECTILES) {
        _player->attack();
        _projectiles.push_back(Projectile(ProjectileType::Honk, ProjectileOwner::Player, _player->get_shot_velocity(), _player->get_position()));
    }
    if (bn::keypad::start_pressed()) {
        bn::music::pause();
        _state = State::Pause;  //pause button just stops running the game logic
    }

    //Enemies
    for (Enemy& enemy : _enemies) {
        enemy.update(_bounds[0], _bounds[1], _bounds[2], _bounds[3], _player->get_position());
        // Colission checks
        if (_player->get_hitbox().intersects(enemy.get_hitbox())) {
            //enemy.set_alive(false);
            _player->take_damage(1);
            _player->apply_knockback(enemy.get_velocity());
        }
    }
    for(int i = 0; i < _enemies.size(); ) { //erasing dead guys
        if(!_enemies[i].is_alive()) {
            _enemies.erase(_enemies.begin() + i); //using pointers!!
        } else {
            ++i;
        }
    }
    for(int i = 0; i < _projectiles.size(); ) { //erasing stray shots
        if(!_projectiles[i].is_alive()) {
            _projectiles.erase(_projectiles.begin() + i); //using pointers!!
        } else {
            ++i;
        }
    }

    //Projectiles
    for (Projectile& projectile : _projectiles) {
        projectile.update();
    }

    //HUD
    _hud->update(_player->get_hp(), _player->get_hp_max());
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
    random.update();
}