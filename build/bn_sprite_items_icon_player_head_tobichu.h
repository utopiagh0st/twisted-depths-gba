#ifndef BN_SPRITE_ITEMS_ICON_PLAYER_HEAD_TOBICHU_H
#define BN_SPRITE_ITEMS_ICON_PLAYER_HEAD_TOBICHU_H

#include "bn_sprite_item.h"

//{{BLOCK(icon_player_head_tobichu_bn_gfx)

//======================================================================
//
//	icon_player_head_tobichu_bn_gfx, 48x16@4, 
//	+ palette 16 entries, not compressed
//	+ 12 tiles Metatiled by 2x2 not compressed
//	Total size: 32 + 384 = 416
//
//	Time-stamp: 2026-11-10, 08:01:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ICON_PLAYER_HEAD_TOBICHU_BN_GFX_H
#define GRIT_ICON_PLAYER_HEAD_TOBICHU_BN_GFX_H

#define icon_player_head_tobichu_bn_gfxTilesLen 384
extern const bn::tile icon_player_head_tobichu_bn_gfxTiles[12];

#define icon_player_head_tobichu_bn_gfxPalLen 32
extern const bn::color icon_player_head_tobichu_bn_gfxPal[16];

#endif // GRIT_ICON_PLAYER_HEAD_TOBICHU_BN_GFX_H

//}}BLOCK(icon_player_head_tobichu_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item icon_player_head_tobichu(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(icon_player_head_tobichu_bn_gfxTiles, 12), bpp_mode::BPP_4, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(icon_player_head_tobichu_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

