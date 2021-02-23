;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module stm8s_flash
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _assert_failed
	.globl _FLASH_Unlock
	.globl _FLASH_Lock
	.globl _FLASH_DeInit
	.globl _FLASH_ITConfig
	.globl _FLASH_EraseByte
	.globl _FLASH_ProgramByte
	.globl _FLASH_ReadByte
	.globl _FLASH_ProgramWord
	.globl _FLASH_ProgramOptionByte
	.globl _FLASH_EraseOptionByte
	.globl _FLASH_ReadOptionByte
	.globl _FLASH_SetLowPowerMode
	.globl _FLASH_SetProgrammingTime
	.globl _FLASH_GetLowPowerMode
	.globl _FLASH_GetProgrammingTime
	.globl _FLASH_GetBootSize
	.globl _FLASH_GetFlagStatus
	.globl _FLASH_WaitForLastOperation
	.globl _FLASH_EraseBlock
	.globl _FLASH_ProgramBlock
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)

; default segment ordering for linker
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area CONST
	.area INITIALIZER
	.area CODE

;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 168: void FLASH_Unlock(FLASH_MemType_TypeDef FLASH_MemType)
;	-----------------------------------------
;	 function FLASH_Unlock
;	-----------------------------------------
_FLASH_Unlock:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 171: assert_param(IS_MEMORY_TYPE_OK(FLASH_MemType));
	ld	a, (0x03, sp)
	sub	a, #0xfd
	jrne	00127$
	inc	a
	.byte 0x21
00127$:
	clr	a
00128$:
	tnz	a
	jrne	00107$
	push	a
	ld	a, (0x04, sp)
	cp	a, #0xf7
	pop	a
	jreq	00107$
	push	a
	push	#0xab
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
	pop	a
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 174: if(FLASH_MemType == FLASH_MEMTYPE_PROG)
	tnz	a
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 176: FLASH->PUKR = FLASH_RASS_KEY1;
	mov	0x5062+0, #0x56
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 177: FLASH->PUKR = FLASH_RASS_KEY2;
	mov	0x5062+0, #0xae
	ret
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 182: FLASH->DUKR = FLASH_RASS_KEY2; /* Warning: keys are reversed on data memory !!! */
	mov	0x5064+0, #0xae
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 183: FLASH->DUKR = FLASH_RASS_KEY1;
	mov	0x5064+0, #0x56
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 185: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 193: void FLASH_Lock(FLASH_MemType_TypeDef FLASH_MemType)
;	-----------------------------------------
;	 function FLASH_Lock
;	-----------------------------------------
_FLASH_Lock:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 196: assert_param(IS_MEMORY_TYPE_OK(FLASH_MemType));
	ld	a, (0x03, sp)
	cp	a, #0xfd
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0xf7
	jreq	00104$
	push	#0xc4
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 199: FLASH->IAPSR &= (uint8_t)FLASH_MemType;
	ld	a, 0x505f
	and	a, (0x03, sp)
	ld	0x505f, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 200: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 207: void FLASH_DeInit(void)
;	-----------------------------------------
;	 function FLASH_DeInit
;	-----------------------------------------
_FLASH_DeInit:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 209: FLASH->CR1 = FLASH_CR1_RESET_VALUE;
	mov	0x505a+0, #0x00
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 210: FLASH->CR2 = FLASH_CR2_RESET_VALUE;
	mov	0x505b+0, #0x00
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 211: FLASH->NCR2 = FLASH_NCR2_RESET_VALUE;
	mov	0x505c+0, #0xff
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 212: FLASH->IAPSR &= (uint8_t)(~FLASH_IAPSR_DUL);
	bres	20575, #3
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 213: FLASH->IAPSR &= (uint8_t)(~FLASH_IAPSR_PUL);
	bres	20575, #1
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 214: (void) FLASH->IAPSR; /* Reading of this register causes the clearing of status flags */
	ld	a, 0x505f
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 215: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 223: void FLASH_ITConfig(FunctionalState NewState)
;	-----------------------------------------
;	 function FLASH_ITConfig
;	-----------------------------------------
_FLASH_ITConfig:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 226: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0xe2
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 230: FLASH->CR1 |= FLASH_CR1_IE; /* Enables the interrupt sources */
	ld	a, 0x505a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 228: if(NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 230: FLASH->CR1 |= FLASH_CR1_IE; /* Enables the interrupt sources */
	or	a, #0x02
	ld	0x505a, a
	ret
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 234: FLASH->CR1 &= (uint8_t)(~FLASH_CR1_IE); /* Disables the interrupt sources */
	and	a, #0xfd
	ld	0x505a, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 236: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 245: void FLASH_EraseByte(uint32_t Address)
;	-----------------------------------------
;	 function FLASH_EraseByte
;	-----------------------------------------
_FLASH_EraseByte:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 248: assert_param(IS_FLASH_ADDRESS_OK(Address));
	ldw	x, (0x05, sp)
	cpw	x, #0x8000
	ld	a, (0x04, sp)
	sbc	a, #0x00
	ld	a, (0x03, sp)
	sbc	a, #0x00
	jrc	00110$
	ldw	x, #0x9fff
	cpw	x, (0x05, sp)
	clr	a
	sbc	a, (0x04, sp)
	clr	a
	sbc	a, (0x03, sp)
	jrnc	00104$
00110$:
	ldw	x, (0x05, sp)
	cpw	x, #0x4000
	ld	a, (0x04, sp)
	sbc	a, #0x00
	ld	a, (0x03, sp)
	sbc	a, #0x00
	jrc	00103$
	ldw	x, #0x427f
	cpw	x, (0x05, sp)
	clr	a
	sbc	a, (0x04, sp)
	clr	a
	sbc	a, (0x03, sp)
	jrnc	00104$
00103$:
	push	#0xf8
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 253: *(PointerAttr uint8_t*) (MemoryAddressCast)Address = FLASH_CLEAR_BYTE;
	ldw	x, (0x05, sp)
	clr	(x)
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 257: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 267: void FLASH_ProgramByte(uint32_t Address, uint8_t Data)
;	-----------------------------------------
;	 function FLASH_ProgramByte
;	-----------------------------------------
_FLASH_ProgramByte:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 270: assert_param(IS_FLASH_ADDRESS_OK(Address));
	ldw	x, (0x05, sp)
	cpw	x, #0x8000
	ld	a, (0x04, sp)
	sbc	a, #0x00
	ld	a, (0x03, sp)
	sbc	a, #0x00
	jrc	00110$
	ldw	x, #0x9fff
	cpw	x, (0x05, sp)
	clr	a
	sbc	a, (0x04, sp)
	clr	a
	sbc	a, (0x03, sp)
	jrnc	00104$
00110$:
	ldw	x, (0x05, sp)
	cpw	x, #0x4000
	ld	a, (0x04, sp)
	sbc	a, #0x00
	ld	a, (0x03, sp)
	sbc	a, #0x00
	jrc	00103$
	ldw	x, #0x427f
	cpw	x, (0x05, sp)
	clr	a
	sbc	a, (0x04, sp)
	clr	a
	sbc	a, (0x03, sp)
	jrnc	00104$
00103$:
	push	#0x0e
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 275: *(PointerAttr uint8_t*) (MemoryAddressCast)Address = Data;
	ldw	x, (0x05, sp)
	ld	a, (0x07, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 279: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 288: uint8_t FLASH_ReadByte(uint32_t Address)
;	-----------------------------------------
;	 function FLASH_ReadByte
;	-----------------------------------------
_FLASH_ReadByte:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 291: assert_param(IS_FLASH_ADDRESS_OK(Address));
	ldw	x, (0x05, sp)
	cpw	x, #0x8000
	ld	a, (0x04, sp)
	sbc	a, #0x00
	ld	a, (0x03, sp)
	sbc	a, #0x00
	jrc	00110$
	ldw	x, #0x9fff
	cpw	x, (0x05, sp)
	clr	a
	sbc	a, (0x04, sp)
	clr	a
	sbc	a, (0x03, sp)
	jrnc	00104$
00110$:
	ldw	x, (0x05, sp)
	cpw	x, #0x4000
	ld	a, (0x04, sp)
	sbc	a, #0x00
	ld	a, (0x03, sp)
	sbc	a, #0x00
	jrc	00103$
	ldw	x, #0x427f
	cpw	x, (0x05, sp)
	clr	a
	sbc	a, (0x04, sp)
	clr	a
	sbc	a, (0x03, sp)
	jrnc	00104$
00103$:
	push	#0x23
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 296: return(*(PointerAttr uint8_t *) (MemoryAddressCast)Address); 
	ldw	x, (0x05, sp)
	ld	a, (x)
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 300: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 310: void FLASH_ProgramWord(uint32_t Address, uint32_t Data)
;	-----------------------------------------
;	 function FLASH_ProgramWord
;	-----------------------------------------
_FLASH_ProgramWord:
	sub	sp, #6
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 313: assert_param(IS_FLASH_ADDRESS_OK(Address));
	ldw	x, (0x0b, sp)
	cpw	x, #0x8000
	ld	a, (0x0a, sp)
	sbc	a, #0x00
	ld	a, (0x09, sp)
	sbc	a, #0x00
	jrc	00110$
	ldw	x, #0x9fff
	cpw	x, (0x0b, sp)
	clr	a
	sbc	a, (0x0a, sp)
	clr	a
	sbc	a, (0x09, sp)
	jrnc	00104$
00110$:
	ldw	x, (0x0b, sp)
	cpw	x, #0x4000
	ld	a, (0x0a, sp)
	sbc	a, #0x00
	ld	a, (0x09, sp)
	sbc	a, #0x00
	jrc	00103$
	ldw	x, #0x427f
	cpw	x, (0x0b, sp)
	clr	a
	sbc	a, (0x0a, sp)
	clr	a
	sbc	a, (0x09, sp)
	jrnc	00104$
00103$:
	push	#0x39
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 316: FLASH->CR2 |= FLASH_CR2_WPRG;
	bset	20571, #6
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 317: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NWPRG);
	bres	20572, #6
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 322: *((PointerAttr uint8_t*)(MemoryAddressCast)Address)       = *((uint8_t*)(&Data));
	ldw	y, (0x0b, sp)
	ldw	x, sp
	addw	x, #13
	ldw	(0x05, sp), x
	ld	a, (x)
	ld	(y), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 324: *(((PointerAttr uint8_t*)(MemoryAddressCast)Address) + 1) = *((uint8_t*)(&Data)+1); 
	ldw	x, y
	incw	x
	ldw	(0x03, sp), x
	ldw	x, (0x05, sp)
	ld	a, (0x1, x)
	ldw	x, (0x03, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 326: *(((PointerAttr uint8_t*)(MemoryAddressCast)Address) + 2) = *((uint8_t*)(&Data)+2); 
	ldw	x, y
	incw	x
	incw	x
	ldw	(0x01, sp), x
	ldw	x, (0x05, sp)
	ld	a, (0x2, x)
	ldw	x, (0x01, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 328: *(((PointerAttr uint8_t*)(MemoryAddressCast)Address) + 3) = *((uint8_t*)(&Data)+3); 
	addw	y, #0x0003
	ldw	x, (0x05, sp)
	ld	a, (0x3, x)
	ld	(y), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 335: }
	addw	sp, #6
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 343: void FLASH_ProgramOptionByte(uint16_t Address, uint8_t Data)
;	-----------------------------------------
;	 function FLASH_ProgramOptionByte
;	-----------------------------------------
_FLASH_ProgramOptionByte:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 346: assert_param(IS_OPTION_BYTE_ADDRESS_OK(Address));
	ldw	x, (0x03, sp)
	cpw	x, #0x4800
	jrc	00106$
	ldw	x, (0x03, sp)
	cpw	x, #0x487f
	jrule	00107$
00106$:
	push	#0x5a
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 349: FLASH->CR2 |= FLASH_CR2_OPT;
	bset	20571, #7
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 350: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NOPT);
	ld	a, 0x505c
	and	a, #0x7f
	ld	0x505c, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 356: *((NEAR uint8_t*)Address) = Data;
	ldw	x, (0x03, sp)
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 353: if(Address == 0x4800)
	pushw	x
	ldw	x, (0x05, sp)
	cpw	x, #0x4800
	popw	x
	jrne	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 356: *((NEAR uint8_t*)Address) = Data;
	ld	a, (0x05, sp)
	ld	(x), a
	jra	00103$
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 361: *((NEAR uint8_t*)Address) = Data;
	ld	a, (0x05, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 362: *((NEAR uint8_t*)((uint16_t)(Address + 1))) = (uint8_t)(~Data);
	ldw	x, (0x03, sp)
	incw	x
	ld	a, (0x05, sp)
	cpl	a
	ld	(x), a
00103$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 364: FLASH_WaitForLastOperation(FLASH_MEMTYPE_PROG);
	push	#0xfd
	call	_FLASH_WaitForLastOperation
	pop	a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 367: FLASH->CR2 &= (uint8_t)(~FLASH_CR2_OPT);
	bres	20571, #7
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 368: FLASH->NCR2 |= FLASH_NCR2_NOPT;
	bset	20572, #7
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 369: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 376: void FLASH_EraseOptionByte(uint16_t Address)
;	-----------------------------------------
;	 function FLASH_EraseOptionByte
;	-----------------------------------------
_FLASH_EraseOptionByte:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 379: assert_param(IS_OPTION_BYTE_ADDRESS_OK(Address));
	ldw	x, (0x03, sp)
	cpw	x, #0x4800
	jrc	00106$
	ldw	x, (0x03, sp)
	cpw	x, #0x487f
	jrule	00107$
00106$:
	push	#0x7b
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 382: FLASH->CR2 |= FLASH_CR2_OPT;
	bset	20571, #7
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 383: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NOPT);
	ld	a, 0x505c
	and	a, #0x7f
	ld	0x505c, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 389: *((NEAR uint8_t*)Address) = FLASH_CLEAR_BYTE;
	ldw	y, (0x03, sp)
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 386: if(Address == 0x4800)
	ldw	x, (0x03, sp)
	cpw	x, #0x4800
	jrne	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 389: *((NEAR uint8_t*)Address) = FLASH_CLEAR_BYTE;
	clr	(y)
	jra	00103$
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 394: *((NEAR uint8_t*)Address) = FLASH_CLEAR_BYTE;
	clr	(y)
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 395: *((NEAR uint8_t*)((uint16_t)(Address + (uint16_t)1 ))) = FLASH_SET_BYTE;
	ldw	x, (0x03, sp)
	incw	x
	ld	a, #0xff
	ld	(x), a
00103$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 397: FLASH_WaitForLastOperation(FLASH_MEMTYPE_PROG);
	push	#0xfd
	call	_FLASH_WaitForLastOperation
	pop	a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 400: FLASH->CR2 &= (uint8_t)(~FLASH_CR2_OPT);
	bres	20571, #7
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 401: FLASH->NCR2 |= FLASH_NCR2_NOPT;
	bset	20572, #7
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 402: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 409: uint16_t FLASH_ReadOptionByte(uint16_t Address)
;	-----------------------------------------
;	 function FLASH_ReadOptionByte
;	-----------------------------------------
_FLASH_ReadOptionByte:
	sub	sp, #7
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 415: assert_param(IS_OPTION_BYTE_ADDRESS_OK(Address));
	ldw	x, (0x0a, sp)
	cpw	x, #0x4800
	jrc	00109$
	ldw	x, (0x0a, sp)
	cpw	x, #0x487f
	jrule	00110$
00109$:
	push	#0x9f
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00110$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 417: value_optbyte = *((NEAR uint8_t*)Address); /* Read option byte */
	ldw	x, (0x0a, sp)
	ld	a, (x)
	ld	(0x04, sp), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 418: value_optbyte_complement = *(((NEAR uint8_t*)Address) + 1); /* Read option byte complement */
	ld	a, (0x1, x)
	ld	(0x03, sp), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 423: res_value =	 value_optbyte;
	clrw	y
	ld	a, (0x04, sp)
	ld	yl, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 421: if(Address == 0x4800)	 
	ldw	x, (0x0a, sp)
	cpw	x, #0x4800
	jrne	00105$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 423: res_value =	 value_optbyte;
	ldw	x, y
	jra	00106$
00105$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 427: if(value_optbyte == (uint8_t)(~value_optbyte_complement))
	ld	a, (0x03, sp)
	cpl	a
	ld	(0x05, sp), a
	ld	a, (0x04, sp)
	cp	a, (0x05, sp)
	jrne	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 429: res_value = (uint16_t)((uint16_t)value_optbyte << 8);
	clr	a
	ld	(0x02, sp), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 430: res_value = res_value | (uint16_t)value_optbyte_complement;
	ld	a, (0x03, sp)
	clr	(0x06, sp)
	or	a, (0x02, sp)
	ld	xl, a
	ld	a, yl
	or	a, (0x06, sp)
	ld	xh, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 434: res_value = FLASH_OPTIONBYTE_ERROR;
	.byte 0xbc
00102$:
	ldw	x, #0x5555
00106$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 437: return(res_value);
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 438: }
	addw	sp, #7
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 446: void FLASH_SetLowPowerMode(FLASH_LPMode_TypeDef FLASH_LPMode)
;	-----------------------------------------
;	 function FLASH_SetLowPowerMode
;	-----------------------------------------
_FLASH_SetLowPowerMode:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 449: assert_param(IS_FLASH_LOW_POWER_MODE_OK(FLASH_LPMode));
	ld	a, (0x03, sp)
	cp	a, #0x04
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x08
	jreq	00104$
	tnz	(0x03, sp)
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x0c
	jreq	00104$
	push	#0xc1
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 452: FLASH->CR1 &= (uint8_t)(~(FLASH_CR1_HALT | FLASH_CR1_AHALT)); 
	ld	a, 0x505a
	and	a, #0xf3
	ld	0x505a, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 455: FLASH->CR1 |= (uint8_t)FLASH_LPMode; 
	ld	a, 0x505a
	or	a, (0x03, sp)
	ld	0x505a, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 456: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 464: void FLASH_SetProgrammingTime(FLASH_ProgramTime_TypeDef FLASH_ProgTime)
;	-----------------------------------------
;	 function FLASH_SetProgrammingTime
;	-----------------------------------------
_FLASH_SetProgrammingTime:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 467: assert_param(IS_FLASH_PROGRAM_TIME_OK(FLASH_ProgTime));
	tnz	(0x03, sp)
	jreq	00104$
	ld	a, (0x03, sp)
	dec	a
	jreq	00104$
	push	#0xd3
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 469: FLASH->CR1 &= (uint8_t)(~FLASH_CR1_FIX);
	ld	a, 0x505a
	and	a, #0xfe
	ld	0x505a, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 470: FLASH->CR1 |= (uint8_t)FLASH_ProgTime;
	ld	a, 0x505a
	or	a, (0x03, sp)
	ld	0x505a, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 471: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 478: FLASH_LPMode_TypeDef FLASH_GetLowPowerMode(void)
;	-----------------------------------------
;	 function FLASH_GetLowPowerMode
;	-----------------------------------------
_FLASH_GetLowPowerMode:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 480: return((FLASH_LPMode_TypeDef)(FLASH->CR1 & (uint8_t)(FLASH_CR1_HALT | FLASH_CR1_AHALT)));
	ld	a, 0x505a
	and	a, #0x0c
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 481: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 488: FLASH_ProgramTime_TypeDef FLASH_GetProgrammingTime(void)
;	-----------------------------------------
;	 function FLASH_GetProgrammingTime
;	-----------------------------------------
_FLASH_GetProgrammingTime:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 490: return((FLASH_ProgramTime_TypeDef)(FLASH->CR1 & FLASH_CR1_FIX));
	ld	a, 0x505a
	and	a, #0x01
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 491: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 498: uint32_t FLASH_GetBootSize(void)
;	-----------------------------------------
;	 function FLASH_GetBootSize
;	-----------------------------------------
_FLASH_GetBootSize:
	sub	sp, #4
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 503: temp = (uint32_t)((uint32_t)FLASH->FPR * (uint32_t)512);
	ld	a, 0x505d
	clrw	x
	clr	(0x04, sp)
	sll	(0x04, sp)
	rlc	a
	rlcw	x
	ld	yh, a
	ld	a, (0x04, sp)
	ld	yl, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 506: if(FLASH->FPR == 0xFF)
	ld	a, 0x505d
	inc	a
	jrne	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 508: temp += 512;
	addw	y, #0x0200
	ld	a, xl
	adc	a, #0x00
	rlwa	x
	adc	a, #0x00
	ld	xh, a
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 512: return(temp);
	exgw	x, y
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 513: }
	addw	sp, #4
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 523: FlagStatus FLASH_GetFlagStatus(FLASH_Flag_TypeDef FLASH_FLAG)
;	-----------------------------------------
;	 function FLASH_GetFlagStatus
;	-----------------------------------------
_FLASH_GetFlagStatus:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 527: assert_param(IS_FLASH_FLAGS_OK(FLASH_FLAG));
	ld	a, (0x03, sp)
	cp	a, #0x08
	jreq	00107$
	ld	a, (0x03, sp)
	cp	a, #0x04
	jreq	00107$
	ld	a, (0x03, sp)
	cp	a, #0x02
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0x0f
	push	#0x02
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 530: if((FLASH->IAPSR & (uint8_t)FLASH_FLAG) != (uint8_t)RESET)
	ld	a, 0x505f
	and	a, (0x03, sp)
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 532: status = SET; /* FLASH_FLAG is set */
	ld	a, #0x01
	ret
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 536: status = RESET; /* FLASH_FLAG is reset*/
	clr	a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 540: return status;
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 541: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 660: IN_RAM(FLASH_Status_TypeDef FLASH_WaitForLastOperation(FLASH_MemType_TypeDef FLASH_MemType)) 
;	-----------------------------------------
;	 function FLASH_WaitForLastOperation
;	-----------------------------------------
_FLASH_WaitForLastOperation:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 662: uint8_t flagstatus = 0x00;
	clr	a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 688: while((flagstatus == 0x00) && (timeout != 0x00))
	clrw	x
	decw	x
00102$:
	tnz	a
	jrne	00104$
	tnzw	x
	jreq	00104$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 690: flagstatus = (uint8_t)(FLASH->IAPSR & (FLASH_IAPSR_EOP | FLASH_IAPSR_WR_PG_DIS));
	ld	a, 0x505f
	and	a, #0x05
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 691: timeout--;
	decw	x
	jra	00102$
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 695: if(timeout == 0x00 )
	tnzw	x
	jreq	00132$
	ret
00132$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 697: flagstatus = FLASH_STATUS_TIMEOUT;
	ld	a, #0x02
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 700: return((FLASH_Status_TypeDef)flagstatus);
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 701: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 710: IN_RAM(void FLASH_EraseBlock(uint16_t BlockNum, FLASH_MemType_TypeDef FLASH_MemType))
;	-----------------------------------------
;	 function FLASH_EraseBlock
;	-----------------------------------------
_FLASH_EraseBlock:
	sub	sp, #6
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 722: assert_param(IS_MEMORY_TYPE_OK(FLASH_MemType));
	ld	a, (0x0b, sp)
	sub	a, #0xfd
	jrne	00141$
	inc	a
	.byte 0x21
00141$:
	clr	a
00142$:
	tnz	a
	jrne	00107$
	push	a
	ld	a, (0x0c, sp)
	cp	a, #0xf7
	pop	a
	jreq	00107$
	push	a
	push	#0xd2
	push	#0x02
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
	pop	a
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 723: if(FLASH_MemType == FLASH_MEMTYPE_PROG)
	tnz	a
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 725: assert_param(IS_FLASH_PROG_BLOCK_NUMBER_OK(BlockNum));
	ldw	x, (0x09, sp)
	cpw	x, #0x0080
	jrc	00112$
	push	#0xd5
	push	#0x02
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00112$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 726: startaddress = FLASH_PROG_START_PHYSICAL_ADDRESS;
	clr	(0x06, sp)
	ld	a, #0x80
	clrw	x
	ldw	(0x03, sp), x
	jra	00103$
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 730: assert_param(IS_FLASH_DATA_BLOCK_NUMBER_OK(BlockNum));
	ldw	x, (0x09, sp)
	cpw	x, #0x000a
	jrc	00114$
	push	#0xda
	push	#0x02
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00114$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 731: startaddress = FLASH_DATA_START_PHYSICAL_ADDRESS;
	clr	(0x06, sp)
	ld	a, #0x40
	clrw	x
	ldw	(0x03, sp), x
00103$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 739: pwFlash = (PointerAttr uint32_t *)(MemoryAddressCast)(startaddress + ((uint32_t)BlockNum * FLASH_BLOCK_SIZE));
	ldw	x, (0x09, sp)
	sllw	x
	sllw	x
	sllw	x
	sllw	x
	sllw	x
	sllw	x
	ldw	(0x01, sp), x
	ld	xh, a
	ld	a, (0x06, sp)
	ld	xl, a
	addw	x, (0x01, sp)
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 743: FLASH->CR2 |= FLASH_CR2_ERASE;
	bset	20571, #5
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 744: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NERASE);
	bres	20572, #5
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 748: *pwFlash = (uint32_t)0;
	clrw	y
	ldw	(0x2, x), y
	ldw	(x), y
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 756: }
	addw	sp, #6
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 767: IN_RAM(void FLASH_ProgramBlock(uint16_t BlockNum, FLASH_MemType_TypeDef FLASH_MemType, 
;	-----------------------------------------
;	 function FLASH_ProgramBlock
;	-----------------------------------------
_FLASH_ProgramBlock:
	sub	sp, #17
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 774: assert_param(IS_MEMORY_TYPE_OK(FLASH_MemType));
	ld	a, (0x16, sp)
	cp	a, #0xfd
	jrne	00173$
	ld	a, #0x01
	ld	(0x05, sp), a
	.byte 0xc1
00173$:
	clr	(0x05, sp)
00174$:
	tnz	(0x05, sp)
	jrne	00113$
	ld	a, (0x16, sp)
	cp	a, #0xf7
	jreq	00113$
	push	#0x06
	push	#0x03
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00113$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 775: assert_param(IS_FLASH_PROGRAM_MODE_OK(FLASH_ProgMode));
	tnz	(0x17, sp)
	jreq	00118$
	ld	a, (0x17, sp)
	cp	a, #0x10
	jreq	00118$
	push	#0x07
	push	#0x03
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00118$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 776: if(FLASH_MemType == FLASH_MEMTYPE_PROG)
	tnz	(0x05, sp)
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 778: assert_param(IS_FLASH_PROG_BLOCK_NUMBER_OK(BlockNum));
	ldw	x, (0x14, sp)
	cpw	x, #0x0080
	jrc	00123$
	push	#0x0a
	push	#0x03
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00123$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 779: startaddress = FLASH_PROG_START_PHYSICAL_ADDRESS;
	clr	(0x09, sp)
	ld	a, #0x80
	clrw	x
	ldw	(0x06, sp), x
	jra	00103$
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 783: assert_param(IS_FLASH_DATA_BLOCK_NUMBER_OK(BlockNum));
	ldw	x, (0x14, sp)
	cpw	x, #0x000a
	jrc	00125$
	push	#0x0f
	push	#0x03
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00125$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 784: startaddress = FLASH_DATA_START_PHYSICAL_ADDRESS;
	clr	(0x09, sp)
	ld	a, #0x40
	clrw	x
	ldw	(0x06, sp), x
00103$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 788: startaddress = startaddress + ((uint32_t)BlockNum * FLASH_BLOCK_SIZE);
	ldw	y, (0x14, sp)
	clrw	x
	push	a
	ld	a, #0x06
00186$:
	sllw	y
	rlcw	x
	dec	a
	jrne	00186$
	ldw	(0x04, sp), y
	pop	a
	ld	yh, a
	exg	a, yl
	ld	a, (0x09, sp)
	exg	a, yl
	addw	y, (0x03, sp)
	ld	a, xl
	adc	a, (0x07, sp)
	rlwa	x
	adc	a, (0x06, sp)
	ld	xh, a
	ldw	(0x10, sp), y
	ldw	(0x0e, sp), x
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 794: FLASH->CR2 |= FLASH_CR2_PRG;
	ld	a, 0x505b
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 791: if(FLASH_ProgMode == FLASH_PROGRAMMODE_STANDARD)
	tnz	(0x17, sp)
	jrne	00105$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 794: FLASH->CR2 |= FLASH_CR2_PRG;
	or	a, #0x01
	ld	0x505b, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 795: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NPRG);
	bres	20572, #0
	jra	00134$
00105$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 800: FLASH->CR2 |= FLASH_CR2_FPRG;
	or	a, #0x10
	ld	0x505b, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 801: FLASH->NCR2 &= (uint8_t)(~FLASH_NCR2_NFPRG);
	bres	20572, #4
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 805: for(Count = 0; Count < FLASH_BLOCK_SIZE; Count++)
00134$:
	clrw	y
00108$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 807: *((PointerAttr uint8_t*) (MemoryAddressCast)startaddress + Count) = ((uint8_t)(Buffer[Count]));
	ldw	x, (0x10, sp)
	ldw	(0x0a, sp), x
	ldw	x, y
	addw	x, (0x0a, sp)
	ldw	(0x0c, sp), x
	ldw	x, y
	addw	x, (0x18, sp)
	ld	a, (x)
	ldw	x, (0x0c, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 805: for(Count = 0; Count < FLASH_BLOCK_SIZE; Count++)
	incw	y
	cpw	y, #0x0040
	jrc	00108$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c: 809: }
	addw	sp, #17
	ret
	.area CODE
	.area CONST
___str_0:
	.ascii "../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_flash.c"
	.db 0x00
	.area INITIALIZER
	.area CABS (ABS)
