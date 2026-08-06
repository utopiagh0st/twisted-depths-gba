#ifndef BN_REGULAR_BG_ITEMS_BORDER_BLUE_H
#define BN_REGULAR_BG_ITEMS_BORDER_BLUE_H

#include "bn_regular_bg_item.h"

//{{BLOCK(border_blue_bn_gfx)

//======================================================================
//
//	border_blue_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 14 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 448 + 2048 = 2528
//
//	Time-stamp: 2026-08-05, 07:45:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BORDER_BLUE_BN_GFX_H
#define GRIT_BORDER_BLUE_BN_GFX_H

#define border_blue_bn_gfxTilesLen 448
extern const bn::tile border_blue_bn_gfxTiles[14];

#define border_blue_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell border_blue_bn_gfxMap[1024];

#define border_blue_bn_gfxPalLen 32
extern const bn::color border_blue_bn_gfxPal[16];

#endif // GRIT_BORDER_BLUE_BN_GFX_H

//}}BLOCK(border_blue_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item border_blue(
            regular_bg_tiles_item(span<const tile>(border_blue_bn_gfxTiles, 14), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(border_blue_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(border_blue_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

