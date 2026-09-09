#ifndef BN_SPRITE_ITEMS_ENEMY_CASTABELL_H
#define BN_SPRITE_ITEMS_ENEMY_CASTABELL_H

#include "bn_sprite_item.h"

//{{BLOCK(enemy_castabell_bn_gfx)

//======================================================================
//
//	enemy_castabell_bn_gfx, 48x16@4, 
//	+ palette 16 entries, not compressed
//	+ 12 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 384 = 416
//
//	Time-stamp: 2026-09-08, 22:50:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ENEMY_CASTABELL_BN_GFX_H
#define GRIT_ENEMY_CASTABELL_BN_GFX_H

#define enemy_castabell_bn_gfxTilesLen 384
extern const bn::tile enemy_castabell_bn_gfxTiles[12];

#define enemy_castabell_bn_gfxPalLen 32
extern const bn::color enemy_castabell_bn_gfxPal[16];

#endif // GRIT_ENEMY_CASTABELL_BN_GFX_H

//}}BLOCK(enemy_castabell_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item enemy_castabell(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(enemy_castabell_bn_gfxTiles, 12), bpp_mode::BPP_4, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(enemy_castabell_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

