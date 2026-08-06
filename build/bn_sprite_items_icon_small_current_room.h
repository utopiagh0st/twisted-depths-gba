#ifndef BN_SPRITE_ITEMS_ICON_SMALL_CURRENT_ROOM_H
#define BN_SPRITE_ITEMS_ICON_SMALL_CURRENT_ROOM_H

#include "bn_sprite_item.h"

//{{BLOCK(icon_small_current_room_bn_gfx)

//======================================================================
//
//	icon_small_current_room_bn_gfx, 8x8@4, 
//	+ palette 16 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 32 + 32 = 64
//
//	Time-stamp: 2026-08-05, 11:50:40
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ICON_SMALL_CURRENT_ROOM_BN_GFX_H
#define GRIT_ICON_SMALL_CURRENT_ROOM_BN_GFX_H

#define icon_small_current_room_bn_gfxTilesLen 32
extern const bn::tile icon_small_current_room_bn_gfxTiles[1];

#define icon_small_current_room_bn_gfxPalLen 32
extern const bn::color icon_small_current_room_bn_gfxPal[16];

#endif // GRIT_ICON_SMALL_CURRENT_ROOM_BN_GFX_H

//}}BLOCK(icon_small_current_room_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item icon_small_current_room(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(icon_small_current_room_bn_gfxTiles, 1), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(icon_small_current_room_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

