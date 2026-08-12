#ifndef BN_SPRITE_ITEMS_HP_CLOSED_H
#define BN_SPRITE_ITEMS_HP_CLOSED_H

#include "bn_sprite_item.h"

//{{BLOCK(hp_closed_bn_gfx)

//======================================================================
//
//	hp_closed_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2026-08-11, 19:35:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HP_CLOSED_BN_GFX_H
#define GRIT_HP_CLOSED_BN_GFX_H

#define hp_closed_bn_gfxTilesLen 32
extern const bn::tile hp_closed_bn_gfxTiles[1];

#define hp_closed_bn_gfxPalLen 32
extern const bn::color hp_closed_bn_gfxPal[16];

#endif // GRIT_HP_CLOSED_BN_GFX_H

//}}BLOCK(hp_closed_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item hp_closed(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(hp_closed_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(hp_closed_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

