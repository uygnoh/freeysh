;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _printf
	.globl _UART1_GetFlagStatus
	.globl _UART1_SendData8
	.globl _UART1_ReceiveData8
	.globl _UART1_Init
	.globl _UART1_DeInit
	.globl _TIM4_ClearFlag
	.globl _TIM4_ITConfig
	.globl _TIM4_Cmd
	.globl _TIM4_TimeBaseInit
	.globl _TIM4_DeInit
	.globl _GPIO_WriteReverse
	.globl _GPIO_WriteHigh
	.globl _GPIO_Init
	.globl _CLK_HSIPrescalerConfig
	.globl _CLK_PeripheralClockConfig
	.globl _g_count1ms
	.globl _g_flag1ms
	.globl _putchar
	.globl _getchar
	.globl _assert_failed
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
_g_flag1ms::
	.ds 1
_g_count1ms::
	.ds 4
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

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
; interrupt vector 
;--------------------------------------------------------
	.area HOME
__interrupt_vect:
	int s_GSINIT ; reset
	int _TRAP_IRQHandler ; trap
	int _TLI_IRQHandler ; int0
	int _AWU_IRQHandler ; int1
	int _CLK_IRQHandler ; int2
	int _EXTI_PORTA_IRQHandler ; int3
	int _EXTI_PORTB_IRQHandler ; int4
	int _EXTI_PORTC_IRQHandler ; int5
	int _EXTI_PORTD_IRQHandler ; int6
	int _EXTI_PORTE_IRQHandler ; int7
	int 0x000000 ; int8
	int 0x000000 ; int9
	int _SPI_IRQHandler ; int10
	int _TIM1_UPD_OVF_TRG_BRK_IRQHandler ; int11
	int _TIM1_CAP_COM_IRQHandler ; int12
	int _TIM2_UPD_OVF_BRK_IRQHandler ; int13
	int _TIM2_CAP_COM_IRQHandler ; int14
	int 0x000000 ; int15
	int 0x000000 ; int16
	int _UART1_TX_IRQHandler ; int17
	int _UART1_RX_IRQHandler ; int18
	int _I2C_IRQHandler ; int19
	int 0x000000 ; int20
	int 0x000000 ; int21
	int _ADC1_IRQHandler ; int22
	int _TIM4_UPD_OVF_IRQHandler ; int23
	int _EEPROM_EEC_IRQHandler ; int24
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
__sdcc_gs_init_startup:
__sdcc_init_data:
; stm8_genXINIT() start
	ldw x, #l_DATA
	jreq	00002$
00001$:
	clr (s_DATA - 1, x)
	decw x
	jrne	00001$
00002$:
	ldw	x, #l_INITIALIZER
	jreq	00004$
00003$:
	ld	a, (s_INITIALIZER - 1, x)
	ld	(s_INITIALIZED - 1, x), a
	decw	x
	jrne	00003$
00004$:
; stm8_genXINIT() end
	.area GSFINAL
	jp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
__sdcc_program_startup:
	jp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	../main.c: 68: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	../main.c: 75: CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
	push	#0x00
	call	_CLK_HSIPrescalerConfig
	pop	a
;	../main.c: 78: CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);
	push	#0x01
	push	#0x04
	call	_CLK_PeripheralClockConfig
	popw	x
;	../main.c: 82: GPIO_Init(GPIOD, (GPIO_Pin_TypeDef)GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
	push	#0xe0
	push	#0x08
	push	#0x0f
	push	#0x50
	call	_GPIO_Init
	addw	sp, #4
;	../main.c: 83: GPIO_WriteHigh(GPIOD, (GPIO_Pin_TypeDef)GPIO_PIN_3);
	push	#0x08
	push	#0x0f
	push	#0x50
	call	_GPIO_WriteHigh
	addw	sp, #3
;	../main.c: 92: TIM4_DeInit();
	call	_TIM4_DeInit
;	../main.c: 93: TIM4_TimeBaseInit(TIM4_PRESCALER_128, 124);
	push	#0x7c
	push	#0x07
	call	_TIM4_TimeBaseInit
	popw	x
;	../main.c: 94: TIM4_ClearFlag(TIM4_FLAG_UPDATE);
	push	#0x01
	call	_TIM4_ClearFlag
	pop	a
;	../main.c: 95: TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
	push	#0x01
	push	#0x01
	call	_TIM4_ITConfig
	popw	x
;	../main.c: 96: TIM4_Cmd(ENABLE);
	push	#0x01
	call	_TIM4_Cmd
	pop	a
;	../main.c: 99: UART1_DeInit();
	call	_UART1_DeInit
;	../main.c: 100: UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
	push	#0x0c
	push	#0x80
	push	#0x00
	push	#0x00
	push	#0x00
	push	#0x00
	push	#0xc2
	push	#0x01
	push	#0x00
	call	_UART1_Init
	addw	sp, #9
;	../main.c: 110: enableInterrupts();
	rim
;	../main.c: 113: while (1)
00108$:
;	../main.c: 116: if (UART1_GetFlagStatus(UART1_FLAG_RXNE))
	push	#0x20
	push	#0x00
	call	_UART1_GetFlagStatus
	popw	x
	tnz	a
	jreq	00102$
;	../main.c: 118: val = getchar();
	call	_getchar
;	../main.c: 119: printf("read %c%c%c", val,10,13);
	clr	a
	ld	xh, a
	push	#0x0d
	push	#0x00
	push	#0x0a
	push	#0x00
	pushw	x
	push	#<___str_0
	push	#(___str_0 >> 8)
	call	_printf
	addw	sp, #8
00102$:
;	../main.c: 125: if (g_flag1ms)
	tnz	_g_flag1ms+0
	jreq	00108$
;	../main.c: 127: g_flag1ms=0;
	clr	_g_flag1ms+0
;	../main.c: 129: if ((g_count1ms % 500) == 0)
	push	#0xf4
	push	#0x01
	clrw	x
	pushw	x
	ldw	x, _g_count1ms+2
	pushw	x
	ldw	x, _g_count1ms+0
	pushw	x
	call	__modulong
	addw	sp, #8
	tnzw	x
	jrne	00108$
	tnzw	y
	jrne	00108$
;	../main.c: 133: GPIO_WriteReverse(GPIOD, (GPIO_Pin_TypeDef)GPIO_PIN_3);
	push	#0x08
	push	#0x0f
	push	#0x50
	call	_GPIO_WriteReverse
	addw	sp, #3
;	../main.c: 141: printf("time %ld%c%c", g_count1ms,10,13);
	push	#0x0d
	push	#0x00
	push	#0x0a
	push	#0x00
	ldw	x, _g_count1ms+2
	pushw	x
	ldw	x, _g_count1ms+0
	pushw	x
	push	#<___str_1
	push	#(___str_1 >> 8)
	call	_printf
	addw	sp, #10
	jra	00108$
;	../main.c: 179: } // main()
	ret
;	../main.c: 187: PUTCHAR_PROTOTYPE
;	-----------------------------------------
;	 function putchar
;	-----------------------------------------
_putchar:
;	../main.c: 190: UART1_SendData8(c);
	ld	a, (0x04, sp)
	push	a
	call	_UART1_SendData8
	pop	a
;	../main.c: 192: while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
00101$:
	push	#0x80
	push	#0x00
	call	_UART1_GetFlagStatus
	popw	x
	tnz	a
	jreq	00101$
;	../main.c: 198: }
	ret
;	../main.c: 206: GETCHAR_PROTOTYPE
;	-----------------------------------------
;	 function getchar
;	-----------------------------------------
_getchar:
;	../main.c: 214: while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);
00101$:
	push	#0x20
	push	#0x00
	call	_UART1_GetFlagStatus
	popw	x
	tnz	a
	jreq	00101$
;	../main.c: 215: c = UART1_ReceiveData8();
	call	_UART1_ReceiveData8
	clrw	x
	ld	xl, a
;	../main.c: 216: return (c);
;	../main.c: 217: }
	ret
;	../main.c: 229: void assert_failed(uint8_t* file, uint32_t line)
;	-----------------------------------------
;	 function assert_failed
;	-----------------------------------------
_assert_failed:
;	../main.c: 239: while (1)
00102$:
	jra	00102$
;	../main.c: 242: }
	ret
	.area CODE
	.area CONST
___str_0:
	.ascii "read %c%c%c"
	.db 0x00
___str_1:
	.ascii "time %ld%c%c"
	.db 0x00
	.area INITIALIZER
__xinit__g_flag1ms:
	.db #0x00	; 0
__xinit__g_count1ms:
	.byte #0x00,#0x00,#0x00,#0x00	; 0
	.area CABS (ABS)
