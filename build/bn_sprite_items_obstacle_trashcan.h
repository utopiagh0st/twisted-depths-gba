#ifndef BN_SPRITE_ITEMS_OBSTACLE_TRASHCAN_H
#define BN_SPRITE_ITEMS_OBSTACLE_TRASHCAN_H

#include "bn_sprite_item.h"

//{{BLOCK(obstacle_trashcan_bn_gfx)

//======================================================================
//
//	obstacle_trashcan_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2026-08-12, 08:11:53
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_OBSTACLE_TRASHCAN_BN_GFX_H
#define GRIT_OBSTACLE_TRASHCAN_BN_GFX_H

#define obstacle_trashcan_bn_gfxTilesLen 128
extern const bn::tile obstacle_trashcan_bn_gfxTiles[4];

#define obstacle_trashcan_bn_gfxPalLen 32
extern const bn::color obstacle_trashcan_bn_gfxPal[16];

#endif // GRIT_OBSTACLE_TRASHCAN_BN_GFX_H

//}}BLOCK(obstacle_trashcan_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item obstacle_trashcan(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(obstacle_trashcan_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(obstacle_trashcan_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

