#include "room_data.h"
#include "bn_array.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

#include "bn_regular_bg_items_bg_street_u.h"
#include "bn_regular_bg_items_bg_street_d.h"
#include "bn_regular_bg_items_bg_street_l.h"
#include "bn_regular_bg_items_bg_street_r.h"
#include "bn_regular_bg_items_bg_street_ud.h"
#include "bn_regular_bg_items_bg_street_lr.h"
#include "bn_regular_bg_items_bg_street_ul.h"
#include "bn_regular_bg_items_bg_street_ur.h"
#include "bn_regular_bg_items_bg_street_dl.h"
#include "bn_regular_bg_items_bg_street_dr.h"
#include "bn_regular_bg_items_bg_street_ulr.h"
#include "bn_regular_bg_items_bg_street_dlr.h"
#include "bn_regular_bg_items_bg_street_udl.h"
#include "bn_regular_bg_items_bg_street_udr.h"
#include "bn_regular_bg_items_bg_street_udlr.h"

//only has ts lookup array
/*
lil coords helper
[-64,-48][-48,-48][-32,-48][-16,-48][  0,-48][ 16,-48][ 32,-48][ 48,-48][ 64,-48]
[-64,-32][-48,-32][-32,-32][-16,-32][  0,-32][ 16,-32][ 32,-32][ 48,-32][ 64,-32]
[-64,-16][-48,-16][-32,-16][-16,-16][  0,-16][ 16,-16][ 32,-16][ 48,-16][ 64,-16]
[-64,0  ][-48,0  ][-32,0  ][-16,0  ][  0,0  ][ 16,0  ][ 32,0  ][ 48,0  ][ 64,0  ]
[-64,16 ][-48,16 ][-32,16 ][-16,16 ][  0,16 ][ 16,16 ][ 32,16 ][ 48,16 ][ 64,16 ]
[-64,32 ][-48,32 ][-32,32 ][-16,32 ][  0,32 ][ 16,32 ][ 32,32 ][ 48,32 ][ 64,32 ]
[-64,48 ][-48,48 ][-32,48 ][-16,48 ][  0,48 ][ 16,48 ][ 32,48 ][ 48,48 ][ 64,48 ]
*/
const bn::array<RoomData, 15> ROOM_LOOKUP = {{ //Leveltype, roomtype (entrances), background, array of obstacle data, obstacle num (adding enemies next!!)
    //STREET U
    {   LevelType::STREET, RoomType::U, bn::regular_bg_items::bg_street_u,
    {
        {ObstacleType::Trashcan, bn::fixed_point(-64,-32)},
        {ObstacleType::Trashcan, bn::fixed_point(48,48)}
    }, 2},

    {   LevelType::STREET, RoomType::D, bn::regular_bg_items::bg_street_d,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::L, bn::regular_bg_items::bg_street_l,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::R, bn::regular_bg_items::bg_street_r,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::U | RoomType::D, bn::regular_bg_items::bg_street_ud,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::L | RoomType::R, bn::regular_bg_items::bg_street_lr,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::U | RoomType::L, bn::regular_bg_items::bg_street_ul,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::U | RoomType::R, bn::regular_bg_items::bg_street_ur,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::D | RoomType::L, bn::regular_bg_items::bg_street_dl,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::D | RoomType::R, bn::regular_bg_items::bg_street_dr,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::U | RoomType::L | RoomType::R, bn::regular_bg_items::bg_street_ulr,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},

    {   LevelType::STREET, RoomType::D | RoomType::L | RoomType::R, bn::regular_bg_items::bg_street_dlr,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},

    {   LevelType::STREET, RoomType::U | RoomType::D | RoomType::L, bn::regular_bg_items::bg_street_udl,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::U | RoomType::D | RoomType::R, bn::regular_bg_items::bg_street_udr,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1},
    {   LevelType::STREET, RoomType::U | RoomType::D | RoomType::L | RoomType::R, bn::regular_bg_items::bg_street_udlr,
    {
        {ObstacleType::Trashcan, bn::fixed_point(0,0)}
    }, 1}
}};