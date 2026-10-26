#include "item.h"
#include "bn_fixed_point.h"
#include "bn_math.h"
#include "bn_sprite_items_obstacle_trashcan.h"

Item::Item(ItemId id)
{   
    _id = id;
    _rarity = ItemRarity::Normie;
    _type = ItemType::Hand;
    _position = bn::fixed_point(0,0);
}

Item::showInInventory(int inventory_position) {
    switch (inventory_position) {
    case 1:
        break;
    
    default:
        break;
    }
}

Item::doItemEffect(Player player) {
    switch (_id) {
    case 0:
        player.heal(2);
        break;
    default:
        break;
    }
}



'''
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
'''