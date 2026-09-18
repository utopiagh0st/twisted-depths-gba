#ifndef BN_SPRITE_ITEMS_ITEM_HEALDEAL_H
#define BN_SPRITE_ITEMS_ITEM_HEALDEAL_H

#include "bn_sprite_item.h"

//{{BLOCK(item_healdeal_bn_gfx)

//======================================================================
//
//	item_healdeal_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2026-09-15, 14:07:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ITEM_HEALDEAL_BN_GFX_H
#define GRIT_ITEM_HEALDEAL_BN_GFX_H

#define item_healdeal_bn_gfxTilesLen 128
extern const bn::tile item_healdeal_bn_gfxTiles[4];

#define item_healdeal_bn_gfxPalLen 32
extern const bn::color item_healdeal_bn_gfxPal[16];

#endif // GRIT_ITEM_HEALDEAL_BN_GFX_H

//}}BLOCK(item_healdeal_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item item_healdeal(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(item_healdeal_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(item_healdeal_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

