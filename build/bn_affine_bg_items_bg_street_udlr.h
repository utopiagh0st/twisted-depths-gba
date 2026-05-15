#ifndef BN_AFFINE_BG_ITEMS_BG_STREET_UDLR_H
#define BN_AFFINE_BG_ITEMS_BG_STREET_UDLR_H

#include "bn_affine_bg_item.h"

//{{BLOCK(bg_street_udlr_bn_gfx)

//======================================================================
//
//	bg_street_udlr_bn_gfx, 256x256@8, 
//	+ palette 16 entries, not compressed
//	+ 166 tiles (t reduced) not compressed
//	+ affine map, not compressed, 32x32 
//	Total size: 32 + 10624 + 1024 = 11680
//
//	Time-stamp: 2026-05-15, 00:36:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_STREET_UDLR_BN_GFX_H
#define GRIT_BG_STREET_UDLR_BN_GFX_H

#define bg_street_udlr_bn_gfxTilesLen 10624
extern const bn::tile bg_street_udlr_bn_gfxTiles[332];

#define bg_street_udlr_bn_gfxMapLen 1024
extern const bn::affine_bg_map_cell bg_street_udlr_bn_gfxMap[1024];

#define bg_street_udlr_bn_gfxPalLen 32
extern const bn::color bg_street_udlr_bn_gfxPal[16];

#endif // GRIT_BG_STREET_UDLR_BN_GFX_H

//}}BLOCK(bg_street_udlr_bn_gfx)

namespace bn::affine_bg_items
{
    constexpr inline affine_bg_item bg_street_udlr(
            affine_bg_tiles_item(span<const tile>(bg_street_udlr_bn_gfxTiles, 332), compression_type::NONE), 
            bg_palette_item(span<const color>(bg_street_udlr_bn_gfxPal, 16), bpp_mode::BPP_8, compression_type::NONE),
            affine_bg_map_item(bg_street_udlr_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

