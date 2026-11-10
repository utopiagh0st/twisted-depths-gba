#ifndef BN_REGULAR_BG_ITEMS_BG_FALLEN_SUNSET_H
#define BN_REGULAR_BG_ITEMS_BG_FALLEN_SUNSET_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_fallen_sunset_bn_gfx)

//======================================================================
//
//	bg_fallen_sunset_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 339 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 10848 + 2048 = 12928
//
//	Time-stamp: 2026-11-10, 08:01:45
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_FALLEN_SUNSET_BN_GFX_H
#define GRIT_BG_FALLEN_SUNSET_BN_GFX_H

#define bg_fallen_sunset_bn_gfxTilesLen 10848
extern const bn::tile bg_fallen_sunset_bn_gfxTiles[339];

#define bg_fallen_sunset_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell bg_fallen_sunset_bn_gfxMap[1024];

#define bg_fallen_sunset_bn_gfxPalLen 32
extern const bn::color bg_fallen_sunset_bn_gfxPal[16];

#endif // GRIT_BG_FALLEN_SUNSET_BN_GFX_H

//}}BLOCK(bg_fallen_sunset_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg_fallen_sunset(
            regular_bg_tiles_item(span<const tile>(bg_fallen_sunset_bn_gfxTiles, 339), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_fallen_sunset_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg_fallen_sunset_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

