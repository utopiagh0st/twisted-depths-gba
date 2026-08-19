
@{{BLOCK(projectile_bn_gfx)

@=======================================================================
@
@	projectile_bn_gfx, 16x8@4, 
@	+ palette 16 entries, not compressed
@	+ 2 tiles not compressed
@	Total size: 32 + 64 = 96
@
@	Time-stamp: 2026-08-19, 11:32:57
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global projectile_bn_gfxTiles		@ 64 unsigned chars
	.hidden projectile_bn_gfxTiles
projectile_bn_gfxTiles:
	.word 0x00000000,0x00011000,0x00122100,0x01233210,0x01233210,0x00122100,0x00011000,0x00000000
	.word 0x00000000,0x00033000,0x00344300,0x03444430,0x03444430,0x00344300,0x00033000,0x00000000

	.section .rodata
	.align	2
	.global projectile_bn_gfxPal		@ 32 unsigned chars
	.hidden projectile_bn_gfxPal
projectile_bn_gfxPal:
	.hword 0x7C1F,0x0000,0x3240,0x2B82,0x7FFF,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(projectile_bn_gfx)
