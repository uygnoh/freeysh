;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module stm8s_tim4
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _assert_failed
	.globl _TIM4_DeInit
	.globl _TIM4_TimeBaseInit
	.globl _TIM4_Cmd
	.globl _TIM4_ITConfig
	.globl _TIM4_UpdateDisableConfig
	.globl _TIM4_UpdateRequestConfig
	.globl _TIM4_SelectOnePulseMode
	.globl _TIM4_PrescalerConfig
	.globl _TIM4_ARRPreloadConfig
	.globl _TIM4_GenerateEvent
	.globl _TIM4_SetCounter
	.globl _TIM4_SetAutoreload
	.globl _TIM4_GetCounter
	.globl _TIM4_GetPrescaler
	.globl _TIM4_GetFlagStatus
	.globl _TIM4_ClearFlag
	.globl _TIM4_GetITStatus
	.globl _TIM4_ClearITPendingBit
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
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 49: void TIM4_DeInit(void)
;	-----------------------------------------
;	 function TIM4_DeInit
;	-----------------------------------------
_TIM4_DeInit:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 51: TIM4->CR1 = TIM4_CR1_RESET_VALUE;
	mov	0x5340+0, #0x00
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 52: TIM4->IER = TIM4_IER_RESET_VALUE;
	mov	0x5343+0, #0x00
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 53: TIM4->CNTR = TIM4_CNTR_RESET_VALUE;
	mov	0x5346+0, #0x00
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 54: TIM4->PSCR = TIM4_PSCR_RESET_VALUE;
	mov	0x5347+0, #0x00
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 55: TIM4->ARR = TIM4_ARR_RESET_VALUE;
	mov	0x5348+0, #0xff
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 56: TIM4->SR1 = TIM4_SR1_RESET_VALUE;
	mov	0x5344+0, #0x00
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 57: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 65: void TIM4_TimeBaseInit(TIM4_Prescaler_TypeDef TIM4_Prescaler, uint8_t TIM4_Period)
;	-----------------------------------------
;	 function TIM4_TimeBaseInit
;	-----------------------------------------
_TIM4_TimeBaseInit:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 68: assert_param(IS_TIM4_PRESCALER_OK(TIM4_Prescaler));
	tnz	(0x03, sp)
	jreq	00104$
	ld	a, (0x03, sp)
	dec	a
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x02
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x03
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x04
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x05
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x06
	jreq	00104$
	ld	a, (0x03, sp)
	cp	a, #0x07
	jreq	00104$
	push	#0x44
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 70: TIM4->PSCR = (uint8_t)(TIM4_Prescaler);
	ldw	x, #0x5347
	ld	a, (0x03, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 72: TIM4->ARR = (uint8_t)(TIM4_Period);
	ldw	x, #0x5348
	ld	a, (0x04, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 73: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 81: void TIM4_Cmd(FunctionalState NewState)
;	-----------------------------------------
;	 function TIM4_Cmd
;	-----------------------------------------
_TIM4_Cmd:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 84: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0x54
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 89: TIM4->CR1 |= TIM4_CR1_CEN;
	ld	a, 0x5340
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 87: if (NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 89: TIM4->CR1 |= TIM4_CR1_CEN;
	or	a, #0x01
	ld	0x5340, a
	ret
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 93: TIM4->CR1 &= (uint8_t)(~TIM4_CR1_CEN);
	and	a, #0xfe
	ld	0x5340, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 95: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 107: void TIM4_ITConfig(TIM4_IT_TypeDef TIM4_IT, FunctionalState NewState)
;	-----------------------------------------
;	 function TIM4_ITConfig
;	-----------------------------------------
_TIM4_ITConfig:
	push	a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 110: assert_param(IS_TIM4_IT_OK(TIM4_IT));
	ld	a, (0x04, sp)
	dec	a
	jreq	00107$
	push	#0x6e
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 111: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x05, sp)
	jreq	00109$
	ld	a, (0x05, sp)
	dec	a
	jreq	00109$
	push	#0x6f
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00109$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 116: TIM4->IER |= (uint8_t)TIM4_IT;
	ld	a, 0x5343
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 113: if (NewState != DISABLE)
	tnz	(0x05, sp)
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 116: TIM4->IER |= (uint8_t)TIM4_IT;
	or	a, (0x04, sp)
	ld	0x5343, a
	jra	00104$
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 121: TIM4->IER &= (uint8_t)(~TIM4_IT);
	push	a
	ld	a, (0x05, sp)
	cpl	a
	ld	(0x02, sp), a
	pop	a
	and	a, (0x01, sp)
	ld	0x5343, a
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 123: }
	pop	a
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 131: void TIM4_UpdateDisableConfig(FunctionalState NewState)
;	-----------------------------------------
;	 function TIM4_UpdateDisableConfig
;	-----------------------------------------
_TIM4_UpdateDisableConfig:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 134: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0x86
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 139: TIM4->CR1 |= TIM4_CR1_UDIS;
	ld	a, 0x5340
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 137: if (NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 139: TIM4->CR1 |= TIM4_CR1_UDIS;
	or	a, #0x02
	ld	0x5340, a
	ret
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 143: TIM4->CR1 &= (uint8_t)(~TIM4_CR1_UDIS);
	and	a, #0xfd
	ld	0x5340, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 145: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 155: void TIM4_UpdateRequestConfig(TIM4_UpdateSource_TypeDef TIM4_UpdateSource)
;	-----------------------------------------
;	 function TIM4_UpdateRequestConfig
;	-----------------------------------------
_TIM4_UpdateRequestConfig:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 158: assert_param(IS_TIM4_UPDATE_SOURCE_OK(TIM4_UpdateSource));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0x9e
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 163: TIM4->CR1 |= TIM4_CR1_URS;
	ld	a, 0x5340
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 161: if (TIM4_UpdateSource != TIM4_UPDATESOURCE_GLOBAL)
	tnz	(0x03, sp)
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 163: TIM4->CR1 |= TIM4_CR1_URS;
	or	a, #0x04
	ld	0x5340, a
	ret
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 167: TIM4->CR1 &= (uint8_t)(~TIM4_CR1_URS);
	and	a, #0xfb
	ld	0x5340, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 169: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 179: void TIM4_SelectOnePulseMode(TIM4_OPMode_TypeDef TIM4_OPMode)
;	-----------------------------------------
;	 function TIM4_SelectOnePulseMode
;	-----------------------------------------
_TIM4_SelectOnePulseMode:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 182: assert_param(IS_TIM4_OPM_MODE_OK(TIM4_OPMode));
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	tnz	(0x03, sp)
	jreq	00107$
	push	#0xb6
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 187: TIM4->CR1 |= TIM4_CR1_OPM;
	ld	a, 0x5340
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 185: if (TIM4_OPMode != TIM4_OPMODE_REPETITIVE)
	tnz	(0x03, sp)
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 187: TIM4->CR1 |= TIM4_CR1_OPM;
	or	a, #0x08
	ld	0x5340, a
	ret
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 191: TIM4->CR1 &= (uint8_t)(~TIM4_CR1_OPM);
	and	a, #0xf7
	ld	0x5340, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 193: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 215: void TIM4_PrescalerConfig(TIM4_Prescaler_TypeDef Prescaler, TIM4_PSCReloadMode_TypeDef TIM4_PSCReloadMode)
;	-----------------------------------------
;	 function TIM4_PrescalerConfig
;	-----------------------------------------
_TIM4_PrescalerConfig:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 218: assert_param(IS_TIM4_PRESCALER_RELOAD_OK(TIM4_PSCReloadMode));
	tnz	(0x04, sp)
	jreq	00104$
	ld	a, (0x04, sp)
	dec	a
	jreq	00104$
	push	#0xda
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 219: assert_param(IS_TIM4_PRESCALER_OK(Prescaler));
	tnz	(0x03, sp)
	jreq	00109$
	ld	a, (0x03, sp)
	dec	a
	jreq	00109$
	ld	a, (0x03, sp)
	cp	a, #0x02
	jreq	00109$
	ld	a, (0x03, sp)
	cp	a, #0x03
	jreq	00109$
	ld	a, (0x03, sp)
	cp	a, #0x04
	jreq	00109$
	ld	a, (0x03, sp)
	cp	a, #0x05
	jreq	00109$
	ld	a, (0x03, sp)
	cp	a, #0x06
	jreq	00109$
	ld	a, (0x03, sp)
	cp	a, #0x07
	jreq	00109$
	push	#0xdb
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00109$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 222: TIM4->PSCR = (uint8_t)Prescaler;
	ldw	x, #0x5347
	ld	a, (0x03, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 225: TIM4->EGR = (uint8_t)TIM4_PSCReloadMode;
	ldw	x, #0x5345
	ld	a, (0x04, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 226: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 234: void TIM4_ARRPreloadConfig(FunctionalState NewState)
;	-----------------------------------------
;	 function TIM4_ARRPreloadConfig
;	-----------------------------------------
_TIM4_ARRPreloadConfig:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 237: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
	tnz	(0x03, sp)
	jreq	00107$
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0xed
	clrw	x
	pushw	x
	push	#0x00
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 242: TIM4->CR1 |= TIM4_CR1_ARPE;
	ld	a, 0x5340
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 240: if (NewState != DISABLE)
	tnz	(0x03, sp)
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 242: TIM4->CR1 |= TIM4_CR1_ARPE;
	or	a, #0x80
	ld	0x5340, a
	ret
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 246: TIM4->CR1 &= (uint8_t)(~TIM4_CR1_ARPE);
	and	a, #0x7f
	ld	0x5340, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 248: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 257: void TIM4_GenerateEvent(TIM4_EventSource_TypeDef TIM4_EventSource)
;	-----------------------------------------
;	 function TIM4_GenerateEvent
;	-----------------------------------------
_TIM4_GenerateEvent:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 260: assert_param(IS_TIM4_EVENT_SOURCE_OK(TIM4_EventSource));
	ld	a, (0x03, sp)
	dec	a
	jreq	00104$
	push	#0x04
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 263: TIM4->EGR = (uint8_t)(TIM4_EventSource);
	ldw	x, #0x5345
	ld	a, (0x03, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 264: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 272: void TIM4_SetCounter(uint8_t Counter)
;	-----------------------------------------
;	 function TIM4_SetCounter
;	-----------------------------------------
_TIM4_SetCounter:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 275: TIM4->CNTR = (uint8_t)(Counter);
	ldw	x, #0x5346
	ld	a, (0x03, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 276: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 284: void TIM4_SetAutoreload(uint8_t Autoreload)
;	-----------------------------------------
;	 function TIM4_SetAutoreload
;	-----------------------------------------
_TIM4_SetAutoreload:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 287: TIM4->ARR = (uint8_t)(Autoreload);
	ldw	x, #0x5348
	ld	a, (0x03, sp)
	ld	(x), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 288: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 295: uint8_t TIM4_GetCounter(void)
;	-----------------------------------------
;	 function TIM4_GetCounter
;	-----------------------------------------
_TIM4_GetCounter:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 298: return (uint8_t)(TIM4->CNTR);
	ld	a, 0x5346
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 299: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 306: TIM4_Prescaler_TypeDef TIM4_GetPrescaler(void)
;	-----------------------------------------
;	 function TIM4_GetPrescaler
;	-----------------------------------------
_TIM4_GetPrescaler:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 309: return (TIM4_Prescaler_TypeDef)(TIM4->PSCR);
	ld	a, 0x5347
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 310: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 319: FlagStatus TIM4_GetFlagStatus(TIM4_FLAG_TypeDef TIM4_FLAG)
;	-----------------------------------------
;	 function TIM4_GetFlagStatus
;	-----------------------------------------
_TIM4_GetFlagStatus:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 324: assert_param(IS_TIM4_GET_FLAG_OK(TIM4_FLAG));
	ld	a, (0x03, sp)
	dec	a
	jreq	00107$
	push	#0x44
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00107$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 326: if ((TIM4->SR1 & (uint8_t)TIM4_FLAG)  != 0)
	ld	a, 0x5344
	and	a, (0x03, sp)
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 328: bitstatus = SET;
	ld	a, #0x01
	ret
00102$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 332: bitstatus = RESET;
	clr	a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 334: return ((FlagStatus)bitstatus);
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 335: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 344: void TIM4_ClearFlag(TIM4_FLAG_TypeDef TIM4_FLAG)
;	-----------------------------------------
;	 function TIM4_ClearFlag
;	-----------------------------------------
_TIM4_ClearFlag:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 347: assert_param(IS_TIM4_GET_FLAG_OK(TIM4_FLAG));
	ld	a, (0x03, sp)
	dec	a
	jreq	00104$
	push	#0x5b
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 350: TIM4->SR1 = (uint8_t)(~TIM4_FLAG);
	ld	a, (0x03, sp)
	cpl	a
	ld	0x5344, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 351: }
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 360: ITStatus TIM4_GetITStatus(TIM4_IT_TypeDef TIM4_IT)
;	-----------------------------------------
;	 function TIM4_GetITStatus
;	-----------------------------------------
_TIM4_GetITStatus:
	push	a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 367: assert_param(IS_TIM4_IT_OK(TIM4_IT));
	ld	a, (0x04, sp)
	dec	a
	jreq	00108$
	push	#0x6f
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00108$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 369: itstatus = (uint8_t)(TIM4->SR1 & (uint8_t)TIM4_IT);
	ld	a, 0x5344
	and	a, (0x04, sp)
	ld	(0x01, sp), a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 371: itenable = (uint8_t)(TIM4->IER & (uint8_t)TIM4_IT);
	ld	a, 0x5343
	and	a, (0x04, sp)
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 373: if ((itstatus != (uint8_t)RESET ) && (itenable != (uint8_t)RESET ))
	tnz	(0x01, sp)
	jreq	00102$
	tnz	a
	jreq	00102$
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 375: bitstatus = (ITStatus)SET;
	ld	a, #0x01
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 379: bitstatus = (ITStatus)RESET;
	.byte 0x21
00102$:
	clr	a
00103$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 381: return ((ITStatus)bitstatus);
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 382: }
	addw	sp, #1
	ret
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 391: void TIM4_ClearITPendingBit(TIM4_IT_TypeDef TIM4_IT)
;	-----------------------------------------
;	 function TIM4_ClearITPendingBit
;	-----------------------------------------
_TIM4_ClearITPendingBit:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 394: assert_param(IS_TIM4_IT_OK(TIM4_IT));
	ld	a, (0x03, sp)
	dec	a
	jreq	00104$
	push	#0x8a
	push	#0x01
	clrw	x
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_assert_failed
	addw	sp, #6
00104$:
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 397: TIM4->SR1 = (uint8_t)(~TIM4_IT);
	ld	a, (0x03, sp)
	cpl	a
	ld	0x5344, a
;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 398: }
	ret
	.area CODE
	.area CONST
___str_0:
	.ascii "../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c"
	.db 0x00
	.area INITIALIZER
	.area CABS (ABS)
