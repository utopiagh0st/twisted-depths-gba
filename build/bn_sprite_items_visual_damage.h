#ifndef BN_SPRITE_ITEMS_VISUAL_DAMAGE_H
#define BN_SPRITE_ITEMS_VISUAL_DAMAGE_H

#include "bn_sprite_item.h"

//{{BLOCK(visual_damage_bn_gfx)

//======================================================================
//
//	visual_damage_bn_gfx, 256x32@4, 
//	+ palette 16 entries, not compressed
//	+ 128 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 4096 = 4128
//
//	Time-stamp: 2026-08-14, 02:09:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_VISUAL_DAMAGE_BN_GFX_H
#define GRIT_VISUAL_DAMAGE_BN_GFX_H

#define visual_damage_bn_gfxTilesLen 4096
extern const bn::tile visual_damage_bn_gfxTiles[128];

#define visual_damage_bn_gfxPalLen 32
extern const bn::color visual_damage_bn_gfxPal[16];

#endif // GRIT_VISUAL_DAMAGE_BN_GFX_H

//}}BLOCK(visual_damage_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item visual_damage(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(visual_damage_bn_gfxTiles, 128), bpp_mode::BPP_4, compression_type::NONE, 8), 
            sprite_palette_item(span<const color>(visual_damage_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

