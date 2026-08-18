
@{{BLOCK(obstacle_trashbox_bn_gfx)

@=======================================================================
@
@	obstacle_trashbox_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-08-14, 08:24:47
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global obstacle_trashbox_bn_gfxTiles		@ 128 unsigned chars
	.hidden obstacle_trashbox_bn_gfxTiles
obstacle_trashbox_bn_gfxTiles:
	.word 0x00110000,0x44111200,0x41111111,0x41111114,0x11111140,0x11111140,0x11111433,0x22114333
	.word 0x00000311,0x00011113,0x00211114,0x00111134,0x02111144,0x02111444,0x21112442,0x11244444
	.word 0x44224333,0x33323330,0x22323330,0x22322300,0x32322400,0x33332400,0x33332000,0x44444000
	.word 0x34444444,0x33322223,0x33222222,0x33322222,0x33333333,0x42223333,0x44444222,0x00000044

	.section .rodata
	.align	2
	.global obstacle_trashbox_bn_gfxPal		@ 32 unsigned chars
	.hidden obstacle_trashbox_bn_gfxPal
obstacle_trashbox_bn_gfxPal:
	.hword 0x7C1F,0x3C25,0x3C20,0x3400,0x2800,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(obstacle_trashbox_bn_gfx)
