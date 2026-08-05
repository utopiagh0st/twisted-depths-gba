
@{{BLOCK(wall_bn_gfx)

@=======================================================================
@
@	wall_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-08-04, 22:45:38
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global wall_bn_gfxTiles		@ 128 unsigned chars
	.hidden wall_bn_gfxTiles
wall_bn_gfxTiles:
	.word 0x00000000,0x05500000,0x22222200,0x11115200,0x11111200,0x11111200,0x11111250,0x11111255
	.word 0x00000000,0x00000000,0x00222222,0x00205551,0x00251111,0x55211111,0x55211111,0x54211111
	.word 0x11155235,0x15533235,0x53333235,0x33333255,0x33355200,0x22222200,0x50000000,0x00000000
	.word 0x54211111,0x54251111,0x54245115,0x05245553,0x00245333,0x00222222,0x00055355,0x00005500

	.section .rodata
	.align	2
	.global wall_bn_gfxPal		@ 32 unsigned chars
	.hidden wall_bn_gfxPal
wall_bn_gfxPal:
	.hword 0x7C1F,0x1091,0x001F,0x0C68,0x0005,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(wall_bn_gfx)
