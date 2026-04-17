
@{{BLOCK(hp_open_bn_gfx)

@=======================================================================
@
@	hp_open_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-04-17, 11:41:00
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global hp_open_bn_gfxTiles		@ 128 unsigned chars
	.hidden hp_open_bn_gfxTiles
hp_open_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x43000000,0x43022000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00022034,0x01221034
	.word 0x43011210,0x43000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000034,0x00000034,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global hp_open_bn_gfxPal		@ 32 unsigned chars
	.hidden hp_open_bn_gfxPal
hp_open_bn_gfxPal:
	.hword 0x7C1F,0x2801,0x4C05,0x3680,0x1F62,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(hp_open_bn_gfx)
