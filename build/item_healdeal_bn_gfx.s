
@{{BLOCK(item_healdeal_bn_gfx)

@=======================================================================
@
@	item_healdeal_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-09-15, 14:07:51
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global item_healdeal_bn_gfxTiles		@ 128 unsigned chars
	.hidden item_healdeal_bn_gfxTiles
item_healdeal_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x33133000,0x21111300,0x11111200,0x11441200,0x11111200
	.word 0x00000000,0x00031130,0x00311112,0x00314311,0x00311431,0x00311141,0x00314113,0x00311411
	.word 0x11411300,0x34112300,0x13123000,0x12333000,0x33000000,0x00000000,0x00000000,0x00000000
	.word 0x00011341,0x00031314,0x00003111,0x00003321,0x00000002,0x00000002,0x00000002,0x00000000

	.section .rodata
	.align	2
	.global item_healdeal_bn_gfxPal		@ 32 unsigned chars
	.hidden item_healdeal_bn_gfxPal
item_healdeal_bn_gfxPal:
	.hword 0x7C1F,0x201F,0x2414,0x140A,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(item_healdeal_bn_gfx)
