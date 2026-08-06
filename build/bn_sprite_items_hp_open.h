#ifndef BN_SPRITE_ITEMS_HP_OPEN_H
#define BN_SPRITE_ITEMS_HP_OPEN_H

#include "bn_sprite_item.h"

//{{BLOCK(hp_open_bn_gfx)

//======================================================================
//
//	hp_open_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2026-08-05, 07:45:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HP_OPEN_BN_GFX_H
#define GRIT_HP_OPEN_BN_GFX_H

#define hp_open_bn_gfxTilesLen 128
extern const bn::tile hp_open_bn_gfxTiles[4];

#define hp_open_bn_gfxPalLen 32
extern const bn::color hp_open_bn_gfxPal[16];

#endif // GRIT_HP_OPEN_BN_GFX_H

//}}BLOCK(hp_open_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item hp_open(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(hp_open_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(hp_open_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

