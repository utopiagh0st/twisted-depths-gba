//classes
#include "game.h"
#include "room_data.h"
#include "hud.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "obstacle.h"
#include <algorithm>
#include <string>

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
#include "bn_sprite_items_icon_player_head_fran.h"
#include "bn_sprite_items_icon_player_head_tobichu.h"
#include "bn_sprite_items_icon_small_up_arrow.h"
#include "bn_regular_bg_items_bg_title_city.h"

//bgs
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_font.h"
#include "bn_sprite_items_common_fixed_8x8_font.h"
#include "bn_string.h"
#include "bn_string_view.h"

#include "bn_blending.h"


Game::Game() :
    _state(State::Title),    //starts with title state
    _level_generator(_rnd),
    _font_sprite(bn::sprite_items::common_fixed_8x8_font),
    _text_generator(_font_sprite)
{   
    _frame = 0;
    _bounds[UP] = -60;   //up
    _bounds[DOWN] = 60;    //down
    _bounds[LEFT] = -80;   //left
    _bounds[RIGHT] = 80;    //right
    _selected_pocket_item = 0;
    _title_screen.emplace(_font_sprite, _text_generator);
}

void Game::update_title() { //use this one as a template of a state change
    _title_screen->update();
    if (_title_screen->is_ready_to_start_game()) {  //game doesn't start till player presses start
        _player.emplace(_title_screen->get_selected_character(), 0, 0, _rnd);   //replaces the empty player
        _title_screen.reset();
        _level.emplace(_level_generator.generate_level(LevelType::STREET));
        _level->load_room(_level->get_starting_room_pos(), _obstacles);
        _hud.emplace(true);
        
        bn::music_items::popkorn.play(0.4);    //banger starts
        
        _state = State::Playing;    //change of state
        bn::blending::set_transparency_alpha(bn::fixed(0.5));

        _pocket.push_back(Item(2, _rnd));
        _pocket.push_back(Item(0, _rnd));
        _pocket.push_back(Item(1, _rnd));
        _pocket.push_back(Item(1, _rnd));
        _pocket.push_back(Item(2, _rnd));
        _pocket.push_back(Item(2, _rnd));
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
    _level->update(_obstacles,_enemies);

    //Player
    _player->update(_obstacles, _projectiles, _enemies);    //cuz of bn::optional u gotta use the arrow -> to access an object's contents
    //Room Transition
    
    if (_player->get_position().y() < _bounds[UP]) {
        _player->set_position(bn::fixed_point(_player->get_position().x(),_bounds[DOWN] - 15));
        _player->set_freeze_movement(true);
        _level->begin_room_transition(UP, _obstacles, _enemies);
    } else if (_player->get_position().y() > _bounds[DOWN]) {
        _player->set_position(bn::fixed_point(_player->get_position().x(),_bounds[UP] + 10));
        _player->set_freeze_movement(true);
        _level->begin_room_transition(DOWN, _obstacles, _enemies);
    } else if (_player->get_position().x() < _bounds[LEFT]) {
        _player->set_position(bn::fixed_point(_bounds[RIGHT] - 10,_player->get_position().y()));
        _player->set_freeze_movement(true);
        _level->begin_room_transition(LEFT, _obstacles, _enemies);
    } else if (_player->get_position().x() > _bounds[RIGHT]) {
        _player->set_position(bn::fixed_point(_bounds[LEFT] + 10,_player->get_position().y()));
        _player->set_freeze_movement(true);
        _level->begin_room_transition(RIGHT, _obstacles, _enemies);
    }

    if (_level->can_unfreeze_movement() && !_level->is_doing_room_transition()) {
        _player->set_freeze_movement(false);
        _level->set_can_unfreeze_movement(false);
    }
    

    //Miscelaneous inputs
    if (bn::keypad::a_pressed() && _enemies.size() < max_enemies) {
        _enemies.push_back(Enemy(EnemyType::Castabell, bn::fixed_point(_rnd.get_int(-66,66), _rnd.get_int(-50,48)), _rnd));
    }
    //&& _projectiles.size() < max_projectiles
    if (bn::keypad::b_held() && _projectiles.size() < max_projectiles) {
        _player->attack(_projectiles);
    }
    if (bn::keypad::start_pressed()) {
        bn::music::pause();
        if (_enemies.size() == 0) {
            _level->toggle_map(true);
        }
        _state = State::Pause;  //pause button just stops running the game logic
    }
    if (bn::keypad::l_pressed() && _pocket.size() > 0) {
        _pocket[_selected_pocket_item].do_item_effect(_player.value());
    }

    if (bn::keypad::r_pressed() && _pocket.size() > 0) {
        _selected_pocket_item++;
        if (_selected_pocket_item >= _pocket.size()) {
            _selected_pocket_item = 0;
        }
    }

    //Enemies
    for (Enemy& enemy : _enemies) {
        enemy.update(_bounds[UP], _bounds[DOWN], _bounds[LEFT], _bounds[RIGHT], _player->get_position(), _obstacles);
        // Colission checks
        if (!enemy.is_dying() && _player->get_hitbox().intersects(enemy.get_hitbox())) {
            if (_player->is_doing_burst_attack()) {
                enemy.take_damage(_player->get_damage());
                enemy.apply_knockback(_player->get_shot_velocity() * _player->get_attack_knockback());
            } else {
                _player->take_damage(1);
                _player->apply_knockback(enemy.get_velocity());
            }
        }
        for (Projectile& projectile : _projectiles) {
            if (enemy.get_hitbox().intersects(projectile.get_hitbox()) && projectile.get_owner() == ProjectileOwner::Player) {
                if (!enemy.is_dying() && !projectile.is_piercing()) {
                    projectile.set_alive(false);
                }
                enemy.take_damage(projectile.get_damage());
                enemy.apply_knockback(projectile.get_unit_velocity_vector() * projectile.get_knockback());
            }
            
        }
    }

    for (Projectile& projectile : _projectiles) {
        if (!projectile.is_spectral()) {
            for (Obstacle& obstacle : _obstacles) {
                if (projectile.get_hitbox().intersects(obstacle.get_hitbox_for_projectile())) {
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
    for (Obstacle& obstacle : _obstacles) {
        obstacle.update();
    }
    //enemies
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
    _hud->update(_player.value(), _pocket, _selected_pocket_item);
    if (_player->get_hp() <= 0) {
        game_over();
    }
}

void Game::game_over() {
    _state = State::Title;
    _projectiles.clear();
    _enemies.clear();
    _obstacles.clear();
    _pocket.clear();
    _player.reset();
    _level.reset();
    _hud.reset();
    bn::music::stop();
    _selected_pocket_item = 0;
    _title_screen.emplace(_font_sprite, _text_generator);
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
        default:
            break;
    }
    _frame++;
    if (_frame > 60) {
        _frame = 1;
    }
    
    _rnd.update();
}
