#ifndef BN_SPRITE_ITEMS_ENEMY_PEPPERGUM_H
#define BN_SPRITE_ITEMS_ENEMY_PEPPERGUM_H

#include "bn_sprite_item.h"

//{{BLOCK(enemy_peppergum_bn_gfx)

//======================================================================
//
//	enemy_peppergum_bn_gfx, 96x16@4, 
//	+ palette 16 entries, not compressed
//	+ 24 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 768 = 800
//
//	Time-stamp: 2026-08-19, 08:40:19
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ENEMY_PEPPERGUM_BN_GFX_H
#define GRIT_ENEMY_PEPPERGUM_BN_GFX_H

#define enemy_peppergum_bn_gfxTilesLen 768
extern const bn::tile enemy_peppergum_bn_gfxTiles[24];

#define enemy_peppergum_bn_gfxPalLen 32
extern const bn::color enemy_peppergum_bn_gfxPal[16];

#endif // GRIT_ENEMY_PEPPERGUM_BN_GFX_H

//}}BLOCK(enemy_peppergum_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item enemy_peppergum(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(enemy_peppergum_bn_gfxTiles, 24), bpp_mode::BPP_4, compression_type::NONE, 6), 
            sprite_palette_item(span<const color>(enemy_peppergum_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

