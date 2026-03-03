#ifndef BN_SPRITE_ITEMS_PLAYER_FRAN_H
#define BN_SPRITE_ITEMS_PLAYER_FRAN_H

#include "bn_sprite_item.h"

//{{BLOCK(player_fran_bn_gfx)

//======================================================================
//
//	player_fran_bn_gfx, 64x16@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2026-03-03, 11:22:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PLAYER_FRAN_BN_GFX_H
#define GRIT_PLAYER_FRAN_BN_GFX_H

#define player_fran_bn_gfxTilesLen 512
extern const bn::tile player_fran_bn_gfxTiles[16];

#define player_fran_bn_gfxPalLen 32
extern const bn::color player_fran_bn_gfxPal[16];

#endif // GRIT_PLAYER_FRAN_BN_GFX_H

//}}BLOCK(player_fran_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item player_fran(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(player_fran_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(player_fran_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

