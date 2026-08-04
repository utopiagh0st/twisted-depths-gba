#ifndef BN_SPRITE_ITEMS_PROJECTILE_H
#define BN_SPRITE_ITEMS_PROJECTILE_H

#include "bn_sprite_item.h"

//{{BLOCK(projectile_bn_gfx)

//======================================================================
//
//	projectile_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2026-08-03, 09:53:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PROJECTILE_BN_GFX_H
#define GRIT_PROJECTILE_BN_GFX_H

#define projectile_bn_gfxTilesLen 32
extern const bn::tile projectile_bn_gfxTiles[1];

#define projectile_bn_gfxPalLen 32
extern const bn::color projectile_bn_gfxPal[16];

#endif // GRIT_PROJECTILE_BN_GFX_H

//}}BLOCK(projectile_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item projectile(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(projectile_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(projectile_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

