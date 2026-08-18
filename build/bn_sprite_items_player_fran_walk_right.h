#ifndef BN_SPRITE_ITEMS_PLAYER_FRAN_WALK_RIGHT_H
#define BN_SPRITE_ITEMS_PLAYER_FRAN_WALK_RIGHT_H

#include "bn_sprite_item.h"

//{{BLOCK(player_fran_walk_right_bn_gfx)

//======================================================================
//
//	player_fran_walk_right_bn_gfx, 128x32@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2026-08-14, 08:24:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PLAYER_FRAN_WALK_RIGHT_BN_GFX_H
#define GRIT_PLAYER_FRAN_WALK_RIGHT_BN_GFX_H

#define player_fran_walk_right_bn_gfxTilesLen 2048
extern const bn::tile player_fran_walk_right_bn_gfxTiles[64];

#define player_fran_walk_right_bn_gfxPalLen 32
extern const bn::color player_fran_walk_right_bn_gfxPal[16];

#endif // GRIT_PLAYER_FRAN_WALK_RIGHT_BN_GFX_H

//}}BLOCK(player_fran_walk_right_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item player_fran_walk_right(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(player_fran_walk_right_bn_gfxTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(player_fran_walk_right_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

