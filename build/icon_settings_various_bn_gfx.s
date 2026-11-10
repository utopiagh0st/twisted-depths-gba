
@{{BLOCK(icon_settings_various_bn_gfx)

@=======================================================================
@
@	icon_settings_various_bn_gfx, 40x8@4, 
@	+ palette 16 entries, not compressed
@	+ 5 tiles not compressed
@	Total size: 32 + 160 = 192
@
@	Time-stamp: 2026-11-10, 08:59:35
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global icon_settings_various_bn_gfxTiles		@ 160 unsigned chars
	.hidden icon_settings_various_bn_gfxTiles
icon_settings_various_bn_gfxTiles:
	.word 0x00000000,0x02222222,0x21111112,0x21111112,0x21111112,0x21111112,0x02222222,0x00000000
	.word 0x00000000,0x02222222,0x23333332,0x23333332,0x23333332,0x23333332,0x02222222,0x00000000
	.word 0x00110000,0x01010000,0x10010000,0x10010000,0x00010000,0x00011100,0x00011110,0x00001100
	.word 0x00010000,0x01000010,0x00011000,0x00111101,0x10111100,0x00011000,0x01000010,0x00001000
	.word 0x00011000,0x00001000,0x10101011,0x01001001,0x01011011,0x01001010,0x10101011,0x00001000

	.section .rodata
	.align	2
	.global icon_settings_various_bn_gfxPal		@ 32 unsigned chars
	.hidden icon_settings_various_bn_gfxPal
icon_settings_various_bn_gfxPal:
	.hword 0x7C1F,0x7FFF,0x318C,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(icon_settings_various_bn_gfx)
