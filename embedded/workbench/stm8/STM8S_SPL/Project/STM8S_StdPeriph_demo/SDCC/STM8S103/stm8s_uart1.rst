                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_uart1
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _assert_failed
                                     12 	.globl _CLK_GetClockFreq
                                     13 	.globl _UART1_DeInit
                                     14 	.globl _UART1_Init
                                     15 	.globl _UART1_Cmd
                                     16 	.globl _UART1_ITConfig
                                     17 	.globl _UART1_HalfDuplexCmd
                                     18 	.globl _UART1_IrDAConfig
                                     19 	.globl _UART1_IrDACmd
                                     20 	.globl _UART1_LINBreakDetectionConfig
                                     21 	.globl _UART1_LINCmd
                                     22 	.globl _UART1_SmartCardCmd
                                     23 	.globl _UART1_SmartCardNACKCmd
                                     24 	.globl _UART1_WakeUpConfig
                                     25 	.globl _UART1_ReceiverWakeUpCmd
                                     26 	.globl _UART1_ReceiveData8
                                     27 	.globl _UART1_ReceiveData9
                                     28 	.globl _UART1_SendData8
                                     29 	.globl _UART1_SendData9
                                     30 	.globl _UART1_SendBreak
                                     31 	.globl _UART1_SetAddress
                                     32 	.globl _UART1_SetGuardTime
                                     33 	.globl _UART1_SetPrescaler
                                     34 	.globl _UART1_GetFlagStatus
                                     35 	.globl _UART1_ClearFlag
                                     36 	.globl _UART1_GetITStatus
                                     37 	.globl _UART1_ClearITPendingBit
                                     38 ;--------------------------------------------------------
                                     39 ; ram data
                                     40 ;--------------------------------------------------------
                                     41 	.area DATA
                                     42 ;--------------------------------------------------------
                                     43 ; ram data
                                     44 ;--------------------------------------------------------
                                     45 	.area INITIALIZED
                                     46 ;--------------------------------------------------------
                                     47 ; absolute external ram data
                                     48 ;--------------------------------------------------------
                                     49 	.area DABS (ABS)
                                     50 
                                     51 ; default segment ordering for linker
                                     52 	.area HOME
                                     53 	.area GSINIT
                                     54 	.area GSFINAL
                                     55 	.area CONST
                                     56 	.area INITIALIZER
                                     57 	.area CODE
                                     58 
                                     59 ;--------------------------------------------------------
                                     60 ; global & static initialisations
                                     61 ;--------------------------------------------------------
                                     62 	.area HOME
                                     63 	.area GSINIT
                                     64 	.area GSFINAL
                                     65 	.area GSINIT
                                     66 ;--------------------------------------------------------
                                     67 ; Home
                                     68 ;--------------------------------------------------------
                                     69 	.area HOME
                                     70 	.area HOME
                                     71 ;--------------------------------------------------------
                                     72 ; code
                                     73 ;--------------------------------------------------------
                                     74 	.area CODE
                                     75 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 53: void UART1_DeInit(void)
                                     76 ;	-----------------------------------------
                                     77 ;	 function UART1_DeInit
                                     78 ;	-----------------------------------------
      00907D                         79 _UART1_DeInit:
                                     80 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 57: (void)UART1->SR;
      00907D C6 52 30         [ 1]   81 	ld	a, 0x5230
                                     82 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 58: (void)UART1->DR;
      009080 C6 52 31         [ 1]   83 	ld	a, 0x5231
                                     84 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 60: UART1->BRR2 = UART1_BRR2_RESET_VALUE;  /* Set UART1_BRR2 to reset value 0x00 */
      009083 35 00 52 33      [ 1]   85 	mov	0x5233+0, #0x00
                                     86 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 61: UART1->BRR1 = UART1_BRR1_RESET_VALUE;  /* Set UART1_BRR1 to reset value 0x00 */
      009087 35 00 52 32      [ 1]   87 	mov	0x5232+0, #0x00
                                     88 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 63: UART1->CR1 = UART1_CR1_RESET_VALUE;  /* Set UART1_CR1 to reset value 0x00 */
      00908B 35 00 52 34      [ 1]   89 	mov	0x5234+0, #0x00
                                     90 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 64: UART1->CR2 = UART1_CR2_RESET_VALUE;  /* Set UART1_CR2 to reset value 0x00 */
      00908F 35 00 52 35      [ 1]   91 	mov	0x5235+0, #0x00
                                     92 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 65: UART1->CR3 = UART1_CR3_RESET_VALUE;  /* Set UART1_CR3 to reset value 0x00 */
      009093 35 00 52 36      [ 1]   93 	mov	0x5236+0, #0x00
                                     94 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 66: UART1->CR4 = UART1_CR4_RESET_VALUE;  /* Set UART1_CR4 to reset value 0x00 */
      009097 35 00 52 37      [ 1]   95 	mov	0x5237+0, #0x00
                                     96 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 67: UART1->CR5 = UART1_CR5_RESET_VALUE;  /* Set UART1_CR5 to reset value 0x00 */
      00909B 35 00 52 38      [ 1]   97 	mov	0x5238+0, #0x00
                                     98 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 69: UART1->GTR = UART1_GTR_RESET_VALUE;
      00909F 35 00 52 39      [ 1]   99 	mov	0x5239+0, #0x00
                                    100 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 70: UART1->PSCR = UART1_PSCR_RESET_VALUE;
      0090A3 35 00 52 3A      [ 1]  101 	mov	0x523a+0, #0x00
                                    102 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 71: }
      0090A7 81               [ 4]  103 	ret
                                    104 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 90: void UART1_Init(uint32_t BaudRate, UART1_WordLength_TypeDef WordLength, 
                                    105 ;	-----------------------------------------
                                    106 ;	 function UART1_Init
                                    107 ;	-----------------------------------------
      0090A8                        108 _UART1_Init:
      0090A8 52 1D            [ 2]  109 	sub	sp, #29
                                    110 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 97: assert_param(IS_UART1_BAUDRATE_OK(BaudRate));
      0090AA AE 89 68         [ 2]  111 	ldw	x, #0x8968
      0090AD 13 22            [ 2]  112 	cpw	x, (0x22, sp)
      0090AF A6 09            [ 1]  113 	ld	a, #0x09
      0090B1 12 21            [ 1]  114 	sbc	a, (0x21, sp)
      0090B3 4F               [ 1]  115 	clr	a
      0090B4 12 20            [ 1]  116 	sbc	a, (0x20, sp)
      0090B6 24 0F            [ 1]  117 	jrnc	00113$
      0090B8 4B 61            [ 1]  118 	push	#0x61
      0090BA 5F               [ 1]  119 	clrw	x
      0090BB 89               [ 2]  120 	pushw	x
      0090BC 4B 00            [ 1]  121 	push	#0x00
      0090BE 4B 62            [ 1]  122 	push	#<___str_0
      0090C0 4B 81            [ 1]  123 	push	#(___str_0 >> 8)
      0090C2 CD 83 14         [ 4]  124 	call	_assert_failed
      0090C5 5B 06            [ 2]  125 	addw	sp, #6
      0090C7                        126 00113$:
                                    127 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 98: assert_param(IS_UART1_WORDLENGTH_OK(WordLength));
      0090C7 0D 24            [ 1]  128 	tnz	(0x24, sp)
      0090C9 27 15            [ 1]  129 	jreq	00115$
      0090CB 7B 24            [ 1]  130 	ld	a, (0x24, sp)
      0090CD A1 10            [ 1]  131 	cp	a, #0x10
      0090CF 27 0F            [ 1]  132 	jreq	00115$
      0090D1 4B 62            [ 1]  133 	push	#0x62
      0090D3 5F               [ 1]  134 	clrw	x
      0090D4 89               [ 2]  135 	pushw	x
      0090D5 4B 00            [ 1]  136 	push	#0x00
      0090D7 4B 62            [ 1]  137 	push	#<___str_0
      0090D9 4B 81            [ 1]  138 	push	#(___str_0 >> 8)
      0090DB CD 83 14         [ 4]  139 	call	_assert_failed
      0090DE 5B 06            [ 2]  140 	addw	sp, #6
      0090E0                        141 00115$:
                                    142 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 99: assert_param(IS_UART1_STOPBITS_OK(StopBits));
      0090E0 0D 25            [ 1]  143 	tnz	(0x25, sp)
      0090E2 27 21            [ 1]  144 	jreq	00120$
      0090E4 7B 25            [ 1]  145 	ld	a, (0x25, sp)
      0090E6 A1 10            [ 1]  146 	cp	a, #0x10
      0090E8 27 1B            [ 1]  147 	jreq	00120$
      0090EA 7B 25            [ 1]  148 	ld	a, (0x25, sp)
      0090EC A1 20            [ 1]  149 	cp	a, #0x20
      0090EE 27 15            [ 1]  150 	jreq	00120$
      0090F0 7B 25            [ 1]  151 	ld	a, (0x25, sp)
      0090F2 A1 30            [ 1]  152 	cp	a, #0x30
      0090F4 27 0F            [ 1]  153 	jreq	00120$
      0090F6 4B 63            [ 1]  154 	push	#0x63
      0090F8 5F               [ 1]  155 	clrw	x
      0090F9 89               [ 2]  156 	pushw	x
      0090FA 4B 00            [ 1]  157 	push	#0x00
      0090FC 4B 62            [ 1]  158 	push	#<___str_0
      0090FE 4B 81            [ 1]  159 	push	#(___str_0 >> 8)
      009100 CD 83 14         [ 4]  160 	call	_assert_failed
      009103 5B 06            [ 2]  161 	addw	sp, #6
      009105                        162 00120$:
                                    163 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 100: assert_param(IS_UART1_PARITY_OK(Parity));
      009105 0D 26            [ 1]  164 	tnz	(0x26, sp)
      009107 27 1B            [ 1]  165 	jreq	00131$
      009109 7B 26            [ 1]  166 	ld	a, (0x26, sp)
      00910B A1 04            [ 1]  167 	cp	a, #0x04
      00910D 27 15            [ 1]  168 	jreq	00131$
      00910F 7B 26            [ 1]  169 	ld	a, (0x26, sp)
      009111 A1 06            [ 1]  170 	cp	a, #0x06
      009113 27 0F            [ 1]  171 	jreq	00131$
      009115 4B 64            [ 1]  172 	push	#0x64
      009117 5F               [ 1]  173 	clrw	x
      009118 89               [ 2]  174 	pushw	x
      009119 4B 00            [ 1]  175 	push	#0x00
      00911B 4B 62            [ 1]  176 	push	#<___str_0
      00911D 4B 81            [ 1]  177 	push	#(___str_0 >> 8)
      00911F CD 83 14         [ 4]  178 	call	_assert_failed
      009122 5B 06            [ 2]  179 	addw	sp, #6
      009124                        180 00131$:
                                    181 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 101: assert_param(IS_UART1_MODE_OK((uint8_t)Mode));
      009124 7B 28            [ 1]  182 	ld	a, (0x28, sp)
      009126 A1 08            [ 1]  183 	cp	a, #0x08
      009128 27 42            [ 1]  184 	jreq	00139$
      00912A 7B 28            [ 1]  185 	ld	a, (0x28, sp)
      00912C A1 40            [ 1]  186 	cp	a, #0x40
      00912E 27 3C            [ 1]  187 	jreq	00139$
      009130 7B 28            [ 1]  188 	ld	a, (0x28, sp)
      009132 A1 04            [ 1]  189 	cp	a, #0x04
      009134 27 36            [ 1]  190 	jreq	00139$
      009136 7B 28            [ 1]  191 	ld	a, (0x28, sp)
      009138 A1 80            [ 1]  192 	cp	a, #0x80
      00913A 27 30            [ 1]  193 	jreq	00139$
      00913C 7B 28            [ 1]  194 	ld	a, (0x28, sp)
      00913E A0 0C            [ 1]  195 	sub	a, #0x0c
      009140 26 02            [ 1]  196 	jrne	00339$
      009142 4C               [ 1]  197 	inc	a
      009143 21                     198 	.byte 0x21
      009144                        199 00339$:
      009144 4F               [ 1]  200 	clr	a
      009145                        201 00340$:
      009145 4D               [ 1]  202 	tnz	a
      009146 26 24            [ 1]  203 	jrne	00139$
      009148 4D               [ 1]  204 	tnz	a
      009149 26 21            [ 1]  205 	jrne	00139$
      00914B 7B 28            [ 1]  206 	ld	a, (0x28, sp)
      00914D A1 44            [ 1]  207 	cp	a, #0x44
      00914F 27 1B            [ 1]  208 	jreq	00139$
      009151 7B 28            [ 1]  209 	ld	a, (0x28, sp)
      009153 A1 C0            [ 1]  210 	cp	a, #0xc0
      009155 27 15            [ 1]  211 	jreq	00139$
      009157 7B 28            [ 1]  212 	ld	a, (0x28, sp)
      009159 A1 88            [ 1]  213 	cp	a, #0x88
      00915B 27 0F            [ 1]  214 	jreq	00139$
      00915D 4B 65            [ 1]  215 	push	#0x65
      00915F 5F               [ 1]  216 	clrw	x
      009160 89               [ 2]  217 	pushw	x
      009161 4B 00            [ 1]  218 	push	#0x00
      009163 4B 62            [ 1]  219 	push	#<___str_0
      009165 4B 81            [ 1]  220 	push	#(___str_0 >> 8)
      009167 CD 83 14         [ 4]  221 	call	_assert_failed
      00916A 5B 06            [ 2]  222 	addw	sp, #6
      00916C                        223 00139$:
                                    224 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 102: assert_param(IS_UART1_SYNCMODE_OK((uint8_t)SyncMode));
      00916C 7B 27            [ 1]  225 	ld	a, (0x27, sp)
      00916E A4 88            [ 1]  226 	and	a, #0x88
      009170 A1 88            [ 1]  227 	cp	a, #0x88
      009172 27 18            [ 1]  228 	jreq	00167$
      009174 7B 27            [ 1]  229 	ld	a, (0x27, sp)
      009176 A4 44            [ 1]  230 	and	a, #0x44
      009178 A1 44            [ 1]  231 	cp	a, #0x44
      00917A 27 10            [ 1]  232 	jreq	00167$
      00917C 7B 27            [ 1]  233 	ld	a, (0x27, sp)
      00917E A4 22            [ 1]  234 	and	a, #0x22
      009180 A1 22            [ 1]  235 	cp	a, #0x22
      009182 27 08            [ 1]  236 	jreq	00167$
      009184 7B 27            [ 1]  237 	ld	a, (0x27, sp)
      009186 A4 11            [ 1]  238 	and	a, #0x11
      009188 A1 11            [ 1]  239 	cp	a, #0x11
      00918A 26 0F            [ 1]  240 	jrne	00165$
      00918C                        241 00167$:
      00918C 4B 66            [ 1]  242 	push	#0x66
      00918E 5F               [ 1]  243 	clrw	x
      00918F 89               [ 2]  244 	pushw	x
      009190 4B 00            [ 1]  245 	push	#0x00
      009192 4B 62            [ 1]  246 	push	#<___str_0
      009194 4B 81            [ 1]  247 	push	#(___str_0 >> 8)
      009196 CD 83 14         [ 4]  248 	call	_assert_failed
      009199 5B 06            [ 2]  249 	addw	sp, #6
      00919B                        250 00165$:
                                    251 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 105: UART1->CR1 &= (uint8_t)(~UART1_CR1_M);  
      00919B 72 19 52 34      [ 1]  252 	bres	21044, #4
                                    253 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 108: UART1->CR1 |= (uint8_t)WordLength;
      00919F C6 52 34         [ 1]  254 	ld	a, 0x5234
      0091A2 1A 24            [ 1]  255 	or	a, (0x24, sp)
      0091A4 C7 52 34         [ 1]  256 	ld	0x5234, a
                                    257 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 111: UART1->CR3 &= (uint8_t)(~UART1_CR3_STOP);  
      0091A7 C6 52 36         [ 1]  258 	ld	a, 0x5236
      0091AA A4 CF            [ 1]  259 	and	a, #0xcf
      0091AC C7 52 36         [ 1]  260 	ld	0x5236, a
                                    261 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 113: UART1->CR3 |= (uint8_t)StopBits;  
      0091AF C6 52 36         [ 1]  262 	ld	a, 0x5236
      0091B2 1A 25            [ 1]  263 	or	a, (0x25, sp)
      0091B4 C7 52 36         [ 1]  264 	ld	0x5236, a
                                    265 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 116: UART1->CR1 &= (uint8_t)(~(UART1_CR1_PCEN | UART1_CR1_PS  ));  
      0091B7 C6 52 34         [ 1]  266 	ld	a, 0x5234
      0091BA A4 F9            [ 1]  267 	and	a, #0xf9
      0091BC C7 52 34         [ 1]  268 	ld	0x5234, a
                                    269 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 118: UART1->CR1 |= (uint8_t)Parity;  
      0091BF C6 52 34         [ 1]  270 	ld	a, 0x5234
      0091C2 1A 26            [ 1]  271 	or	a, (0x26, sp)
      0091C4 C7 52 34         [ 1]  272 	ld	0x5234, a
                                    273 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 121: UART1->BRR1 &= (uint8_t)(~UART1_BRR1_DIVM);  
      0091C7 C6 52 32         [ 1]  274 	ld	a, 0x5232
      0091CA 35 00 52 32      [ 1]  275 	mov	0x5232+0, #0x00
                                    276 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 123: UART1->BRR2 &= (uint8_t)(~UART1_BRR2_DIVM);  
      0091CE C6 52 33         [ 1]  277 	ld	a, 0x5233
      0091D1 A4 0F            [ 1]  278 	and	a, #0x0f
      0091D3 C7 52 33         [ 1]  279 	ld	0x5233, a
                                    280 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 125: UART1->BRR2 &= (uint8_t)(~UART1_BRR2_DIVF);  
      0091D6 C6 52 33         [ 1]  281 	ld	a, 0x5233
      0091D9 A4 F0            [ 1]  282 	and	a, #0xf0
      0091DB C7 52 33         [ 1]  283 	ld	0x5233, a
                                    284 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 128: BaudRate_Mantissa    = ((uint32_t)CLK_GetClockFreq() / (BaudRate << 4));
      0091DE CD 89 9E         [ 4]  285 	call	_CLK_GetClockFreq
      0091E1 1F 10            [ 2]  286 	ldw	(0x10, sp), x
      0091E3 1E 20            [ 2]  287 	ldw	x, (0x20, sp)
      0091E5 1F 12            [ 2]  288 	ldw	(0x12, sp), x
      0091E7 1E 22            [ 2]  289 	ldw	x, (0x22, sp)
      0091E9 A6 04            [ 1]  290 	ld	a, #0x04
      0091EB                        291 00364$:
      0091EB 58               [ 2]  292 	sllw	x
      0091EC 09 13            [ 1]  293 	rlc	(0x13, sp)
      0091EE 09 12            [ 1]  294 	rlc	(0x12, sp)
      0091F0 4A               [ 1]  295 	dec	a
      0091F1 26 F8            [ 1]  296 	jrne	00364$
      0091F3 1F 14            [ 2]  297 	ldw	(0x14, sp), x
      0091F5 89               [ 2]  298 	pushw	x
      0091F6 1E 14            [ 2]  299 	ldw	x, (0x14, sp)
      0091F8 89               [ 2]  300 	pushw	x
      0091F9 1E 14            [ 2]  301 	ldw	x, (0x14, sp)
      0091FB 89               [ 2]  302 	pushw	x
      0091FC 90 89            [ 2]  303 	pushw	y
      0091FE CD 9A BE         [ 4]  304 	call	__divulong
      009201 5B 08            [ 2]  305 	addw	sp, #8
      009203 1F 1C            [ 2]  306 	ldw	(0x1c, sp), x
      009205 17 1A            [ 2]  307 	ldw	(0x1a, sp), y
                                    308 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 129: BaudRate_Mantissa100 = (((uint32_t)CLK_GetClockFreq() * 100) / (BaudRate << 4));
      009207 CD 89 9E         [ 4]  309 	call	_CLK_GetClockFreq
      00920A 89               [ 2]  310 	pushw	x
      00920B 90 89            [ 2]  311 	pushw	y
      00920D 4B 64            [ 1]  312 	push	#0x64
      00920F 5F               [ 1]  313 	clrw	x
      009210 89               [ 2]  314 	pushw	x
      009211 4B 00            [ 1]  315 	push	#0x00
      009213 CD 9B 4B         [ 4]  316 	call	__mullong
      009216 5B 08            [ 2]  317 	addw	sp, #8
      009218 1F 07            [ 2]  318 	ldw	(0x07, sp), x
      00921A 1E 14            [ 2]  319 	ldw	x, (0x14, sp)
      00921C 89               [ 2]  320 	pushw	x
      00921D 1E 14            [ 2]  321 	ldw	x, (0x14, sp)
      00921F 89               [ 2]  322 	pushw	x
      009220 1E 0B            [ 2]  323 	ldw	x, (0x0b, sp)
      009222 89               [ 2]  324 	pushw	x
      009223 90 89            [ 2]  325 	pushw	y
      009225 CD 9A BE         [ 4]  326 	call	__divulong
      009228 5B 08            [ 2]  327 	addw	sp, #8
      00922A 90 9E            [ 1]  328 	ld	a, yh
      00922C 1F 18            [ 2]  329 	ldw	(0x18, sp), x
      00922E 6B 16            [ 1]  330 	ld	(0x16, sp), a
      009230 90 9F            [ 1]  331 	ld	a, yl
                                    332 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 131: UART1->BRR2 |= (uint8_t)((uint8_t)(((BaudRate_Mantissa100 - (BaudRate_Mantissa * 100)) << 4) / 100) & (uint8_t)0x0F); 
      009232 AE 52 33         [ 2]  333 	ldw	x, #0x5233
      009235 88               [ 1]  334 	push	a
      009236 F6               [ 1]  335 	ld	a, (x)
      009237 6B 0E            [ 1]  336 	ld	(0x0e, sp), a
      009239 1E 1D            [ 2]  337 	ldw	x, (0x1d, sp)
      00923B 89               [ 2]  338 	pushw	x
      00923C 1E 1D            [ 2]  339 	ldw	x, (0x1d, sp)
      00923E 89               [ 2]  340 	pushw	x
      00923F 4B 64            [ 1]  341 	push	#0x64
      009241 5F               [ 1]  342 	clrw	x
      009242 89               [ 2]  343 	pushw	x
      009243 4B 00            [ 1]  344 	push	#0x00
      009245 CD 9B 4B         [ 4]  345 	call	__mullong
      009248 5B 08            [ 2]  346 	addw	sp, #8
      00924A 1F 0C            [ 2]  347 	ldw	(0x0c, sp), x
      00924C 17 0A            [ 2]  348 	ldw	(0x0a, sp), y
      00924E 84               [ 1]  349 	pop	a
      00924F 16 18            [ 2]  350 	ldw	y, (0x18, sp)
      009251 72 F2 0B         [ 2]  351 	subw	y, (0x0b, sp)
      009254 12 0A            [ 1]  352 	sbc	a, (0x0a, sp)
      009256 97               [ 1]  353 	ld	xl, a
      009257 7B 16            [ 1]  354 	ld	a, (0x16, sp)
      009259 12 09            [ 1]  355 	sbc	a, (0x09, sp)
      00925B 95               [ 1]  356 	ld	xh, a
      00925C A6 04            [ 1]  357 	ld	a, #0x04
      00925E                        358 00366$:
      00925E 90 58            [ 2]  359 	sllw	y
      009260 59               [ 2]  360 	rlcw	x
      009261 4A               [ 1]  361 	dec	a
      009262 26 FA            [ 1]  362 	jrne	00366$
      009264 4B 64            [ 1]  363 	push	#0x64
      009266 4B 00            [ 1]  364 	push	#0x00
      009268 4B 00            [ 1]  365 	push	#0x00
      00926A 4B 00            [ 1]  366 	push	#0x00
      00926C 90 89            [ 2]  367 	pushw	y
      00926E 89               [ 2]  368 	pushw	x
      00926F CD 9A BE         [ 4]  369 	call	__divulong
      009272 5B 08            [ 2]  370 	addw	sp, #8
      009274 9F               [ 1]  371 	ld	a, xl
      009275 A4 0F            [ 1]  372 	and	a, #0x0f
      009277 1A 0D            [ 1]  373 	or	a, (0x0d, sp)
      009279 C7 52 33         [ 1]  374 	ld	0x5233, a
                                    375 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 133: UART1->BRR2 |= (uint8_t)((BaudRate_Mantissa >> 4) & (uint8_t)0xF0); 
      00927C C6 52 33         [ 1]  376 	ld	a, 0x5233
      00927F 6B 04            [ 1]  377 	ld	(0x04, sp), a
      009281 1E 1C            [ 2]  378 	ldw	x, (0x1c, sp)
      009283 A6 10            [ 1]  379 	ld	a, #0x10
      009285 62               [ 2]  380 	div	x, a
      009286 9F               [ 1]  381 	ld	a, xl
      009287 A4 F0            [ 1]  382 	and	a, #0xf0
      009289 1A 04            [ 1]  383 	or	a, (0x04, sp)
      00928B C7 52 33         [ 1]  384 	ld	0x5233, a
                                    385 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 135: UART1->BRR1 |= (uint8_t)BaudRate_Mantissa;           
      00928E C6 52 32         [ 1]  386 	ld	a, 0x5232
      009291 6B 03            [ 1]  387 	ld	(0x03, sp), a
      009293 7B 1D            [ 1]  388 	ld	a, (0x1d, sp)
      009295 1A 03            [ 1]  389 	or	a, (0x03, sp)
      009297 C7 52 32         [ 1]  390 	ld	0x5232, a
                                    391 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 138: UART1->CR2 &= (uint8_t)~(UART1_CR2_TEN | UART1_CR2_REN); 
      00929A C6 52 35         [ 1]  392 	ld	a, 0x5235
      00929D A4 F3            [ 1]  393 	and	a, #0xf3
      00929F C7 52 35         [ 1]  394 	ld	0x5235, a
                                    395 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 140: UART1->CR3 &= (uint8_t)~(UART1_CR3_CPOL | UART1_CR3_CPHA | UART1_CR3_LBCL); 
      0092A2 C6 52 36         [ 1]  396 	ld	a, 0x5236
      0092A5 A4 F8            [ 1]  397 	and	a, #0xf8
      0092A7 C7 52 36         [ 1]  398 	ld	0x5236, a
                                    399 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 142: UART1->CR3 |= (uint8_t)((uint8_t)SyncMode & (uint8_t)(UART1_CR3_CPOL | 
      0092AA C6 52 36         [ 1]  400 	ld	a, 0x5236
      0092AD 6B 02            [ 1]  401 	ld	(0x02, sp), a
      0092AF 7B 27            [ 1]  402 	ld	a, (0x27, sp)
      0092B1 A4 07            [ 1]  403 	and	a, #0x07
      0092B3 1A 02            [ 1]  404 	or	a, (0x02, sp)
      0092B5 C7 52 36         [ 1]  405 	ld	0x5236, a
                                    406 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 138: UART1->CR2 &= (uint8_t)~(UART1_CR2_TEN | UART1_CR2_REN); 
      0092B8 C6 52 35         [ 1]  407 	ld	a, 0x5235
                                    408 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 145: if ((uint8_t)(Mode & UART1_MODE_TX_ENABLE))
      0092BB 88               [ 1]  409 	push	a
      0092BC 7B 29            [ 1]  410 	ld	a, (0x29, sp)
      0092BE A5 04            [ 1]  411 	bcp	a, #0x04
      0092C0 84               [ 1]  412 	pop	a
      0092C1 27 07            [ 1]  413 	jreq	00102$
                                    414 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 148: UART1->CR2 |= (uint8_t)UART1_CR2_TEN;  
      0092C3 AA 08            [ 1]  415 	or	a, #0x08
      0092C5 C7 52 35         [ 1]  416 	ld	0x5235, a
      0092C8 20 05            [ 2]  417 	jra	00103$
      0092CA                        418 00102$:
                                    419 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 153: UART1->CR2 &= (uint8_t)(~UART1_CR2_TEN);  
      0092CA A4 F7            [ 1]  420 	and	a, #0xf7
      0092CC C7 52 35         [ 1]  421 	ld	0x5235, a
      0092CF                        422 00103$:
                                    423 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 138: UART1->CR2 &= (uint8_t)~(UART1_CR2_TEN | UART1_CR2_REN); 
      0092CF C6 52 35         [ 1]  424 	ld	a, 0x5235
                                    425 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 155: if ((uint8_t)(Mode & UART1_MODE_RX_ENABLE))
      0092D2 88               [ 1]  426 	push	a
      0092D3 7B 29            [ 1]  427 	ld	a, (0x29, sp)
      0092D5 A5 08            [ 1]  428 	bcp	a, #0x08
      0092D7 84               [ 1]  429 	pop	a
      0092D8 27 07            [ 1]  430 	jreq	00105$
                                    431 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 158: UART1->CR2 |= (uint8_t)UART1_CR2_REN;  
      0092DA AA 04            [ 1]  432 	or	a, #0x04
      0092DC C7 52 35         [ 1]  433 	ld	0x5235, a
      0092DF 20 05            [ 2]  434 	jra	00106$
      0092E1                        435 00105$:
                                    436 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 163: UART1->CR2 &= (uint8_t)(~UART1_CR2_REN);  
      0092E1 A4 FB            [ 1]  437 	and	a, #0xfb
      0092E3 C7 52 35         [ 1]  438 	ld	0x5235, a
      0092E6                        439 00106$:
                                    440 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 111: UART1->CR3 &= (uint8_t)(~UART1_CR3_STOP);  
      0092E6 C6 52 36         [ 1]  441 	ld	a, 0x5236
                                    442 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 167: if ((uint8_t)(SyncMode & UART1_SYNCMODE_CLOCK_DISABLE))
      0092E9 0D 27            [ 1]  443 	tnz	(0x27, sp)
      0092EB 2A 07            [ 1]  444 	jrpl	00108$
                                    445 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 170: UART1->CR3 &= (uint8_t)(~UART1_CR3_CKEN); 
      0092ED A4 F7            [ 1]  446 	and	a, #0xf7
      0092EF C7 52 36         [ 1]  447 	ld	0x5236, a
      0092F2 20 0D            [ 2]  448 	jra	00110$
      0092F4                        449 00108$:
                                    450 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 174: UART1->CR3 |= (uint8_t)((uint8_t)SyncMode & UART1_CR3_CKEN);
      0092F4 88               [ 1]  451 	push	a
      0092F5 7B 28            [ 1]  452 	ld	a, (0x28, sp)
      0092F7 A4 08            [ 1]  453 	and	a, #0x08
      0092F9 6B 02            [ 1]  454 	ld	(0x02, sp), a
      0092FB 84               [ 1]  455 	pop	a
      0092FC 1A 01            [ 1]  456 	or	a, (0x01, sp)
      0092FE C7 52 36         [ 1]  457 	ld	0x5236, a
      009301                        458 00110$:
                                    459 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 176: }
      009301 5B 1D            [ 2]  460 	addw	sp, #29
      009303 81               [ 4]  461 	ret
                                    462 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 184: void UART1_Cmd(FunctionalState NewState)
                                    463 ;	-----------------------------------------
                                    464 ;	 function UART1_Cmd
                                    465 ;	-----------------------------------------
      009304                        466 _UART1_Cmd:
                                    467 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 189: UART1->CR1 &= (uint8_t)(~UART1_CR1_UARTD); 
      009304 C6 52 34         [ 1]  468 	ld	a, 0x5234
                                    469 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 186: if (NewState != DISABLE)
      009307 0D 03            [ 1]  470 	tnz	(0x03, sp)
      009309 27 06            [ 1]  471 	jreq	00102$
                                    472 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 189: UART1->CR1 &= (uint8_t)(~UART1_CR1_UARTD); 
      00930B A4 DF            [ 1]  473 	and	a, #0xdf
      00930D C7 52 34         [ 1]  474 	ld	0x5234, a
      009310 81               [ 4]  475 	ret
      009311                        476 00102$:
                                    477 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 194: UART1->CR1 |= UART1_CR1_UARTD;  
      009311 AA 20            [ 1]  478 	or	a, #0x20
      009313 C7 52 34         [ 1]  479 	ld	0x5234, a
                                    480 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 196: }
      009316 81               [ 4]  481 	ret
                                    482 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 211: void UART1_ITConfig(UART1_IT_TypeDef UART1_IT, FunctionalState NewState)
                                    483 ;	-----------------------------------------
                                    484 ;	 function UART1_ITConfig
                                    485 ;	-----------------------------------------
      009317                        486 _UART1_ITConfig:
      009317 52 03            [ 2]  487 	sub	sp, #3
                                    488 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 216: assert_param(IS_UART1_CONFIG_IT_OK(UART1_IT));
      009319 1E 06            [ 2]  489 	ldw	x, (0x06, sp)
      00931B A3 01 00         [ 2]  490 	cpw	x, #0x0100
      00931E 27 32            [ 1]  491 	jreq	00119$
      009320 1E 06            [ 2]  492 	ldw	x, (0x06, sp)
      009322 A3 02 77         [ 2]  493 	cpw	x, #0x0277
      009325 27 2B            [ 1]  494 	jreq	00119$
      009327 1E 06            [ 2]  495 	ldw	x, (0x06, sp)
      009329 A3 02 66         [ 2]  496 	cpw	x, #0x0266
      00932C 27 24            [ 1]  497 	jreq	00119$
      00932E 1E 06            [ 2]  498 	ldw	x, (0x06, sp)
      009330 A3 02 05         [ 2]  499 	cpw	x, #0x0205
      009333 27 1D            [ 1]  500 	jreq	00119$
      009335 1E 06            [ 2]  501 	ldw	x, (0x06, sp)
      009337 A3 02 44         [ 2]  502 	cpw	x, #0x0244
      00933A 27 16            [ 1]  503 	jreq	00119$
      00933C 1E 06            [ 2]  504 	ldw	x, (0x06, sp)
      00933E A3 03 46         [ 2]  505 	cpw	x, #0x0346
      009341 27 0F            [ 1]  506 	jreq	00119$
      009343 4B D8            [ 1]  507 	push	#0xd8
      009345 5F               [ 1]  508 	clrw	x
      009346 89               [ 2]  509 	pushw	x
      009347 4B 00            [ 1]  510 	push	#0x00
      009349 4B 62            [ 1]  511 	push	#<___str_0
      00934B 4B 81            [ 1]  512 	push	#(___str_0 >> 8)
      00934D CD 83 14         [ 4]  513 	call	_assert_failed
      009350 5B 06            [ 2]  514 	addw	sp, #6
      009352                        515 00119$:
                                    516 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 217: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      009352 0D 08            [ 1]  517 	tnz	(0x08, sp)
      009354 27 14            [ 1]  518 	jreq	00136$
      009356 7B 08            [ 1]  519 	ld	a, (0x08, sp)
      009358 4A               [ 1]  520 	dec	a
      009359 27 0F            [ 1]  521 	jreq	00136$
      00935B 4B D9            [ 1]  522 	push	#0xd9
      00935D 5F               [ 1]  523 	clrw	x
      00935E 89               [ 2]  524 	pushw	x
      00935F 4B 00            [ 1]  525 	push	#0x00
      009361 4B 62            [ 1]  526 	push	#<___str_0
      009363 4B 81            [ 1]  527 	push	#(___str_0 >> 8)
      009365 CD 83 14         [ 4]  528 	call	_assert_failed
      009368 5B 06            [ 2]  529 	addw	sp, #6
      00936A                        530 00136$:
                                    531 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 220: uartreg = (uint8_t)((uint16_t)UART1_IT >> 0x08);
      00936A 7B 06            [ 1]  532 	ld	a, (0x06, sp)
      00936C 97               [ 1]  533 	ld	xl, a
                                    534 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 222: itpos = (uint8_t)((uint8_t)1 << (uint8_t)((uint8_t)UART1_IT & (uint8_t)0x0F));
      00936D 7B 07            [ 1]  535 	ld	a, (0x07, sp)
      00936F A4 0F            [ 1]  536 	and	a, #0x0f
      009371 88               [ 1]  537 	push	a
      009372 A6 01            [ 1]  538 	ld	a, #0x01
      009374 6B 04            [ 1]  539 	ld	(0x04, sp), a
      009376 84               [ 1]  540 	pop	a
      009377 4D               [ 1]  541 	tnz	a
      009378 27 05            [ 1]  542 	jreq	00228$
      00937A                        543 00227$:
      00937A 08 03            [ 1]  544 	sll	(0x03, sp)
      00937C 4A               [ 1]  545 	dec	a
      00937D 26 FB            [ 1]  546 	jrne	00227$
      00937F                        547 00228$:
                                    548 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 227: if (uartreg == 0x01)
      00937F 9F               [ 1]  549 	ld	a, xl
      009380 4A               [ 1]  550 	dec	a
      009381 26 05            [ 1]  551 	jrne	00230$
      009383 A6 01            [ 1]  552 	ld	a, #0x01
      009385 6B 02            [ 1]  553 	ld	(0x02, sp), a
      009387 C1                     554 	.byte 0xc1
      009388                        555 00230$:
      009388 0F 02            [ 1]  556 	clr	(0x02, sp)
      00938A                        557 00231$:
                                    558 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 231: else if (uartreg == 0x02)
      00938A 9F               [ 1]  559 	ld	a, xl
      00938B A0 02            [ 1]  560 	sub	a, #0x02
      00938D 26 02            [ 1]  561 	jrne	00233$
      00938F 4C               [ 1]  562 	inc	a
      009390 21                     563 	.byte 0x21
      009391                        564 00233$:
      009391 4F               [ 1]  565 	clr	a
      009392                        566 00234$:
                                    567 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 224: if (NewState != DISABLE)
      009392 0D 08            [ 1]  568 	tnz	(0x08, sp)
      009394 27 25            [ 1]  569 	jreq	00114$
                                    570 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 227: if (uartreg == 0x01)
      009396 0D 02            [ 1]  571 	tnz	(0x02, sp)
      009398 27 0A            [ 1]  572 	jreq	00105$
                                    573 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 229: UART1->CR1 |= itpos;
      00939A C6 52 34         [ 1]  574 	ld	a, 0x5234
      00939D 1A 03            [ 1]  575 	or	a, (0x03, sp)
      00939F C7 52 34         [ 1]  576 	ld	0x5234, a
      0093A2 20 41            [ 2]  577 	jra	00116$
      0093A4                        578 00105$:
                                    579 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 231: else if (uartreg == 0x02)
      0093A4 4D               [ 1]  580 	tnz	a
      0093A5 27 0A            [ 1]  581 	jreq	00102$
                                    582 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 233: UART1->CR2 |= itpos;
      0093A7 C6 52 35         [ 1]  583 	ld	a, 0x5235
      0093AA 1A 03            [ 1]  584 	or	a, (0x03, sp)
      0093AC C7 52 35         [ 1]  585 	ld	0x5235, a
      0093AF 20 34            [ 2]  586 	jra	00116$
      0093B1                        587 00102$:
                                    588 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 237: UART1->CR4 |= itpos;
      0093B1 C6 52 37         [ 1]  589 	ld	a, 0x5237
      0093B4 1A 03            [ 1]  590 	or	a, (0x03, sp)
      0093B6 C7 52 37         [ 1]  591 	ld	0x5237, a
      0093B9 20 2A            [ 2]  592 	jra	00116$
      0093BB                        593 00114$:
                                    594 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 245: UART1->CR1 &= (uint8_t)(~itpos);
      0093BB 88               [ 1]  595 	push	a
      0093BC 7B 04            [ 1]  596 	ld	a, (0x04, sp)
      0093BE 43               [ 1]  597 	cpl	a
      0093BF 6B 02            [ 1]  598 	ld	(0x02, sp), a
      0093C1 84               [ 1]  599 	pop	a
                                    600 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 243: if (uartreg == 0x01)
      0093C2 0D 02            [ 1]  601 	tnz	(0x02, sp)
      0093C4 27 0A            [ 1]  602 	jreq	00111$
                                    603 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 245: UART1->CR1 &= (uint8_t)(~itpos);
      0093C6 C6 52 34         [ 1]  604 	ld	a, 0x5234
      0093C9 14 01            [ 1]  605 	and	a, (0x01, sp)
      0093CB C7 52 34         [ 1]  606 	ld	0x5234, a
      0093CE 20 15            [ 2]  607 	jra	00116$
      0093D0                        608 00111$:
                                    609 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 247: else if (uartreg == 0x02)
      0093D0 4D               [ 1]  610 	tnz	a
      0093D1 27 0A            [ 1]  611 	jreq	00108$
                                    612 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 249: UART1->CR2 &= (uint8_t)(~itpos);
      0093D3 C6 52 35         [ 1]  613 	ld	a, 0x5235
      0093D6 14 01            [ 1]  614 	and	a, (0x01, sp)
      0093D8 C7 52 35         [ 1]  615 	ld	0x5235, a
      0093DB 20 08            [ 2]  616 	jra	00116$
      0093DD                        617 00108$:
                                    618 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 253: UART1->CR4 &= (uint8_t)(~itpos);
      0093DD C6 52 37         [ 1]  619 	ld	a, 0x5237
      0093E0 14 01            [ 1]  620 	and	a, (0x01, sp)
      0093E2 C7 52 37         [ 1]  621 	ld	0x5237, a
      0093E5                        622 00116$:
                                    623 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 257: }
      0093E5 5B 03            [ 2]  624 	addw	sp, #3
      0093E7 81               [ 4]  625 	ret
                                    626 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 265: void UART1_HalfDuplexCmd(FunctionalState NewState)
                                    627 ;	-----------------------------------------
                                    628 ;	 function UART1_HalfDuplexCmd
                                    629 ;	-----------------------------------------
      0093E8                        630 _UART1_HalfDuplexCmd:
                                    631 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 267: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      0093E8 0D 03            [ 1]  632 	tnz	(0x03, sp)
      0093EA 27 14            [ 1]  633 	jreq	00107$
      0093EC 7B 03            [ 1]  634 	ld	a, (0x03, sp)
      0093EE 4A               [ 1]  635 	dec	a
      0093EF 27 0F            [ 1]  636 	jreq	00107$
      0093F1 4B 0B            [ 1]  637 	push	#0x0b
      0093F3 4B 01            [ 1]  638 	push	#0x01
      0093F5 5F               [ 1]  639 	clrw	x
      0093F6 89               [ 2]  640 	pushw	x
      0093F7 4B 62            [ 1]  641 	push	#<___str_0
      0093F9 4B 81            [ 1]  642 	push	#(___str_0 >> 8)
      0093FB CD 83 14         [ 4]  643 	call	_assert_failed
      0093FE 5B 06            [ 2]  644 	addw	sp, #6
      009400                        645 00107$:
                                    646 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 271: UART1->CR5 |= UART1_CR5_HDSEL;  /**< UART1 Half Duplex Enable  */
      009400 C6 52 38         [ 1]  647 	ld	a, 0x5238
                                    648 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 269: if (NewState != DISABLE)
      009403 0D 03            [ 1]  649 	tnz	(0x03, sp)
      009405 27 06            [ 1]  650 	jreq	00102$
                                    651 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 271: UART1->CR5 |= UART1_CR5_HDSEL;  /**< UART1 Half Duplex Enable  */
      009407 AA 08            [ 1]  652 	or	a, #0x08
      009409 C7 52 38         [ 1]  653 	ld	0x5238, a
      00940C 81               [ 4]  654 	ret
      00940D                        655 00102$:
                                    656 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 275: UART1->CR5 &= (uint8_t)~UART1_CR5_HDSEL; /**< UART1 Half Duplex Disable */
      00940D A4 F7            [ 1]  657 	and	a, #0xf7
      00940F C7 52 38         [ 1]  658 	ld	0x5238, a
                                    659 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 277: }
      009412 81               [ 4]  660 	ret
                                    661 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 285: void UART1_IrDAConfig(UART1_IrDAMode_TypeDef UART1_IrDAMode)
                                    662 ;	-----------------------------------------
                                    663 ;	 function UART1_IrDAConfig
                                    664 ;	-----------------------------------------
      009413                        665 _UART1_IrDAConfig:
                                    666 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 287: assert_param(IS_UART1_IRDAMODE_OK(UART1_IrDAMode));
      009413 7B 03            [ 1]  667 	ld	a, (0x03, sp)
      009415 4A               [ 1]  668 	dec	a
      009416 27 13            [ 1]  669 	jreq	00107$
      009418 0D 03            [ 1]  670 	tnz	(0x03, sp)
      00941A 27 0F            [ 1]  671 	jreq	00107$
      00941C 4B 1F            [ 1]  672 	push	#0x1f
      00941E 4B 01            [ 1]  673 	push	#0x01
      009420 5F               [ 1]  674 	clrw	x
      009421 89               [ 2]  675 	pushw	x
      009422 4B 62            [ 1]  676 	push	#<___str_0
      009424 4B 81            [ 1]  677 	push	#(___str_0 >> 8)
      009426 CD 83 14         [ 4]  678 	call	_assert_failed
      009429 5B 06            [ 2]  679 	addw	sp, #6
      00942B                        680 00107$:
                                    681 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 291: UART1->CR5 |= UART1_CR5_IRLP;
      00942B C6 52 38         [ 1]  682 	ld	a, 0x5238
                                    683 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 289: if (UART1_IrDAMode != UART1_IRDAMODE_NORMAL)
      00942E 0D 03            [ 1]  684 	tnz	(0x03, sp)
      009430 27 06            [ 1]  685 	jreq	00102$
                                    686 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 291: UART1->CR5 |= UART1_CR5_IRLP;
      009432 AA 04            [ 1]  687 	or	a, #0x04
      009434 C7 52 38         [ 1]  688 	ld	0x5238, a
      009437 81               [ 4]  689 	ret
      009438                        690 00102$:
                                    691 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 295: UART1->CR5 &= ((uint8_t)~UART1_CR5_IRLP);
      009438 A4 FB            [ 1]  692 	and	a, #0xfb
      00943A C7 52 38         [ 1]  693 	ld	0x5238, a
                                    694 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 297: }
      00943D 81               [ 4]  695 	ret
                                    696 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 305: void UART1_IrDACmd(FunctionalState NewState)
                                    697 ;	-----------------------------------------
                                    698 ;	 function UART1_IrDACmd
                                    699 ;	-----------------------------------------
      00943E                        700 _UART1_IrDACmd:
                                    701 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 308: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      00943E 0D 03            [ 1]  702 	tnz	(0x03, sp)
      009440 27 14            [ 1]  703 	jreq	00107$
      009442 7B 03            [ 1]  704 	ld	a, (0x03, sp)
      009444 4A               [ 1]  705 	dec	a
      009445 27 0F            [ 1]  706 	jreq	00107$
      009447 4B 34            [ 1]  707 	push	#0x34
      009449 4B 01            [ 1]  708 	push	#0x01
      00944B 5F               [ 1]  709 	clrw	x
      00944C 89               [ 2]  710 	pushw	x
      00944D 4B 62            [ 1]  711 	push	#<___str_0
      00944F 4B 81            [ 1]  712 	push	#(___str_0 >> 8)
      009451 CD 83 14         [ 4]  713 	call	_assert_failed
      009454 5B 06            [ 2]  714 	addw	sp, #6
      009456                        715 00107$:
                                    716 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 313: UART1->CR5 |= UART1_CR5_IREN;
      009456 C6 52 38         [ 1]  717 	ld	a, 0x5238
                                    718 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 310: if (NewState != DISABLE)
      009459 0D 03            [ 1]  719 	tnz	(0x03, sp)
      00945B 27 06            [ 1]  720 	jreq	00102$
                                    721 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 313: UART1->CR5 |= UART1_CR5_IREN;
      00945D AA 02            [ 1]  722 	or	a, #0x02
      00945F C7 52 38         [ 1]  723 	ld	0x5238, a
      009462 81               [ 4]  724 	ret
      009463                        725 00102$:
                                    726 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 318: UART1->CR5 &= ((uint8_t)~UART1_CR5_IREN);
      009463 A4 FD            [ 1]  727 	and	a, #0xfd
      009465 C7 52 38         [ 1]  728 	ld	0x5238, a
                                    729 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 320: }
      009468 81               [ 4]  730 	ret
                                    731 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 329: void UART1_LINBreakDetectionConfig(UART1_LINBreakDetectionLength_TypeDef UART1_LINBreakDetectionLength)
                                    732 ;	-----------------------------------------
                                    733 ;	 function UART1_LINBreakDetectionConfig
                                    734 ;	-----------------------------------------
      009469                        735 _UART1_LINBreakDetectionConfig:
                                    736 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 331: assert_param(IS_UART1_LINBREAKDETECTIONLENGTH_OK(UART1_LINBreakDetectionLength));
      009469 0D 03            [ 1]  737 	tnz	(0x03, sp)
      00946B 27 14            [ 1]  738 	jreq	00107$
      00946D 7B 03            [ 1]  739 	ld	a, (0x03, sp)
      00946F 4A               [ 1]  740 	dec	a
      009470 27 0F            [ 1]  741 	jreq	00107$
      009472 4B 4B            [ 1]  742 	push	#0x4b
      009474 4B 01            [ 1]  743 	push	#0x01
      009476 5F               [ 1]  744 	clrw	x
      009477 89               [ 2]  745 	pushw	x
      009478 4B 62            [ 1]  746 	push	#<___str_0
      00947A 4B 81            [ 1]  747 	push	#(___str_0 >> 8)
      00947C CD 83 14         [ 4]  748 	call	_assert_failed
      00947F 5B 06            [ 2]  749 	addw	sp, #6
      009481                        750 00107$:
                                    751 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 335: UART1->CR4 |= UART1_CR4_LBDL;
      009481 C6 52 37         [ 1]  752 	ld	a, 0x5237
                                    753 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 333: if (UART1_LINBreakDetectionLength != UART1_LINBREAKDETECTIONLENGTH_10BITS)
      009484 0D 03            [ 1]  754 	tnz	(0x03, sp)
      009486 27 06            [ 1]  755 	jreq	00102$
                                    756 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 335: UART1->CR4 |= UART1_CR4_LBDL;
      009488 AA 20            [ 1]  757 	or	a, #0x20
      00948A C7 52 37         [ 1]  758 	ld	0x5237, a
      00948D 81               [ 4]  759 	ret
      00948E                        760 00102$:
                                    761 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 339: UART1->CR4 &= ((uint8_t)~UART1_CR4_LBDL);
      00948E A4 DF            [ 1]  762 	and	a, #0xdf
      009490 C7 52 37         [ 1]  763 	ld	0x5237, a
                                    764 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 341: }
      009493 81               [ 4]  765 	ret
                                    766 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 349: void UART1_LINCmd(FunctionalState NewState)
                                    767 ;	-----------------------------------------
                                    768 ;	 function UART1_LINCmd
                                    769 ;	-----------------------------------------
      009494                        770 _UART1_LINCmd:
                                    771 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 351: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      009494 0D 03            [ 1]  772 	tnz	(0x03, sp)
      009496 27 14            [ 1]  773 	jreq	00107$
      009498 7B 03            [ 1]  774 	ld	a, (0x03, sp)
      00949A 4A               [ 1]  775 	dec	a
      00949B 27 0F            [ 1]  776 	jreq	00107$
      00949D 4B 5F            [ 1]  777 	push	#0x5f
      00949F 4B 01            [ 1]  778 	push	#0x01
      0094A1 5F               [ 1]  779 	clrw	x
      0094A2 89               [ 2]  780 	pushw	x
      0094A3 4B 62            [ 1]  781 	push	#<___str_0
      0094A5 4B 81            [ 1]  782 	push	#(___str_0 >> 8)
      0094A7 CD 83 14         [ 4]  783 	call	_assert_failed
      0094AA 5B 06            [ 2]  784 	addw	sp, #6
      0094AC                        785 00107$:
                                    786 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 356: UART1->CR3 |= UART1_CR3_LINEN;
      0094AC C6 52 36         [ 1]  787 	ld	a, 0x5236
                                    788 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 353: if (NewState != DISABLE)
      0094AF 0D 03            [ 1]  789 	tnz	(0x03, sp)
      0094B1 27 06            [ 1]  790 	jreq	00102$
                                    791 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 356: UART1->CR3 |= UART1_CR3_LINEN;
      0094B3 AA 40            [ 1]  792 	or	a, #0x40
      0094B5 C7 52 36         [ 1]  793 	ld	0x5236, a
      0094B8 81               [ 4]  794 	ret
      0094B9                        795 00102$:
                                    796 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 361: UART1->CR3 &= ((uint8_t)~UART1_CR3_LINEN);
      0094B9 A4 BF            [ 1]  797 	and	a, #0xbf
      0094BB C7 52 36         [ 1]  798 	ld	0x5236, a
                                    799 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 363: }
      0094BE 81               [ 4]  800 	ret
                                    801 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 371: void UART1_SmartCardCmd(FunctionalState NewState)
                                    802 ;	-----------------------------------------
                                    803 ;	 function UART1_SmartCardCmd
                                    804 ;	-----------------------------------------
      0094BF                        805 _UART1_SmartCardCmd:
                                    806 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 373: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      0094BF 0D 03            [ 1]  807 	tnz	(0x03, sp)
      0094C1 27 14            [ 1]  808 	jreq	00107$
      0094C3 7B 03            [ 1]  809 	ld	a, (0x03, sp)
      0094C5 4A               [ 1]  810 	dec	a
      0094C6 27 0F            [ 1]  811 	jreq	00107$
      0094C8 4B 75            [ 1]  812 	push	#0x75
      0094CA 4B 01            [ 1]  813 	push	#0x01
      0094CC 5F               [ 1]  814 	clrw	x
      0094CD 89               [ 2]  815 	pushw	x
      0094CE 4B 62            [ 1]  816 	push	#<___str_0
      0094D0 4B 81            [ 1]  817 	push	#(___str_0 >> 8)
      0094D2 CD 83 14         [ 4]  818 	call	_assert_failed
      0094D5 5B 06            [ 2]  819 	addw	sp, #6
      0094D7                        820 00107$:
                                    821 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 378: UART1->CR5 |= UART1_CR5_SCEN;
      0094D7 C6 52 38         [ 1]  822 	ld	a, 0x5238
                                    823 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 375: if (NewState != DISABLE)
      0094DA 0D 03            [ 1]  824 	tnz	(0x03, sp)
      0094DC 27 06            [ 1]  825 	jreq	00102$
                                    826 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 378: UART1->CR5 |= UART1_CR5_SCEN;
      0094DE AA 20            [ 1]  827 	or	a, #0x20
      0094E0 C7 52 38         [ 1]  828 	ld	0x5238, a
      0094E3 81               [ 4]  829 	ret
      0094E4                        830 00102$:
                                    831 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 383: UART1->CR5 &= ((uint8_t)(~UART1_CR5_SCEN));
      0094E4 A4 DF            [ 1]  832 	and	a, #0xdf
      0094E6 C7 52 38         [ 1]  833 	ld	0x5238, a
                                    834 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 385: }
      0094E9 81               [ 4]  835 	ret
                                    836 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 394: void UART1_SmartCardNACKCmd(FunctionalState NewState)
                                    837 ;	-----------------------------------------
                                    838 ;	 function UART1_SmartCardNACKCmd
                                    839 ;	-----------------------------------------
      0094EA                        840 _UART1_SmartCardNACKCmd:
                                    841 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 396: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      0094EA 0D 03            [ 1]  842 	tnz	(0x03, sp)
      0094EC 27 14            [ 1]  843 	jreq	00107$
      0094EE 7B 03            [ 1]  844 	ld	a, (0x03, sp)
      0094F0 4A               [ 1]  845 	dec	a
      0094F1 27 0F            [ 1]  846 	jreq	00107$
      0094F3 4B 8C            [ 1]  847 	push	#0x8c
      0094F5 4B 01            [ 1]  848 	push	#0x01
      0094F7 5F               [ 1]  849 	clrw	x
      0094F8 89               [ 2]  850 	pushw	x
      0094F9 4B 62            [ 1]  851 	push	#<___str_0
      0094FB 4B 81            [ 1]  852 	push	#(___str_0 >> 8)
      0094FD CD 83 14         [ 4]  853 	call	_assert_failed
      009500 5B 06            [ 2]  854 	addw	sp, #6
      009502                        855 00107$:
                                    856 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 401: UART1->CR5 |= UART1_CR5_NACK;
      009502 C6 52 38         [ 1]  857 	ld	a, 0x5238
                                    858 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 398: if (NewState != DISABLE)
      009505 0D 03            [ 1]  859 	tnz	(0x03, sp)
      009507 27 06            [ 1]  860 	jreq	00102$
                                    861 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 401: UART1->CR5 |= UART1_CR5_NACK;
      009509 AA 10            [ 1]  862 	or	a, #0x10
      00950B C7 52 38         [ 1]  863 	ld	0x5238, a
      00950E 81               [ 4]  864 	ret
      00950F                        865 00102$:
                                    866 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 406: UART1->CR5 &= ((uint8_t)~(UART1_CR5_NACK));
      00950F A4 EF            [ 1]  867 	and	a, #0xef
      009511 C7 52 38         [ 1]  868 	ld	0x5238, a
                                    869 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 408: }
      009514 81               [ 4]  870 	ret
                                    871 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 416: void UART1_WakeUpConfig(UART1_WakeUp_TypeDef UART1_WakeUp)
                                    872 ;	-----------------------------------------
                                    873 ;	 function UART1_WakeUpConfig
                                    874 ;	-----------------------------------------
      009515                        875 _UART1_WakeUpConfig:
                                    876 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 418: assert_param(IS_UART1_WAKEUP_OK(UART1_WakeUp));
      009515 0D 03            [ 1]  877 	tnz	(0x03, sp)
      009517 27 15            [ 1]  878 	jreq	00104$
      009519 7B 03            [ 1]  879 	ld	a, (0x03, sp)
      00951B A1 08            [ 1]  880 	cp	a, #0x08
      00951D 27 0F            [ 1]  881 	jreq	00104$
      00951F 4B A2            [ 1]  882 	push	#0xa2
      009521 4B 01            [ 1]  883 	push	#0x01
      009523 5F               [ 1]  884 	clrw	x
      009524 89               [ 2]  885 	pushw	x
      009525 4B 62            [ 1]  886 	push	#<___str_0
      009527 4B 81            [ 1]  887 	push	#(___str_0 >> 8)
      009529 CD 83 14         [ 4]  888 	call	_assert_failed
      00952C 5B 06            [ 2]  889 	addw	sp, #6
      00952E                        890 00104$:
                                    891 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 420: UART1->CR1 &= ((uint8_t)~UART1_CR1_WAKE);
      00952E 72 17 52 34      [ 1]  892 	bres	21044, #3
                                    893 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 421: UART1->CR1 |= (uint8_t)UART1_WakeUp;
      009532 C6 52 34         [ 1]  894 	ld	a, 0x5234
      009535 1A 03            [ 1]  895 	or	a, (0x03, sp)
      009537 C7 52 34         [ 1]  896 	ld	0x5234, a
                                    897 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 422: }
      00953A 81               [ 4]  898 	ret
                                    899 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 430: void UART1_ReceiverWakeUpCmd(FunctionalState NewState)
                                    900 ;	-----------------------------------------
                                    901 ;	 function UART1_ReceiverWakeUpCmd
                                    902 ;	-----------------------------------------
      00953B                        903 _UART1_ReceiverWakeUpCmd:
                                    904 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 432: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      00953B 0D 03            [ 1]  905 	tnz	(0x03, sp)
      00953D 27 14            [ 1]  906 	jreq	00107$
      00953F 7B 03            [ 1]  907 	ld	a, (0x03, sp)
      009541 4A               [ 1]  908 	dec	a
      009542 27 0F            [ 1]  909 	jreq	00107$
      009544 4B B0            [ 1]  910 	push	#0xb0
      009546 4B 01            [ 1]  911 	push	#0x01
      009548 5F               [ 1]  912 	clrw	x
      009549 89               [ 2]  913 	pushw	x
      00954A 4B 62            [ 1]  914 	push	#<___str_0
      00954C 4B 81            [ 1]  915 	push	#(___str_0 >> 8)
      00954E CD 83 14         [ 4]  916 	call	_assert_failed
      009551 5B 06            [ 2]  917 	addw	sp, #6
      009553                        918 00107$:
                                    919 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 437: UART1->CR2 |= UART1_CR2_RWU;
      009553 C6 52 35         [ 1]  920 	ld	a, 0x5235
                                    921 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 434: if (NewState != DISABLE)
      009556 0D 03            [ 1]  922 	tnz	(0x03, sp)
      009558 27 06            [ 1]  923 	jreq	00102$
                                    924 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 437: UART1->CR2 |= UART1_CR2_RWU;
      00955A AA 02            [ 1]  925 	or	a, #0x02
      00955C C7 52 35         [ 1]  926 	ld	0x5235, a
      00955F 81               [ 4]  927 	ret
      009560                        928 00102$:
                                    929 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 442: UART1->CR2 &= ((uint8_t)~UART1_CR2_RWU);
      009560 A4 FD            [ 1]  930 	and	a, #0xfd
      009562 C7 52 35         [ 1]  931 	ld	0x5235, a
                                    932 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 444: }
      009565 81               [ 4]  933 	ret
                                    934 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 451: uint8_t UART1_ReceiveData8(void)
                                    935 ;	-----------------------------------------
                                    936 ;	 function UART1_ReceiveData8
                                    937 ;	-----------------------------------------
      009566                        938 _UART1_ReceiveData8:
                                    939 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 453: return ((uint8_t)UART1->DR);
      009566 C6 52 31         [ 1]  940 	ld	a, 0x5231
                                    941 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 454: }
      009569 81               [ 4]  942 	ret
                                    943 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 461: uint16_t UART1_ReceiveData9(void)
                                    944 ;	-----------------------------------------
                                    945 ;	 function UART1_ReceiveData9
                                    946 ;	-----------------------------------------
      00956A                        947 _UART1_ReceiveData9:
      00956A 89               [ 2]  948 	pushw	x
                                    949 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 465: temp = (uint16_t)(((uint16_t)( (uint16_t)UART1->CR1 & (uint16_t)UART1_CR1_R8)) << 1);
      00956B C6 52 34         [ 1]  950 	ld	a, 0x5234
      00956E A4 80            [ 1]  951 	and	a, #0x80
      009570 97               [ 1]  952 	ld	xl, a
      009571 4F               [ 1]  953 	clr	a
      009572 95               [ 1]  954 	ld	xh, a
      009573 58               [ 2]  955 	sllw	x
                                    956 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 466: return (uint16_t)( (((uint16_t) UART1->DR) | temp ) & ((uint16_t)0x01FF));
      009574 C6 52 31         [ 1]  957 	ld	a, 0x5231
      009577 6B 02            [ 1]  958 	ld	(0x02, sp), a
      009579 0F 01            [ 1]  959 	clr	(0x01, sp)
      00957B 9F               [ 1]  960 	ld	a, xl
      00957C 1A 02            [ 1]  961 	or	a, (0x02, sp)
      00957E 02               [ 1]  962 	rlwa	x
      00957F 1A 01            [ 1]  963 	or	a, (0x01, sp)
      009581 A4 01            [ 1]  964 	and	a, #0x01
      009583 95               [ 1]  965 	ld	xh, a
                                    966 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 467: }
      009584 5B 02            [ 2]  967 	addw	sp, #2
      009586 81               [ 4]  968 	ret
                                    969 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 474: void UART1_SendData8(uint8_t Data)
                                    970 ;	-----------------------------------------
                                    971 ;	 function UART1_SendData8
                                    972 ;	-----------------------------------------
      009587                        973 _UART1_SendData8:
                                    974 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 477: UART1->DR = Data;
      009587 AE 52 31         [ 2]  975 	ldw	x, #0x5231
      00958A 7B 03            [ 1]  976 	ld	a, (0x03, sp)
      00958C F7               [ 1]  977 	ld	(x), a
                                    978 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 478: }
      00958D 81               [ 4]  979 	ret
                                    980 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 486: void UART1_SendData9(uint16_t Data)
                                    981 ;	-----------------------------------------
                                    982 ;	 function UART1_SendData9
                                    983 ;	-----------------------------------------
      00958E                        984 _UART1_SendData9:
      00958E 88               [ 1]  985 	push	a
                                    986 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 489: UART1->CR1 &= ((uint8_t)~UART1_CR1_T8);
      00958F 72 1D 52 34      [ 1]  987 	bres	21044, #6
                                    988 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 491: UART1->CR1 |= (uint8_t)(((uint8_t)(Data >> 2)) & UART1_CR1_T8);
      009593 C6 52 34         [ 1]  989 	ld	a, 0x5234
      009596 6B 01            [ 1]  990 	ld	(0x01, sp), a
      009598 1E 04            [ 2]  991 	ldw	x, (0x04, sp)
      00959A 54               [ 2]  992 	srlw	x
      00959B 54               [ 2]  993 	srlw	x
      00959C 9F               [ 1]  994 	ld	a, xl
      00959D A4 40            [ 1]  995 	and	a, #0x40
      00959F 1A 01            [ 1]  996 	or	a, (0x01, sp)
      0095A1 C7 52 34         [ 1]  997 	ld	0x5234, a
                                    998 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 493: UART1->DR   = (uint8_t)(Data);
      0095A4 7B 05            [ 1]  999 	ld	a, (0x05, sp)
      0095A6 C7 52 31         [ 1] 1000 	ld	0x5231, a
                                   1001 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 494: }
      0095A9 84               [ 1] 1002 	pop	a
      0095AA 81               [ 4] 1003 	ret
                                   1004 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 501: void UART1_SendBreak(void)
                                   1005 ;	-----------------------------------------
                                   1006 ;	 function UART1_SendBreak
                                   1007 ;	-----------------------------------------
      0095AB                       1008 _UART1_SendBreak:
                                   1009 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 503: UART1->CR2 |= UART1_CR2_SBK;
      0095AB 72 10 52 35      [ 1] 1010 	bset	21045, #0
                                   1011 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 504: }
      0095AF 81               [ 4] 1012 	ret
                                   1013 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 511: void UART1_SetAddress(uint8_t UART1_Address)
                                   1014 ;	-----------------------------------------
                                   1015 ;	 function UART1_SetAddress
                                   1016 ;	-----------------------------------------
      0095B0                       1017 _UART1_SetAddress:
                                   1018 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 514: assert_param(IS_UART1_ADDRESS_OK(UART1_Address));
      0095B0 7B 03            [ 1] 1019 	ld	a, (0x03, sp)
      0095B2 A1 10            [ 1] 1020 	cp	a, #0x10
      0095B4 25 0F            [ 1] 1021 	jrc	00104$
      0095B6 4B 02            [ 1] 1022 	push	#0x02
      0095B8 4B 02            [ 1] 1023 	push	#0x02
      0095BA 5F               [ 1] 1024 	clrw	x
      0095BB 89               [ 2] 1025 	pushw	x
      0095BC 4B 62            [ 1] 1026 	push	#<___str_0
      0095BE 4B 81            [ 1] 1027 	push	#(___str_0 >> 8)
      0095C0 CD 83 14         [ 4] 1028 	call	_assert_failed
      0095C3 5B 06            [ 2] 1029 	addw	sp, #6
      0095C5                       1030 00104$:
                                   1031 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 517: UART1->CR4 &= ((uint8_t)~UART1_CR4_ADD);
      0095C5 C6 52 37         [ 1] 1032 	ld	a, 0x5237
      0095C8 A4 F0            [ 1] 1033 	and	a, #0xf0
      0095CA C7 52 37         [ 1] 1034 	ld	0x5237, a
                                   1035 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 519: UART1->CR4 |= UART1_Address;
      0095CD C6 52 37         [ 1] 1036 	ld	a, 0x5237
      0095D0 1A 03            [ 1] 1037 	or	a, (0x03, sp)
      0095D2 C7 52 37         [ 1] 1038 	ld	0x5237, a
                                   1039 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 520: }
      0095D5 81               [ 4] 1040 	ret
                                   1041 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 528: void UART1_SetGuardTime(uint8_t UART1_GuardTime)
                                   1042 ;	-----------------------------------------
                                   1043 ;	 function UART1_SetGuardTime
                                   1044 ;	-----------------------------------------
      0095D6                       1045 _UART1_SetGuardTime:
                                   1046 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 531: UART1->GTR = UART1_GuardTime;
      0095D6 AE 52 39         [ 2] 1047 	ldw	x, #0x5239
      0095D9 7B 03            [ 1] 1048 	ld	a, (0x03, sp)
      0095DB F7               [ 1] 1049 	ld	(x), a
                                   1050 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 532: }
      0095DC 81               [ 4] 1051 	ret
                                   1052 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 556: void UART1_SetPrescaler(uint8_t UART1_Prescaler)
                                   1053 ;	-----------------------------------------
                                   1054 ;	 function UART1_SetPrescaler
                                   1055 ;	-----------------------------------------
      0095DD                       1056 _UART1_SetPrescaler:
                                   1057 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 559: UART1->PSCR = UART1_Prescaler;
      0095DD AE 52 3A         [ 2] 1058 	ldw	x, #0x523a
      0095E0 7B 03            [ 1] 1059 	ld	a, (0x03, sp)
      0095E2 F7               [ 1] 1060 	ld	(x), a
                                   1061 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 560: }
      0095E3 81               [ 4] 1062 	ret
                                   1063 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 568: FlagStatus UART1_GetFlagStatus(UART1_Flag_TypeDef UART1_FLAG)
                                   1064 ;	-----------------------------------------
                                   1065 ;	 function UART1_GetFlagStatus
                                   1066 ;	-----------------------------------------
      0095E4                       1067 _UART1_GetFlagStatus:
      0095E4 89               [ 2] 1068 	pushw	x
                                   1069 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 573: assert_param(IS_UART1_FLAG_OK(UART1_FLAG));
      0095E5 1E 05            [ 2] 1070 	ldw	x, (0x05, sp)
      0095E7 A3 01 01         [ 2] 1071 	cpw	x, #0x0101
      0095EA 26 05            [ 1] 1072 	jrne	00223$
      0095EC A6 01            [ 1] 1073 	ld	a, #0x01
      0095EE 6B 02            [ 1] 1074 	ld	(0x02, sp), a
      0095F0 C1                    1075 	.byte 0xc1
      0095F1                       1076 00223$:
      0095F1 0F 02            [ 1] 1077 	clr	(0x02, sp)
      0095F3                       1078 00224$:
      0095F3 1E 05            [ 2] 1079 	ldw	x, (0x05, sp)
      0095F5 A3 02 10         [ 2] 1080 	cpw	x, #0x0210
      0095F8 26 03            [ 1] 1081 	jrne	00226$
      0095FA A6 01            [ 1] 1082 	ld	a, #0x01
      0095FC 21                    1083 	.byte 0x21
      0095FD                       1084 00226$:
      0095FD 4F               [ 1] 1085 	clr	a
      0095FE                       1086 00227$:
      0095FE 1E 05            [ 2] 1087 	ldw	x, (0x05, sp)
      009600 A3 00 80         [ 2] 1088 	cpw	x, #0x0080
      009603 27 47            [ 1] 1089 	jreq	00119$
      009605 1E 05            [ 2] 1090 	ldw	x, (0x05, sp)
      009607 A3 00 40         [ 2] 1091 	cpw	x, #0x0040
      00960A 27 40            [ 1] 1092 	jreq	00119$
      00960C 1E 05            [ 2] 1093 	ldw	x, (0x05, sp)
      00960E A3 00 20         [ 2] 1094 	cpw	x, #0x0020
      009611 27 39            [ 1] 1095 	jreq	00119$
      009613 1E 05            [ 2] 1096 	ldw	x, (0x05, sp)
      009615 A3 00 10         [ 2] 1097 	cpw	x, #0x0010
      009618 27 32            [ 1] 1098 	jreq	00119$
      00961A 1E 05            [ 2] 1099 	ldw	x, (0x05, sp)
      00961C A3 00 08         [ 2] 1100 	cpw	x, #0x0008
      00961F 27 2B            [ 1] 1101 	jreq	00119$
      009621 1E 05            [ 2] 1102 	ldw	x, (0x05, sp)
      009623 A3 00 04         [ 2] 1103 	cpw	x, #0x0004
      009626 27 24            [ 1] 1104 	jreq	00119$
      009628 1E 05            [ 2] 1105 	ldw	x, (0x05, sp)
      00962A A3 00 02         [ 2] 1106 	cpw	x, #0x0002
      00962D 27 1D            [ 1] 1107 	jreq	00119$
      00962F 1E 05            [ 2] 1108 	ldw	x, (0x05, sp)
      009631 5A               [ 2] 1109 	decw	x
      009632 27 18            [ 1] 1110 	jreq	00119$
      009634 0D 02            [ 1] 1111 	tnz	(0x02, sp)
      009636 26 14            [ 1] 1112 	jrne	00119$
      009638 4D               [ 1] 1113 	tnz	a
      009639 26 11            [ 1] 1114 	jrne	00119$
      00963B 88               [ 1] 1115 	push	a
      00963C 4B 3D            [ 1] 1116 	push	#0x3d
      00963E 4B 02            [ 1] 1117 	push	#0x02
      009640 5F               [ 1] 1118 	clrw	x
      009641 89               [ 2] 1119 	pushw	x
      009642 4B 62            [ 1] 1120 	push	#<___str_0
      009644 4B 81            [ 1] 1121 	push	#(___str_0 >> 8)
      009646 CD 83 14         [ 4] 1122 	call	_assert_failed
      009649 5B 06            [ 2] 1123 	addw	sp, #6
      00964B 84               [ 1] 1124 	pop	a
      00964C                       1125 00119$:
                                   1126 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 579: if ((UART1->CR4 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      00964C 88               [ 1] 1127 	push	a
      00964D 7B 07            [ 1] 1128 	ld	a, (0x07, sp)
      00964F 6B 02            [ 1] 1129 	ld	(0x02, sp), a
      009651 84               [ 1] 1130 	pop	a
                                   1131 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 577: if (UART1_FLAG == UART1_FLAG_LBDF)
      009652 4D               [ 1] 1132 	tnz	a
      009653 27 0E            [ 1] 1133 	jreq	00114$
                                   1134 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 579: if ((UART1->CR4 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      009655 C6 52 37         [ 1] 1135 	ld	a, 0x5237
      009658 14 01            [ 1] 1136 	and	a, (0x01, sp)
      00965A 27 04            [ 1] 1137 	jreq	00102$
                                   1138 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 582: status = SET;
      00965C A6 01            [ 1] 1139 	ld	a, #0x01
      00965E 20 20            [ 2] 1140 	jra	00115$
      009660                       1141 00102$:
                                   1142 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 587: status = RESET;
      009660 4F               [ 1] 1143 	clr	a
      009661 20 1D            [ 2] 1144 	jra	00115$
      009663                       1145 00114$:
                                   1146 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 590: else if (UART1_FLAG == UART1_FLAG_SBK)
      009663 0D 02            [ 1] 1147 	tnz	(0x02, sp)
      009665 27 0E            [ 1] 1148 	jreq	00111$
                                   1149 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 592: if ((UART1->CR2 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      009667 C6 52 35         [ 1] 1150 	ld	a, 0x5235
      00966A 14 01            [ 1] 1151 	and	a, (0x01, sp)
      00966C 27 04            [ 1] 1152 	jreq	00105$
                                   1153 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 595: status = SET;
      00966E A6 01            [ 1] 1154 	ld	a, #0x01
      009670 20 0E            [ 2] 1155 	jra	00115$
      009672                       1156 00105$:
                                   1157 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 600: status = RESET;
      009672 4F               [ 1] 1158 	clr	a
      009673 20 0B            [ 2] 1159 	jra	00115$
      009675                       1160 00111$:
                                   1161 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 605: if ((UART1->SR & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
      009675 C6 52 30         [ 1] 1162 	ld	a, 0x5230
      009678 14 01            [ 1] 1163 	and	a, (0x01, sp)
      00967A 27 03            [ 1] 1164 	jreq	00108$
                                   1165 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 608: status = SET;
      00967C A6 01            [ 1] 1166 	ld	a, #0x01
                                   1167 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 613: status = RESET;
      00967E 21                    1168 	.byte 0x21
      00967F                       1169 00108$:
      00967F 4F               [ 1] 1170 	clr	a
      009680                       1171 00115$:
                                   1172 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 617: return status;
                                   1173 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 618: }
      009680 85               [ 2] 1174 	popw	x
      009681 81               [ 4] 1175 	ret
                                   1176 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 646: void UART1_ClearFlag(UART1_Flag_TypeDef UART1_FLAG)
                                   1177 ;	-----------------------------------------
                                   1178 ;	 function UART1_ClearFlag
                                   1179 ;	-----------------------------------------
      009682                       1180 _UART1_ClearFlag:
                                   1181 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 648: assert_param(IS_UART1_CLEAR_FLAG_OK(UART1_FLAG));
      009682 1E 03            [ 2] 1182 	ldw	x, (0x03, sp)
      009684 A3 00 20         [ 2] 1183 	cpw	x, #0x0020
      009687 26 03            [ 1] 1184 	jrne	00127$
      009689 A6 01            [ 1] 1185 	ld	a, #0x01
      00968B 21                    1186 	.byte 0x21
      00968C                       1187 00127$:
      00968C 4F               [ 1] 1188 	clr	a
      00968D                       1189 00128$:
      00968D 4D               [ 1] 1190 	tnz	a
      00968E 26 18            [ 1] 1191 	jrne	00107$
      009690 1E 03            [ 2] 1192 	ldw	x, (0x03, sp)
      009692 A3 02 10         [ 2] 1193 	cpw	x, #0x0210
      009695 27 11            [ 1] 1194 	jreq	00107$
      009697 88               [ 1] 1195 	push	a
      009698 4B 88            [ 1] 1196 	push	#0x88
      00969A 4B 02            [ 1] 1197 	push	#0x02
      00969C 5F               [ 1] 1198 	clrw	x
      00969D 89               [ 2] 1199 	pushw	x
      00969E 4B 62            [ 1] 1200 	push	#<___str_0
      0096A0 4B 81            [ 1] 1201 	push	#(___str_0 >> 8)
      0096A2 CD 83 14         [ 4] 1202 	call	_assert_failed
      0096A5 5B 06            [ 2] 1203 	addw	sp, #6
      0096A7 84               [ 1] 1204 	pop	a
      0096A8                       1205 00107$:
                                   1206 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 651: if (UART1_FLAG == UART1_FLAG_RXNE)
      0096A8 4D               [ 1] 1207 	tnz	a
      0096A9 27 05            [ 1] 1208 	jreq	00102$
                                   1209 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 653: UART1->SR = (uint8_t)~(UART1_SR_RXNE);
      0096AB 35 DF 52 30      [ 1] 1210 	mov	0x5230+0, #0xdf
      0096AF 81               [ 4] 1211 	ret
      0096B0                       1212 00102$:
                                   1213 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 658: UART1->CR4 &= (uint8_t)~(UART1_CR4_LBDF);
      0096B0 72 19 52 37      [ 1] 1214 	bres	21047, #4
                                   1215 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 660: }
      0096B4 81               [ 4] 1216 	ret
                                   1217 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 675: ITStatus UART1_GetITStatus(UART1_IT_TypeDef UART1_IT)
                                   1218 ;	-----------------------------------------
                                   1219 ;	 function UART1_GetITStatus
                                   1220 ;	-----------------------------------------
      0096B5                       1221 _UART1_GetITStatus:
      0096B5 52 04            [ 2] 1222 	sub	sp, #4
                                   1223 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 684: assert_param(IS_UART1_GET_IT_OK(UART1_IT));
      0096B7 1E 07            [ 2] 1224 	ldw	x, (0x07, sp)
      0096B9 A3 03 46         [ 2] 1225 	cpw	x, #0x0346
      0096BC 26 05            [ 1] 1226 	jrne	00217$
      0096BE A6 01            [ 1] 1227 	ld	a, #0x01
      0096C0 6B 02            [ 1] 1228 	ld	(0x02, sp), a
      0096C2 C1                    1229 	.byte 0xc1
      0096C3                       1230 00217$:
      0096C3 0F 02            [ 1] 1231 	clr	(0x02, sp)
      0096C5                       1232 00218$:
      0096C5 1E 07            [ 2] 1233 	ldw	x, (0x07, sp)
      0096C7 A3 01 00         [ 2] 1234 	cpw	x, #0x0100
      0096CA 26 05            [ 1] 1235 	jrne	00220$
      0096CC A6 01            [ 1] 1236 	ld	a, #0x01
      0096CE 6B 01            [ 1] 1237 	ld	(0x01, sp), a
      0096D0 C1                    1238 	.byte 0xc1
      0096D1                       1239 00220$:
      0096D1 0F 01            [ 1] 1240 	clr	(0x01, sp)
      0096D3                       1241 00221$:
      0096D3 1E 07            [ 2] 1242 	ldw	x, (0x07, sp)
      0096D5 A3 02 77         [ 2] 1243 	cpw	x, #0x0277
      0096D8 27 33            [ 1] 1244 	jreq	00122$
      0096DA 1E 07            [ 2] 1245 	ldw	x, (0x07, sp)
      0096DC A3 02 66         [ 2] 1246 	cpw	x, #0x0266
      0096DF 27 2C            [ 1] 1247 	jreq	00122$
      0096E1 1E 07            [ 2] 1248 	ldw	x, (0x07, sp)
      0096E3 A3 02 55         [ 2] 1249 	cpw	x, #0x0255
      0096E6 27 25            [ 1] 1250 	jreq	00122$
      0096E8 1E 07            [ 2] 1251 	ldw	x, (0x07, sp)
      0096EA A3 02 44         [ 2] 1252 	cpw	x, #0x0244
      0096ED 27 1E            [ 1] 1253 	jreq	00122$
      0096EF 1E 07            [ 2] 1254 	ldw	x, (0x07, sp)
      0096F1 A3 02 35         [ 2] 1255 	cpw	x, #0x0235
      0096F4 27 17            [ 1] 1256 	jreq	00122$
      0096F6 0D 02            [ 1] 1257 	tnz	(0x02, sp)
      0096F8 26 13            [ 1] 1258 	jrne	00122$
      0096FA 0D 01            [ 1] 1259 	tnz	(0x01, sp)
      0096FC 26 0F            [ 1] 1260 	jrne	00122$
      0096FE 4B AC            [ 1] 1261 	push	#0xac
      009700 4B 02            [ 1] 1262 	push	#0x02
      009702 5F               [ 1] 1263 	clrw	x
      009703 89               [ 2] 1264 	pushw	x
      009704 4B 62            [ 1] 1265 	push	#<___str_0
      009706 4B 81            [ 1] 1266 	push	#(___str_0 >> 8)
      009708 CD 83 14         [ 4] 1267 	call	_assert_failed
      00970B 5B 06            [ 2] 1268 	addw	sp, #6
      00970D                       1269 00122$:
                                   1270 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 687: itpos = (uint8_t)((uint8_t)1 << (uint8_t)((uint8_t)UART1_IT & (uint8_t)0x0F));
      00970D 7B 08            [ 1] 1271 	ld	a, (0x08, sp)
      00970F 97               [ 1] 1272 	ld	xl, a
      009710 A4 0F            [ 1] 1273 	and	a, #0x0f
      009712 88               [ 1] 1274 	push	a
      009713 A6 01            [ 1] 1275 	ld	a, #0x01
      009715 6B 05            [ 1] 1276 	ld	(0x05, sp), a
      009717 84               [ 1] 1277 	pop	a
      009718 4D               [ 1] 1278 	tnz	a
      009719 27 05            [ 1] 1279 	jreq	00240$
      00971B                       1280 00239$:
      00971B 08 04            [ 1] 1281 	sll	(0x04, sp)
      00971D 4A               [ 1] 1282 	dec	a
      00971E 26 FB            [ 1] 1283 	jrne	00239$
      009720                       1284 00240$:
                                   1285 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 689: itmask1 = (uint8_t)((uint8_t)UART1_IT >> (uint8_t)4);
      009720 9F               [ 1] 1286 	ld	a, xl
      009721 4E               [ 1] 1287 	swap	a
      009722 A4 0F            [ 1] 1288 	and	a, #0x0f
                                   1289 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 691: itmask2 = (uint8_t)((uint8_t)1 << itmask1);
      009724 88               [ 1] 1290 	push	a
      009725 A6 01            [ 1] 1291 	ld	a, #0x01
      009727 6B 04            [ 1] 1292 	ld	(0x04, sp), a
      009729 84               [ 1] 1293 	pop	a
      00972A 4D               [ 1] 1294 	tnz	a
      00972B 27 05            [ 1] 1295 	jreq	00242$
      00972D                       1296 00241$:
      00972D 08 03            [ 1] 1297 	sll	(0x03, sp)
      00972F 4A               [ 1] 1298 	dec	a
      009730 26 FB            [ 1] 1299 	jrne	00241$
      009732                       1300 00242$:
                                   1301 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 695: if (UART1_IT == UART1_IT_PE)
      009732 0D 01            [ 1] 1302 	tnz	(0x01, sp)
      009734 27 18            [ 1] 1303 	jreq	00117$
                                   1304 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 698: enablestatus = (uint8_t)((uint8_t)UART1->CR1 & itmask2);
      009736 C6 52 34         [ 1] 1305 	ld	a, 0x5234
      009739 14 03            [ 1] 1306 	and	a, (0x03, sp)
      00973B 97               [ 1] 1307 	ld	xl, a
                                   1308 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 701: if (((UART1->SR & itpos) != (uint8_t)0x00) && enablestatus)
      00973C C6 52 30         [ 1] 1309 	ld	a, 0x5230
      00973F 14 04            [ 1] 1310 	and	a, (0x04, sp)
      009741 27 08            [ 1] 1311 	jreq	00102$
      009743 9F               [ 1] 1312 	ld	a, xl
      009744 4D               [ 1] 1313 	tnz	a
      009745 27 04            [ 1] 1314 	jreq	00102$
                                   1315 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 704: pendingbitstatus = SET;
      009747 A6 01            [ 1] 1316 	ld	a, #0x01
      009749 20 34            [ 2] 1317 	jra	00118$
      00974B                       1318 00102$:
                                   1319 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 709: pendingbitstatus = RESET;
      00974B 4F               [ 1] 1320 	clr	a
      00974C 20 31            [ 2] 1321 	jra	00118$
      00974E                       1322 00117$:
                                   1323 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 713: else if (UART1_IT == UART1_IT_LBDF)
      00974E 0D 02            [ 1] 1324 	tnz	(0x02, sp)
      009750 27 18            [ 1] 1325 	jreq	00114$
                                   1326 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 716: enablestatus = (uint8_t)((uint8_t)UART1->CR4 & itmask2);
      009752 C6 52 37         [ 1] 1327 	ld	a, 0x5237
      009755 14 03            [ 1] 1328 	and	a, (0x03, sp)
      009757 97               [ 1] 1329 	ld	xl, a
                                   1330 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 718: if (((UART1->CR4 & itpos) != (uint8_t)0x00) && enablestatus)
      009758 C6 52 37         [ 1] 1331 	ld	a, 0x5237
      00975B 14 04            [ 1] 1332 	and	a, (0x04, sp)
      00975D 27 08            [ 1] 1333 	jreq	00106$
      00975F 9F               [ 1] 1334 	ld	a, xl
      009760 4D               [ 1] 1335 	tnz	a
      009761 27 04            [ 1] 1336 	jreq	00106$
                                   1337 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 721: pendingbitstatus = SET;
      009763 A6 01            [ 1] 1338 	ld	a, #0x01
      009765 20 18            [ 2] 1339 	jra	00118$
      009767                       1340 00106$:
                                   1341 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 726: pendingbitstatus = RESET;
      009767 4F               [ 1] 1342 	clr	a
      009768 20 15            [ 2] 1343 	jra	00118$
      00976A                       1344 00114$:
                                   1345 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 732: enablestatus = (uint8_t)((uint8_t)UART1->CR2 & itmask2);
      00976A C6 52 35         [ 1] 1346 	ld	a, 0x5235
      00976D 14 03            [ 1] 1347 	and	a, (0x03, sp)
      00976F 97               [ 1] 1348 	ld	xl, a
                                   1349 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 734: if (((UART1->SR & itpos) != (uint8_t)0x00) && enablestatus)
      009770 C6 52 30         [ 1] 1350 	ld	a, 0x5230
      009773 14 04            [ 1] 1351 	and	a, (0x04, sp)
      009775 27 07            [ 1] 1352 	jreq	00110$
      009777 9F               [ 1] 1353 	ld	a, xl
      009778 4D               [ 1] 1354 	tnz	a
      009779 27 03            [ 1] 1355 	jreq	00110$
                                   1356 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 737: pendingbitstatus = SET;
      00977B A6 01            [ 1] 1357 	ld	a, #0x01
                                   1358 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 742: pendingbitstatus = RESET;
      00977D 21                    1359 	.byte 0x21
      00977E                       1360 00110$:
      00977E 4F               [ 1] 1361 	clr	a
      00977F                       1362 00118$:
                                   1363 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 747: return  pendingbitstatus;
                                   1364 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 748: }
      00977F 5B 04            [ 2] 1365 	addw	sp, #4
      009781 81               [ 4] 1366 	ret
                                   1367 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 775: void UART1_ClearITPendingBit(UART1_IT_TypeDef UART1_IT)
                                   1368 ;	-----------------------------------------
                                   1369 ;	 function UART1_ClearITPendingBit
                                   1370 ;	-----------------------------------------
      009782                       1371 _UART1_ClearITPendingBit:
                                   1372 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 777: assert_param(IS_UART1_CLEAR_IT_OK(UART1_IT));
      009782 1E 03            [ 2] 1373 	ldw	x, (0x03, sp)
      009784 A3 02 55         [ 2] 1374 	cpw	x, #0x0255
      009787 26 03            [ 1] 1375 	jrne	00127$
      009789 A6 01            [ 1] 1376 	ld	a, #0x01
      00978B 21                    1377 	.byte 0x21
      00978C                       1378 00127$:
      00978C 4F               [ 1] 1379 	clr	a
      00978D                       1380 00128$:
      00978D 4D               [ 1] 1381 	tnz	a
      00978E 26 18            [ 1] 1382 	jrne	00107$
      009790 1E 03            [ 2] 1383 	ldw	x, (0x03, sp)
      009792 A3 03 46         [ 2] 1384 	cpw	x, #0x0346
      009795 27 11            [ 1] 1385 	jreq	00107$
      009797 88               [ 1] 1386 	push	a
      009798 4B 09            [ 1] 1387 	push	#0x09
      00979A 4B 03            [ 1] 1388 	push	#0x03
      00979C 5F               [ 1] 1389 	clrw	x
      00979D 89               [ 2] 1390 	pushw	x
      00979E 4B 62            [ 1] 1391 	push	#<___str_0
      0097A0 4B 81            [ 1] 1392 	push	#(___str_0 >> 8)
      0097A2 CD 83 14         [ 4] 1393 	call	_assert_failed
      0097A5 5B 06            [ 2] 1394 	addw	sp, #6
      0097A7 84               [ 1] 1395 	pop	a
      0097A8                       1396 00107$:
                                   1397 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 780: if (UART1_IT == UART1_IT_RXNE)
      0097A8 4D               [ 1] 1398 	tnz	a
      0097A9 27 05            [ 1] 1399 	jreq	00102$
                                   1400 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 782: UART1->SR = (uint8_t)~(UART1_SR_RXNE);
      0097AB 35 DF 52 30      [ 1] 1401 	mov	0x5230+0, #0xdf
      0097AF 81               [ 4] 1402 	ret
      0097B0                       1403 00102$:
                                   1404 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 787: UART1->CR4 &= (uint8_t)~(UART1_CR4_LBDF);
      0097B0 72 19 52 37      [ 1] 1405 	bres	21047, #4
                                   1406 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c: 789: }
      0097B4 81               [ 4] 1407 	ret
                                   1408 	.area CODE
                                   1409 	.area CONST
      008162                       1410 ___str_0:
      008162 2E 2E 2F 2E 2E 2F 2E  1411 	.ascii "../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_uart1.c"
             2E 2F 4C 69 62 72 61
             72 69 65 73 2F 53 54
             4D 38 53 5F 53 74 64
             50 65 72 69 70 68 5F
             44 72 69 76 65 72 2F
             73 72 63 2F 73 74 6D
             38 73 5F 75 61 72 74
             31 2E 63
      00819D 00                    1412 	.db 0x00
                                   1413 	.area INITIALIZER
                                   1414 	.area CABS (ABS)
