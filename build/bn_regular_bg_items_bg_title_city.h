#ifndef BN_REGULAR_BG_ITEMS_BG_TITLE_CITY_H
#define BN_REGULAR_BG_ITEMS_BG_TITLE_CITY_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_title_city_bn_gfx)

//======================================================================
//
//	bg_title_city_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 495 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 15840 + 2048 = 17920
//
//	Time-stamp: 2026-11-10, 08:01:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_TITLE_CITY_BN_GFX_H
#define GRIT_BG_TITLE_CITY_BN_GFX_H

#define bg_title_city_bn_gfxTilesLen 15840
extern const bn::tile bg_title_city_bn_gfxTiles[495];

#define bg_title_city_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell bg_title_city_bn_gfxMap[1024];

#define bg_title_city_bn_gfxPalLen 32
extern const bn::color bg_title_city_bn_gfxPal[16];

#endif // GRIT_BG_TITLE_CITY_BN_GFX_H

//}}BLOCK(bg_title_city_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg_title_city(
            regular_bg_tiles_item(span<const tile>(bg_title_city_bn_gfxTiles, 495), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_title_city_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg_title_city_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

