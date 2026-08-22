#ifndef BN_SPRITE_ITEMS_VISUAL_ENEMY_DAMAGE_H
#define BN_SPRITE_ITEMS_VISUAL_ENEMY_DAMAGE_H

#include "bn_sprite_item.h"

//{{BLOCK(visual_enemy_damage_bn_gfx)

//======================================================================
//
//	visual_enemy_damage_bn_gfx, 224x32@4, 
//	+ palette 16 entries, not compressed
//	+ 112 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 3584 = 3616
//
//	Time-stamp: 2026-08-21, 12:38:43
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_VISUAL_ENEMY_DAMAGE_BN_GFX_H
#define GRIT_VISUAL_ENEMY_DAMAGE_BN_GFX_H

#define visual_enemy_damage_bn_gfxTilesLen 3584
extern const bn::tile visual_enemy_damage_bn_gfxTiles[112];

#define visual_enemy_damage_bn_gfxPalLen 32
extern const bn::color visual_enemy_damage_bn_gfxPal[16];

#endif // GRIT_VISUAL_ENEMY_DAMAGE_BN_GFX_H

//}}BLOCK(visual_enemy_damage_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item visual_enemy_damage(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(visual_enemy_damage_bn_gfxTiles, 112), bpp_mode::BPP_4, compression_type::NONE, 7), 
            sprite_palette_item(span<const color>(visual_enemy_damage_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

