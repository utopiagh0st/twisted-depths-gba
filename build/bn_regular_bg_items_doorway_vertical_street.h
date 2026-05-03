#ifndef BN_REGULAR_BG_ITEMS_DOORWAY_VERTICAL_STREET_H
#define BN_REGULAR_BG_ITEMS_DOORWAY_VERTICAL_STREET_H

#include "bn_regular_bg_item.h"

//{{BLOCK(doorway_vertical_street_bn_gfx)

//======================================================================
//
//	doorway_vertical_street_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 25 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 800 + 2048 = 2880
//
//	Time-stamp: 2026-05-02, 18:12:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DOORWAY_VERTICAL_STREET_BN_GFX_H
#define GRIT_DOORWAY_VERTICAL_STREET_BN_GFX_H

#define doorway_vertical_street_bn_gfxTilesLen 800
extern const bn::tile doorway_vertical_street_bn_gfxTiles[25];

#define doorway_vertical_street_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell doorway_vertical_street_bn_gfxMap[1024];

#define doorway_vertical_street_bn_gfxPalLen 32
extern const bn::color doorway_vertical_street_bn_gfxPal[16];

#endif // GRIT_DOORWAY_VERTICAL_STREET_BN_GFX_H

//}}BLOCK(doorway_vertical_street_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item doorway_vertical_street(
            regular_bg_tiles_item(span<const tile>(doorway_vertical_street_bn_gfxTiles, 25), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(doorway_vertical_street_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(doorway_vertical_street_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

