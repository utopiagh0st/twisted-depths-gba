
@{{BLOCK(enemy_bn_gfx)

@=======================================================================
@
@	enemy_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-02-27, 15:44:40
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global enemy_bn_gfxTiles		@ 128 unsigned chars
	.hidden enemy_bn_gfxTiles
enemy_bn_gfxTiles:
	.word 0x00000000,0x00770000,0x77757000,0x55544700,0x64446160,0x66466160,0x44444700,0x24242470
	.word 0x00000000,0x00007770,0x00007557,0x00007544,0x07707441,0x70077461,0x07077444,0x00077344
	.word 0x42424470,0x44444700,0x44444370,0x34443700,0x32337700,0x77770000,0x00000000,0x00000000
	.word 0x00707444,0x00707344,0x00777444,0x00727344,0x00077232,0x00077777,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global enemy_bn_gfxPal		@ 32 unsigned chars
	.hidden enemy_bn_gfxPal
enemy_bn_gfxPal:
	.hword 0x1400,0x0000,0x1D80,0x2EA0,0x4BE0,0x3BEE,0x03F6,0x7FFF
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(enemy_bn_gfx)
