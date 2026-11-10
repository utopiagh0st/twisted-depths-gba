#ifndef BN_SPRITE_ITEMS_ICON_SETTINGS_VARIOUS_H
#define BN_SPRITE_ITEMS_ICON_SETTINGS_VARIOUS_H

#include "bn_sprite_item.h"

//{{BLOCK(icon_settings_various_bn_gfx)

//======================================================================
//
//	icon_settings_various_bn_gfx, 40x8@4, 
//	+ palette 16 entries, not compressed
//	+ 5 tiles not compressed
//	Total size: 32 + 160 = 192
//
//	Time-stamp: 2026-11-10, 08:59:35
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ICON_SETTINGS_VARIOUS_BN_GFX_H
#define GRIT_ICON_SETTINGS_VARIOUS_BN_GFX_H

#define icon_settings_various_bn_gfxTilesLen 160
extern const bn::tile icon_settings_various_bn_gfxTiles[5];

#define icon_settings_various_bn_gfxPalLen 32
extern const bn::color icon_settings_various_bn_gfxPal[16];

#endif // GRIT_ICON_SETTINGS_VARIOUS_BN_GFX_H

//}}BLOCK(icon_settings_various_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item icon_settings_various(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(icon_settings_various_bn_gfxTiles, 5), bpp_mode::BPP_4, compression_type::NONE, 5), 
            sprite_palette_item(span<const color>(icon_settings_various_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

