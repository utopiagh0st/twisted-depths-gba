#ifndef BN_REGULAR_BG_ITEMS_BG_STREET_UL_H
#define BN_REGULAR_BG_ITEMS_BG_STREET_UL_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_street_ul_bn_gfx)

//======================================================================
//
//	bg_street_ul_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 199 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 6368 + 2048 = 8448
//
//	Time-stamp: 2026-08-13, 19:12:59
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_STREET_UL_BN_GFX_H
#define GRIT_BG_STREET_UL_BN_GFX_H

#define bg_street_ul_bn_gfxTilesLen 6368
extern const bn::tile bg_street_ul_bn_gfxTiles[199];

#define bg_street_ul_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell bg_street_ul_bn_gfxMap[1024];

#define bg_street_ul_bn_gfxPalLen 32
extern const bn::color bg_street_ul_bn_gfxPal[16];

#endif // GRIT_BG_STREET_UL_BN_GFX_H

//}}BLOCK(bg_street_ul_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg_street_ul(
            regular_bg_tiles_item(span<const tile>(bg_street_ul_bn_gfxTiles, 199), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_street_ul_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg_street_ul_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

