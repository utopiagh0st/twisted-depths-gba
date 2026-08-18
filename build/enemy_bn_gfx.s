
@{{BLOCK(enemy_bn_gfx)

@=======================================================================
@
@	enemy_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-08-14, 08:24:48
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global enemy_bn_gfxTiles		@ 128 unsigned chars
	.hidden enemy_bn_gfxTiles
enemy_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00030000,0x22222000,0x12221510,0x11211510,0x22222000,0x32323200
	.word 0x00000000,0x00000000,0x00000330,0x00000322,0x02200225,0x20020215,0x02030222,0x00030322
	.word 0x23232200,0x22222000,0x22222300,0x32223000,0x34334000,0x00000000,0x00000000,0x00000000
	.word 0x00300222,0x00300322,0x00340222,0x00044322,0x00000434,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global enemy_bn_gfxPal		@ 32 unsigned chars
	.hidden enemy_bn_gfxPal
enemy_bn_gfxPal:
	.hword 0x7C1F,0x03FC,0x18BB,0x2C33,0x2C02,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(enemy_bn_gfx)
