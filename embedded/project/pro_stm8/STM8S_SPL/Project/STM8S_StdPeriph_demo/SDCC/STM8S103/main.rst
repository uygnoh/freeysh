                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _printf
                                     13 	.globl _UART1_GetFlagStatus
                                     14 	.globl _UART1_SendData8
                                     15 	.globl _UART1_ReceiveData8
                                     16 	.globl _UART1_Init
                                     17 	.globl _UART1_DeInit
                                     18 	.globl _TIM4_ClearFlag
                                     19 	.globl _TIM4_ITConfig
                                     20 	.globl _TIM4_Cmd
                                     21 	.globl _TIM4_TimeBaseInit
                                     22 	.globl _TIM4_DeInit
                                     23 	.globl _GPIO_WriteReverse
                                     24 	.globl _GPIO_WriteHigh
                                     25 	.globl _GPIO_Init
                                     26 	.globl _CLK_HSIPrescalerConfig
                                     27 	.globl _CLK_PeripheralClockConfig
                                     28 	.globl _g_count1ms
                                     29 	.globl _g_flag1ms
                                     30 	.globl _putchar
                                     31 	.globl _getchar
                                     32 	.globl _assert_failed
                                     33 ;--------------------------------------------------------
                                     34 ; ram data
                                     35 ;--------------------------------------------------------
                                     36 	.area DATA
                                     37 ;--------------------------------------------------------
                                     38 ; ram data
                                     39 ;--------------------------------------------------------
                                     40 	.area INITIALIZED
      000001                         41 _g_flag1ms::
      000001                         42 	.ds 1
      000002                         43 _g_count1ms::
      000002                         44 	.ds 4
                                     45 ;--------------------------------------------------------
                                     46 ; Stack segment in internal ram 
                                     47 ;--------------------------------------------------------
                                     48 	.area	SSEG
      FFFFFF                         49 __start__stack:
      FFFFFF                         50 	.ds	1
                                     51 
                                     52 ;--------------------------------------------------------
                                     53 ; absolute external ram data
                                     54 ;--------------------------------------------------------
                                     55 	.area DABS (ABS)
                                     56 
                                     57 ; default segment ordering for linker
                                     58 	.area HOME
                                     59 	.area GSINIT
                                     60 	.area GSFINAL
                                     61 	.area CONST
                                     62 	.area INITIALIZER
                                     63 	.area CODE
                                     64 
                                     65 ;--------------------------------------------------------
                                     66 ; interrupt vector 
                                     67 ;--------------------------------------------------------
                                     68 	.area HOME
      008000                         69 __interrupt_vect:
      008000 82 00 80 6F             70 	int s_GSINIT ; reset
      008004 82 00 81 E9             71 	int _TRAP_IRQHandler ; trap
      008008 82 00 81 EA             72 	int _TLI_IRQHandler ; int0
      00800C 82 00 81 EB             73 	int _AWU_IRQHandler ; int1
      008010 82 00 81 EC             74 	int _CLK_IRQHandler ; int2
      008014 82 00 81 ED             75 	int _EXTI_PORTA_IRQHandler ; int3
      008018 82 00 81 EE             76 	int _EXTI_PORTB_IRQHandler ; int4
      00801C 82 00 81 EF             77 	int _EXTI_PORTC_IRQHandler ; int5
      008020 82 00 81 F0             78 	int _EXTI_PORTD_IRQHandler ; int6
      008024 82 00 81 F1             79 	int _EXTI_PORTE_IRQHandler ; int7
      008028 82 00 00 00             80 	int 0x000000 ; int8
      00802C 82 00 00 00             81 	int 0x000000 ; int9
      008030 82 00 81 F2             82 	int _SPI_IRQHandler ; int10
      008034 82 00 81 F3             83 	int _TIM1_UPD_OVF_TRG_BRK_IRQHandler ; int11
      008038 82 00 81 F4             84 	int _TIM1_CAP_COM_IRQHandler ; int12
      00803C 82 00 81 F5             85 	int _TIM2_UPD_OVF_BRK_IRQHandler ; int13
      008040 82 00 81 F6             86 	int _TIM2_CAP_COM_IRQHandler ; int14
      008044 82 00 00 00             87 	int 0x000000 ; int15
      008048 82 00 00 00             88 	int 0x000000 ; int16
      00804C 82 00 81 F7             89 	int _UART1_TX_IRQHandler ; int17
      008050 82 00 81 F8             90 	int _UART1_RX_IRQHandler ; int18
      008054 82 00 81 F9             91 	int _I2C_IRQHandler ; int19
      008058 82 00 00 00             92 	int 0x000000 ; int20
      00805C 82 00 00 00             93 	int 0x000000 ; int21
      008060 82 00 81 FA             94 	int _ADC1_IRQHandler ; int22
      008064 82 00 81 FB             95 	int _TIM4_UPD_OVF_IRQHandler ; int23
      008068 82 00 82 22             96 	int _EEPROM_EEC_IRQHandler ; int24
                                     97 ;--------------------------------------------------------
                                     98 ; global & static initialisations
                                     99 ;--------------------------------------------------------
                                    100 	.area HOME
                                    101 	.area GSINIT
                                    102 	.area GSFINAL
                                    103 	.area GSINIT
      00806F                        104 __sdcc_gs_init_startup:
      00806F                        105 __sdcc_init_data:
                                    106 ; stm8_genXINIT() start
      00806F AE 00 00         [ 2]  107 	ldw x, #l_DATA
      008072 27 07            [ 1]  108 	jreq	00002$
      008074                        109 00001$:
      008074 72 4F 00 00      [ 1]  110 	clr (s_DATA - 1, x)
      008078 5A               [ 2]  111 	decw x
      008079 26 F9            [ 1]  112 	jrne	00001$
      00807B                        113 00002$:
      00807B AE 00 05         [ 2]  114 	ldw	x, #l_INITIALIZER
      00807E 27 09            [ 1]  115 	jreq	00004$
      008080                        116 00003$:
      008080 D6 81 E3         [ 1]  117 	ld	a, (s_INITIALIZER - 1, x)
      008083 D7 00 00         [ 1]  118 	ld	(s_INITIALIZED - 1, x), a
      008086 5A               [ 2]  119 	decw	x
      008087 26 F7            [ 1]  120 	jrne	00003$
      008089                        121 00004$:
                                    122 ; stm8_genXINIT() end
                                    123 	.area GSFINAL
      008089 CC 80 6C         [ 2]  124 	jp	__sdcc_program_startup
                                    125 ;--------------------------------------------------------
                                    126 ; Home
                                    127 ;--------------------------------------------------------
                                    128 	.area HOME
                                    129 	.area HOME
      00806C                        130 __sdcc_program_startup:
      00806C CC 82 23         [ 2]  131 	jp	_main
                                    132 ;	return from main will return to caller
                                    133 ;--------------------------------------------------------
                                    134 ; code
                                    135 ;--------------------------------------------------------
                                    136 	.area CODE
                                    137 ;	../main.c: 68: void main(void)
                                    138 ;	-----------------------------------------
                                    139 ;	 function main
                                    140 ;	-----------------------------------------
      008223                        141 _main:
                                    142 ;	../main.c: 75: CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
      008223 4B 00            [ 1]  143 	push	#0x00
      008225 CD 87 CD         [ 4]  144 	call	_CLK_HSIPrescalerConfig
      008228 84               [ 1]  145 	pop	a
                                    146 ;	../main.c: 78: CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);
      008229 4B 01            [ 1]  147 	push	#0x01
      00822B 4B 04            [ 1]  148 	push	#0x04
      00822D CD 85 E0         [ 4]  149 	call	_CLK_PeripheralClockConfig
      008230 85               [ 2]  150 	popw	x
                                    151 ;	../main.c: 82: GPIO_Init(GPIOD, (GPIO_Pin_TypeDef)GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
      008231 4B E0            [ 1]  152 	push	#0xe0
      008233 4B 08            [ 1]  153 	push	#0x08
      008235 4B 0F            [ 1]  154 	push	#0x0f
      008237 4B 50            [ 1]  155 	push	#0x50
      008239 CD 83 26         [ 4]  156 	call	_GPIO_Init
      00823C 5B 04            [ 2]  157 	addw	sp, #4
                                    158 ;	../main.c: 83: GPIO_WriteHigh(GPIOD, (GPIO_Pin_TypeDef)GPIO_PIN_3);
      00823E 4B 08            [ 1]  159 	push	#0x08
      008240 4B 0F            [ 1]  160 	push	#0x0f
      008242 4B 50            [ 1]  161 	push	#0x50
      008244 CD 84 09         [ 4]  162 	call	_GPIO_WriteHigh
      008247 5B 03            [ 2]  163 	addw	sp, #3
                                    164 ;	../main.c: 92: TIM4_DeInit();
      008249 CD 97 B5         [ 4]  165 	call	_TIM4_DeInit
                                    166 ;	../main.c: 93: TIM4_TimeBaseInit(TIM4_PRESCALER_128, 124);
      00824C 4B 7C            [ 1]  167 	push	#0x7c
      00824E 4B 07            [ 1]  168 	push	#0x07
      008250 CD 97 CE         [ 4]  169 	call	_TIM4_TimeBaseInit
      008253 85               [ 2]  170 	popw	x
                                    171 ;	../main.c: 94: TIM4_ClearFlag(TIM4_FLAG_UPDATE);
      008254 4B 01            [ 1]  172 	push	#0x01
      008256 CD 99 E9         [ 4]  173 	call	_TIM4_ClearFlag
      008259 84               [ 1]  174 	pop	a
                                    175 ;	../main.c: 95: TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
      00825A 4B 01            [ 1]  176 	push	#0x01
      00825C 4B 01            [ 1]  177 	push	#0x01
      00825E CD 98 42         [ 4]  178 	call	_TIM4_ITConfig
      008261 85               [ 2]  179 	popw	x
                                    180 ;	../main.c: 96: TIM4_Cmd(ENABLE);
      008262 4B 01            [ 1]  181 	push	#0x01
      008264 CD 98 17         [ 4]  182 	call	_TIM4_Cmd
      008267 84               [ 1]  183 	pop	a
                                    184 ;	../main.c: 99: UART1_DeInit();
      008268 CD 90 7D         [ 4]  185 	call	_UART1_DeInit
                                    186 ;	../main.c: 100: UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
      00826B 4B 0C            [ 1]  187 	push	#0x0c
      00826D 4B 80            [ 1]  188 	push	#0x80
      00826F 4B 00            [ 1]  189 	push	#0x00
      008271 4B 00            [ 1]  190 	push	#0x00
      008273 4B 00            [ 1]  191 	push	#0x00
      008275 4B 00            [ 1]  192 	push	#0x00
      008277 4B C2            [ 1]  193 	push	#0xc2
      008279 4B 01            [ 1]  194 	push	#0x01
      00827B 4B 00            [ 1]  195 	push	#0x00
      00827D CD 90 A8         [ 4]  196 	call	_UART1_Init
      008280 5B 09            [ 2]  197 	addw	sp, #9
                                    198 ;	../main.c: 110: enableInterrupts();
      008282 9A               [ 1]  199 	rim
                                    200 ;	../main.c: 113: while (1)
      008283                        201 00108$:
                                    202 ;	../main.c: 116: if (UART1_GetFlagStatus(UART1_FLAG_RXNE))
      008283 4B 20            [ 1]  203 	push	#0x20
      008285 4B 00            [ 1]  204 	push	#0x00
      008287 CD 95 E4         [ 4]  205 	call	_UART1_GetFlagStatus
      00828A 85               [ 2]  206 	popw	x
      00828B 4D               [ 1]  207 	tnz	a
      00828C 27 17            [ 1]  208 	jreq	00102$
                                    209 ;	../main.c: 118: val = getchar();
      00828E CD 83 03         [ 4]  210 	call	_getchar
                                    211 ;	../main.c: 119: printf("read %c%c%c", val,10,13);
      008291 4F               [ 1]  212 	clr	a
      008292 95               [ 1]  213 	ld	xh, a
      008293 4B 0D            [ 1]  214 	push	#0x0d
      008295 4B 00            [ 1]  215 	push	#0x00
      008297 4B 0A            [ 1]  216 	push	#0x0a
      008299 4B 00            [ 1]  217 	push	#0x00
      00829B 89               [ 2]  218 	pushw	x
      00829C 4B 8C            [ 1]  219 	push	#<___str_0
      00829E 4B 80            [ 1]  220 	push	#(___str_0 >> 8)
      0082A0 CD 9B 35         [ 4]  221 	call	_printf
      0082A3 5B 08            [ 2]  222 	addw	sp, #8
      0082A5                        223 00102$:
                                    224 ;	../main.c: 125: if (g_flag1ms)
      0082A5 72 5D 00 01      [ 1]  225 	tnz	_g_flag1ms+0
      0082A9 27 D8            [ 1]  226 	jreq	00108$
                                    227 ;	../main.c: 127: g_flag1ms=0;
      0082AB 72 5F 00 01      [ 1]  228 	clr	_g_flag1ms+0
                                    229 ;	../main.c: 129: if ((g_count1ms % 500) == 0)
      0082AF 4B F4            [ 1]  230 	push	#0xf4
      0082B1 4B 01            [ 1]  231 	push	#0x01
      0082B3 5F               [ 1]  232 	clrw	x
      0082B4 89               [ 2]  233 	pushw	x
      0082B5 CE 00 04         [ 2]  234 	ldw	x, _g_count1ms+2
      0082B8 89               [ 2]  235 	pushw	x
      0082B9 CE 00 02         [ 2]  236 	ldw	x, _g_count1ms+0
      0082BC 89               [ 2]  237 	pushw	x
      0082BD CD 9A 4E         [ 4]  238 	call	__modulong
      0082C0 5B 08            [ 2]  239 	addw	sp, #8
      0082C2 5D               [ 2]  240 	tnzw	x
      0082C3 26 BE            [ 1]  241 	jrne	00108$
      0082C5 90 5D            [ 2]  242 	tnzw	y
      0082C7 26 BA            [ 1]  243 	jrne	00108$
                                    244 ;	../main.c: 133: GPIO_WriteReverse(GPIOD, (GPIO_Pin_TypeDef)GPIO_PIN_3);
      0082C9 4B 08            [ 1]  245 	push	#0x08
      0082CB 4B 0F            [ 1]  246 	push	#0x0f
      0082CD 4B 50            [ 1]  247 	push	#0x50
      0082CF CD 84 1E         [ 4]  248 	call	_GPIO_WriteReverse
      0082D2 5B 03            [ 2]  249 	addw	sp, #3
                                    250 ;	../main.c: 141: printf("time %ld%c%c", g_count1ms,10,13);
      0082D4 4B 0D            [ 1]  251 	push	#0x0d
      0082D6 4B 00            [ 1]  252 	push	#0x00
      0082D8 4B 0A            [ 1]  253 	push	#0x0a
      0082DA 4B 00            [ 1]  254 	push	#0x00
      0082DC CE 00 04         [ 2]  255 	ldw	x, _g_count1ms+2
      0082DF 89               [ 2]  256 	pushw	x
      0082E0 CE 00 02         [ 2]  257 	ldw	x, _g_count1ms+0
      0082E3 89               [ 2]  258 	pushw	x
      0082E4 4B 98            [ 1]  259 	push	#<___str_1
      0082E6 4B 80            [ 1]  260 	push	#(___str_1 >> 8)
      0082E8 CD 9B 35         [ 4]  261 	call	_printf
      0082EB 5B 0A            [ 2]  262 	addw	sp, #10
      0082ED 20 94            [ 2]  263 	jra	00108$
                                    264 ;	../main.c: 179: } // main()
      0082EF 81               [ 4]  265 	ret
                                    266 ;	../main.c: 187: PUTCHAR_PROTOTYPE
                                    267 ;	-----------------------------------------
                                    268 ;	 function putchar
                                    269 ;	-----------------------------------------
      0082F0                        270 _putchar:
                                    271 ;	../main.c: 190: UART1_SendData8(c);
      0082F0 7B 04            [ 1]  272 	ld	a, (0x04, sp)
      0082F2 88               [ 1]  273 	push	a
      0082F3 CD 95 87         [ 4]  274 	call	_UART1_SendData8
      0082F6 84               [ 1]  275 	pop	a
                                    276 ;	../main.c: 192: while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
      0082F7                        277 00101$:
      0082F7 4B 80            [ 1]  278 	push	#0x80
      0082F9 4B 00            [ 1]  279 	push	#0x00
      0082FB CD 95 E4         [ 4]  280 	call	_UART1_GetFlagStatus
      0082FE 85               [ 2]  281 	popw	x
      0082FF 4D               [ 1]  282 	tnz	a
      008300 27 F5            [ 1]  283 	jreq	00101$
                                    284 ;	../main.c: 198: }
      008302 81               [ 4]  285 	ret
                                    286 ;	../main.c: 206: GETCHAR_PROTOTYPE
                                    287 ;	-----------------------------------------
                                    288 ;	 function getchar
                                    289 ;	-----------------------------------------
      008303                        290 _getchar:
                                    291 ;	../main.c: 214: while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);
      008303                        292 00101$:
      008303 4B 20            [ 1]  293 	push	#0x20
      008305 4B 00            [ 1]  294 	push	#0x00
      008307 CD 95 E4         [ 4]  295 	call	_UART1_GetFlagStatus
      00830A 85               [ 2]  296 	popw	x
      00830B 4D               [ 1]  297 	tnz	a
      00830C 27 F5            [ 1]  298 	jreq	00101$
                                    299 ;	../main.c: 215: c = UART1_ReceiveData8();
      00830E CD 95 66         [ 4]  300 	call	_UART1_ReceiveData8
      008311 5F               [ 1]  301 	clrw	x
      008312 97               [ 1]  302 	ld	xl, a
                                    303 ;	../main.c: 216: return (c);
                                    304 ;	../main.c: 217: }
      008313 81               [ 4]  305 	ret
                                    306 ;	../main.c: 229: void assert_failed(uint8_t* file, uint32_t line)
                                    307 ;	-----------------------------------------
                                    308 ;	 function assert_failed
                                    309 ;	-----------------------------------------
      008314                        310 _assert_failed:
                                    311 ;	../main.c: 239: while (1)
      008314                        312 00102$:
      008314 20 FE            [ 2]  313 	jra	00102$
                                    314 ;	../main.c: 242: }
      008316 81               [ 4]  315 	ret
                                    316 	.area CODE
                                    317 	.area CONST
      00808C                        318 ___str_0:
      00808C 72 65 61 64 20 25 63   319 	.ascii "read %c%c%c"
             25 63 25 63
      008097 00                     320 	.db 0x00
      008098                        321 ___str_1:
      008098 74 69 6D 65 20 25 6C   322 	.ascii "time %ld%c%c"
             64 25 63 25 63
      0080A4 00                     323 	.db 0x00
                                    324 	.area INITIALIZER
      0081E4                        325 __xinit__g_flag1ms:
      0081E4 00                     326 	.db #0x00	; 0
      0081E5                        327 __xinit__g_count1ms:
      0081E5 00 00 00 00            328 	.byte #0x00,#0x00,#0x00,#0x00	; 0
                                    329 	.area CABS (ABS)
