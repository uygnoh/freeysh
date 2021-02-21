                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_gpio
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _assert_failed
                                     12 	.globl _GPIO_DeInit
                                     13 	.globl _GPIO_Init
                                     14 	.globl _GPIO_Write
                                     15 	.globl _GPIO_WriteHigh
                                     16 	.globl _GPIO_WriteLow
                                     17 	.globl _GPIO_WriteReverse
                                     18 	.globl _GPIO_ReadOutputData
                                     19 	.globl _GPIO_ReadInputData
                                     20 	.globl _GPIO_ReadInputPin
                                     21 	.globl _GPIO_ExternalPullUpConfig
                                     22 ;--------------------------------------------------------
                                     23 ; ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area DATA
                                     26 ;--------------------------------------------------------
                                     27 ; ram data
                                     28 ;--------------------------------------------------------
                                     29 	.area INITIALIZED
                                     30 ;--------------------------------------------------------
                                     31 ; absolute external ram data
                                     32 ;--------------------------------------------------------
                                     33 	.area DABS (ABS)
                                     34 
                                     35 ; default segment ordering for linker
                                     36 	.area HOME
                                     37 	.area GSINIT
                                     38 	.area GSFINAL
                                     39 	.area CONST
                                     40 	.area INITIALIZER
                                     41 	.area CODE
                                     42 
                                     43 ;--------------------------------------------------------
                                     44 ; global & static initialisations
                                     45 ;--------------------------------------------------------
                                     46 	.area HOME
                                     47 	.area GSINIT
                                     48 	.area GSFINAL
                                     49 	.area GSINIT
                                     50 ;--------------------------------------------------------
                                     51 ; Home
                                     52 ;--------------------------------------------------------
                                     53 	.area HOME
                                     54 	.area HOME
                                     55 ;--------------------------------------------------------
                                     56 ; code
                                     57 ;--------------------------------------------------------
                                     58 	.area CODE
                                     59 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 53: void GPIO_DeInit(GPIO_TypeDef* GPIOx)
                                     60 ;	-----------------------------------------
                                     61 ;	 function GPIO_DeInit
                                     62 ;	-----------------------------------------
      008317                         63 _GPIO_DeInit:
                                     64 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 55: GPIOx->ODR = GPIO_ODR_RESET_VALUE; /* Reset Output Data Register */
      008317 16 03            [ 2]   65 	ldw	y, (0x03, sp)
      008319 90 7F            [ 1]   66 	clr	(y)
                                     67 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 56: GPIOx->DDR = GPIO_DDR_RESET_VALUE; /* Reset Data Direction Register */
      00831B 93               [ 1]   68 	ldw	x, y
      00831C 5C               [ 1]   69 	incw	x
      00831D 5C               [ 1]   70 	incw	x
      00831E 7F               [ 1]   71 	clr	(x)
                                     72 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 57: GPIOx->CR1 = GPIO_CR1_RESET_VALUE; /* Reset Control Register 1 */
      00831F 93               [ 1]   73 	ldw	x, y
      008320 6F 03            [ 1]   74 	clr	(0x0003, x)
                                     75 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 58: GPIOx->CR2 = GPIO_CR2_RESET_VALUE; /* Reset Control Register 2 */
      008322 93               [ 1]   76 	ldw	x, y
      008323 6F 04            [ 1]   77 	clr	(0x0004, x)
                                     78 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 59: }
      008325 81               [ 4]   79 	ret
                                     80 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 71: void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, GPIO_Mode_TypeDef GPIO_Mode)
                                     81 ;	-----------------------------------------
                                     82 ;	 function GPIO_Init
                                     83 ;	-----------------------------------------
      008326                         84 _GPIO_Init:
      008326 52 05            [ 2]   85 	sub	sp, #5
                                     86 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 77: assert_param(IS_GPIO_MODE_OK(GPIO_Mode));
      008328 0D 0B            [ 1]   87 	tnz	(0x0b, sp)
      00832A 27 51            [ 1]   88 	jreq	00116$
      00832C 7B 0B            [ 1]   89 	ld	a, (0x0b, sp)
      00832E A1 40            [ 1]   90 	cp	a, #0x40
      008330 27 4B            [ 1]   91 	jreq	00116$
      008332 7B 0B            [ 1]   92 	ld	a, (0x0b, sp)
      008334 A1 20            [ 1]   93 	cp	a, #0x20
      008336 27 45            [ 1]   94 	jreq	00116$
      008338 7B 0B            [ 1]   95 	ld	a, (0x0b, sp)
      00833A A1 60            [ 1]   96 	cp	a, #0x60
      00833C 27 3F            [ 1]   97 	jreq	00116$
      00833E 7B 0B            [ 1]   98 	ld	a, (0x0b, sp)
      008340 A1 A0            [ 1]   99 	cp	a, #0xa0
      008342 27 39            [ 1]  100 	jreq	00116$
      008344 7B 0B            [ 1]  101 	ld	a, (0x0b, sp)
      008346 A1 E0            [ 1]  102 	cp	a, #0xe0
      008348 27 33            [ 1]  103 	jreq	00116$
      00834A 7B 0B            [ 1]  104 	ld	a, (0x0b, sp)
      00834C A1 80            [ 1]  105 	cp	a, #0x80
      00834E 27 2D            [ 1]  106 	jreq	00116$
      008350 7B 0B            [ 1]  107 	ld	a, (0x0b, sp)
      008352 A1 C0            [ 1]  108 	cp	a, #0xc0
      008354 27 27            [ 1]  109 	jreq	00116$
      008356 7B 0B            [ 1]  110 	ld	a, (0x0b, sp)
      008358 A1 B0            [ 1]  111 	cp	a, #0xb0
      00835A 27 21            [ 1]  112 	jreq	00116$
      00835C 7B 0B            [ 1]  113 	ld	a, (0x0b, sp)
      00835E A1 F0            [ 1]  114 	cp	a, #0xf0
      008360 27 1B            [ 1]  115 	jreq	00116$
      008362 7B 0B            [ 1]  116 	ld	a, (0x0b, sp)
      008364 A1 90            [ 1]  117 	cp	a, #0x90
      008366 27 15            [ 1]  118 	jreq	00116$
      008368 7B 0B            [ 1]  119 	ld	a, (0x0b, sp)
      00836A A1 D0            [ 1]  120 	cp	a, #0xd0
      00836C 27 0F            [ 1]  121 	jreq	00116$
      00836E 4B 4D            [ 1]  122 	push	#0x4d
      008370 5F               [ 1]  123 	clrw	x
      008371 89               [ 2]  124 	pushw	x
      008372 4B 00            [ 1]  125 	push	#0x00
      008374 4B A5            [ 1]  126 	push	#<___str_0
      008376 4B 80            [ 1]  127 	push	#(___str_0 >> 8)
      008378 CD 83 14         [ 4]  128 	call	_assert_failed
      00837B 5B 06            [ 2]  129 	addw	sp, #6
      00837D                        130 00116$:
                                    131 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 78: assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
      00837D 0D 0A            [ 1]  132 	tnz	(0x0a, sp)
      00837F 26 0F            [ 1]  133 	jrne	00151$
      008381 4B 4E            [ 1]  134 	push	#0x4e
      008383 5F               [ 1]  135 	clrw	x
      008384 89               [ 2]  136 	pushw	x
      008385 4B 00            [ 1]  137 	push	#0x00
      008387 4B A5            [ 1]  138 	push	#<___str_0
      008389 4B 80            [ 1]  139 	push	#(___str_0 >> 8)
      00838B CD 83 14         [ 4]  140 	call	_assert_failed
      00838E 5B 06            [ 2]  141 	addw	sp, #6
      008390                        142 00151$:
                                    143 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      008390 16 08            [ 2]  144 	ldw	y, (0x08, sp)
      008392 93               [ 1]  145 	ldw	x, y
      008393 1C 00 04         [ 2]  146 	addw	x, #0x0004
      008396 1F 04            [ 2]  147 	ldw	(0x04, sp), x
      008398 F6               [ 1]  148 	ld	a, (x)
      008399 88               [ 1]  149 	push	a
      00839A 7B 0B            [ 1]  150 	ld	a, (0x0b, sp)
      00839C 43               [ 1]  151 	cpl	a
      00839D 6B 02            [ 1]  152 	ld	(0x02, sp), a
      00839F 84               [ 1]  153 	pop	a
      0083A0 14 01            [ 1]  154 	and	a, (0x01, sp)
      0083A2 1E 04            [ 2]  155 	ldw	x, (0x04, sp)
      0083A4 F7               [ 1]  156 	ld	(x), a
                                    157 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      0083A5 93               [ 1]  158 	ldw	x, y
      0083A6 5C               [ 1]  159 	incw	x
      0083A7 5C               [ 1]  160 	incw	x
      0083A8 1F 02            [ 2]  161 	ldw	(0x02, sp), x
                                    162 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 87: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x80) != (uint8_t)0x00) /* Output mode */
      0083AA 0D 0B            [ 1]  163 	tnz	(0x0b, sp)
      0083AC 2A 1E            [ 1]  164 	jrpl	00105$
                                    165 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      0083AE 90 F6            [ 1]  166 	ld	a, (y)
                                    167 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 89: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x10) != (uint8_t)0x00) /* High level */
      0083B0 88               [ 1]  168 	push	a
      0083B1 7B 0C            [ 1]  169 	ld	a, (0x0c, sp)
      0083B3 A5 10            [ 1]  170 	bcp	a, #0x10
      0083B5 84               [ 1]  171 	pop	a
      0083B6 27 06            [ 1]  172 	jreq	00102$
                                    173 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      0083B8 1A 0A            [ 1]  174 	or	a, (0x0a, sp)
      0083BA 90 F7            [ 1]  175 	ld	(y), a
      0083BC 20 04            [ 2]  176 	jra	00103$
      0083BE                        177 00102$:
                                    178 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 95: GPIOx->ODR &= (uint8_t)(~(GPIO_Pin));
      0083BE 14 01            [ 1]  179 	and	a, (0x01, sp)
      0083C0 90 F7            [ 1]  180 	ld	(y), a
      0083C2                        181 00103$:
                                    182 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      0083C2 1E 02            [ 2]  183 	ldw	x, (0x02, sp)
      0083C4 F6               [ 1]  184 	ld	a, (x)
      0083C5 1A 0A            [ 1]  185 	or	a, (0x0a, sp)
      0083C7 1E 02            [ 2]  186 	ldw	x, (0x02, sp)
      0083C9 F7               [ 1]  187 	ld	(x), a
      0083CA 20 08            [ 2]  188 	jra	00106$
      0083CC                        189 00105$:
                                    190 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 103: GPIOx->DDR &= (uint8_t)(~(GPIO_Pin));
      0083CC 1E 02            [ 2]  191 	ldw	x, (0x02, sp)
      0083CE F6               [ 1]  192 	ld	a, (x)
      0083CF 14 01            [ 1]  193 	and	a, (0x01, sp)
      0083D1 1E 02            [ 2]  194 	ldw	x, (0x02, sp)
      0083D3 F7               [ 1]  195 	ld	(x), a
      0083D4                        196 00106$:
                                    197 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      0083D4 93               [ 1]  198 	ldw	x, y
      0083D5 1C 00 03         [ 2]  199 	addw	x, #0x0003
      0083D8 F6               [ 1]  200 	ld	a, (x)
                                    201 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 110: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x40) != (uint8_t)0x00) /* Pull-Up or Push-Pull */
      0083D9 88               [ 1]  202 	push	a
      0083DA 7B 0C            [ 1]  203 	ld	a, (0x0c, sp)
      0083DC A5 40            [ 1]  204 	bcp	a, #0x40
      0083DE 84               [ 1]  205 	pop	a
      0083DF 27 05            [ 1]  206 	jreq	00108$
                                    207 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      0083E1 1A 0A            [ 1]  208 	or	a, (0x0a, sp)
      0083E3 F7               [ 1]  209 	ld	(x), a
      0083E4 20 03            [ 2]  210 	jra	00109$
      0083E6                        211 00108$:
                                    212 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 116: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      0083E6 14 01            [ 1]  213 	and	a, (0x01, sp)
      0083E8 F7               [ 1]  214 	ld	(x), a
      0083E9                        215 00109$:
                                    216 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      0083E9 1E 04            [ 2]  217 	ldw	x, (0x04, sp)
      0083EB F6               [ 1]  218 	ld	a, (x)
                                    219 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 123: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x20) != (uint8_t)0x00) /* Interrupt or Slow slope */
      0083EC 88               [ 1]  220 	push	a
      0083ED 7B 0C            [ 1]  221 	ld	a, (0x0c, sp)
      0083EF A5 20            [ 1]  222 	bcp	a, #0x20
      0083F1 84               [ 1]  223 	pop	a
      0083F2 27 07            [ 1]  224 	jreq	00111$
                                    225 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 125: GPIOx->CR2 |= (uint8_t)GPIO_Pin;
      0083F4 1A 0A            [ 1]  226 	or	a, (0x0a, sp)
      0083F6 1E 04            [ 2]  227 	ldw	x, (0x04, sp)
      0083F8 F7               [ 1]  228 	ld	(x), a
      0083F9 20 05            [ 2]  229 	jra	00113$
      0083FB                        230 00111$:
                                    231 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 129: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      0083FB 14 01            [ 1]  232 	and	a, (0x01, sp)
      0083FD 1E 04            [ 2]  233 	ldw	x, (0x04, sp)
      0083FF F7               [ 1]  234 	ld	(x), a
      008400                        235 00113$:
                                    236 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 131: }
      008400 5B 05            [ 2]  237 	addw	sp, #5
      008402 81               [ 4]  238 	ret
                                    239 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 141: void GPIO_Write(GPIO_TypeDef* GPIOx, uint8_t PortVal)
                                    240 ;	-----------------------------------------
                                    241 ;	 function GPIO_Write
                                    242 ;	-----------------------------------------
      008403                        243 _GPIO_Write:
                                    244 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 143: GPIOx->ODR = PortVal;
      008403 1E 03            [ 2]  245 	ldw	x, (0x03, sp)
      008405 7B 05            [ 1]  246 	ld	a, (0x05, sp)
      008407 F7               [ 1]  247 	ld	(x), a
                                    248 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 144: }
      008408 81               [ 4]  249 	ret
                                    250 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 154: void GPIO_WriteHigh(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    251 ;	-----------------------------------------
                                    252 ;	 function GPIO_WriteHigh
                                    253 ;	-----------------------------------------
      008409                        254 _GPIO_WriteHigh:
                                    255 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 156: GPIOx->ODR |= (uint8_t)PortPins;
      008409 1E 03            [ 2]  256 	ldw	x, (0x03, sp)
      00840B F6               [ 1]  257 	ld	a, (x)
      00840C 1A 05            [ 1]  258 	or	a, (0x05, sp)
      00840E F7               [ 1]  259 	ld	(x), a
                                    260 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 157: }
      00840F 81               [ 4]  261 	ret
                                    262 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 167: void GPIO_WriteLow(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    263 ;	-----------------------------------------
                                    264 ;	 function GPIO_WriteLow
                                    265 ;	-----------------------------------------
      008410                        266 _GPIO_WriteLow:
      008410 88               [ 1]  267 	push	a
                                    268 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 169: GPIOx->ODR &= (uint8_t)(~PortPins);
      008411 1E 04            [ 2]  269 	ldw	x, (0x04, sp)
      008413 F6               [ 1]  270 	ld	a, (x)
      008414 6B 01            [ 1]  271 	ld	(0x01, sp), a
      008416 7B 06            [ 1]  272 	ld	a, (0x06, sp)
      008418 43               [ 1]  273 	cpl	a
      008419 14 01            [ 1]  274 	and	a, (0x01, sp)
      00841B F7               [ 1]  275 	ld	(x), a
                                    276 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 170: }
      00841C 84               [ 1]  277 	pop	a
      00841D 81               [ 4]  278 	ret
                                    279 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 180: void GPIO_WriteReverse(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    280 ;	-----------------------------------------
                                    281 ;	 function GPIO_WriteReverse
                                    282 ;	-----------------------------------------
      00841E                        283 _GPIO_WriteReverse:
                                    284 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 182: GPIOx->ODR ^= (uint8_t)PortPins;
      00841E 1E 03            [ 2]  285 	ldw	x, (0x03, sp)
      008420 F6               [ 1]  286 	ld	a, (x)
      008421 18 05            [ 1]  287 	xor	a, (0x05, sp)
      008423 F7               [ 1]  288 	ld	(x), a
                                    289 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 183: }
      008424 81               [ 4]  290 	ret
                                    291 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 191: uint8_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
                                    292 ;	-----------------------------------------
                                    293 ;	 function GPIO_ReadOutputData
                                    294 ;	-----------------------------------------
      008425                        295 _GPIO_ReadOutputData:
                                    296 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 193: return ((uint8_t)GPIOx->ODR);
      008425 1E 03            [ 2]  297 	ldw	x, (0x03, sp)
      008427 F6               [ 1]  298 	ld	a, (x)
                                    299 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 194: }
      008428 81               [ 4]  300 	ret
                                    301 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 202: uint8_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
                                    302 ;	-----------------------------------------
                                    303 ;	 function GPIO_ReadInputData
                                    304 ;	-----------------------------------------
      008429                        305 _GPIO_ReadInputData:
                                    306 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 204: return ((uint8_t)GPIOx->IDR);
      008429 1E 03            [ 2]  307 	ldw	x, (0x03, sp)
      00842B E6 01            [ 1]  308 	ld	a, (0x1, x)
                                    309 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 205: }
      00842D 81               [ 4]  310 	ret
                                    311 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 213: BitStatus GPIO_ReadInputPin(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
                                    312 ;	-----------------------------------------
                                    313 ;	 function GPIO_ReadInputPin
                                    314 ;	-----------------------------------------
      00842E                        315 _GPIO_ReadInputPin:
                                    316 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 215: return ((BitStatus)(GPIOx->IDR & (uint8_t)GPIO_Pin));
      00842E 1E 03            [ 2]  317 	ldw	x, (0x03, sp)
      008430 E6 01            [ 1]  318 	ld	a, (0x1, x)
      008432 14 05            [ 1]  319 	and	a, (0x05, sp)
                                    320 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 216: }
      008434 81               [ 4]  321 	ret
                                    322 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 225: void GPIO_ExternalPullUpConfig(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, FunctionalState NewState)
                                    323 ;	-----------------------------------------
                                    324 ;	 function GPIO_ExternalPullUpConfig
                                    325 ;	-----------------------------------------
      008435                        326 _GPIO_ExternalPullUpConfig:
      008435 88               [ 1]  327 	push	a
                                    328 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 228: assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
      008436 0D 06            [ 1]  329 	tnz	(0x06, sp)
      008438 26 0F            [ 1]  330 	jrne	00107$
      00843A 4B E4            [ 1]  331 	push	#0xe4
      00843C 5F               [ 1]  332 	clrw	x
      00843D 89               [ 2]  333 	pushw	x
      00843E 4B 00            [ 1]  334 	push	#0x00
      008440 4B A5            [ 1]  335 	push	#<___str_0
      008442 4B 80            [ 1]  336 	push	#(___str_0 >> 8)
      008444 CD 83 14         [ 4]  337 	call	_assert_failed
      008447 5B 06            [ 2]  338 	addw	sp, #6
      008449                        339 00107$:
                                    340 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 229: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008449 0D 07            [ 1]  341 	tnz	(0x07, sp)
      00844B 27 14            [ 1]  342 	jreq	00109$
      00844D 7B 07            [ 1]  343 	ld	a, (0x07, sp)
      00844F 4A               [ 1]  344 	dec	a
      008450 27 0F            [ 1]  345 	jreq	00109$
      008452 4B E5            [ 1]  346 	push	#0xe5
      008454 5F               [ 1]  347 	clrw	x
      008455 89               [ 2]  348 	pushw	x
      008456 4B 00            [ 1]  349 	push	#0x00
      008458 4B A5            [ 1]  350 	push	#<___str_0
      00845A 4B 80            [ 1]  351 	push	#(___str_0 >> 8)
      00845C CD 83 14         [ 4]  352 	call	_assert_failed
      00845F 5B 06            [ 2]  353 	addw	sp, #6
      008461                        354 00109$:
                                    355 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008461 1E 04            [ 2]  356 	ldw	x, (0x04, sp)
      008463 1C 00 03         [ 2]  357 	addw	x, #0x0003
      008466 F6               [ 1]  358 	ld	a, (x)
                                    359 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 231: if (NewState != DISABLE) /* External Pull-Up Set*/
      008467 0D 07            [ 1]  360 	tnz	(0x07, sp)
      008469 27 05            [ 1]  361 	jreq	00102$
                                    362 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      00846B 1A 06            [ 1]  363 	or	a, (0x06, sp)
      00846D F7               [ 1]  364 	ld	(x), a
      00846E 20 0A            [ 2]  365 	jra	00104$
      008470                        366 00102$:
                                    367 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 236: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      008470 88               [ 1]  368 	push	a
      008471 7B 07            [ 1]  369 	ld	a, (0x07, sp)
      008473 43               [ 1]  370 	cpl	a
      008474 6B 02            [ 1]  371 	ld	(0x02, sp), a
      008476 84               [ 1]  372 	pop	a
      008477 14 01            [ 1]  373 	and	a, (0x01, sp)
      008479 F7               [ 1]  374 	ld	(x), a
      00847A                        375 00104$:
                                    376 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c: 238: }
      00847A 84               [ 1]  377 	pop	a
      00847B 81               [ 4]  378 	ret
                                    379 	.area CODE
                                    380 	.area CONST
      0080A5                        381 ___str_0:
      0080A5 2E 2E 2F 2E 2E 2F 2E   382 	.ascii "../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_gpio.c"
             2E 2F 4C 69 62 72 61
             72 69 65 73 2F 53 54
             4D 38 53 5F 53 74 64
             50 65 72 69 70 68 5F
             44 72 69 76 65 72 2F
             73 72 63 2F 73 74 6D
             38 73 5F 67 70 69 6F
             2E 63
      0080DF 00                     383 	.db 0x00
                                    384 	.area INITIALIZER
                                    385 	.area CABS (ABS)
