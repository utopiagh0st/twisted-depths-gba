#ifndef BN_REGULAR_BG_ITEMS_WALL_VERTICAL_STREET_H
#define BN_REGULAR_BG_ITEMS_WALL_VERTICAL_STREET_H

#include "bn_regular_bg_item.h"

//{{BLOCK(wall_vertical_street_bn_gfx)

//======================================================================
//
//	wall_vertical_street_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 35 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 1120 + 2048 = 3200
//
//	Time-stamp: 2026-05-02, 18:12:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WALL_VERTICAL_STREET_BN_GFX_H
#define GRIT_WALL_VERTICAL_STREET_BN_GFX_H

#define wall_vertical_street_bn_gfxTilesLen 1120
extern const bn::tile wall_vertical_street_bn_gfxTiles[35];

#define wall_vertical_street_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell wall_vertical_street_bn_gfxMap[1024];

#define wall_vertical_street_bn_gfxPalLen 32
extern const bn::color wall_vertical_street_bn_gfxPal[16];

#endif // GRIT_WALL_VERTICAL_STREET_BN_GFX_H

//}}BLOCK(wall_vertical_street_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item wall_vertical_street(
            regular_bg_tiles_item(span<const tile>(wall_vertical_street_bn_gfxTiles, 35), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(wall_vertical_street_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(wall_vertical_street_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

