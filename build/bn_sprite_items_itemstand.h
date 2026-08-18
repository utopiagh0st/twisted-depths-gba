#ifndef BN_SPRITE_ITEMS_ITEMSTAND_H
#define BN_SPRITE_ITEMS_ITEMSTAND_H

#include "bn_sprite_item.h"

//{{BLOCK(itemstand_bn_gfx)

//======================================================================
//
//	itemstand_bn_gfx, 128x16@4, 
//	+ palette 16 entries, not compressed
//	+ 32 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 1024 = 1056
//
//	Time-stamp: 2026-08-14, 08:24:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ITEMSTAND_BN_GFX_H
#define GRIT_ITEMSTAND_BN_GFX_H

#define itemstand_bn_gfxTilesLen 1024
extern const bn::tile itemstand_bn_gfxTiles[32];

#define itemstand_bn_gfxPalLen 32
extern const bn::color itemstand_bn_gfxPal[16];

#endif // GRIT_ITEMSTAND_BN_GFX_H

//}}BLOCK(itemstand_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item itemstand(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(itemstand_bn_gfxTiles, 32), bpp_mode::BPP_4, compression_type::NONE, 8), 
            sprite_palette_item(span<const color>(itemstand_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

