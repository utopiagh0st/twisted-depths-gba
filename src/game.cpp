//classes
#include "game.h"
#include "room_data.h"
#include "hud.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "obstacle.h"
#include <algorithm>

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

Game::Game() :
    _state(State::Title),    //starts with title state
    _level_generator(_rnd)
{   
    _frame = 0;
    _bounds[UP] = -60;   //up
    _bounds[DOWN] = 60;    //down
    _bounds[LEFT] = -80;   //left
    _bounds[RIGHT] = 80;    //right
}

void Game::update_title() { //use this one as a template of a state change
    if (bn::keypad::start_pressed()) {  //game doesn't start till player presses start
        _level.emplace(_level_generator.generate_level(LevelType::STREET));
        _level->load_room(_level->get_starting_room_pos(), _obstacles);
        //_room.emplace(_rnd, RoomType::U);

        _player.emplace(CharacterName::diabolus, 0, 0, _rnd);   //replaces the empty player
        _hud.emplace(true);

        bn::music_items::corrupt2.play(0.3);    //banger starts

        _state = State::Playing;    //change of state
    }
}

void Game::update_pause() {
    if (bn::keypad::start_pressed()) {
        _level->toggle_map(false);
        bn::music::resume();
        _state = State::Playing;  //pause button just stops running the game logic
    }  
}

void Game::update_playing() {
    _level->update(_obstacles);

    //Player
    _player->update(_bounds[UP], _bounds[DOWN], _bounds[LEFT], _bounds[RIGHT], _obstacles);    //cuz of bn::optional u gotta use the arrow -> to access an object's contents
    //Room Transition
    
    if (_player->get_position().y() < _bounds[UP]) {
        _player->set_position(bn::fixed_point(_player->get_position().x(),_bounds[DOWN] - 10));
        _player->set_freeze_movement(true);
        _level->begin_room_transition(UP, _obstacles);
    } else if (_player->get_position().y() > _bounds[DOWN]) {
        _player->set_position(bn::fixed_point(_player->get_position().x(),_bounds[UP] + 10));
        _player->set_freeze_movement(true);
        _level->begin_room_transition(DOWN, _obstacles);
    } else if (_player->get_position().x() < _bounds[LEFT]) {
        _player->set_position(bn::fixed_point(_bounds[RIGHT] - 10,_player->get_position().y()));
        _player->set_freeze_movement(true);
        _level->begin_room_transition(LEFT, _obstacles);
    } else if (_player->get_position().x() > _bounds[RIGHT]) {
        _player->set_position(bn::fixed_point(_bounds[LEFT] + 10,_player->get_position().y()));
        _player->set_freeze_movement(true);
        _level->begin_room_transition(RIGHT, _obstacles);
    }

    if (_player->is_movement_freezed() && !_level->is_doing_room_transition()) {
        _player->set_freeze_movement(false);
    }
    /**/

    //Miscelaneous inputs
    if (bn::keypad::a_pressed() && _enemies.size() < MAX_ENEMIES) {
        _enemies.push_back(Enemy(EnemyType::PepperGum, bn::fixed_point(_rnd.get_int(-66,66), _rnd.get_int(-50,48))));
    }
    if (bn::keypad::b_held() && _projectiles.size() < MAX_PROJECTILES) {
        _player->attack(_projectiles);
    }
    if (bn::keypad::start_pressed()) {
        bn::music::pause();
        _level->toggle_map(true);
        _state = State::Pause;  //pause button just stops running the game logic
    }

    //Enemies
    for (Enemy& enemy : _enemies) {
        enemy.update(_bounds[UP], _bounds[DOWN], _bounds[LEFT], _bounds[RIGHT], _player->get_position(), _obstacles);
        // Colission checks
        if (_player->get_hitbox().intersects(enemy.get_hitbox())) {
            //enemy.set_alive(false);
            _player->take_damage(1);
            _player->apply_knockback(enemy.get_velocity());
        }
        for (Projectile& projectile : _projectiles) {
            if (enemy.get_hitbox().intersects(projectile.get_hitbox()) && projectile.get_owner() == ProjectileOwner::Player) {
                enemy.take_damage(projectile.get_damage());
                enemy.apply_knockback(projectile.get_unit_velocity_vector() * projectile.get_knockback());
                if (!projectile.is_piercing()) {
                    projectile.set_alive(false);
                }
            }
            
        }
    }
    if (_frame % 5 == 0) { // DO every 5 frames
    for(int i = 0; i < _enemies.size(); ++i) {
        for(int j = i + 1; j < _enemies.size(); ++j) {
            Enemy& enemy1 = _enemies[i];
            Enemy& enemy2 = _enemies[j];

            if(enemy1.get_hitbox().intersects(enemy2.get_hitbox())) {
                bn::fixed_point direction =
                    enemy1.get_position() - enemy2.get_position();

                bn::fixed length = bn::sqrt(
                    direction.x() * direction.x() +
                    direction.y() * direction.y()
                );

                if(length != 0)
                {
                    direction.set_x(direction.x() / length);
                    direction.set_y(direction.y() / length);

                    enemy1.apply_knockback(direction * bn::fixed(0.2));
                    enemy2.apply_knockback(-direction * bn::fixed(0.2));
                }
            }
        }
    }
}

    //Projectiles
    for (Projectile& projectile : _projectiles) {
        projectile.update();
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

    

    //HUD
    _hud->update(_player->get_hp(), _player->get_hp_max());
    if (_player->get_hp() <= 0) {
        game_over();
    }
}

void Game::game_over() {
    _state = State::Title;
    _projectiles.clear();
    _enemies.clear();
    _obstacles.clear();
    _player.reset();
    _level.reset();
    _hud.reset();
    bn::music::stop();
}

void Game::update() {   //main update loop
    switch (_state) {   //switch to use different update thingys
        case State::Title:
            update_title();
            _rnd.update();
            break;
        case State::Playing:
            update_playing();
            break;
        case State::Pause:
            update_pause();
            break;
    }
    _frame++;
    if (_frame > 60) {
        _frame = 1;
    }
    
    _rnd.update();
}