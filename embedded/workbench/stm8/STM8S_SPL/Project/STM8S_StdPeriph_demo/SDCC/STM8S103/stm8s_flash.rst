                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_flash
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _assert_failed
                                     12 	.globl _FLASH_Unlock
                                     13 	.globl _FLASH_Lock
                                     14 	.globl _FLASH_DeInit
                                     15 	.globl _FLASH_ITConfig
                                     16 	.globl _FLASH_EraseByte
                                     17 	.globl _FLASH_ProgramByte
                                     18 	.globl _FLASH_ReadByte
                                     19 	.globl _FLASH_ProgramWord
                                     20 	.globl _FLASH_ProgramOptionByte
                                     21 	.globl _FLASH_EraseOptionByte
                                     22 	.globl _FLASH_ReadOptionByte
                                     23 	.globl _FLASH_SetLowPowerMode
                                     24 	.globl _FLASH_SetProgrammingTime
                                     25 	.globl _FLASH_GetLowPowerMode
                                     26 	.globl _FLASH_GetProgrammingTime
                                     27 	.globl _FLASH_GetBootSize
                                     28 	.globl _FLASH_GetFlagStatus
                                     29 	.globl _FLASH_WaitForLastOperation
                                     30 	.globl _FLASH_EraseBlock
                                     31 	.globl _FLASH_ProgramBlock
                                     32 ;--------------------------------------------------------
                                     33 ; ram data
                                     34 ;--------------------------------------------------------
                                     35 	.area DATA
                                     36 ;--------------------------------------------------------
                                     37 ; ram data
                                     38 ;--------------------------------------------------------
                                     39 	.area INITIALIZED
                                     40 ;--------------------------------------------------------
                                     41 ; absolute external ram data
                                     42 ;--------------------------------------------------------
                                     43 	.area DABS (ABS)
                                     44 
                                     45 ; default segment ordering for linker
                                     46 	.area HOME
                                     47 	.area GSINIT
                                     48 	.area GSFINAL
                                     49 	.area CONST
                                     50 	.area INITIALIZER
                                     51 	.area CODE
                                     52 
                                     53 ;--------------------------------------------------------
                                     54 ; global & static initialisations
                                     55 ;--------------------------------------------------------
                                     56 	.area HOME
                                     57 	.area GSINIT
                                     58 	.area GSFINAL
                                     59 	.area GSINIT
                                     60 ;--------------------------------------------------------
                                     61 ; Home
                                     62 ;--------------------------------------------------------
                                     63 	.area HOME
                                     64 	.area HOME
                                     65 ;--------------------------------------------------------
                                     66 ; code
                                     67 ;--------------------------------------------------------
                                     68 	.area CODE
                                     69 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 168: void FLASH_Unlock(FLASH_MemType_TypeDef FLASH_MemType)
                                     70 ;	-----------------------------------------
                                     71 ;	 function FLASH_Unlock
                                     72 ;	-----------------------------------------
      008B40                         73 _FLASH_Unlock:
                                     74 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 171: assert_param(IS_MEMORY_TYPE_OK(FLASH_MemType));
      008B40 7B 03            [ 1]   75 	ld	a, (0x03, sp)
      008B42 A0 FD            [ 1]   76 	sub	a, #0xfd
      008B44 26 02            [ 1]   77 	jrne	00127$
      008B46 4C               [ 1]   78 	inc	a
      008B47 21                      79 	.byte 0x21
      008B48                         80 00127$:
      008B48 4F               [ 1]   81 	clr	a
      008B49                         82 00128$:
      008B49 4D               [ 1]   83 	tnz	a
      008B4A 26 19            [ 1]   84 	jrne	00107$
      008B4C 88               [ 1]   85 	push	a
      008B4D 7B 04            [ 1]   86 	ld	a, (0x04, sp)
      008B4F A1 F7            [ 1]   87 	cp	a, #0xf7
      008B51 84               [ 1]   88 	pop	a
      008B52 27 11            [ 1]   89 	jreq	00107$
      008B54 88               [ 1]   90 	push	a
      008B55 4B AB            [ 1]   91 	push	#0xab
      008B57 5F               [ 1]   92 	clrw	x
      008B58 89               [ 2]   93 	pushw	x
      008B59 4B 00            [ 1]   94 	push	#0x00
      008B5B 4B 26            [ 1]   95 	push	#<___str_0
      008B5D 4B 81            [ 1]   96 	push	#(___str_0 >> 8)
      008B5F CD 83 14         [ 4]   97 	call	_assert_failed
      008B62 5B 06            [ 2]   98 	addw	sp, #6
      008B64 84               [ 1]   99 	pop	a
      008B65                        100 00107$:
                                    101 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 174: if(FLASH_MemType == FLASH_MEMTYPE_PROG)
      008B65 4D               [ 1]  102 	tnz	a
      008B66 27 09            [ 1]  103 	jreq	00102$
                                    104 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 176: FLASH->PUKR = FLASH_RASS_KEY1;
      008B68 35 56 50 62      [ 1]  105 	mov	0x5062+0, #0x56
                                    106 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 177: FLASH->PUKR = FLASH_RASS_KEY2;
      008B6C 35 AE 50 62      [ 1]  107 	mov	0x5062+0, #0xae
      008B70 81               [ 4]  108 	ret
      008B71                        109 00102$:
                                    110 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 182: FLASH->DUKR = FLASH_RASS_KEY2; /* Warning: keys are reversed on data memory !!! */
      008B71 35 AE 50 64      [ 1]  111 	mov	0x5064+0, #0xae
                                    112 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 183: FLASH->DUKR = FLASH_RASS_KEY1;
      008B75 35 56 50 64      [ 1]  113 	mov	0x5064+0, #0x56
                                    114 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 185: }
      008B79 81               [ 4]  115 	ret
                                    116 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 193: void FLASH_Lock(FLASH_MemType_TypeDef FLASH_MemType)
                                    117 ;	-----------------------------------------
                                    118 ;	 function FLASH_Lock
                                    119 ;	-----------------------------------------
      008B7A                        120 _FLASH_Lock:
                                    121 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 196: assert_param(IS_MEMORY_TYPE_OK(FLASH_MemType));
      008B7A 7B 03            [ 1]  122 	ld	a, (0x03, sp)
      008B7C A1 FD            [ 1]  123 	cp	a, #0xfd
      008B7E 27 15            [ 1]  124 	jreq	00104$
      008B80 7B 03            [ 1]  125 	ld	a, (0x03, sp)
      008B82 A1 F7            [ 1]  126 	cp	a, #0xf7
      008B84 27 0F            [ 1]  127 	jreq	00104$
      008B86 4B C4            [ 1]  128 	push	#0xc4
      008B88 5F               [ 1]  129 	clrw	x
      008B89 89               [ 2]  130 	pushw	x
      008B8A 4B 00            [ 1]  131 	push	#0x00
      008B8C 4B 26            [ 1]  132 	push	#<___str_0
      008B8E 4B 81            [ 1]  133 	push	#(___str_0 >> 8)
      008B90 CD 83 14         [ 4]  134 	call	_assert_failed
      008B93 5B 06            [ 2]  135 	addw	sp, #6
      008B95                        136 00104$:
                                    137 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 199: FLASH->IAPSR &= (uint8_t)FLASH_MemType;
      008B95 C6 50 5F         [ 1]  138 	ld	a, 0x505f
      008B98 14 03            [ 1]  139 	and	a, (0x03, sp)
      008B9A C7 50 5F         [ 1]  140 	ld	0x505f, a
                                    141 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 200: }
      008B9D 81               [ 4]  142 	ret
                                    143 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 207: void FLASH_DeInit(void)
                                    144 ;	-----------------------------------------
                                    145 ;	 function FLASH_DeInit
                                    146 ;	-----------------------------------------
      008B9E                        147 _FLASH_DeInit:
                                    148 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 209: FLASH->CR1 = FLASH_CR1_RESET_VALUE;
      008B9E 35 00 50 5A      [ 1]  149 	mov	0x505a+0, #0x00
                                    150 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 210: FLASH->CR2 = FLASH_CR2_RESET_VALUE;
      008BA2 35 00 50 5B      [ 1]  151 	mov	0x505b+0, #0x00
                                    152 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 211: FLASH->NCR2 = FLASH_NCR2_RESET_VALUE;
      008BA6 35 FF 50 5C      [ 1]  153 	mov	0x505c+0, #0xff
                                    154 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 212: FLASH->IAPSR &= (uint8_t)(~FLASH_IAPSR_DUL);
      008BAA 72 17 50 5F      [ 1]  155 	bres	20575, #3
                                    156 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 213: FLASH->IAPSR &= (uint8_t)(~FLASH_IAPSR_PUL);
      008BAE 72 13 50 5F      [ 1]  157 	bres	20575, #1
                                    158 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 214: (void) FLASH->IAPSR; /* Reading of this register causes the clearing of status flags */
      008BB2 C6 50 5F         [ 1]  159 	ld	a, 0x505f
                                    160 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 215: }
      008BB5 81               [ 4]  161 	ret
                                    162 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 223: void FLASH_ITConfig(FunctionalState NewState)
                                    163 ;	-----------------------------------------
                                    164 ;	 function FLASH_ITConfig
                                    165 ;	-----------------------------------------
      008BB6                        166 _FLASH_ITConfig:
                                    167 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 226: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008BB6 0D 03            [ 1]  168 	tnz	(0x03, sp)
      008BB8 27 14            [ 1]  169 	jreq	00107$
      008BBA 7B 03            [ 1]  170 	ld	a, (0x03, sp)
      008BBC 4A               [ 1]  171 	dec	a
      008BBD 27 0F            [ 1]  172 	jreq	00107$
      008BBF 4B E2            [ 1]  173 	push	#0xe2
      008BC1 5F               [ 1]  174 	clrw	x
      008BC2 89               [ 2]  175 	pushw	x
      008BC3 4B 00            [ 1]  176 	push	#0x00
      008BC5 4B 26            [ 1]  177 	push	#<___str_0
      008BC7 4B 81            [ 1]  178 	push	#(___str_0 >> 8)
      008BC9 CD 83 14         [ 4]  179 	call	_assert_failed
      008BCC 5B 06            [ 2]  180 	addw	sp, #6
      008BCE                        181 00107$:
                                    182 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 230: FLASH->CR1 |= FLASH_CR1_IE; /* Enables the interrupt sources */
      008BCE C6 50 5A         [ 1]  183 	ld	a, 0x505a
                                    184 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 228: if(NewState != DISABLE)
      008BD1 0D 03            [ 1]  185 	tnz	(0x03, sp)
      008BD3 27 06            [ 1]  186 	jreq	00102$
                                    187 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 230: FLASH->CR1 |= FLASH_CR1_IE; /* Enables the interrupt sources */
      008BD5 AA 02            [ 1]  188 	or	a, #0x02
      008BD7 C7 50 5A         [ 1]  189 	ld	0x505a, a
      008BDA 81               [ 4]  190 	ret
      008BDB                        191 00102$:
                                    192 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 234: FLASH->CR1 &= (uint8_t)(~FLASH_CR1_IE); /* Disables the interrupt sources */
      008BDB A4 FD            [ 1]  193 	and	a, #0xfd
      008BDD C7 50 5A         [ 1]  194 	ld	0x505a, a
                                    195 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 236: }
      008BE0 81               [ 4]  196 	ret
                                    197 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 245: void FLASH_EraseByte(uint32_t Address)
                                    198 ;	-----------------------------------------
                                    199 ;	 function FLASH_EraseByte
                                    200 ;	-----------------------------------------
      008BE1                        201 _FLASH_EraseByte:
                                    202 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 248: assert_param(IS_FLASH_ADDRESS_OK(Address));
      008BE1 1E 05            [ 2]  203 	ldw	x, (0x05, sp)
      008BE3 A3 80 00         [ 2]  204 	cpw	x, #0x8000
      008BE6 7B 04            [ 1]  205 	ld	a, (0x04, sp)
      008BE8 A2 00            [ 1]  206 	sbc	a, #0x00
      008BEA 7B 03            [ 1]  207 	ld	a, (0x03, sp)
      008BEC A2 00            [ 1]  208 	sbc	a, #0x00
      008BEE 25 0D            [ 1]  209 	jrc	00110$
      008BF0 AE 9F FF         [ 2]  210 	ldw	x, #0x9fff
      008BF3 13 05            [ 2]  211 	cpw	x, (0x05, sp)
      008BF5 4F               [ 1]  212 	clr	a
      008BF6 12 04            [ 1]  213 	sbc	a, (0x04, sp)
      008BF8 4F               [ 1]  214 	clr	a
      008BF9 12 03            [ 1]  215 	sbc	a, (0x03, sp)
      008BFB 24 2B            [ 1]  216 	jrnc	00104$
      008BFD                        217 00110$:
      008BFD 1E 05            [ 2]  218 	ldw	x, (0x05, sp)
      008BFF A3 40 00         [ 2]  219 	cpw	x, #0x4000
      008C02 7B 04            [ 1]  220 	ld	a, (0x04, sp)
      008C04 A2 00            [ 1]  221 	sbc	a, #0x00
      008C06 7B 03            [ 1]  222 	ld	a, (0x03, sp)
      008C08 A2 00            [ 1]  223 	sbc	a, #0x00
      008C0A 25 0D            [ 1]  224 	jrc	00103$
      008C0C AE 42 7F         [ 2]  225 	ldw	x, #0x427f
      008C0F 13 05            [ 2]  226 	cpw	x, (0x05, sp)
      008C11 4F               [ 1]  227 	clr	a
      008C12 12 04            [ 1]  228 	sbc	a, (0x04, sp)
      008C14 4F               [ 1]  229 	clr	a
      008C15 12 03            [ 1]  230 	sbc	a, (0x03, sp)
      008C17 24 0F            [ 1]  231 	jrnc	00104$
      008C19                        232 00103$:
      008C19 4B F8            [ 1]  233 	push	#0xf8
      008C1B 5F               [ 1]  234 	clrw	x
      008C1C 89               [ 2]  235 	pushw	x
      008C1D 4B 00            [ 1]  236 	push	#0x00
      008C1F 4B 26            [ 1]  237 	push	#<___str_0
      008C21 4B 81            [ 1]  238 	push	#(___str_0 >> 8)
      008C23 CD 83 14         [ 4]  239 	call	_assert_failed
      008C26 5B 06            [ 2]  240 	addw	sp, #6
      008C28                        241 00104$:
                                    242 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 253: *(PointerAttr uint8_t*) (MemoryAddressCast)Address = FLASH_CLEAR_BYTE;
      008C28 1E 05            [ 2]  243 	ldw	x, (0x05, sp)
      008C2A 7F               [ 1]  244 	clr	(x)
                                    245 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 257: }
      008C2B 81               [ 4]  246 	ret
                                    247 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 267: void FLASH_ProgramByte(uint32_t Address, uint8_t Data)
                                    248 ;	-----------------------------------------
                                    249 ;	 function FLASH_ProgramByte
                                    250 ;	-----------------------------------------
      008C2C                        251 _FLASH_ProgramByte:
                                    252 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 270: assert_param(IS_FLASH_ADDRESS_OK(Address));
      008C2C 1E 05            [ 2]  253 	ldw	x, (0x05, sp)
      008C2E A3 80 00         [ 2]  254 	cpw	x, #0x8000
      008C31 7B 04            [ 1]  255 	ld	a, (0x04, sp)
      008C33 A2 00            [ 1]  256 	sbc	a, #0x00
      008C35 7B 03            [ 1]  257 	ld	a, (0x03, sp)
      008C37 A2 00            [ 1]  258 	sbc	a, #0x00
      008C39 25 0D            [ 1]  259 	jrc	00110$
      008C3B AE 9F FF         [ 2]  260 	ldw	x, #0x9fff
      008C3E 13 05            [ 2]  261 	cpw	x, (0x05, sp)
      008C40 4F               [ 1]  262 	clr	a
      008C41 12 04            [ 1]  263 	sbc	a, (0x04, sp)
      008C43 4F               [ 1]  264 	clr	a
      008C44 12 03            [ 1]  265 	sbc	a, (0x03, sp)
      008C46 24 2B            [ 1]  266 	jrnc	00104$
      008C48                        267 00110$:
      008C48 1E 05            [ 2]  268 	ldw	x, (0x05, sp)
      008C4A A3 40 00         [ 2]  269 	cpw	x, #0x4000
      008C4D 7B 04            [ 1]  270 	ld	a, (0x04, sp)
      008C4F A2 00            [ 1]  271 	sbc	a, #0x00
      008C51 7B 03            [ 1]  272 	ld	a, (0x03, sp)
      008C53 A2 00            [ 1]  273 	sbc	a, #0x00
      008C55 25 0D            [ 1]  274 	jrc	00103$
      008C57 AE 42 7F         [ 2]  275 	ldw	x, #0x427f
      008C5A 13 05            [ 2]  276 	cpw	x, (0x05, sp)
      008C5C 4F               [ 1]  277 	clr	a
      008C5D 12 04            [ 1]  278 	sbc	a, (0x04, sp)
      008C5F 4F               [ 1]  279 	clr	a
      008C60 12 03            [ 1]  280 	sbc	a, (0x03, sp)
      008C62 24 0F            [ 1]  281 	jrnc	00104$
      008C64                        282 00103$:
      008C64 4B 0E            [ 1]  283 	push	#0x0e
      008C66 4B 01            [ 1]  284 	push	#0x01
      008C68 5F               [ 1]  285 	clrw	x
      008C69 89               [ 2]  286 	pushw	x
      008C6A 4B 26            [ 1]  287 	push	#<___str_0
      008C6C 4B 81            [ 1]  288 	push	#(___str_0 >> 8)
      008C6E CD 83 14         [ 4]  289 	call	_assert_failed
      008C71 5B 06            [ 2]  290 	addw	sp, #6
      008C73                        291 00104$:
                                    292 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 275: *(PointerAttr uint8_t*) (MemoryAddressCast)Address = Data;
      008C73 1E 05            [ 2]  293 	ldw	x, (0x05, sp)
      008C75 7B 07            [ 1]  294 	ld	a, (0x07, sp)
      008C77 F7               [ 1]  295 	ld	(x), a
                                    296 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 279: }
      008C78 81               [ 4]  297 	ret
                                    298 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 288: uint8_t FLASH_ReadByte(uint32_t Address)
                                    299 ;	-----------------------------------------
                                    300 ;	 function FLASH_ReadByte
                                    301 ;	-----------------------------------------
      008C79                        302 _FLASH_ReadByte:
                                    303 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 291: assert_param(IS_FLASH_ADDRESS_OK(Address));
      008C79 1E 05            [ 2]  304 	ldw	x, (0x05, sp)
      008C7B A3 80 00         [ 2]  305 	cpw	x, #0x8000
      008C7E 7B 04            [ 1]  306 	ld	a, (0x04, sp)
      008C80 A2 00            [ 1]  307 	sbc	a, #0x00
      008C82 7B 03            [ 1]  308 	ld	a, (0x03, sp)
      008C84 A2 00            [ 1]  309 	sbc	a, #0x00
      008C86 25 0D            [ 1]  310 	jrc	00110$
      008C88 AE 9F FF         [ 2]  311 	ldw	x, #0x9fff
      008C8B 13 05            [ 2]  312 	cpw	x, (0x05, sp)
      008C8D 4F               [ 1]  313 	clr	a
      008C8E 12 04            [ 1]  314 	sbc	a, (0x04, sp)
      008C90 4F               [ 1]  315 	clr	a
      008C91 12 03            [ 1]  316 	sbc	a, (0x03, sp)
      008C93 24 2B            [ 1]  317 	jrnc	00104$
      008C95                        318 00110$:
      008C95 1E 05            [ 2]  319 	ldw	x, (0x05, sp)
      008C97 A3 40 00         [ 2]  320 	cpw	x, #0x4000
      008C9A 7B 04            [ 1]  321 	ld	a, (0x04, sp)
      008C9C A2 00            [ 1]  322 	sbc	a, #0x00
      008C9E 7B 03            [ 1]  323 	ld	a, (0x03, sp)
      008CA0 A2 00            [ 1]  324 	sbc	a, #0x00
      008CA2 25 0D            [ 1]  325 	jrc	00103$
      008CA4 AE 42 7F         [ 2]  326 	ldw	x, #0x427f
      008CA7 13 05            [ 2]  327 	cpw	x, (0x05, sp)
      008CA9 4F               [ 1]  328 	clr	a
      008CAA 12 04            [ 1]  329 	sbc	a, (0x04, sp)
      008CAC 4F               [ 1]  330 	clr	a
      008CAD 12 03            [ 1]  331 	sbc	a, (0x03, sp)
      008CAF 24 0F            [ 1]  332 	jrnc	00104$
      008CB1                        333 00103$:
      008CB1 4B 23            [ 1]  334 	push	#0x23
      008CB3 4B 01            [ 1]  335 	push	#0x01
      008CB5 5F               [ 1]  336 	clrw	x
      008CB6 89               [ 2]  337 	pushw	x
      008CB7 4B 26            [ 1]  338 	push	#<___str_0
      008CB9 4B 81            [ 1]  339 	push	#(___str_0 >> 8)
      008CBB CD 83 14         [ 4]  340 	call	_assert_failed
      008CBE 5B 06            [ 2]  341 	addw	sp, #6
      008CC0                        342 00104$:
                                    343 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 296: return(*(PointerAttr uint8_t *) (MemoryAddressCast)Address); 
      008CC0 1E 05            [ 2]  344 	ldw	x, (0x05, sp)
      008CC2 F6               [ 1]  345 	ld	a, (x)
                                    346 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 300: }
      008CC3 81               [ 4]  347 	ret
                                    348 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 310: void FLASH_ProgramWord(uint32_t Address, uint32_t Data)
                                    349 ;	-----------------------------------------
                                    350 ;	 function FLASH_ProgramWord
                                    351 ;	-----------------------------------------
      008CC4                        352 _FLASH_ProgramWord:
      008CC4 52 06            [ 2]  353 	sub	sp, #6
                                    354 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 313: assert_param(IS_FLASH_ADDRESS_OK(Address));
      008CC6 1E 0B            [ 2]  355 	ldw	x, (0x0b, sp)
      008CC8 A3 80 00         [ 2]  356 	cpw	x, #0x8000
      008CCB 7B 0A            [ 1]  357 	ld	a, (0x0a, sp)
      008CCD A2 00            [ 1]  358 	sbc	a, #0x00
      008CCF 7B 09            [ 1]  359 	ld	a, (0x09, sp)
      008CD1 A2 00            [ 1]  360 	sbc	a, #0x00
      008CD3 25 0D            [ 1]  361 	jrc	00110$
      008CD5 AE 9F FF         [ 2]  362 	ldw	x, #0x9fff
      008CD8 13 0B            [ 2]  363 	cpw	x, (0x0b, sp)
      008CDA 4F               [ 1]  364 	clr	a
      008CDB 12 0A            [ 1]  365 	sbc	a, (0x0a, sp)
      008CDD 4F               [ 1]  366 	clr	a
      008CDE 12 09            [ 1]  367 	sbc	a, (0x09, sp)
      008CE0 24 2B            [ 1]  368 	jrnc	00104$
      008CE2                        369 00110$:
      008CE2 1E 0B            [ 2]  370 	ldw	x, (0x0b, sp)
      008CE4 A3 40 00         [ 2]  371 	cpw	x, #0x4000
      008CE7 7B 0A            [ 1]  372 	ld	a, (0x0a, sp)
      008CE9 A2 00            [ 1]  373 	sbc	a, #0x00
      008CEB 7B 09            [ 1]  374 	ld	a, (0x09, sp)
      008CED A2 00            [ 1]  375 	sbc	a, #0x00
      008CEF 25 0D            [ 1]  376 	jrc	00103$
      008CF1 AE 42 7F         [ 2]  377 	ldw	x, #0x427f
      008CF4 13 0B            [ 2]  378 	cpw	x, (0x0b, sp)
      008CF6 4F               [ 1]  379 	clr	a
      008CF7 12 0A            [ 1]  380 	sbc	a, (0x0a, sp)
      008CF9 4F               [ 1]  381 	clr	a
      008CFA 12 09            [ 1]  382 	sbc	a, (0x09, sp)
      008CFC 24 0F            [ 1]  383 	jrnc	00104$
      008CFE                        384 00103$:
      008CFE 4B 39            [ 1]  385 	push	#0x39
      008D00 4B 01            [ 1]  386 	push	#0x01
      008D02 5F               [ 1]  387 	clrw	x
      008D03 89               [ 2]  388 	pushw	x
      008D04 4B 26            [ 1]  389 	push	#<___str_0
      008D06 4B 81            [ 1]  390 	push	#(___str_0 >> 8)
      008D08 CD 83 14         [ 4]  391 	call	_assert_failed
      008D0B 5B 06            [ 2]  392 	addw	sp, #6
      008D0D                        393 00104$:
                                    394 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 316: FLASH->CR2 |= FLASH_CR2_WPRG;
      008D0D 72 1C 50 5B      [ 1]  395 	bset	20571, #6
                                    396 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 317: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NWPRG);
      008D11 72 1D 50 5C      [ 1]  397 	bres	20572, #6
                                    398 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 322: *((PointerAttr uint8_t*)(MemoryAddressCast)Address)       = *((uint8_t*)(&Data));
      008D15 16 0B            [ 2]  399 	ldw	y, (0x0b, sp)
      008D17 96               [ 1]  400 	ldw	x, sp
      008D18 1C 00 0D         [ 2]  401 	addw	x, #13
      008D1B 1F 05            [ 2]  402 	ldw	(0x05, sp), x
      008D1D F6               [ 1]  403 	ld	a, (x)
      008D1E 90 F7            [ 1]  404 	ld	(y), a
                                    405 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 324: *(((PointerAttr uint8_t*)(MemoryAddressCast)Address) + 1) = *((uint8_t*)(&Data)+1); 
      008D20 93               [ 1]  406 	ldw	x, y
      008D21 5C               [ 1]  407 	incw	x
      008D22 1F 03            [ 2]  408 	ldw	(0x03, sp), x
      008D24 1E 05            [ 2]  409 	ldw	x, (0x05, sp)
      008D26 E6 01            [ 1]  410 	ld	a, (0x1, x)
      008D28 1E 03            [ 2]  411 	ldw	x, (0x03, sp)
      008D2A F7               [ 1]  412 	ld	(x), a
                                    413 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 326: *(((PointerAttr uint8_t*)(MemoryAddressCast)Address) + 2) = *((uint8_t*)(&Data)+2); 
      008D2B 93               [ 1]  414 	ldw	x, y
      008D2C 5C               [ 1]  415 	incw	x
      008D2D 5C               [ 1]  416 	incw	x
      008D2E 1F 01            [ 2]  417 	ldw	(0x01, sp), x
      008D30 1E 05            [ 2]  418 	ldw	x, (0x05, sp)
      008D32 E6 02            [ 1]  419 	ld	a, (0x2, x)
      008D34 1E 01            [ 2]  420 	ldw	x, (0x01, sp)
      008D36 F7               [ 1]  421 	ld	(x), a
                                    422 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 328: *(((PointerAttr uint8_t*)(MemoryAddressCast)Address) + 3) = *((uint8_t*)(&Data)+3); 
      008D37 72 A9 00 03      [ 2]  423 	addw	y, #0x0003
      008D3B 1E 05            [ 2]  424 	ldw	x, (0x05, sp)
      008D3D E6 03            [ 1]  425 	ld	a, (0x3, x)
      008D3F 90 F7            [ 1]  426 	ld	(y), a
                                    427 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 335: }
      008D41 5B 06            [ 2]  428 	addw	sp, #6
      008D43 81               [ 4]  429 	ret
                                    430 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 343: void FLASH_ProgramOptionByte(uint16_t Address, uint8_t Data)
                                    431 ;	-----------------------------------------
                                    432 ;	 function FLASH_ProgramOptionByte
                                    433 ;	-----------------------------------------
      008D44                        434 _FLASH_ProgramOptionByte:
                                    435 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 346: assert_param(IS_OPTION_BYTE_ADDRESS_OK(Address));
      008D44 1E 03            [ 2]  436 	ldw	x, (0x03, sp)
      008D46 A3 48 00         [ 2]  437 	cpw	x, #0x4800
      008D49 25 07            [ 1]  438 	jrc	00106$
      008D4B 1E 03            [ 2]  439 	ldw	x, (0x03, sp)
      008D4D A3 48 7F         [ 2]  440 	cpw	x, #0x487f
      008D50 23 0F            [ 2]  441 	jrule	00107$
      008D52                        442 00106$:
      008D52 4B 5A            [ 1]  443 	push	#0x5a
      008D54 4B 01            [ 1]  444 	push	#0x01
      008D56 5F               [ 1]  445 	clrw	x
      008D57 89               [ 2]  446 	pushw	x
      008D58 4B 26            [ 1]  447 	push	#<___str_0
      008D5A 4B 81            [ 1]  448 	push	#(___str_0 >> 8)
      008D5C CD 83 14         [ 4]  449 	call	_assert_failed
      008D5F 5B 06            [ 2]  450 	addw	sp, #6
      008D61                        451 00107$:
                                    452 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 349: FLASH->CR2 |= FLASH_CR2_OPT;
      008D61 72 1E 50 5B      [ 1]  453 	bset	20571, #7
                                    454 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 350: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NOPT);
      008D65 C6 50 5C         [ 1]  455 	ld	a, 0x505c
      008D68 A4 7F            [ 1]  456 	and	a, #0x7f
      008D6A C7 50 5C         [ 1]  457 	ld	0x505c, a
                                    458 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 356: *((NEAR uint8_t*)Address) = Data;
      008D6D 1E 03            [ 2]  459 	ldw	x, (0x03, sp)
                                    460 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 353: if(Address == 0x4800)
      008D6F 89               [ 2]  461 	pushw	x
      008D70 1E 05            [ 2]  462 	ldw	x, (0x05, sp)
      008D72 A3 48 00         [ 2]  463 	cpw	x, #0x4800
      008D75 85               [ 2]  464 	popw	x
      008D76 26 05            [ 1]  465 	jrne	00102$
                                    466 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 356: *((NEAR uint8_t*)Address) = Data;
      008D78 7B 05            [ 1]  467 	ld	a, (0x05, sp)
      008D7A F7               [ 1]  468 	ld	(x), a
      008D7B 20 0A            [ 2]  469 	jra	00103$
      008D7D                        470 00102$:
                                    471 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 361: *((NEAR uint8_t*)Address) = Data;
      008D7D 7B 05            [ 1]  472 	ld	a, (0x05, sp)
      008D7F F7               [ 1]  473 	ld	(x), a
                                    474 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 362: *((NEAR uint8_t*)((uint16_t)(Address + 1))) = (uint8_t)(~Data);
      008D80 1E 03            [ 2]  475 	ldw	x, (0x03, sp)
      008D82 5C               [ 1]  476 	incw	x
      008D83 7B 05            [ 1]  477 	ld	a, (0x05, sp)
      008D85 43               [ 1]  478 	cpl	a
      008D86 F7               [ 1]  479 	ld	(x), a
      008D87                        480 00103$:
                                    481 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 364: FLASH_WaitForLastOperation(FLASH_MEMTYPE_PROG);
      008D87 4B FD            [ 1]  482 	push	#0xfd
      008D89 CD 8F 00         [ 4]  483 	call	_FLASH_WaitForLastOperation
      008D8C 84               [ 1]  484 	pop	a
                                    485 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 367: FLASH->CR2 &= (uint8_t)(~FLASH_CR2_OPT);
      008D8D 72 1F 50 5B      [ 1]  486 	bres	20571, #7
                                    487 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 368: FLASH->NCR2 |= FLASH_NCR2_NOPT;
      008D91 72 1E 50 5C      [ 1]  488 	bset	20572, #7
                                    489 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 369: }
      008D95 81               [ 4]  490 	ret
                                    491 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 376: void FLASH_EraseOptionByte(uint16_t Address)
                                    492 ;	-----------------------------------------
                                    493 ;	 function FLASH_EraseOptionByte
                                    494 ;	-----------------------------------------
      008D96                        495 _FLASH_EraseOptionByte:
                                    496 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 379: assert_param(IS_OPTION_BYTE_ADDRESS_OK(Address));
      008D96 1E 03            [ 2]  497 	ldw	x, (0x03, sp)
      008D98 A3 48 00         [ 2]  498 	cpw	x, #0x4800
      008D9B 25 07            [ 1]  499 	jrc	00106$
      008D9D 1E 03            [ 2]  500 	ldw	x, (0x03, sp)
      008D9F A3 48 7F         [ 2]  501 	cpw	x, #0x487f
      008DA2 23 0F            [ 2]  502 	jrule	00107$
      008DA4                        503 00106$:
      008DA4 4B 7B            [ 1]  504 	push	#0x7b
      008DA6 4B 01            [ 1]  505 	push	#0x01
      008DA8 5F               [ 1]  506 	clrw	x
      008DA9 89               [ 2]  507 	pushw	x
      008DAA 4B 26            [ 1]  508 	push	#<___str_0
      008DAC 4B 81            [ 1]  509 	push	#(___str_0 >> 8)
      008DAE CD 83 14         [ 4]  510 	call	_assert_failed
      008DB1 5B 06            [ 2]  511 	addw	sp, #6
      008DB3                        512 00107$:
                                    513 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 382: FLASH->CR2 |= FLASH_CR2_OPT;
      008DB3 72 1E 50 5B      [ 1]  514 	bset	20571, #7
                                    515 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 383: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NOPT);
      008DB7 C6 50 5C         [ 1]  516 	ld	a, 0x505c
      008DBA A4 7F            [ 1]  517 	and	a, #0x7f
      008DBC C7 50 5C         [ 1]  518 	ld	0x505c, a
                                    519 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 389: *((NEAR uint8_t*)Address) = FLASH_CLEAR_BYTE;
      008DBF 16 03            [ 2]  520 	ldw	y, (0x03, sp)
                                    521 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 386: if(Address == 0x4800)
      008DC1 1E 03            [ 2]  522 	ldw	x, (0x03, sp)
      008DC3 A3 48 00         [ 2]  523 	cpw	x, #0x4800
      008DC6 26 04            [ 1]  524 	jrne	00102$
                                    525 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 389: *((NEAR uint8_t*)Address) = FLASH_CLEAR_BYTE;
      008DC8 90 7F            [ 1]  526 	clr	(y)
      008DCA 20 08            [ 2]  527 	jra	00103$
      008DCC                        528 00102$:
                                    529 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 394: *((NEAR uint8_t*)Address) = FLASH_CLEAR_BYTE;
      008DCC 90 7F            [ 1]  530 	clr	(y)
                                    531 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 395: *((NEAR uint8_t*)((uint16_t)(Address + (uint16_t)1 ))) = FLASH_SET_BYTE;
      008DCE 1E 03            [ 2]  532 	ldw	x, (0x03, sp)
      008DD0 5C               [ 1]  533 	incw	x
      008DD1 A6 FF            [ 1]  534 	ld	a, #0xff
      008DD3 F7               [ 1]  535 	ld	(x), a
      008DD4                        536 00103$:
                                    537 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 397: FLASH_WaitForLastOperation(FLASH_MEMTYPE_PROG);
      008DD4 4B FD            [ 1]  538 	push	#0xfd
      008DD6 CD 8F 00         [ 4]  539 	call	_FLASH_WaitForLastOperation
      008DD9 84               [ 1]  540 	pop	a
                                    541 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 400: FLASH->CR2 &= (uint8_t)(~FLASH_CR2_OPT);
      008DDA 72 1F 50 5B      [ 1]  542 	bres	20571, #7
                                    543 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 401: FLASH->NCR2 |= FLASH_NCR2_NOPT;
      008DDE 72 1E 50 5C      [ 1]  544 	bset	20572, #7
                                    545 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 402: }
      008DE2 81               [ 4]  546 	ret
                                    547 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 409: uint16_t FLASH_ReadOptionByte(uint16_t Address)
                                    548 ;	-----------------------------------------
                                    549 ;	 function FLASH_ReadOptionByte
                                    550 ;	-----------------------------------------
      008DE3                        551 _FLASH_ReadOptionByte:
      008DE3 52 07            [ 2]  552 	sub	sp, #7
                                    553 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 415: assert_param(IS_OPTION_BYTE_ADDRESS_OK(Address));
      008DE5 1E 0A            [ 2]  554 	ldw	x, (0x0a, sp)
      008DE7 A3 48 00         [ 2]  555 	cpw	x, #0x4800
      008DEA 25 07            [ 1]  556 	jrc	00109$
      008DEC 1E 0A            [ 2]  557 	ldw	x, (0x0a, sp)
      008DEE A3 48 7F         [ 2]  558 	cpw	x, #0x487f
      008DF1 23 0F            [ 2]  559 	jrule	00110$
      008DF3                        560 00109$:
      008DF3 4B 9F            [ 1]  561 	push	#0x9f
      008DF5 4B 01            [ 1]  562 	push	#0x01
      008DF7 5F               [ 1]  563 	clrw	x
      008DF8 89               [ 2]  564 	pushw	x
      008DF9 4B 26            [ 1]  565 	push	#<___str_0
      008DFB 4B 81            [ 1]  566 	push	#(___str_0 >> 8)
      008DFD CD 83 14         [ 4]  567 	call	_assert_failed
      008E00 5B 06            [ 2]  568 	addw	sp, #6
      008E02                        569 00110$:
                                    570 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 417: value_optbyte = *((NEAR uint8_t*)Address); /* Read option byte */
      008E02 1E 0A            [ 2]  571 	ldw	x, (0x0a, sp)
      008E04 F6               [ 1]  572 	ld	a, (x)
      008E05 6B 04            [ 1]  573 	ld	(0x04, sp), a
                                    574 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 418: value_optbyte_complement = *(((NEAR uint8_t*)Address) + 1); /* Read option byte complement */
      008E07 E6 01            [ 1]  575 	ld	a, (0x1, x)
      008E09 6B 03            [ 1]  576 	ld	(0x03, sp), a
                                    577 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 423: res_value =	 value_optbyte;
      008E0B 90 5F            [ 1]  578 	clrw	y
      008E0D 7B 04            [ 1]  579 	ld	a, (0x04, sp)
      008E0F 90 97            [ 1]  580 	ld	yl, a
                                    581 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 421: if(Address == 0x4800)	 
      008E11 1E 0A            [ 2]  582 	ldw	x, (0x0a, sp)
      008E13 A3 48 00         [ 2]  583 	cpw	x, #0x4800
      008E16 26 03            [ 1]  584 	jrne	00105$
                                    585 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 423: res_value =	 value_optbyte;
      008E18 93               [ 1]  586 	ldw	x, y
      008E19 20 1E            [ 2]  587 	jra	00106$
      008E1B                        588 00105$:
                                    589 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 427: if(value_optbyte == (uint8_t)(~value_optbyte_complement))
      008E1B 7B 03            [ 1]  590 	ld	a, (0x03, sp)
      008E1D 43               [ 1]  591 	cpl	a
      008E1E 6B 05            [ 1]  592 	ld	(0x05, sp), a
      008E20 7B 04            [ 1]  593 	ld	a, (0x04, sp)
      008E22 11 05            [ 1]  594 	cp	a, (0x05, sp)
      008E24 26 10            [ 1]  595 	jrne	00102$
                                    596 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 429: res_value = (uint16_t)((uint16_t)value_optbyte << 8);
      008E26 4F               [ 1]  597 	clr	a
      008E27 6B 02            [ 1]  598 	ld	(0x02, sp), a
                                    599 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 430: res_value = res_value | (uint16_t)value_optbyte_complement;
      008E29 7B 03            [ 1]  600 	ld	a, (0x03, sp)
      008E2B 0F 06            [ 1]  601 	clr	(0x06, sp)
      008E2D 1A 02            [ 1]  602 	or	a, (0x02, sp)
      008E2F 97               [ 1]  603 	ld	xl, a
      008E30 90 9F            [ 1]  604 	ld	a, yl
      008E32 1A 06            [ 1]  605 	or	a, (0x06, sp)
      008E34 95               [ 1]  606 	ld	xh, a
                                    607 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 434: res_value = FLASH_OPTIONBYTE_ERROR;
      008E35 BC                     608 	.byte 0xbc
      008E36                        609 00102$:
      008E36 AE 55 55         [ 2]  610 	ldw	x, #0x5555
      008E39                        611 00106$:
                                    612 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 437: return(res_value);
                                    613 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 438: }
      008E39 5B 07            [ 2]  614 	addw	sp, #7
      008E3B 81               [ 4]  615 	ret
                                    616 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 446: void FLASH_SetLowPowerMode(FLASH_LPMode_TypeDef FLASH_LPMode)
                                    617 ;	-----------------------------------------
                                    618 ;	 function FLASH_SetLowPowerMode
                                    619 ;	-----------------------------------------
      008E3C                        620 _FLASH_SetLowPowerMode:
                                    621 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 449: assert_param(IS_FLASH_LOW_POWER_MODE_OK(FLASH_LPMode));
      008E3C 7B 03            [ 1]  622 	ld	a, (0x03, sp)
      008E3E A1 04            [ 1]  623 	cp	a, #0x04
      008E40 27 1F            [ 1]  624 	jreq	00104$
      008E42 7B 03            [ 1]  625 	ld	a, (0x03, sp)
      008E44 A1 08            [ 1]  626 	cp	a, #0x08
      008E46 27 19            [ 1]  627 	jreq	00104$
      008E48 0D 03            [ 1]  628 	tnz	(0x03, sp)
      008E4A 27 15            [ 1]  629 	jreq	00104$
      008E4C 7B 03            [ 1]  630 	ld	a, (0x03, sp)
      008E4E A1 0C            [ 1]  631 	cp	a, #0x0c
      008E50 27 0F            [ 1]  632 	jreq	00104$
      008E52 4B C1            [ 1]  633 	push	#0xc1
      008E54 4B 01            [ 1]  634 	push	#0x01
      008E56 5F               [ 1]  635 	clrw	x
      008E57 89               [ 2]  636 	pushw	x
      008E58 4B 26            [ 1]  637 	push	#<___str_0
      008E5A 4B 81            [ 1]  638 	push	#(___str_0 >> 8)
      008E5C CD 83 14         [ 4]  639 	call	_assert_failed
      008E5F 5B 06            [ 2]  640 	addw	sp, #6
      008E61                        641 00104$:
                                    642 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 452: FLASH->CR1 &= (uint8_t)(~(FLASH_CR1_HALT | FLASH_CR1_AHALT)); 
      008E61 C6 50 5A         [ 1]  643 	ld	a, 0x505a
      008E64 A4 F3            [ 1]  644 	and	a, #0xf3
      008E66 C7 50 5A         [ 1]  645 	ld	0x505a, a
                                    646 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 455: FLASH->CR1 |= (uint8_t)FLASH_LPMode; 
      008E69 C6 50 5A         [ 1]  647 	ld	a, 0x505a
      008E6C 1A 03            [ 1]  648 	or	a, (0x03, sp)
      008E6E C7 50 5A         [ 1]  649 	ld	0x505a, a
                                    650 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 456: }
      008E71 81               [ 4]  651 	ret
                                    652 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 464: void FLASH_SetProgrammingTime(FLASH_ProgramTime_TypeDef FLASH_ProgTime)
                                    653 ;	-----------------------------------------
                                    654 ;	 function FLASH_SetProgrammingTime
                                    655 ;	-----------------------------------------
      008E72                        656 _FLASH_SetProgrammingTime:
                                    657 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 467: assert_param(IS_FLASH_PROGRAM_TIME_OK(FLASH_ProgTime));
      008E72 0D 03            [ 1]  658 	tnz	(0x03, sp)
      008E74 27 14            [ 1]  659 	jreq	00104$
      008E76 7B 03            [ 1]  660 	ld	a, (0x03, sp)
      008E78 4A               [ 1]  661 	dec	a
      008E79 27 0F            [ 1]  662 	jreq	00104$
      008E7B 4B D3            [ 1]  663 	push	#0xd3
      008E7D 4B 01            [ 1]  664 	push	#0x01
      008E7F 5F               [ 1]  665 	clrw	x
      008E80 89               [ 2]  666 	pushw	x
      008E81 4B 26            [ 1]  667 	push	#<___str_0
      008E83 4B 81            [ 1]  668 	push	#(___str_0 >> 8)
      008E85 CD 83 14         [ 4]  669 	call	_assert_failed
      008E88 5B 06            [ 2]  670 	addw	sp, #6
      008E8A                        671 00104$:
                                    672 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 469: FLASH->CR1 &= (uint8_t)(~FLASH_CR1_FIX);
      008E8A C6 50 5A         [ 1]  673 	ld	a, 0x505a
      008E8D A4 FE            [ 1]  674 	and	a, #0xfe
      008E8F C7 50 5A         [ 1]  675 	ld	0x505a, a
                                    676 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 470: FLASH->CR1 |= (uint8_t)FLASH_ProgTime;
      008E92 C6 50 5A         [ 1]  677 	ld	a, 0x505a
      008E95 1A 03            [ 1]  678 	or	a, (0x03, sp)
      008E97 C7 50 5A         [ 1]  679 	ld	0x505a, a
                                    680 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 471: }
      008E9A 81               [ 4]  681 	ret
                                    682 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 478: FLASH_LPMode_TypeDef FLASH_GetLowPowerMode(void)
                                    683 ;	-----------------------------------------
                                    684 ;	 function FLASH_GetLowPowerMode
                                    685 ;	-----------------------------------------
      008E9B                        686 _FLASH_GetLowPowerMode:
                                    687 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 480: return((FLASH_LPMode_TypeDef)(FLASH->CR1 & (uint8_t)(FLASH_CR1_HALT | FLASH_CR1_AHALT)));
      008E9B C6 50 5A         [ 1]  688 	ld	a, 0x505a
      008E9E A4 0C            [ 1]  689 	and	a, #0x0c
                                    690 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 481: }
      008EA0 81               [ 4]  691 	ret
                                    692 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 488: FLASH_ProgramTime_TypeDef FLASH_GetProgrammingTime(void)
                                    693 ;	-----------------------------------------
                                    694 ;	 function FLASH_GetProgrammingTime
                                    695 ;	-----------------------------------------
      008EA1                        696 _FLASH_GetProgrammingTime:
                                    697 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 490: return((FLASH_ProgramTime_TypeDef)(FLASH->CR1 & FLASH_CR1_FIX));
      008EA1 C6 50 5A         [ 1]  698 	ld	a, 0x505a
      008EA4 A4 01            [ 1]  699 	and	a, #0x01
                                    700 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 491: }
      008EA6 81               [ 4]  701 	ret
                                    702 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 498: uint32_t FLASH_GetBootSize(void)
                                    703 ;	-----------------------------------------
                                    704 ;	 function FLASH_GetBootSize
                                    705 ;	-----------------------------------------
      008EA7                        706 _FLASH_GetBootSize:
      008EA7 52 04            [ 2]  707 	sub	sp, #4
                                    708 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 503: temp = (uint32_t)((uint32_t)FLASH->FPR * (uint32_t)512);
      008EA9 C6 50 5D         [ 1]  709 	ld	a, 0x505d
      008EAC 5F               [ 1]  710 	clrw	x
      008EAD 0F 04            [ 1]  711 	clr	(0x04, sp)
      008EAF 08 04            [ 1]  712 	sll	(0x04, sp)
      008EB1 49               [ 1]  713 	rlc	a
      008EB2 59               [ 2]  714 	rlcw	x
      008EB3 90 95            [ 1]  715 	ld	yh, a
      008EB5 7B 04            [ 1]  716 	ld	a, (0x04, sp)
      008EB7 90 97            [ 1]  717 	ld	yl, a
                                    718 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 506: if(FLASH->FPR == 0xFF)
      008EB9 C6 50 5D         [ 1]  719 	ld	a, 0x505d
      008EBC 4C               [ 1]  720 	inc	a
      008EBD 26 0B            [ 1]  721 	jrne	00102$
                                    722 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 508: temp += 512;
      008EBF 72 A9 02 00      [ 2]  723 	addw	y, #0x0200
      008EC3 9F               [ 1]  724 	ld	a, xl
      008EC4 A9 00            [ 1]  725 	adc	a, #0x00
      008EC6 02               [ 1]  726 	rlwa	x
      008EC7 A9 00            [ 1]  727 	adc	a, #0x00
      008EC9 95               [ 1]  728 	ld	xh, a
      008ECA                        729 00102$:
                                    730 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 512: return(temp);
      008ECA 51               [ 1]  731 	exgw	x, y
                                    732 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 513: }
      008ECB 5B 04            [ 2]  733 	addw	sp, #4
      008ECD 81               [ 4]  734 	ret
                                    735 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 523: FlagStatus FLASH_GetFlagStatus(FLASH_Flag_TypeDef FLASH_FLAG)
                                    736 ;	-----------------------------------------
                                    737 ;	 function FLASH_GetFlagStatus
                                    738 ;	-----------------------------------------
      008ECE                        739 _FLASH_GetFlagStatus:
                                    740 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 527: assert_param(IS_FLASH_FLAGS_OK(FLASH_FLAG));
      008ECE 7B 03            [ 1]  741 	ld	a, (0x03, sp)
      008ED0 A1 08            [ 1]  742 	cp	a, #0x08
      008ED2 27 20            [ 1]  743 	jreq	00107$
      008ED4 7B 03            [ 1]  744 	ld	a, (0x03, sp)
      008ED6 A1 04            [ 1]  745 	cp	a, #0x04
      008ED8 27 1A            [ 1]  746 	jreq	00107$
      008EDA 7B 03            [ 1]  747 	ld	a, (0x03, sp)
      008EDC A1 02            [ 1]  748 	cp	a, #0x02
      008EDE 27 14            [ 1]  749 	jreq	00107$
      008EE0 7B 03            [ 1]  750 	ld	a, (0x03, sp)
      008EE2 4A               [ 1]  751 	dec	a
      008EE3 27 0F            [ 1]  752 	jreq	00107$
      008EE5 4B 0F            [ 1]  753 	push	#0x0f
      008EE7 4B 02            [ 1]  754 	push	#0x02
      008EE9 5F               [ 1]  755 	clrw	x
      008EEA 89               [ 2]  756 	pushw	x
      008EEB 4B 26            [ 1]  757 	push	#<___str_0
      008EED 4B 81            [ 1]  758 	push	#(___str_0 >> 8)
      008EEF CD 83 14         [ 4]  759 	call	_assert_failed
      008EF2 5B 06            [ 2]  760 	addw	sp, #6
      008EF4                        761 00107$:
                                    762 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 530: if((FLASH->IAPSR & (uint8_t)FLASH_FLAG) != (uint8_t)RESET)
      008EF4 C6 50 5F         [ 1]  763 	ld	a, 0x505f
      008EF7 14 03            [ 1]  764 	and	a, (0x03, sp)
      008EF9 27 03            [ 1]  765 	jreq	00102$
                                    766 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 532: status = SET; /* FLASH_FLAG is set */
      008EFB A6 01            [ 1]  767 	ld	a, #0x01
      008EFD 81               [ 4]  768 	ret
      008EFE                        769 00102$:
                                    770 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 536: status = RESET; /* FLASH_FLAG is reset*/
      008EFE 4F               [ 1]  771 	clr	a
                                    772 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 540: return status;
                                    773 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 541: }
      008EFF 81               [ 4]  774 	ret
                                    775 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 660: IN_RAM(FLASH_Status_TypeDef FLASH_WaitForLastOperation(FLASH_MemType_TypeDef FLASH_MemType)) 
                                    776 ;	-----------------------------------------
                                    777 ;	 function FLASH_WaitForLastOperation
                                    778 ;	-----------------------------------------
      008F00                        779 _FLASH_WaitForLastOperation:
                                    780 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 662: uint8_t flagstatus = 0x00;
      008F00 4F               [ 1]  781 	clr	a
                                    782 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 688: while((flagstatus == 0x00) && (timeout != 0x00))
      008F01 5F               [ 1]  783 	clrw	x
      008F02 5A               [ 2]  784 	decw	x
      008F03                        785 00102$:
      008F03 4D               [ 1]  786 	tnz	a
      008F04 26 0B            [ 1]  787 	jrne	00104$
      008F06 5D               [ 2]  788 	tnzw	x
      008F07 27 08            [ 1]  789 	jreq	00104$
                                    790 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 690: flagstatus = (uint8_t)(FLASH->IAPSR & (FLASH_IAPSR_EOP | FLASH_IAPSR_WR_PG_DIS));
      008F09 C6 50 5F         [ 1]  791 	ld	a, 0x505f
      008F0C A4 05            [ 1]  792 	and	a, #0x05
                                    793 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 691: timeout--;
      008F0E 5A               [ 2]  794 	decw	x
      008F0F 20 F2            [ 2]  795 	jra	00102$
      008F11                        796 00104$:
                                    797 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 695: if(timeout == 0x00 )
      008F11 5D               [ 2]  798 	tnzw	x
      008F12 27 01            [ 1]  799 	jreq	00132$
      008F14 81               [ 4]  800 	ret
      008F15                        801 00132$:
                                    802 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 697: flagstatus = FLASH_STATUS_TIMEOUT;
      008F15 A6 02            [ 1]  803 	ld	a, #0x02
                                    804 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 700: return((FLASH_Status_TypeDef)flagstatus);
                                    805 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 701: }
      008F17 81               [ 4]  806 	ret
                                    807 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 710: IN_RAM(void FLASH_EraseBlock(uint16_t BlockNum, FLASH_MemType_TypeDef FLASH_MemType))
                                    808 ;	-----------------------------------------
                                    809 ;	 function FLASH_EraseBlock
                                    810 ;	-----------------------------------------
      008F18                        811 _FLASH_EraseBlock:
      008F18 52 06            [ 2]  812 	sub	sp, #6
                                    813 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 722: assert_param(IS_MEMORY_TYPE_OK(FLASH_MemType));
      008F1A 7B 0B            [ 1]  814 	ld	a, (0x0b, sp)
      008F1C A0 FD            [ 1]  815 	sub	a, #0xfd
      008F1E 26 02            [ 1]  816 	jrne	00141$
      008F20 4C               [ 1]  817 	inc	a
      008F21 21                     818 	.byte 0x21
      008F22                        819 00141$:
      008F22 4F               [ 1]  820 	clr	a
      008F23                        821 00142$:
      008F23 4D               [ 1]  822 	tnz	a
      008F24 26 19            [ 1]  823 	jrne	00107$
      008F26 88               [ 1]  824 	push	a
      008F27 7B 0C            [ 1]  825 	ld	a, (0x0c, sp)
      008F29 A1 F7            [ 1]  826 	cp	a, #0xf7
      008F2B 84               [ 1]  827 	pop	a
      008F2C 27 11            [ 1]  828 	jreq	00107$
      008F2E 88               [ 1]  829 	push	a
      008F2F 4B D2            [ 1]  830 	push	#0xd2
      008F31 4B 02            [ 1]  831 	push	#0x02
      008F33 5F               [ 1]  832 	clrw	x
      008F34 89               [ 2]  833 	pushw	x
      008F35 4B 26            [ 1]  834 	push	#<___str_0
      008F37 4B 81            [ 1]  835 	push	#(___str_0 >> 8)
      008F39 CD 83 14         [ 4]  836 	call	_assert_failed
      008F3C 5B 06            [ 2]  837 	addw	sp, #6
      008F3E 84               [ 1]  838 	pop	a
      008F3F                        839 00107$:
                                    840 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 723: if(FLASH_MemType == FLASH_MEMTYPE_PROG)
      008F3F 4D               [ 1]  841 	tnz	a
      008F40 27 1F            [ 1]  842 	jreq	00102$
                                    843 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 725: assert_param(IS_FLASH_PROG_BLOCK_NUMBER_OK(BlockNum));
      008F42 1E 09            [ 2]  844 	ldw	x, (0x09, sp)
      008F44 A3 00 80         [ 2]  845 	cpw	x, #0x0080
      008F47 25 0F            [ 1]  846 	jrc	00112$
      008F49 4B D5            [ 1]  847 	push	#0xd5
      008F4B 4B 02            [ 1]  848 	push	#0x02
      008F4D 5F               [ 1]  849 	clrw	x
      008F4E 89               [ 2]  850 	pushw	x
      008F4F 4B 26            [ 1]  851 	push	#<___str_0
      008F51 4B 81            [ 1]  852 	push	#(___str_0 >> 8)
      008F53 CD 83 14         [ 4]  853 	call	_assert_failed
      008F56 5B 06            [ 2]  854 	addw	sp, #6
      008F58                        855 00112$:
                                    856 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 726: startaddress = FLASH_PROG_START_PHYSICAL_ADDRESS;
      008F58 0F 06            [ 1]  857 	clr	(0x06, sp)
      008F5A A6 80            [ 1]  858 	ld	a, #0x80
      008F5C 5F               [ 1]  859 	clrw	x
      008F5D 1F 03            [ 2]  860 	ldw	(0x03, sp), x
      008F5F 20 1D            [ 2]  861 	jra	00103$
      008F61                        862 00102$:
                                    863 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 730: assert_param(IS_FLASH_DATA_BLOCK_NUMBER_OK(BlockNum));
      008F61 1E 09            [ 2]  864 	ldw	x, (0x09, sp)
      008F63 A3 00 0A         [ 2]  865 	cpw	x, #0x000a
      008F66 25 0F            [ 1]  866 	jrc	00114$
      008F68 4B DA            [ 1]  867 	push	#0xda
      008F6A 4B 02            [ 1]  868 	push	#0x02
      008F6C 5F               [ 1]  869 	clrw	x
      008F6D 89               [ 2]  870 	pushw	x
      008F6E 4B 26            [ 1]  871 	push	#<___str_0
      008F70 4B 81            [ 1]  872 	push	#(___str_0 >> 8)
      008F72 CD 83 14         [ 4]  873 	call	_assert_failed
      008F75 5B 06            [ 2]  874 	addw	sp, #6
      008F77                        875 00114$:
                                    876 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 731: startaddress = FLASH_DATA_START_PHYSICAL_ADDRESS;
      008F77 0F 06            [ 1]  877 	clr	(0x06, sp)
      008F79 A6 40            [ 1]  878 	ld	a, #0x40
      008F7B 5F               [ 1]  879 	clrw	x
      008F7C 1F 03            [ 2]  880 	ldw	(0x03, sp), x
      008F7E                        881 00103$:
                                    882 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 739: pwFlash = (PointerAttr uint32_t *)(MemoryAddressCast)(startaddress + ((uint32_t)BlockNum * FLASH_BLOCK_SIZE));
      008F7E 1E 09            [ 2]  883 	ldw	x, (0x09, sp)
      008F80 58               [ 2]  884 	sllw	x
      008F81 58               [ 2]  885 	sllw	x
      008F82 58               [ 2]  886 	sllw	x
      008F83 58               [ 2]  887 	sllw	x
      008F84 58               [ 2]  888 	sllw	x
      008F85 58               [ 2]  889 	sllw	x
      008F86 1F 01            [ 2]  890 	ldw	(0x01, sp), x
      008F88 95               [ 1]  891 	ld	xh, a
      008F89 7B 06            [ 1]  892 	ld	a, (0x06, sp)
      008F8B 97               [ 1]  893 	ld	xl, a
      008F8C 72 FB 01         [ 2]  894 	addw	x, (0x01, sp)
                                    895 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 743: FLASH->CR2 |= FLASH_CR2_ERASE;
      008F8F 72 1A 50 5B      [ 1]  896 	bset	20571, #5
                                    897 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 744: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NERASE);
      008F93 72 1B 50 5C      [ 1]  898 	bres	20572, #5
                                    899 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 748: *pwFlash = (uint32_t)0;
      008F97 90 5F            [ 1]  900 	clrw	y
      008F99 EF 02            [ 2]  901 	ldw	(0x2, x), y
      008F9B FF               [ 2]  902 	ldw	(x), y
                                    903 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 756: }
      008F9C 5B 06            [ 2]  904 	addw	sp, #6
      008F9E 81               [ 4]  905 	ret
                                    906 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 767: IN_RAM(void FLASH_ProgramBlock(uint16_t BlockNum, FLASH_MemType_TypeDef FLASH_MemType, 
                                    907 ;	-----------------------------------------
                                    908 ;	 function FLASH_ProgramBlock
                                    909 ;	-----------------------------------------
      008F9F                        910 _FLASH_ProgramBlock:
      008F9F 52 11            [ 2]  911 	sub	sp, #17
                                    912 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 774: assert_param(IS_MEMORY_TYPE_OK(FLASH_MemType));
      008FA1 7B 16            [ 1]  913 	ld	a, (0x16, sp)
      008FA3 A1 FD            [ 1]  914 	cp	a, #0xfd
      008FA5 26 05            [ 1]  915 	jrne	00173$
      008FA7 A6 01            [ 1]  916 	ld	a, #0x01
      008FA9 6B 05            [ 1]  917 	ld	(0x05, sp), a
      008FAB C1                     918 	.byte 0xc1
      008FAC                        919 00173$:
      008FAC 0F 05            [ 1]  920 	clr	(0x05, sp)
      008FAE                        921 00174$:
      008FAE 0D 05            [ 1]  922 	tnz	(0x05, sp)
      008FB0 26 15            [ 1]  923 	jrne	00113$
      008FB2 7B 16            [ 1]  924 	ld	a, (0x16, sp)
      008FB4 A1 F7            [ 1]  925 	cp	a, #0xf7
      008FB6 27 0F            [ 1]  926 	jreq	00113$
      008FB8 4B 06            [ 1]  927 	push	#0x06
      008FBA 4B 03            [ 1]  928 	push	#0x03
      008FBC 5F               [ 1]  929 	clrw	x
      008FBD 89               [ 2]  930 	pushw	x
      008FBE 4B 26            [ 1]  931 	push	#<___str_0
      008FC0 4B 81            [ 1]  932 	push	#(___str_0 >> 8)
      008FC2 CD 83 14         [ 4]  933 	call	_assert_failed
      008FC5 5B 06            [ 2]  934 	addw	sp, #6
      008FC7                        935 00113$:
                                    936 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 775: assert_param(IS_FLASH_PROGRAM_MODE_OK(FLASH_ProgMode));
      008FC7 0D 17            [ 1]  937 	tnz	(0x17, sp)
      008FC9 27 15            [ 1]  938 	jreq	00118$
      008FCB 7B 17            [ 1]  939 	ld	a, (0x17, sp)
      008FCD A1 10            [ 1]  940 	cp	a, #0x10
      008FCF 27 0F            [ 1]  941 	jreq	00118$
      008FD1 4B 07            [ 1]  942 	push	#0x07
      008FD3 4B 03            [ 1]  943 	push	#0x03
      008FD5 5F               [ 1]  944 	clrw	x
      008FD6 89               [ 2]  945 	pushw	x
      008FD7 4B 26            [ 1]  946 	push	#<___str_0
      008FD9 4B 81            [ 1]  947 	push	#(___str_0 >> 8)
      008FDB CD 83 14         [ 4]  948 	call	_assert_failed
      008FDE 5B 06            [ 2]  949 	addw	sp, #6
      008FE0                        950 00118$:
                                    951 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 776: if(FLASH_MemType == FLASH_MEMTYPE_PROG)
      008FE0 0D 05            [ 1]  952 	tnz	(0x05, sp)
      008FE2 27 1F            [ 1]  953 	jreq	00102$
                                    954 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 778: assert_param(IS_FLASH_PROG_BLOCK_NUMBER_OK(BlockNum));
      008FE4 1E 14            [ 2]  955 	ldw	x, (0x14, sp)
      008FE6 A3 00 80         [ 2]  956 	cpw	x, #0x0080
      008FE9 25 0F            [ 1]  957 	jrc	00123$
      008FEB 4B 0A            [ 1]  958 	push	#0x0a
      008FED 4B 03            [ 1]  959 	push	#0x03
      008FEF 5F               [ 1]  960 	clrw	x
      008FF0 89               [ 2]  961 	pushw	x
      008FF1 4B 26            [ 1]  962 	push	#<___str_0
      008FF3 4B 81            [ 1]  963 	push	#(___str_0 >> 8)
      008FF5 CD 83 14         [ 4]  964 	call	_assert_failed
      008FF8 5B 06            [ 2]  965 	addw	sp, #6
      008FFA                        966 00123$:
                                    967 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 779: startaddress = FLASH_PROG_START_PHYSICAL_ADDRESS;
      008FFA 0F 09            [ 1]  968 	clr	(0x09, sp)
      008FFC A6 80            [ 1]  969 	ld	a, #0x80
      008FFE 5F               [ 1]  970 	clrw	x
      008FFF 1F 06            [ 2]  971 	ldw	(0x06, sp), x
      009001 20 1D            [ 2]  972 	jra	00103$
      009003                        973 00102$:
                                    974 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 783: assert_param(IS_FLASH_DATA_BLOCK_NUMBER_OK(BlockNum));
      009003 1E 14            [ 2]  975 	ldw	x, (0x14, sp)
      009005 A3 00 0A         [ 2]  976 	cpw	x, #0x000a
      009008 25 0F            [ 1]  977 	jrc	00125$
      00900A 4B 0F            [ 1]  978 	push	#0x0f
      00900C 4B 03            [ 1]  979 	push	#0x03
      00900E 5F               [ 1]  980 	clrw	x
      00900F 89               [ 2]  981 	pushw	x
      009010 4B 26            [ 1]  982 	push	#<___str_0
      009012 4B 81            [ 1]  983 	push	#(___str_0 >> 8)
      009014 CD 83 14         [ 4]  984 	call	_assert_failed
      009017 5B 06            [ 2]  985 	addw	sp, #6
      009019                        986 00125$:
                                    987 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 784: startaddress = FLASH_DATA_START_PHYSICAL_ADDRESS;
      009019 0F 09            [ 1]  988 	clr	(0x09, sp)
      00901B A6 40            [ 1]  989 	ld	a, #0x40
      00901D 5F               [ 1]  990 	clrw	x
      00901E 1F 06            [ 2]  991 	ldw	(0x06, sp), x
      009020                        992 00103$:
                                    993 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 788: startaddress = startaddress + ((uint32_t)BlockNum * FLASH_BLOCK_SIZE);
      009020 16 14            [ 2]  994 	ldw	y, (0x14, sp)
      009022 5F               [ 1]  995 	clrw	x
      009023 88               [ 1]  996 	push	a
      009024 A6 06            [ 1]  997 	ld	a, #0x06
      009026                        998 00186$:
      009026 90 58            [ 2]  999 	sllw	y
      009028 59               [ 2] 1000 	rlcw	x
      009029 4A               [ 1] 1001 	dec	a
      00902A 26 FA            [ 1] 1002 	jrne	00186$
      00902C 17 04            [ 2] 1003 	ldw	(0x04, sp), y
      00902E 84               [ 1] 1004 	pop	a
      00902F 90 95            [ 1] 1005 	ld	yh, a
      009031 61               [ 1] 1006 	exg	a, yl
      009032 7B 09            [ 1] 1007 	ld	a, (0x09, sp)
      009034 61               [ 1] 1008 	exg	a, yl
      009035 72 F9 03         [ 2] 1009 	addw	y, (0x03, sp)
      009038 9F               [ 1] 1010 	ld	a, xl
      009039 19 07            [ 1] 1011 	adc	a, (0x07, sp)
      00903B 02               [ 1] 1012 	rlwa	x
      00903C 19 06            [ 1] 1013 	adc	a, (0x06, sp)
      00903E 95               [ 1] 1014 	ld	xh, a
      00903F 17 10            [ 2] 1015 	ldw	(0x10, sp), y
      009041 1F 0E            [ 2] 1016 	ldw	(0x0e, sp), x
                                   1017 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 794: FLASH->CR2 |= FLASH_CR2_PRG;
      009043 C6 50 5B         [ 1] 1018 	ld	a, 0x505b
                                   1019 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 791: if(FLASH_ProgMode == FLASH_PROGRAMMODE_STANDARD)
      009046 0D 17            [ 1] 1020 	tnz	(0x17, sp)
      009048 26 0B            [ 1] 1021 	jrne	00105$
                                   1022 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 794: FLASH->CR2 |= FLASH_CR2_PRG;
      00904A AA 01            [ 1] 1023 	or	a, #0x01
      00904C C7 50 5B         [ 1] 1024 	ld	0x505b, a
                                   1025 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 795: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NPRG);
      00904F 72 11 50 5C      [ 1] 1026 	bres	20572, #0
      009053 20 09            [ 2] 1027 	jra	00134$
      009055                       1028 00105$:
                                   1029 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 800: FLASH->CR2 |= FLASH_CR2_FPRG;
      009055 AA 10            [ 1] 1030 	or	a, #0x10
      009057 C7 50 5B         [ 1] 1031 	ld	0x505b, a
                                   1032 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 801: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NFPRG);
      00905A 72 19 50 5C      [ 1] 1033 	bres	20572, #4
                                   1034 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 805: for(Count = 0; Count < FLASH_BLOCK_SIZE; Count++)
      00905E                       1035 00134$:
      00905E 90 5F            [ 1] 1036 	clrw	y
      009060                       1037 00108$:
                                   1038 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 807: *((PointerAttr uint8_t*) (MemoryAddressCast)startaddress + Count) = ((uint8_t)(Buffer[Count]));
      009060 1E 10            [ 2] 1039 	ldw	x, (0x10, sp)
      009062 1F 0A            [ 2] 1040 	ldw	(0x0a, sp), x
      009064 93               [ 1] 1041 	ldw	x, y
      009065 72 FB 0A         [ 2] 1042 	addw	x, (0x0a, sp)
      009068 1F 0C            [ 2] 1043 	ldw	(0x0c, sp), x
      00906A 93               [ 1] 1044 	ldw	x, y
      00906B 72 FB 18         [ 2] 1045 	addw	x, (0x18, sp)
      00906E F6               [ 1] 1046 	ld	a, (x)
      00906F 1E 0C            [ 2] 1047 	ldw	x, (0x0c, sp)
      009071 F7               [ 1] 1048 	ld	(x), a
                                   1049 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 805: for(Count = 0; Count < FLASH_BLOCK_SIZE; Count++)
      009072 90 5C            [ 1] 1050 	incw	y
      009074 90 A3 00 40      [ 2] 1051 	cpw	y, #0x0040
      009078 25 E6            [ 1] 1052 	jrc	00108$
                                   1053 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 809: }
      00907A 5B 11            [ 2] 1054 	addw	sp, #17
      00907C 81               [ 4] 1055 	ret
                                   1056 	.area CODE
                                   1057 	.area CONST
      008126                       1058 ___str_0:
      008126 2E 2E 2F 2E 2E 2F 2E  1059 	.ascii "../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c"
             2E 2F 4C 69 62 72 61
             72 69 65 73 2F 53 54
             4D 38 53 5F 53 74 64
             50 65 72 69 70 68 5F
             44 72 69 76 65 72 2F
             73 72 63 2F 73 74 6D
             38 73 5F 66 6C 61 73
             68 2E 63
      008161 00                    1060 	.db 0x00
                                   1061 	.area INITIALIZER
                                   1062 	.area CABS (ABS)
