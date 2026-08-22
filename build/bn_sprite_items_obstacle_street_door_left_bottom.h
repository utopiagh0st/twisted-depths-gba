#ifndef BN_SPRITE_ITEMS_OBSTACLE_STREET_DOOR_LEFT_BOTTOM_H
#define BN_SPRITE_ITEMS_OBSTACLE_STREET_DOOR_LEFT_BOTTOM_H

#include "bn_sprite_item.h"

//{{BLOCK(obstacle_street_door_left_bottom_bn_gfx)

//======================================================================
//
//	obstacle_street_door_left_bottom_bn_gfx, 384x64@4, 
//	+ palette 16 entries, not compressed
//	+ 384 tiles Metatiled by 8x8 not compressed
//	Total size: 32 + 12288 = 12320
//
//	Time-stamp: 2026-08-21, 14:37:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_OBSTACLE_STREET_DOOR_LEFT_BOTTOM_BN_GFX_H
#define GRIT_OBSTACLE_STREET_DOOR_LEFT_BOTTOM_BN_GFX_H

#define obstacle_street_door_left_bottom_bn_gfxTilesLen 12288
extern const bn::tile obstacle_street_door_left_bottom_bn_gfxTiles[384];

#define obstacle_street_door_left_bottom_bn_gfxPalLen 32
extern const bn::color obstacle_street_door_left_bottom_bn_gfxPal[16];

#endif // GRIT_OBSTACLE_STREET_DOOR_LEFT_BOTTOM_BN_GFX_H

//}}BLOCK(obstacle_street_door_left_bottom_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item obstacle_street_door_left_bottom(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(obstacle_street_door_left_bottom_bn_gfxTiles, 384), bpp_mode::BPP_4, compression_type::NONE, 6), 
            sprite_palette_item(span<const color>(obstacle_street_door_left_bottom_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

