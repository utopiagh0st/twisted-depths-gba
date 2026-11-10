#ifndef BN_SPRITE_ITEMS_ITS_OVER_H
#define BN_SPRITE_ITEMS_ITS_OVER_H

#include "bn_sprite_item.h"

//{{BLOCK(its_over_bn_gfx)

//======================================================================
//
//	its_over_bn_gfx, 64x64@4, 
//	+ palette 16 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 32 + 2048 = 2080
//
//	Time-stamp: 2026-11-10, 00:29:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ITS_OVER_BN_GFX_H
#define GRIT_ITS_OVER_BN_GFX_H

#define its_over_bn_gfxTilesLen 2048
extern const bn::tile its_over_bn_gfxTiles[64];

#define its_over_bn_gfxPalLen 32
extern const bn::color its_over_bn_gfxPal[16];

#endif // GRIT_ITS_OVER_BN_GFX_H

//}}BLOCK(its_over_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item its_over(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(its_over_bn_gfxTiles, 64), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(its_over_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

