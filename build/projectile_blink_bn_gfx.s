
@{{BLOCK(projectile_blink_bn_gfx)

@=======================================================================
@
@	projectile_blink_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2026-08-13, 19:12:59
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global projectile_blink_bn_gfxTiles		@ 32 unsigned chars
	.hidden projectile_blink_bn_gfxTiles
projectile_blink_bn_gfxTiles:
	.word 0x00000000,0x01010110,0x00141410,0x01441100,0x00114410,0x01414100,0x01101010,0x00000000

	.section .rodata
	.align	2
	.global projectile_blink_bn_gfxPal		@ 32 unsigned chars
	.hidden projectile_blink_bn_gfxPal
projectile_blink_bn_gfxPal:
	.hword 0x7C1F,0x0000,0x3240,0x2B82,0x7FFF,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(projectile_blink_bn_gfx)
