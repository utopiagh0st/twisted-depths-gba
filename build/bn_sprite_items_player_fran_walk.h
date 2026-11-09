#ifndef BN_SPRITE_ITEMS_PLAYER_FRAN_WALK_H
#define BN_SPRITE_ITEMS_PLAYER_FRAN_WALK_H

#include "bn_sprite_item.h"

//{{BLOCK(player_fran_walk_bn_gfx)

//======================================================================
//
//	player_fran_walk_bn_gfx, 128x128@4, 
//	+ palette 16 entries, not compressed
//	+ 256 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 8192 = 8224
//
//	Time-stamp: 2026-11-09, 07:42:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PLAYER_FRAN_WALK_BN_GFX_H
#define GRIT_PLAYER_FRAN_WALK_BN_GFX_H

#define player_fran_walk_bn_gfxTilesLen 8192
extern const bn::tile player_fran_walk_bn_gfxTiles[256];

#define player_fran_walk_bn_gfxPalLen 32
extern const bn::color player_fran_walk_bn_gfxPal[16];

#endif // GRIT_PLAYER_FRAN_WALK_BN_GFX_H

//}}BLOCK(player_fran_walk_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item player_fran_walk(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(player_fran_walk_bn_gfxTiles, 256), bpp_mode::BPP_4, compression_type::NONE, 16), 
            sprite_palette_item(span<const color>(player_fran_walk_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

