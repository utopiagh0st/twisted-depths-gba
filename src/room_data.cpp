#include "room_data.h"

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
constexpr RoomData ROOM_LOOKUP[] = {
    {   LevelType::STREET, RoomType::U, bn::regular_bg_items::bg_street_u},
    {   LevelType::STREET, RoomType::D, bn::regular_bg_items::bg_street_d},
    {   LevelType::STREET, RoomType::L, bn::regular_bg_items::bg_street_l},
    {   LevelType::STREET, RoomType::R, bn::regular_bg_items::bg_street_r},
    {   LevelType::STREET, RoomType::U | RoomType::D, bn::regular_bg_items::bg_street_ud},
    {   LevelType::STREET, RoomType::L | RoomType::R, bn::regular_bg_items::bg_street_lr},
    {   LevelType::STREET, RoomType::U | RoomType::L, bn::regular_bg_items::bg_street_ul},
    {   LevelType::STREET, RoomType::U | RoomType::R, bn::regular_bg_items::bg_street_ur},
    {   LevelType::STREET, RoomType::D | RoomType::L, bn::regular_bg_items::bg_street_dl},
    {   LevelType::STREET, RoomType::D | RoomType::R, bn::regular_bg_items::bg_street_dr},
    {   LevelType::STREET, RoomType::U | RoomType::L | RoomType::R, bn::regular_bg_items::bg_street_ulr},
    {   LevelType::STREET, RoomType::D | RoomType::L | RoomType::R, bn::regular_bg_items::bg_street_dlr},
    {   LevelType::STREET, RoomType::U | RoomType::D | RoomType::L, bn::regular_bg_items::bg_street_udl},
    {   LevelType::STREET, RoomType::U | RoomType::D | RoomType::R, bn::regular_bg_items::bg_street_udr},
    {   LevelType::STREET, RoomType::U | RoomType::D | RoomType::L | RoomType::R, bn::regular_bg_items::bg_street_udlr}
};