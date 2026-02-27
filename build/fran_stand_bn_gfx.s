
@{{BLOCK(fran_stand_bn_gfx)

@=======================================================================
@
@	fran_stand_bn_gfx, 16x16@4, 
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
	.global fran_stand_bn_gfxTiles		@ 128 unsigned chars
	.hidden fran_stand_bn_gfxTiles
fran_stand_bn_gfxTiles:
	.word 0xCCC0CC00,0x777C7C00,0x55544C00,0x555547C0,0x555557C0,0x5BB5547C,0x5C1C47C0,0x5C1C447C
	.word 0x00CC0CCC,0x00C7C777,0x00C44555,0x0C745555,0x0C7555B5,0xC74554BB,0x0C7441CB,0xC74471CB
	.word 0xBBBA47C0,0x6BAC7C00,0x1144C000,0x74244C00,0x1424BC00,0x898CC000,0xC11C0000,0x0CC00000
	.word 0x0C74ABBB,0x00C7CAB6,0x000C4411,0x00C44241,0x00CB4245,0x000CC898,0x0000C11C,0x00000CC0

	.section .rodata
	.align	2
	.global fran_stand_bn_gfxPal		@ 32 unsigned chars
	.hidden fran_stand_bn_gfxPal
fran_stand_bn_gfxPal:
	.hword 0x7C1F,0x0000,0x0000,0x0800,0x1400,0x1C02,0x0C06,0x3C06
	.hword 0x2C62,0x3CA5,0x2995,0x3218,0x7FFF,0x0000,0x0000,0x0000

@}}BLOCK(fran_stand_bn_gfx)
