
@{{BLOCK(hitbox_bn_gfx)

@=======================================================================
@
@	hitbox_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-05-13, 01:13:59
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global hitbox_bn_gfxTiles		@ 128 unsigned chars
	.hidden hitbox_bn_gfxTiles
hitbox_bn_gfxTiles:
	.word 0x11111111,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001
	.word 0x21111111,0x20000000,0x20000000,0x20000000,0x20000000,0x20000000,0x20000000,0x20000000
	.word 0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x22222221
	.word 0x20000000,0x20000000,0x20000000,0x20000000,0x20000000,0x20000000,0x20000000,0x22222222

	.section .rodata
	.align	2
	.global hitbox_bn_gfxPal		@ 32 unsigned chars
	.hidden hitbox_bn_gfxPal
hitbox_bn_gfxPal:
	.hword 0x7C1F,0x201F,0x001F,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(hitbox_bn_gfx)
