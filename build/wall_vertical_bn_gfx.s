
@{{BLOCK(wall_vertical_bn_gfx)

@=======================================================================
@
@	wall_vertical_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-02-26, 19:04:09
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global wall_vertical_bn_gfxTiles		@ 128 unsigned chars
	.hidden wall_vertical_bn_gfxTiles
wall_vertical_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x01111110,0x12222211,0x13322112,0x13323113,0x11333113
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x11111111,0x21122222,0x32133332,0x32111111
	.word 0x11111111,0x22221222,0x23221333,0x11111333,0x22111111,0x33332122,0x33332133,0x22232133
	.word 0x11212221,0x22213333,0x33321333,0x33321333,0x11111111,0x22112221,0x32113321,0x33133321

	.section .rodata
	.align	2
	.global wall_vertical_bn_gfxPal		@ 32 unsigned chars
	.hidden wall_vertical_bn_gfxPal
wall_vertical_bn_gfxPal:
	.hword 0x7C1F,0x6D27,0x2665,0x52A5,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(wall_vertical_bn_gfx)
