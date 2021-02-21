                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_tim4
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _assert_failed
                                     12 	.globl _TIM4_DeInit
                                     13 	.globl _TIM4_TimeBaseInit
                                     14 	.globl _TIM4_Cmd
                                     15 	.globl _TIM4_ITConfig
                                     16 	.globl _TIM4_UpdateDisableConfig
                                     17 	.globl _TIM4_UpdateRequestConfig
                                     18 	.globl _TIM4_SelectOnePulseMode
                                     19 	.globl _TIM4_PrescalerConfig
                                     20 	.globl _TIM4_ARRPreloadConfig
                                     21 	.globl _TIM4_GenerateEvent
                                     22 	.globl _TIM4_SetCounter
                                     23 	.globl _TIM4_SetAutoreload
                                     24 	.globl _TIM4_GetCounter
                                     25 	.globl _TIM4_GetPrescaler
                                     26 	.globl _TIM4_GetFlagStatus
                                     27 	.globl _TIM4_ClearFlag
                                     28 	.globl _TIM4_GetITStatus
                                     29 	.globl _TIM4_ClearITPendingBit
                                     30 ;--------------------------------------------------------
                                     31 ; ram data
                                     32 ;--------------------------------------------------------
                                     33 	.area DATA
                                     34 ;--------------------------------------------------------
                                     35 ; ram data
                                     36 ;--------------------------------------------------------
                                     37 	.area INITIALIZED
                                     38 ;--------------------------------------------------------
                                     39 ; absolute external ram data
                                     40 ;--------------------------------------------------------
                                     41 	.area DABS (ABS)
                                     42 
                                     43 ; default segment ordering for linker
                                     44 	.area HOME
                                     45 	.area GSINIT
                                     46 	.area GSFINAL
                                     47 	.area CONST
                                     48 	.area INITIALIZER
                                     49 	.area CODE
                                     50 
                                     51 ;--------------------------------------------------------
                                     52 ; global & static initialisations
                                     53 ;--------------------------------------------------------
                                     54 	.area HOME
                                     55 	.area GSINIT
                                     56 	.area GSFINAL
                                     57 	.area GSINIT
                                     58 ;--------------------------------------------------------
                                     59 ; Home
                                     60 ;--------------------------------------------------------
                                     61 	.area HOME
                                     62 	.area HOME
                                     63 ;--------------------------------------------------------
                                     64 ; code
                                     65 ;--------------------------------------------------------
                                     66 	.area CODE
                                     67 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 49: void TIM4_DeInit(void)
                                     68 ;	-----------------------------------------
                                     69 ;	 function TIM4_DeInit
                                     70 ;	-----------------------------------------
      0097B5                         71 _TIM4_DeInit:
                                     72 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 51: TIM4->CR1 = TIM4_CR1_RESET_VALUE;
      0097B5 35 00 53 40      [ 1]   73 	mov	0x5340+0, #0x00
                                     74 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 52: TIM4->IER = TIM4_IER_RESET_VALUE;
      0097B9 35 00 53 43      [ 1]   75 	mov	0x5343+0, #0x00
                                     76 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 53: TIM4->CNTR = TIM4_CNTR_RESET_VALUE;
      0097BD 35 00 53 46      [ 1]   77 	mov	0x5346+0, #0x00
                                     78 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 54: TIM4->PSCR = TIM4_PSCR_RESET_VALUE;
      0097C1 35 00 53 47      [ 1]   79 	mov	0x5347+0, #0x00
                                     80 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 55: TIM4->ARR = TIM4_ARR_RESET_VALUE;
      0097C5 35 FF 53 48      [ 1]   81 	mov	0x5348+0, #0xff
                                     82 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 56: TIM4->SR1 = TIM4_SR1_RESET_VALUE;
      0097C9 35 00 53 44      [ 1]   83 	mov	0x5344+0, #0x00
                                     84 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 57: }
      0097CD 81               [ 4]   85 	ret
                                     86 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 65: void TIM4_TimeBaseInit(TIM4_Prescaler_TypeDef TIM4_Prescaler, uint8_t TIM4_Period)
                                     87 ;	-----------------------------------------
                                     88 ;	 function TIM4_TimeBaseInit
                                     89 ;	-----------------------------------------
      0097CE                         90 _TIM4_TimeBaseInit:
                                     91 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 68: assert_param(IS_TIM4_PRESCALER_OK(TIM4_Prescaler));
      0097CE 0D 03            [ 1]   92 	tnz	(0x03, sp)
      0097D0 27 38            [ 1]   93 	jreq	00104$
      0097D2 7B 03            [ 1]   94 	ld	a, (0x03, sp)
      0097D4 4A               [ 1]   95 	dec	a
      0097D5 27 33            [ 1]   96 	jreq	00104$
      0097D7 7B 03            [ 1]   97 	ld	a, (0x03, sp)
      0097D9 A1 02            [ 1]   98 	cp	a, #0x02
      0097DB 27 2D            [ 1]   99 	jreq	00104$
      0097DD 7B 03            [ 1]  100 	ld	a, (0x03, sp)
      0097DF A1 03            [ 1]  101 	cp	a, #0x03
      0097E1 27 27            [ 1]  102 	jreq	00104$
      0097E3 7B 03            [ 1]  103 	ld	a, (0x03, sp)
      0097E5 A1 04            [ 1]  104 	cp	a, #0x04
      0097E7 27 21            [ 1]  105 	jreq	00104$
      0097E9 7B 03            [ 1]  106 	ld	a, (0x03, sp)
      0097EB A1 05            [ 1]  107 	cp	a, #0x05
      0097ED 27 1B            [ 1]  108 	jreq	00104$
      0097EF 7B 03            [ 1]  109 	ld	a, (0x03, sp)
      0097F1 A1 06            [ 1]  110 	cp	a, #0x06
      0097F3 27 15            [ 1]  111 	jreq	00104$
      0097F5 7B 03            [ 1]  112 	ld	a, (0x03, sp)
      0097F7 A1 07            [ 1]  113 	cp	a, #0x07
      0097F9 27 0F            [ 1]  114 	jreq	00104$
      0097FB 4B 44            [ 1]  115 	push	#0x44
      0097FD 5F               [ 1]  116 	clrw	x
      0097FE 89               [ 2]  117 	pushw	x
      0097FF 4B 00            [ 1]  118 	push	#0x00
      009801 4B 9E            [ 1]  119 	push	#<___str_0
      009803 4B 81            [ 1]  120 	push	#(___str_0 >> 8)
      009805 CD 83 14         [ 4]  121 	call	_assert_failed
      009808 5B 06            [ 2]  122 	addw	sp, #6
      00980A                        123 00104$:
                                    124 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 70: TIM4->PSCR = (uint8_t)(TIM4_Prescaler);
      00980A AE 53 47         [ 2]  125 	ldw	x, #0x5347
      00980D 7B 03            [ 1]  126 	ld	a, (0x03, sp)
      00980F F7               [ 1]  127 	ld	(x), a
                                    128 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 72: TIM4->ARR = (uint8_t)(TIM4_Period);
      009810 AE 53 48         [ 2]  129 	ldw	x, #0x5348
      009813 7B 04            [ 1]  130 	ld	a, (0x04, sp)
      009815 F7               [ 1]  131 	ld	(x), a
                                    132 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 73: }
      009816 81               [ 4]  133 	ret
                                    134 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 81: void TIM4_Cmd(FunctionalState NewState)
                                    135 ;	-----------------------------------------
                                    136 ;	 function TIM4_Cmd
                                    137 ;	-----------------------------------------
      009817                        138 _TIM4_Cmd:
                                    139 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 84: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      009817 0D 03            [ 1]  140 	tnz	(0x03, sp)
      009819 27 14            [ 1]  141 	jreq	00107$
      00981B 7B 03            [ 1]  142 	ld	a, (0x03, sp)
      00981D 4A               [ 1]  143 	dec	a
      00981E 27 0F            [ 1]  144 	jreq	00107$
      009820 4B 54            [ 1]  145 	push	#0x54
      009822 5F               [ 1]  146 	clrw	x
      009823 89               [ 2]  147 	pushw	x
      009824 4B 00            [ 1]  148 	push	#0x00
      009826 4B 9E            [ 1]  149 	push	#<___str_0
      009828 4B 81            [ 1]  150 	push	#(___str_0 >> 8)
      00982A CD 83 14         [ 4]  151 	call	_assert_failed
      00982D 5B 06            [ 2]  152 	addw	sp, #6
      00982F                        153 00107$:
                                    154 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 89: TIM4->CR1 |= TIM4_CR1_CEN;
      00982F C6 53 40         [ 1]  155 	ld	a, 0x5340
                                    156 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 87: if (NewState != DISABLE)
      009832 0D 03            [ 1]  157 	tnz	(0x03, sp)
      009834 27 06            [ 1]  158 	jreq	00102$
                                    159 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 89: TIM4->CR1 |= TIM4_CR1_CEN;
      009836 AA 01            [ 1]  160 	or	a, #0x01
      009838 C7 53 40         [ 1]  161 	ld	0x5340, a
      00983B 81               [ 4]  162 	ret
      00983C                        163 00102$:
                                    164 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 93: TIM4->CR1 &= (uint8_t)(~TIM4_CR1_CEN);
      00983C A4 FE            [ 1]  165 	and	a, #0xfe
      00983E C7 53 40         [ 1]  166 	ld	0x5340, a
                                    167 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 95: }
      009841 81               [ 4]  168 	ret
                                    169 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 107: void TIM4_ITConfig(TIM4_IT_TypeDef TIM4_IT, FunctionalState NewState)
                                    170 ;	-----------------------------------------
                                    171 ;	 function TIM4_ITConfig
                                    172 ;	-----------------------------------------
      009842                        173 _TIM4_ITConfig:
      009842 88               [ 1]  174 	push	a
                                    175 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 110: assert_param(IS_TIM4_IT_OK(TIM4_IT));
      009843 7B 04            [ 1]  176 	ld	a, (0x04, sp)
      009845 4A               [ 1]  177 	dec	a
      009846 27 0F            [ 1]  178 	jreq	00107$
      009848 4B 6E            [ 1]  179 	push	#0x6e
      00984A 5F               [ 1]  180 	clrw	x
      00984B 89               [ 2]  181 	pushw	x
      00984C 4B 00            [ 1]  182 	push	#0x00
      00984E 4B 9E            [ 1]  183 	push	#<___str_0
      009850 4B 81            [ 1]  184 	push	#(___str_0 >> 8)
      009852 CD 83 14         [ 4]  185 	call	_assert_failed
      009855 5B 06            [ 2]  186 	addw	sp, #6
      009857                        187 00107$:
                                    188 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 111: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      009857 0D 05            [ 1]  189 	tnz	(0x05, sp)
      009859 27 14            [ 1]  190 	jreq	00109$
      00985B 7B 05            [ 1]  191 	ld	a, (0x05, sp)
      00985D 4A               [ 1]  192 	dec	a
      00985E 27 0F            [ 1]  193 	jreq	00109$
      009860 4B 6F            [ 1]  194 	push	#0x6f
      009862 5F               [ 1]  195 	clrw	x
      009863 89               [ 2]  196 	pushw	x
      009864 4B 00            [ 1]  197 	push	#0x00
      009866 4B 9E            [ 1]  198 	push	#<___str_0
      009868 4B 81            [ 1]  199 	push	#(___str_0 >> 8)
      00986A CD 83 14         [ 4]  200 	call	_assert_failed
      00986D 5B 06            [ 2]  201 	addw	sp, #6
      00986F                        202 00109$:
                                    203 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 116: TIM4->IER |= (uint8_t)TIM4_IT;
      00986F C6 53 43         [ 1]  204 	ld	a, 0x5343
                                    205 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 113: if (NewState != DISABLE)
      009872 0D 05            [ 1]  206 	tnz	(0x05, sp)
      009874 27 07            [ 1]  207 	jreq	00102$
                                    208 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 116: TIM4->IER |= (uint8_t)TIM4_IT;
      009876 1A 04            [ 1]  209 	or	a, (0x04, sp)
      009878 C7 53 43         [ 1]  210 	ld	0x5343, a
      00987B 20 0C            [ 2]  211 	jra	00104$
      00987D                        212 00102$:
                                    213 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 121: TIM4->IER &= (uint8_t)(~TIM4_IT);
      00987D 88               [ 1]  214 	push	a
      00987E 7B 05            [ 1]  215 	ld	a, (0x05, sp)
      009880 43               [ 1]  216 	cpl	a
      009881 6B 02            [ 1]  217 	ld	(0x02, sp), a
      009883 84               [ 1]  218 	pop	a
      009884 14 01            [ 1]  219 	and	a, (0x01, sp)
      009886 C7 53 43         [ 1]  220 	ld	0x5343, a
      009889                        221 00104$:
                                    222 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 123: }
      009889 84               [ 1]  223 	pop	a
      00988A 81               [ 4]  224 	ret
                                    225 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 131: void TIM4_UpdateDisableConfig(FunctionalState NewState)
                                    226 ;	-----------------------------------------
                                    227 ;	 function TIM4_UpdateDisableConfig
                                    228 ;	-----------------------------------------
      00988B                        229 _TIM4_UpdateDisableConfig:
                                    230 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 134: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      00988B 0D 03            [ 1]  231 	tnz	(0x03, sp)
      00988D 27 14            [ 1]  232 	jreq	00107$
      00988F 7B 03            [ 1]  233 	ld	a, (0x03, sp)
      009891 4A               [ 1]  234 	dec	a
      009892 27 0F            [ 1]  235 	jreq	00107$
      009894 4B 86            [ 1]  236 	push	#0x86
      009896 5F               [ 1]  237 	clrw	x
      009897 89               [ 2]  238 	pushw	x
      009898 4B 00            [ 1]  239 	push	#0x00
      00989A 4B 9E            [ 1]  240 	push	#<___str_0
      00989C 4B 81            [ 1]  241 	push	#(___str_0 >> 8)
      00989E CD 83 14         [ 4]  242 	call	_assert_failed
      0098A1 5B 06            [ 2]  243 	addw	sp, #6
      0098A3                        244 00107$:
                                    245 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 139: TIM4->CR1 |= TIM4_CR1_UDIS;
      0098A3 C6 53 40         [ 1]  246 	ld	a, 0x5340
                                    247 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 137: if (NewState != DISABLE)
      0098A6 0D 03            [ 1]  248 	tnz	(0x03, sp)
      0098A8 27 06            [ 1]  249 	jreq	00102$
                                    250 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 139: TIM4->CR1 |= TIM4_CR1_UDIS;
      0098AA AA 02            [ 1]  251 	or	a, #0x02
      0098AC C7 53 40         [ 1]  252 	ld	0x5340, a
      0098AF 81               [ 4]  253 	ret
      0098B0                        254 00102$:
                                    255 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 143: TIM4->CR1 &= (uint8_t)(~TIM4_CR1_UDIS);
      0098B0 A4 FD            [ 1]  256 	and	a, #0xfd
      0098B2 C7 53 40         [ 1]  257 	ld	0x5340, a
                                    258 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 145: }
      0098B5 81               [ 4]  259 	ret
                                    260 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 155: void TIM4_UpdateRequestConfig(TIM4_UpdateSource_TypeDef TIM4_UpdateSource)
                                    261 ;	-----------------------------------------
                                    262 ;	 function TIM4_UpdateRequestConfig
                                    263 ;	-----------------------------------------
      0098B6                        264 _TIM4_UpdateRequestConfig:
                                    265 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 158: assert_param(IS_TIM4_UPDATE_SOURCE_OK(TIM4_UpdateSource));
      0098B6 0D 03            [ 1]  266 	tnz	(0x03, sp)
      0098B8 27 14            [ 1]  267 	jreq	00107$
      0098BA 7B 03            [ 1]  268 	ld	a, (0x03, sp)
      0098BC 4A               [ 1]  269 	dec	a
      0098BD 27 0F            [ 1]  270 	jreq	00107$
      0098BF 4B 9E            [ 1]  271 	push	#0x9e
      0098C1 5F               [ 1]  272 	clrw	x
      0098C2 89               [ 2]  273 	pushw	x
      0098C3 4B 00            [ 1]  274 	push	#0x00
      0098C5 4B 9E            [ 1]  275 	push	#<___str_0
      0098C7 4B 81            [ 1]  276 	push	#(___str_0 >> 8)
      0098C9 CD 83 14         [ 4]  277 	call	_assert_failed
      0098CC 5B 06            [ 2]  278 	addw	sp, #6
      0098CE                        279 00107$:
                                    280 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 163: TIM4->CR1 |= TIM4_CR1_URS;
      0098CE C6 53 40         [ 1]  281 	ld	a, 0x5340
                                    282 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 161: if (TIM4_UpdateSource != TIM4_UPDATESOURCE_GLOBAL)
      0098D1 0D 03            [ 1]  283 	tnz	(0x03, sp)
      0098D3 27 06            [ 1]  284 	jreq	00102$
                                    285 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 163: TIM4->CR1 |= TIM4_CR1_URS;
      0098D5 AA 04            [ 1]  286 	or	a, #0x04
      0098D7 C7 53 40         [ 1]  287 	ld	0x5340, a
      0098DA 81               [ 4]  288 	ret
      0098DB                        289 00102$:
                                    290 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 167: TIM4->CR1 &= (uint8_t)(~TIM4_CR1_URS);
      0098DB A4 FB            [ 1]  291 	and	a, #0xfb
      0098DD C7 53 40         [ 1]  292 	ld	0x5340, a
                                    293 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 169: }
      0098E0 81               [ 4]  294 	ret
                                    295 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 179: void TIM4_SelectOnePulseMode(TIM4_OPMode_TypeDef TIM4_OPMode)
                                    296 ;	-----------------------------------------
                                    297 ;	 function TIM4_SelectOnePulseMode
                                    298 ;	-----------------------------------------
      0098E1                        299 _TIM4_SelectOnePulseMode:
                                    300 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 182: assert_param(IS_TIM4_OPM_MODE_OK(TIM4_OPMode));
      0098E1 7B 03            [ 1]  301 	ld	a, (0x03, sp)
      0098E3 4A               [ 1]  302 	dec	a
      0098E4 27 13            [ 1]  303 	jreq	00107$
      0098E6 0D 03            [ 1]  304 	tnz	(0x03, sp)
      0098E8 27 0F            [ 1]  305 	jreq	00107$
      0098EA 4B B6            [ 1]  306 	push	#0xb6
      0098EC 5F               [ 1]  307 	clrw	x
      0098ED 89               [ 2]  308 	pushw	x
      0098EE 4B 00            [ 1]  309 	push	#0x00
      0098F0 4B 9E            [ 1]  310 	push	#<___str_0
      0098F2 4B 81            [ 1]  311 	push	#(___str_0 >> 8)
      0098F4 CD 83 14         [ 4]  312 	call	_assert_failed
      0098F7 5B 06            [ 2]  313 	addw	sp, #6
      0098F9                        314 00107$:
                                    315 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 187: TIM4->CR1 |= TIM4_CR1_OPM;
      0098F9 C6 53 40         [ 1]  316 	ld	a, 0x5340
                                    317 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 185: if (TIM4_OPMode != TIM4_OPMODE_REPETITIVE)
      0098FC 0D 03            [ 1]  318 	tnz	(0x03, sp)
      0098FE 27 06            [ 1]  319 	jreq	00102$
                                    320 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 187: TIM4->CR1 |= TIM4_CR1_OPM;
      009900 AA 08            [ 1]  321 	or	a, #0x08
      009902 C7 53 40         [ 1]  322 	ld	0x5340, a
      009905 81               [ 4]  323 	ret
      009906                        324 00102$:
                                    325 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 191: TIM4->CR1 &= (uint8_t)(~TIM4_CR1_OPM);
      009906 A4 F7            [ 1]  326 	and	a, #0xf7
      009908 C7 53 40         [ 1]  327 	ld	0x5340, a
                                    328 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 193: }
      00990B 81               [ 4]  329 	ret
                                    330 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 215: void TIM4_PrescalerConfig(TIM4_Prescaler_TypeDef Prescaler, TIM4_PSCReloadMode_TypeDef TIM4_PSCReloadMode)
                                    331 ;	-----------------------------------------
                                    332 ;	 function TIM4_PrescalerConfig
                                    333 ;	-----------------------------------------
      00990C                        334 _TIM4_PrescalerConfig:
                                    335 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 218: assert_param(IS_TIM4_PRESCALER_RELOAD_OK(TIM4_PSCReloadMode));
      00990C 0D 04            [ 1]  336 	tnz	(0x04, sp)
      00990E 27 14            [ 1]  337 	jreq	00104$
      009910 7B 04            [ 1]  338 	ld	a, (0x04, sp)
      009912 4A               [ 1]  339 	dec	a
      009913 27 0F            [ 1]  340 	jreq	00104$
      009915 4B DA            [ 1]  341 	push	#0xda
      009917 5F               [ 1]  342 	clrw	x
      009918 89               [ 2]  343 	pushw	x
      009919 4B 00            [ 1]  344 	push	#0x00
      00991B 4B 9E            [ 1]  345 	push	#<___str_0
      00991D 4B 81            [ 1]  346 	push	#(___str_0 >> 8)
      00991F CD 83 14         [ 4]  347 	call	_assert_failed
      009922 5B 06            [ 2]  348 	addw	sp, #6
      009924                        349 00104$:
                                    350 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 219: assert_param(IS_TIM4_PRESCALER_OK(Prescaler));
      009924 0D 03            [ 1]  351 	tnz	(0x03, sp)
      009926 27 38            [ 1]  352 	jreq	00109$
      009928 7B 03            [ 1]  353 	ld	a, (0x03, sp)
      00992A 4A               [ 1]  354 	dec	a
      00992B 27 33            [ 1]  355 	jreq	00109$
      00992D 7B 03            [ 1]  356 	ld	a, (0x03, sp)
      00992F A1 02            [ 1]  357 	cp	a, #0x02
      009931 27 2D            [ 1]  358 	jreq	00109$
      009933 7B 03            [ 1]  359 	ld	a, (0x03, sp)
      009935 A1 03            [ 1]  360 	cp	a, #0x03
      009937 27 27            [ 1]  361 	jreq	00109$
      009939 7B 03            [ 1]  362 	ld	a, (0x03, sp)
      00993B A1 04            [ 1]  363 	cp	a, #0x04
      00993D 27 21            [ 1]  364 	jreq	00109$
      00993F 7B 03            [ 1]  365 	ld	a, (0x03, sp)
      009941 A1 05            [ 1]  366 	cp	a, #0x05
      009943 27 1B            [ 1]  367 	jreq	00109$
      009945 7B 03            [ 1]  368 	ld	a, (0x03, sp)
      009947 A1 06            [ 1]  369 	cp	a, #0x06
      009949 27 15            [ 1]  370 	jreq	00109$
      00994B 7B 03            [ 1]  371 	ld	a, (0x03, sp)
      00994D A1 07            [ 1]  372 	cp	a, #0x07
      00994F 27 0F            [ 1]  373 	jreq	00109$
      009951 4B DB            [ 1]  374 	push	#0xdb
      009953 5F               [ 1]  375 	clrw	x
      009954 89               [ 2]  376 	pushw	x
      009955 4B 00            [ 1]  377 	push	#0x00
      009957 4B 9E            [ 1]  378 	push	#<___str_0
      009959 4B 81            [ 1]  379 	push	#(___str_0 >> 8)
      00995B CD 83 14         [ 4]  380 	call	_assert_failed
      00995E 5B 06            [ 2]  381 	addw	sp, #6
      009960                        382 00109$:
                                    383 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 222: TIM4->PSCR = (uint8_t)Prescaler;
      009960 AE 53 47         [ 2]  384 	ldw	x, #0x5347
      009963 7B 03            [ 1]  385 	ld	a, (0x03, sp)
      009965 F7               [ 1]  386 	ld	(x), a
                                    387 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 225: TIM4->EGR = (uint8_t)TIM4_PSCReloadMode;
      009966 AE 53 45         [ 2]  388 	ldw	x, #0x5345
      009969 7B 04            [ 1]  389 	ld	a, (0x04, sp)
      00996B F7               [ 1]  390 	ld	(x), a
                                    391 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 226: }
      00996C 81               [ 4]  392 	ret
                                    393 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 234: void TIM4_ARRPreloadConfig(FunctionalState NewState)
                                    394 ;	-----------------------------------------
                                    395 ;	 function TIM4_ARRPreloadConfig
                                    396 ;	-----------------------------------------
      00996D                        397 _TIM4_ARRPreloadConfig:
                                    398 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 237: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      00996D 0D 03            [ 1]  399 	tnz	(0x03, sp)
      00996F 27 14            [ 1]  400 	jreq	00107$
      009971 7B 03            [ 1]  401 	ld	a, (0x03, sp)
      009973 4A               [ 1]  402 	dec	a
      009974 27 0F            [ 1]  403 	jreq	00107$
      009976 4B ED            [ 1]  404 	push	#0xed
      009978 5F               [ 1]  405 	clrw	x
      009979 89               [ 2]  406 	pushw	x
      00997A 4B 00            [ 1]  407 	push	#0x00
      00997C 4B 9E            [ 1]  408 	push	#<___str_0
      00997E 4B 81            [ 1]  409 	push	#(___str_0 >> 8)
      009980 CD 83 14         [ 4]  410 	call	_assert_failed
      009983 5B 06            [ 2]  411 	addw	sp, #6
      009985                        412 00107$:
                                    413 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 242: TIM4->CR1 |= TIM4_CR1_ARPE;
      009985 C6 53 40         [ 1]  414 	ld	a, 0x5340
                                    415 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 240: if (NewState != DISABLE)
      009988 0D 03            [ 1]  416 	tnz	(0x03, sp)
      00998A 27 06            [ 1]  417 	jreq	00102$
                                    418 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 242: TIM4->CR1 |= TIM4_CR1_ARPE;
      00998C AA 80            [ 1]  419 	or	a, #0x80
      00998E C7 53 40         [ 1]  420 	ld	0x5340, a
      009991 81               [ 4]  421 	ret
      009992                        422 00102$:
                                    423 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 246: TIM4->CR1 &= (uint8_t)(~TIM4_CR1_ARPE);
      009992 A4 7F            [ 1]  424 	and	a, #0x7f
      009994 C7 53 40         [ 1]  425 	ld	0x5340, a
                                    426 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 248: }
      009997 81               [ 4]  427 	ret
                                    428 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 257: void TIM4_GenerateEvent(TIM4_EventSource_TypeDef TIM4_EventSource)
                                    429 ;	-----------------------------------------
                                    430 ;	 function TIM4_GenerateEvent
                                    431 ;	-----------------------------------------
      009998                        432 _TIM4_GenerateEvent:
                                    433 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 260: assert_param(IS_TIM4_EVENT_SOURCE_OK(TIM4_EventSource));
      009998 7B 03            [ 1]  434 	ld	a, (0x03, sp)
      00999A 4A               [ 1]  435 	dec	a
      00999B 27 0F            [ 1]  436 	jreq	00104$
      00999D 4B 04            [ 1]  437 	push	#0x04
      00999F 4B 01            [ 1]  438 	push	#0x01
      0099A1 5F               [ 1]  439 	clrw	x
      0099A2 89               [ 2]  440 	pushw	x
      0099A3 4B 9E            [ 1]  441 	push	#<___str_0
      0099A5 4B 81            [ 1]  442 	push	#(___str_0 >> 8)
      0099A7 CD 83 14         [ 4]  443 	call	_assert_failed
      0099AA 5B 06            [ 2]  444 	addw	sp, #6
      0099AC                        445 00104$:
                                    446 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 263: TIM4->EGR = (uint8_t)(TIM4_EventSource);
      0099AC AE 53 45         [ 2]  447 	ldw	x, #0x5345
      0099AF 7B 03            [ 1]  448 	ld	a, (0x03, sp)
      0099B1 F7               [ 1]  449 	ld	(x), a
                                    450 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 264: }
      0099B2 81               [ 4]  451 	ret
                                    452 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 272: void TIM4_SetCounter(uint8_t Counter)
                                    453 ;	-----------------------------------------
                                    454 ;	 function TIM4_SetCounter
                                    455 ;	-----------------------------------------
      0099B3                        456 _TIM4_SetCounter:
                                    457 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 275: TIM4->CNTR = (uint8_t)(Counter);
      0099B3 AE 53 46         [ 2]  458 	ldw	x, #0x5346
      0099B6 7B 03            [ 1]  459 	ld	a, (0x03, sp)
      0099B8 F7               [ 1]  460 	ld	(x), a
                                    461 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 276: }
      0099B9 81               [ 4]  462 	ret
                                    463 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 284: void TIM4_SetAutoreload(uint8_t Autoreload)
                                    464 ;	-----------------------------------------
                                    465 ;	 function TIM4_SetAutoreload
                                    466 ;	-----------------------------------------
      0099BA                        467 _TIM4_SetAutoreload:
                                    468 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 287: TIM4->ARR = (uint8_t)(Autoreload);
      0099BA AE 53 48         [ 2]  469 	ldw	x, #0x5348
      0099BD 7B 03            [ 1]  470 	ld	a, (0x03, sp)
      0099BF F7               [ 1]  471 	ld	(x), a
                                    472 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 288: }
      0099C0 81               [ 4]  473 	ret
                                    474 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 295: uint8_t TIM4_GetCounter(void)
                                    475 ;	-----------------------------------------
                                    476 ;	 function TIM4_GetCounter
                                    477 ;	-----------------------------------------
      0099C1                        478 _TIM4_GetCounter:
                                    479 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 298: return (uint8_t)(TIM4->CNTR);
      0099C1 C6 53 46         [ 1]  480 	ld	a, 0x5346
                                    481 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 299: }
      0099C4 81               [ 4]  482 	ret
                                    483 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 306: TIM4_Prescaler_TypeDef TIM4_GetPrescaler(void)
                                    484 ;	-----------------------------------------
                                    485 ;	 function TIM4_GetPrescaler
                                    486 ;	-----------------------------------------
      0099C5                        487 _TIM4_GetPrescaler:
                                    488 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 309: return (TIM4_Prescaler_TypeDef)(TIM4->PSCR);
      0099C5 C6 53 47         [ 1]  489 	ld	a, 0x5347
                                    490 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 310: }
      0099C8 81               [ 4]  491 	ret
                                    492 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 319: FlagStatus TIM4_GetFlagStatus(TIM4_FLAG_TypeDef TIM4_FLAG)
                                    493 ;	-----------------------------------------
                                    494 ;	 function TIM4_GetFlagStatus
                                    495 ;	-----------------------------------------
      0099C9                        496 _TIM4_GetFlagStatus:
                                    497 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 324: assert_param(IS_TIM4_GET_FLAG_OK(TIM4_FLAG));
      0099C9 7B 03            [ 1]  498 	ld	a, (0x03, sp)
      0099CB 4A               [ 1]  499 	dec	a
      0099CC 27 0F            [ 1]  500 	jreq	00107$
      0099CE 4B 44            [ 1]  501 	push	#0x44
      0099D0 4B 01            [ 1]  502 	push	#0x01
      0099D2 5F               [ 1]  503 	clrw	x
      0099D3 89               [ 2]  504 	pushw	x
      0099D4 4B 9E            [ 1]  505 	push	#<___str_0
      0099D6 4B 81            [ 1]  506 	push	#(___str_0 >> 8)
      0099D8 CD 83 14         [ 4]  507 	call	_assert_failed
      0099DB 5B 06            [ 2]  508 	addw	sp, #6
      0099DD                        509 00107$:
                                    510 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 326: if ((TIM4->SR1 & (uint8_t)TIM4_FLAG)  != 0)
      0099DD C6 53 44         [ 1]  511 	ld	a, 0x5344
      0099E0 14 03            [ 1]  512 	and	a, (0x03, sp)
      0099E2 27 03            [ 1]  513 	jreq	00102$
                                    514 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 328: bitstatus = SET;
      0099E4 A6 01            [ 1]  515 	ld	a, #0x01
      0099E6 81               [ 4]  516 	ret
      0099E7                        517 00102$:
                                    518 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 332: bitstatus = RESET;
      0099E7 4F               [ 1]  519 	clr	a
                                    520 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 334: return ((FlagStatus)bitstatus);
                                    521 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 335: }
      0099E8 81               [ 4]  522 	ret
                                    523 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 344: void TIM4_ClearFlag(TIM4_FLAG_TypeDef TIM4_FLAG)
                                    524 ;	-----------------------------------------
                                    525 ;	 function TIM4_ClearFlag
                                    526 ;	-----------------------------------------
      0099E9                        527 _TIM4_ClearFlag:
                                    528 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 347: assert_param(IS_TIM4_GET_FLAG_OK(TIM4_FLAG));
      0099E9 7B 03            [ 1]  529 	ld	a, (0x03, sp)
      0099EB 4A               [ 1]  530 	dec	a
      0099EC 27 0F            [ 1]  531 	jreq	00104$
      0099EE 4B 5B            [ 1]  532 	push	#0x5b
      0099F0 4B 01            [ 1]  533 	push	#0x01
      0099F2 5F               [ 1]  534 	clrw	x
      0099F3 89               [ 2]  535 	pushw	x
      0099F4 4B 9E            [ 1]  536 	push	#<___str_0
      0099F6 4B 81            [ 1]  537 	push	#(___str_0 >> 8)
      0099F8 CD 83 14         [ 4]  538 	call	_assert_failed
      0099FB 5B 06            [ 2]  539 	addw	sp, #6
      0099FD                        540 00104$:
                                    541 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 350: TIM4->SR1 = (uint8_t)(~TIM4_FLAG);
      0099FD 7B 03            [ 1]  542 	ld	a, (0x03, sp)
      0099FF 43               [ 1]  543 	cpl	a
      009A00 C7 53 44         [ 1]  544 	ld	0x5344, a
                                    545 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 351: }
      009A03 81               [ 4]  546 	ret
                                    547 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 360: ITStatus TIM4_GetITStatus(TIM4_IT_TypeDef TIM4_IT)
                                    548 ;	-----------------------------------------
                                    549 ;	 function TIM4_GetITStatus
                                    550 ;	-----------------------------------------
      009A04                        551 _TIM4_GetITStatus:
      009A04 88               [ 1]  552 	push	a
                                    553 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 367: assert_param(IS_TIM4_IT_OK(TIM4_IT));
      009A05 7B 04            [ 1]  554 	ld	a, (0x04, sp)
      009A07 4A               [ 1]  555 	dec	a
      009A08 27 0F            [ 1]  556 	jreq	00108$
      009A0A 4B 6F            [ 1]  557 	push	#0x6f
      009A0C 4B 01            [ 1]  558 	push	#0x01
      009A0E 5F               [ 1]  559 	clrw	x
      009A0F 89               [ 2]  560 	pushw	x
      009A10 4B 9E            [ 1]  561 	push	#<___str_0
      009A12 4B 81            [ 1]  562 	push	#(___str_0 >> 8)
      009A14 CD 83 14         [ 4]  563 	call	_assert_failed
      009A17 5B 06            [ 2]  564 	addw	sp, #6
      009A19                        565 00108$:
                                    566 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 369: itstatus = (uint8_t)(TIM4->SR1 & (uint8_t)TIM4_IT);
      009A19 C6 53 44         [ 1]  567 	ld	a, 0x5344
      009A1C 14 04            [ 1]  568 	and	a, (0x04, sp)
      009A1E 6B 01            [ 1]  569 	ld	(0x01, sp), a
                                    570 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 371: itenable = (uint8_t)(TIM4->IER & (uint8_t)TIM4_IT);
      009A20 C6 53 43         [ 1]  571 	ld	a, 0x5343
      009A23 14 04            [ 1]  572 	and	a, (0x04, sp)
                                    573 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 373: if ((itstatus != (uint8_t)RESET ) && (itenable != (uint8_t)RESET ))
      009A25 0D 01            [ 1]  574 	tnz	(0x01, sp)
      009A27 27 06            [ 1]  575 	jreq	00102$
      009A29 4D               [ 1]  576 	tnz	a
      009A2A 27 03            [ 1]  577 	jreq	00102$
                                    578 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 375: bitstatus = (ITStatus)SET;
      009A2C A6 01            [ 1]  579 	ld	a, #0x01
                                    580 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 379: bitstatus = (ITStatus)RESET;
      009A2E 21                     581 	.byte 0x21
      009A2F                        582 00102$:
      009A2F 4F               [ 1]  583 	clr	a
      009A30                        584 00103$:
                                    585 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 381: return ((ITStatus)bitstatus);
                                    586 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 382: }
      009A30 5B 01            [ 2]  587 	addw	sp, #1
      009A32 81               [ 4]  588 	ret
                                    589 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 391: void TIM4_ClearITPendingBit(TIM4_IT_TypeDef TIM4_IT)
                                    590 ;	-----------------------------------------
                                    591 ;	 function TIM4_ClearITPendingBit
                                    592 ;	-----------------------------------------
      009A33                        593 _TIM4_ClearITPendingBit:
                                    594 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 394: assert_param(IS_TIM4_IT_OK(TIM4_IT));
      009A33 7B 03            [ 1]  595 	ld	a, (0x03, sp)
      009A35 4A               [ 1]  596 	dec	a
      009A36 27 0F            [ 1]  597 	jreq	00104$
      009A38 4B 8A            [ 1]  598 	push	#0x8a
      009A3A 4B 01            [ 1]  599 	push	#0x01
      009A3C 5F               [ 1]  600 	clrw	x
      009A3D 89               [ 2]  601 	pushw	x
      009A3E 4B 9E            [ 1]  602 	push	#<___str_0
      009A40 4B 81            [ 1]  603 	push	#(___str_0 >> 8)
      009A42 CD 83 14         [ 4]  604 	call	_assert_failed
      009A45 5B 06            [ 2]  605 	addw	sp, #6
      009A47                        606 00104$:
                                    607 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 397: TIM4->SR1 = (uint8_t)(~TIM4_IT);
      009A47 7B 03            [ 1]  608 	ld	a, (0x03, sp)
      009A49 43               [ 1]  609 	cpl	a
      009A4A C7 53 44         [ 1]  610 	ld	0x5344, a
                                    611 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c: 398: }
      009A4D 81               [ 4]  612 	ret
                                    613 	.area CODE
                                    614 	.area CONST
      00819E                        615 ___str_0:
      00819E 2E 2E 2F 2E 2E 2F 2E   616 	.ascii "../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_tim4.c"
             2E 2F 4C 69 62 72 61
             72 69 65 73 2F 53 54
             4D 38 53 5F 53 74 64
             50 65 72 69 70 68 5F
             44 72 69 76 65 72 2F
             73 72 63 2F 73 74 6D
             38 73 5F 74 69 6D 34
             2E 63
      0081D8 00                     617 	.db 0x00
                                    618 	.area INITIALIZER
                                    619 	.area CABS (ABS)
