
@{{BLOCK(bluhemoji_bn_gfx)

@=======================================================================
@
@	bluhemoji_bn_gfx, 16x16@4, 
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
	.global bluhemoji_bn_gfxTiles		@ 128 unsigned chars
	.hidden bluhemoji_bn_gfxTiles
bluhemoji_bn_gfxTiles:
	.word 0x44000000,0x41150000,0x11155000,0x15111400,0x11111400,0x51115440,0x45554440,0x44444440
	.word 0x00000444,0x00011544,0x00111554,0x04151114,0x04111114,0x44511154,0x44455544,0x44444444
	.word 0x44444440,0x44444440,0x22244400,0x22444400,0x44444000,0x44440000,0x44000000,0x00000000
	.word 0x44444444,0x44444444,0x04442222,0x04443332,0x00443434,0x00043434,0x00003444,0x00000000

	.section .rodata
	.align	2
	.global bluhemoji_bn_gfxPal		@ 32 unsigned chars
	.hidden bluhemoji_bn_gfxPal
bluhemoji_bn_gfxPal:
	.hword 0x7C1F,0x0000,0x0065,0x52C7,0x22B8,0x7FFF,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(bluhemoji_bn_gfx)
