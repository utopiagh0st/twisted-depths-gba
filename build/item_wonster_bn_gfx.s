
@{{BLOCK(item_wonster_bn_gfx)

@=======================================================================
@
@	item_wonster_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-11-09, 07:42:49
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global item_wonster_bn_gfxTiles		@ 128 unsigned chars
	.hidden item_wonster_bn_gfxTiles
item_wonster_bn_gfxTiles:
	.word 0x00000000,0x60000000,0x66000000,0x63600000,0x65300000,0x16360000,0x64560000,0x61630000
	.word 0x00000530,0x00035653,0x00356536,0x00655566,0x06666663,0x06565536,0x06566626,0x00651661
	.word 0x62656000,0x21253000,0x61665600,0x66666300,0x66216600,0x61666000,0x66660000,0x66000000
	.word 0x00656462,0x00066166,0x00065612,0x00006661,0x00006566,0x00000566,0x00000666,0x00000066

	.section .rodata
	.align	2
	.global item_wonster_bn_gfxPal		@ 32 unsigned chars
	.hidden item_wonster_bn_gfxPal
item_wonster_bn_gfxPal:
	.hword 0x7C1F,0x3680,0x1F62,0x5506,0x37A9,0x1C63,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(item_wonster_bn_gfx)
