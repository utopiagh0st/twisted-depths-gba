
@{{BLOCK(obstacle_trashcan_bn_gfx)

@=======================================================================
@
@	obstacle_trashcan_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-08-19, 08:40:17
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global obstacle_trashcan_bn_gfxTiles		@ 128 unsigned chars
	.hidden obstacle_trashcan_bn_gfxTiles
obstacle_trashcan_bn_gfxTiles:
	.word 0x11000000,0x11122000,0x33111210,0x22311111,0x22221112,0x11111123,0x21112330,0x22223330
	.word 0x00221111,0x02211111,0x21111223,0x32122232,0x32112311,0x03221111,0x03321222,0x03332222
	.word 0x33333320,0x33323310,0x32133310,0x32133210,0x32133220,0x33133200,0x33133000,0x33200000
	.word 0x03233333,0x00223233,0x00323332,0x00323331,0x00333321,0x00033321,0x00003321,0x00000332

	.section .rodata
	.align	2
	.global obstacle_trashcan_bn_gfxPal		@ 32 unsigned chars
	.hidden obstacle_trashcan_bn_gfxPal
obstacle_trashcan_bn_gfxPal:
	.hword 0x7C1F,0x5042,0x3C25,0x3000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(obstacle_trashcan_bn_gfx)
