
@{{BLOCK(obstacle_trashbag_bn_gfx)

@=======================================================================
@
@	obstacle_trashbag_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles Metatiled by 2x2 not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2026-08-18, 20:31:02
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global obstacle_trashbag_bn_gfxTiles		@ 128 unsigned chars
	.hidden obstacle_trashbag_bn_gfxTiles
obstacle_trashbag_bn_gfxTiles:
	.word 0x11110000,0x10000000,0x00432200,0x43321130,0x22111113,0x22211112,0x43322112,0x44332211
	.word 0x00000002,0x22200234,0x43324440,0x04433444,0x00044432,0x00443142,0x00433113,0x00333211
	.word 0x34443213,0x12443234,0x11244344,0x32244440,0x43334440,0x44442400,0x44344000,0x44400000
	.word 0x04333211,0x44334321,0x44334332,0x44334443,0x44333444,0x04343334,0x00444433,0x00000444

	.section .rodata
	.align	2
	.global obstacle_trashbag_bn_gfxPal		@ 32 unsigned chars
	.hidden obstacle_trashbag_bn_gfxPal
obstacle_trashbag_bn_gfxPal:
	.hword 0x7C1F,0x3C25,0x3C20,0x3400,0x2800,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(obstacle_trashbag_bn_gfx)
