
@{{BLOCK(projectile_bn_gfx)

@=======================================================================
@
@	projectile_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2026-08-14, 08:24:47
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global projectile_bn_gfxTiles		@ 32 unsigned chars
	.hidden projectile_bn_gfxTiles
projectile_bn_gfxTiles:
	.word 0x00000000,0x01101010,0x01312100,0x00113210,0x01231100,0x00121310,0x01010110,0x00000000

	.section .rodata
	.align	2
	.global projectile_bn_gfxPal		@ 32 unsigned chars
	.hidden projectile_bn_gfxPal
projectile_bn_gfxPal:
	.hword 0x7C1F,0x0000,0x3240,0x2B82,0x7FFF,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(projectile_bn_gfx)
