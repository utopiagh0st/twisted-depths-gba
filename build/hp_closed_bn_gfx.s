
@{{BLOCK(hp_closed_bn_gfx)

@=======================================================================
@
@	hp_closed_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2026-08-05, 07:45:11
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global hp_closed_bn_gfxTiles		@ 32 unsigned chars
	.hidden hp_closed_bn_gfxTiles
hp_closed_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00222000,0x22221100,0x00011122,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global hp_closed_bn_gfxPal		@ 32 unsigned chars
	.hidden hp_closed_bn_gfxPal
hp_closed_bn_gfxPal:
	.hword 0x7C1F,0x2801,0x4C05,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(hp_closed_bn_gfx)
