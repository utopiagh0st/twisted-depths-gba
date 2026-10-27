#include "item.h"
#include "item_data.h"
#include "player.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_sprite_items_obstacle_trashcan.h"
#include "bn_sound_items.h"
#include "bn_sprite_items_item_healdeal.h"


Item::Item(int id) {   
    _id = id;
    const ItemData& item_data = ITEM_LOOKUP[_id];
    _rarity = item_data.rarity;
    _type = item_data.type;
    _position = bn::fixed_point(0,0);
    _wiggle_counter = 0;
    _do_wiggle = false;
}

//getters and setters
ItemType Item::get_type() {
    return _type;
}


//functions
void Item::show_in_pocket(int pocket_position) {
    const ItemData& item_data = ITEM_LOOKUP[_id];
    switch (pocket_position) {
        case 0:
            if(!_sprite.has_value()) {
                _position = bn::fixed_point(-107.5, -48);
                _sprite.emplace(bn::sprite_items::item_healdeal.create_sprite(_position));
                _sprite->set_bg_priority(0);
            }
            _do_wiggle = true;
        break;
        default:
            break;
    }
}

void Item::do_item_effect(Player& player) {
    switch (_id) {
    case 0: //HealTest
        player.heal(2);
        break;
    default:
        break;
    }
}

void Item::update(Player& player) {
    if (_type == ItemType::Relic) {
        do_item_effect(player);
    }
    if (_do_wiggle) {
        if (_wiggle_counter > 360) {
            _wiggle_counter = 0;
        }
        _sprite->set_y(_position.y() + bn::fixed(bn::degrees_sin(_wiggle_counter*4) * bn::fixed(1.2)));
        _sprite->set_x(_position.x() + bn::fixed(bn::degrees_sin(_wiggle_counter*2) * bn::fixed(0.8)));

        _wiggle_counter++;
    }
}

/*
smashed pumpkin
clown spit 
MSC (m some cartoons)
gun ribbon
rib ribbon
herald of toby
fallen lips
cotton sister 
pastel silhouette
underworld wallet
white knuckles
toy dog
delicious boy 
banana milk
book of the void 
freezing effigies
dissolved heart 
christ teeth 
blood moonlight 
broken/falling halo 
twosided rite 
parasite yours (something that reverses) 
holy timer 
risingroach 
humming portal-head 
post modern sleeve 
stomach in a cage 
sad eyes 
star shaped waffle 
love? 
last innocence 
superbug 
cow anesthesia (think of a cooler animal) 
nightcore / daycore
ten to amity 
flowers of silence 
parents dream 
bored angel 
midnight cat 
corvus 
unreal light
7mm bones 
heatwave 
breakup note 
monday moon 
snake union 
hate voodoo 
undone ballad 
saved prayer 
colorful glass
enthity 
space dress 
arabian armor 
pulsing zero 
char list 
hunger (the concept) 
racing rat 
vexed something 
martian mask 
wandering ghosts 
beetle bumm 
S & M 
Untitled song 
unfinished script 
sanity thief 
tarantula guy 
fahrradsattel 
shark bizkit 
half an upper hand
white cat 
weekend fest ticket
private coil 
golden ornaments
sinner grazes 
blue movie 
verbal vomit 
magic air warlord 
loretta young lint 
authorized prescription 
techno bumble bee 
flat beanie 
baptism robes 
rolling heads 
kerosene 
loose cannon 
twin monoliths 
precious doll 
teen smell 
shovel to 6 underground 
black tea 
girdap 
forever self 
militar walkie talkie
hollow ladder 
pocket warped sun
cemetery stone collection 
masterbinder 
wandering staff 
twisted transaction 
dead rock 
blue goblin barrel
pineapple fish bones 
pet tomb 
sunny disco ball 
liver shaped box 
eroded lithium battery 
hero (tetris) 
adeedas jumper 
videotape 
UTOPIC TV
Blackest Wing
*/
