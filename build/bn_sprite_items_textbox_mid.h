#ifndef BN_SPRITE_ITEMS_TEXTBOX_MID_H
#define BN_SPRITE_ITEMS_TEXTBOX_MID_H

#include "bn_sprite_item.h"

//{{BLOCK(textbox_mid_bn_gfx)

//======================================================================
//
//	textbox_mid_bn_gfx, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2026-02-25, 22:53:20
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TEXTBOX_MID_BN_GFX_H
#define GRIT_TEXTBOX_MID_BN_GFX_H

#define textbox_mid_bn_gfxTilesLen 512
extern const bn::tile textbox_mid_bn_gfxTiles[16];

#define textbox_mid_bn_gfxPalLen 32
extern const bn::color textbox_mid_bn_gfxPal[16];

#endif // GRIT_TEXTBOX_MID_BN_GFX_H

//}}BLOCK(textbox_mid_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item textbox_mid(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(textbox_mid_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(textbox_mid_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

