#ifndef BN_SPRITE_ITEMS_BUTTON_SETTINGS_H
#define BN_SPRITE_ITEMS_BUTTON_SETTINGS_H

#include "bn_sprite_item.h"

//{{BLOCK(button_settings_bn_gfx)

//======================================================================
//
//	button_settings_bn_gfx, 128x64@4, 
//	+ palette 16 entries, not compressed
//	+ 128 tiles Metatiled by 8x8 not compressed
//	Total size: 32 + 4096 = 4128
//
//	Time-stamp: 2026-11-08, 21:29:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BUTTON_SETTINGS_BN_GFX_H
#define GRIT_BUTTON_SETTINGS_BN_GFX_H

#define button_settings_bn_gfxTilesLen 4096
extern const bn::tile button_settings_bn_gfxTiles[128];

#define button_settings_bn_gfxPalLen 32
extern const bn::color button_settings_bn_gfxPal[16];

#endif // GRIT_BUTTON_SETTINGS_BN_GFX_H

//}}BLOCK(button_settings_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item button_settings(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(button_settings_bn_gfxTiles, 128), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(button_settings_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

