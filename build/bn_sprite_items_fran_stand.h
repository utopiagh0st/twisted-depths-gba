#ifndef BN_SPRITE_ITEMS_FRAN_STAND_H
#define BN_SPRITE_ITEMS_FRAN_STAND_H

#include "bn_sprite_item.h"

//{{BLOCK(fran_stand_bn_gfx)

//======================================================================
//
//	fran_stand_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2026-02-25, 22:53:20
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FRAN_STAND_BN_GFX_H
#define GRIT_FRAN_STAND_BN_GFX_H

#define fran_stand_bn_gfxTilesLen 128
extern const bn::tile fran_stand_bn_gfxTiles[4];

#define fran_stand_bn_gfxPalLen 32
extern const bn::color fran_stand_bn_gfxPal[16];

#endif // GRIT_FRAN_STAND_BN_GFX_H

//}}BLOCK(fran_stand_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item fran_stand(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(fran_stand_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(fran_stand_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

