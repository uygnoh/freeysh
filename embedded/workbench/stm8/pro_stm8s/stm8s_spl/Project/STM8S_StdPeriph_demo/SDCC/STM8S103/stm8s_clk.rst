                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.8.0 #10562 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_clk
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _CLKPrescTable
                                     12 	.globl _HSIDivFactor
                                     13 	.globl _assert_failed
                                     14 	.globl _CLK_DeInit
                                     15 	.globl _CLK_FastHaltWakeUpCmd
                                     16 	.globl _CLK_HSECmd
                                     17 	.globl _CLK_HSICmd
                                     18 	.globl _CLK_LSICmd
                                     19 	.globl _CLK_CCOCmd
                                     20 	.globl _CLK_ClockSwitchCmd
                                     21 	.globl _CLK_SlowActiveHaltWakeUpCmd
                                     22 	.globl _CLK_PeripheralClockConfig
                                     23 	.globl _CLK_ClockSwitchConfig
                                     24 	.globl _CLK_HSIPrescalerConfig
                                     25 	.globl _CLK_CCOConfig
                                     26 	.globl _CLK_ITConfig
                                     27 	.globl _CLK_SYSCLKConfig
                                     28 	.globl _CLK_SWIMConfig
                                     29 	.globl _CLK_ClockSecuritySystemEnable
                                     30 	.globl _CLK_GetSYSCLKSource
                                     31 	.globl _CLK_GetClockFreq
                                     32 	.globl _CLK_AdjustHSICalibrationValue
                                     33 	.globl _CLK_SYSCLKEmergencyClear
                                     34 	.globl _CLK_GetFlagStatus
                                     35 	.globl _CLK_GetITStatus
                                     36 	.globl _CLK_ClearITPendingBit
                                     37 ;--------------------------------------------------------
                                     38 ; ram data
                                     39 ;--------------------------------------------------------
                                     40 	.area DATA
                                     41 ;--------------------------------------------------------
                                     42 ; ram data
                                     43 ;--------------------------------------------------------
                                     44 	.area INITIALIZED
                                     45 ;--------------------------------------------------------
                                     46 ; absolute external ram data
                                     47 ;--------------------------------------------------------
                                     48 	.area DABS (ABS)
                                     49 
                                     50 ; default segment ordering for linker
                                     51 	.area HOME
                                     52 	.area GSINIT
                                     53 	.area GSFINAL
                                     54 	.area CONST
                                     55 	.area INITIALIZER
                                     56 	.area CODE
                                     57 
                                     58 ;--------------------------------------------------------
                                     59 ; global & static initialisations
                                     60 ;--------------------------------------------------------
                                     61 	.area HOME
                                     62 	.area GSINIT
                                     63 	.area GSFINAL
                                     64 	.area GSINIT
                                     65 ;--------------------------------------------------------
                                     66 ; Home
                                     67 ;--------------------------------------------------------
                                     68 	.area HOME
                                     69 	.area HOME
                                     70 ;--------------------------------------------------------
                                     71 ; code
                                     72 ;--------------------------------------------------------
                                     73 	.area CODE
                                     74 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 72: void CLK_DeInit(void)
                                     75 ;	-----------------------------------------
                                     76 ;	 function CLK_DeInit
                                     77 ;	-----------------------------------------
      00847C                         78 _CLK_DeInit:
                                     79 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 74: CLK->ICKR = CLK_ICKR_RESET_VALUE;
      00847C 35 01 50 C0      [ 1]   80 	mov	0x50c0+0, #0x01
                                     81 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 75: CLK->ECKR = CLK_ECKR_RESET_VALUE;
      008480 35 00 50 C1      [ 1]   82 	mov	0x50c1+0, #0x00
                                     83 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 76: CLK->SWR  = CLK_SWR_RESET_VALUE;
      008484 35 E1 50 C4      [ 1]   84 	mov	0x50c4+0, #0xe1
                                     85 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 77: CLK->SWCR = CLK_SWCR_RESET_VALUE;
      008488 35 00 50 C5      [ 1]   86 	mov	0x50c5+0, #0x00
                                     87 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 78: CLK->CKDIVR = CLK_CKDIVR_RESET_VALUE;
      00848C 35 18 50 C6      [ 1]   88 	mov	0x50c6+0, #0x18
                                     89 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 79: CLK->PCKENR1 = CLK_PCKENR1_RESET_VALUE;
      008490 35 FF 50 C7      [ 1]   90 	mov	0x50c7+0, #0xff
                                     91 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 80: CLK->PCKENR2 = CLK_PCKENR2_RESET_VALUE;
      008494 35 FF 50 CA      [ 1]   92 	mov	0x50ca+0, #0xff
                                     93 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 81: CLK->CSSR = CLK_CSSR_RESET_VALUE;
      008498 35 00 50 C8      [ 1]   94 	mov	0x50c8+0, #0x00
                                     95 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 82: CLK->CCOR = CLK_CCOR_RESET_VALUE;
      00849C 35 00 50 C9      [ 1]   96 	mov	0x50c9+0, #0x00
                                     97 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 83: while ((CLK->CCOR & CLK_CCOR_CCOEN)!= 0)
      0084A0                         98 00101$:
      0084A0 C6 50 C9         [ 1]   99 	ld	a, 0x50c9
      0084A3 44               [ 1]  100 	srl	a
      0084A4 25 FA            [ 1]  101 	jrc	00101$
                                    102 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 85: CLK->CCOR = CLK_CCOR_RESET_VALUE;
      0084A6 35 00 50 C9      [ 1]  103 	mov	0x50c9+0, #0x00
                                    104 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 86: CLK->HSITRIMR = CLK_HSITRIMR_RESET_VALUE;
      0084AA 35 00 50 CC      [ 1]  105 	mov	0x50cc+0, #0x00
                                    106 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 87: CLK->SWIMCCR = CLK_SWIMCCR_RESET_VALUE;
      0084AE 35 00 50 CD      [ 1]  107 	mov	0x50cd+0, #0x00
                                    108 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 88: }
      0084B2 81               [ 4]  109 	ret
                                    110 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 99: void CLK_FastHaltWakeUpCmd(FunctionalState NewState)
                                    111 ;	-----------------------------------------
                                    112 ;	 function CLK_FastHaltWakeUpCmd
                                    113 ;	-----------------------------------------
      0084B3                        114 _CLK_FastHaltWakeUpCmd:
                                    115 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 102: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      0084B3 0D 03            [ 1]  116 	tnz	(0x03, sp)
      0084B5 27 14            [ 1]  117 	jreq	00107$
      0084B7 7B 03            [ 1]  118 	ld	a, (0x03, sp)
      0084B9 4A               [ 1]  119 	dec	a
      0084BA 27 0F            [ 1]  120 	jreq	00107$
      0084BC 4B 66            [ 1]  121 	push	#0x66
      0084BE 5F               [ 1]  122 	clrw	x
      0084BF 89               [ 2]  123 	pushw	x
      0084C0 4B 00            [ 1]  124 	push	#0x00
      0084C2 4B EC            [ 1]  125 	push	#<___str_0
      0084C4 4B 80            [ 1]  126 	push	#(___str_0 >> 8)
      0084C6 CD 83 14         [ 4]  127 	call	_assert_failed
      0084C9 5B 06            [ 2]  128 	addw	sp, #6
      0084CB                        129 00107$:
                                    130 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
      0084CB C6 50 C0         [ 1]  131 	ld	a, 0x50c0
                                    132 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 104: if (NewState != DISABLE)
      0084CE 0D 03            [ 1]  133 	tnz	(0x03, sp)
      0084D0 27 06            [ 1]  134 	jreq	00102$
                                    135 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
      0084D2 AA 04            [ 1]  136 	or	a, #0x04
      0084D4 C7 50 C0         [ 1]  137 	ld	0x50c0, a
      0084D7 81               [ 4]  138 	ret
      0084D8                        139 00102$:
                                    140 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 112: CLK->ICKR &= (uint8_t)(~CLK_ICKR_FHWU);
      0084D8 A4 FB            [ 1]  141 	and	a, #0xfb
      0084DA C7 50 C0         [ 1]  142 	ld	0x50c0, a
                                    143 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 114: }
      0084DD 81               [ 4]  144 	ret
                                    145 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 121: void CLK_HSECmd(FunctionalState NewState)
                                    146 ;	-----------------------------------------
                                    147 ;	 function CLK_HSECmd
                                    148 ;	-----------------------------------------
      0084DE                        149 _CLK_HSECmd:
                                    150 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 124: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      0084DE 0D 03            [ 1]  151 	tnz	(0x03, sp)
      0084E0 27 14            [ 1]  152 	jreq	00107$
      0084E2 7B 03            [ 1]  153 	ld	a, (0x03, sp)
      0084E4 4A               [ 1]  154 	dec	a
      0084E5 27 0F            [ 1]  155 	jreq	00107$
      0084E7 4B 7C            [ 1]  156 	push	#0x7c
      0084E9 5F               [ 1]  157 	clrw	x
      0084EA 89               [ 2]  158 	pushw	x
      0084EB 4B 00            [ 1]  159 	push	#0x00
      0084ED 4B EC            [ 1]  160 	push	#<___str_0
      0084EF 4B 80            [ 1]  161 	push	#(___str_0 >> 8)
      0084F1 CD 83 14         [ 4]  162 	call	_assert_failed
      0084F4 5B 06            [ 2]  163 	addw	sp, #6
      0084F6                        164 00107$:
                                    165 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
      0084F6 C6 50 C1         [ 1]  166 	ld	a, 0x50c1
                                    167 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 126: if (NewState != DISABLE)
      0084F9 0D 03            [ 1]  168 	tnz	(0x03, sp)
      0084FB 27 06            [ 1]  169 	jreq	00102$
                                    170 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
      0084FD AA 01            [ 1]  171 	or	a, #0x01
      0084FF C7 50 C1         [ 1]  172 	ld	0x50c1, a
      008502 81               [ 4]  173 	ret
      008503                        174 00102$:
                                    175 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 134: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
      008503 A4 FE            [ 1]  176 	and	a, #0xfe
      008505 C7 50 C1         [ 1]  177 	ld	0x50c1, a
                                    178 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 136: }
      008508 81               [ 4]  179 	ret
                                    180 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 143: void CLK_HSICmd(FunctionalState NewState)
                                    181 ;	-----------------------------------------
                                    182 ;	 function CLK_HSICmd
                                    183 ;	-----------------------------------------
      008509                        184 _CLK_HSICmd:
                                    185 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 146: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008509 0D 03            [ 1]  186 	tnz	(0x03, sp)
      00850B 27 14            [ 1]  187 	jreq	00107$
      00850D 7B 03            [ 1]  188 	ld	a, (0x03, sp)
      00850F 4A               [ 1]  189 	dec	a
      008510 27 0F            [ 1]  190 	jreq	00107$
      008512 4B 92            [ 1]  191 	push	#0x92
      008514 5F               [ 1]  192 	clrw	x
      008515 89               [ 2]  193 	pushw	x
      008516 4B 00            [ 1]  194 	push	#0x00
      008518 4B EC            [ 1]  195 	push	#<___str_0
      00851A 4B 80            [ 1]  196 	push	#(___str_0 >> 8)
      00851C CD 83 14         [ 4]  197 	call	_assert_failed
      00851F 5B 06            [ 2]  198 	addw	sp, #6
      008521                        199 00107$:
                                    200 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
      008521 C6 50 C0         [ 1]  201 	ld	a, 0x50c0
                                    202 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 148: if (NewState != DISABLE)
      008524 0D 03            [ 1]  203 	tnz	(0x03, sp)
      008526 27 06            [ 1]  204 	jreq	00102$
                                    205 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
      008528 AA 01            [ 1]  206 	or	a, #0x01
      00852A C7 50 C0         [ 1]  207 	ld	0x50c0, a
      00852D 81               [ 4]  208 	ret
      00852E                        209 00102$:
                                    210 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 156: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
      00852E A4 FE            [ 1]  211 	and	a, #0xfe
      008530 C7 50 C0         [ 1]  212 	ld	0x50c0, a
                                    213 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 158: }
      008533 81               [ 4]  214 	ret
                                    215 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 166: void CLK_LSICmd(FunctionalState NewState)
                                    216 ;	-----------------------------------------
                                    217 ;	 function CLK_LSICmd
                                    218 ;	-----------------------------------------
      008534                        219 _CLK_LSICmd:
                                    220 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 169: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008534 0D 03            [ 1]  221 	tnz	(0x03, sp)
      008536 27 14            [ 1]  222 	jreq	00107$
      008538 7B 03            [ 1]  223 	ld	a, (0x03, sp)
      00853A 4A               [ 1]  224 	dec	a
      00853B 27 0F            [ 1]  225 	jreq	00107$
      00853D 4B A9            [ 1]  226 	push	#0xa9
      00853F 5F               [ 1]  227 	clrw	x
      008540 89               [ 2]  228 	pushw	x
      008541 4B 00            [ 1]  229 	push	#0x00
      008543 4B EC            [ 1]  230 	push	#<___str_0
      008545 4B 80            [ 1]  231 	push	#(___str_0 >> 8)
      008547 CD 83 14         [ 4]  232 	call	_assert_failed
      00854A 5B 06            [ 2]  233 	addw	sp, #6
      00854C                        234 00107$:
                                    235 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
      00854C C6 50 C0         [ 1]  236 	ld	a, 0x50c0
                                    237 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 171: if (NewState != DISABLE)
      00854F 0D 03            [ 1]  238 	tnz	(0x03, sp)
      008551 27 06            [ 1]  239 	jreq	00102$
                                    240 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
      008553 AA 08            [ 1]  241 	or	a, #0x08
      008555 C7 50 C0         [ 1]  242 	ld	0x50c0, a
      008558 81               [ 4]  243 	ret
      008559                        244 00102$:
                                    245 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 179: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
      008559 A4 F7            [ 1]  246 	and	a, #0xf7
      00855B C7 50 C0         [ 1]  247 	ld	0x50c0, a
                                    248 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 181: }
      00855E 81               [ 4]  249 	ret
                                    250 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 189: void CLK_CCOCmd(FunctionalState NewState)
                                    251 ;	-----------------------------------------
                                    252 ;	 function CLK_CCOCmd
                                    253 ;	-----------------------------------------
      00855F                        254 _CLK_CCOCmd:
                                    255 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 192: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      00855F 0D 03            [ 1]  256 	tnz	(0x03, sp)
      008561 27 14            [ 1]  257 	jreq	00107$
      008563 7B 03            [ 1]  258 	ld	a, (0x03, sp)
      008565 4A               [ 1]  259 	dec	a
      008566 27 0F            [ 1]  260 	jreq	00107$
      008568 4B C0            [ 1]  261 	push	#0xc0
      00856A 5F               [ 1]  262 	clrw	x
      00856B 89               [ 2]  263 	pushw	x
      00856C 4B 00            [ 1]  264 	push	#0x00
      00856E 4B EC            [ 1]  265 	push	#<___str_0
      008570 4B 80            [ 1]  266 	push	#(___str_0 >> 8)
      008572 CD 83 14         [ 4]  267 	call	_assert_failed
      008575 5B 06            [ 2]  268 	addw	sp, #6
      008577                        269 00107$:
                                    270 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
      008577 C6 50 C9         [ 1]  271 	ld	a, 0x50c9
                                    272 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 194: if (NewState != DISABLE)
      00857A 0D 03            [ 1]  273 	tnz	(0x03, sp)
      00857C 27 06            [ 1]  274 	jreq	00102$
                                    275 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
      00857E AA 01            [ 1]  276 	or	a, #0x01
      008580 C7 50 C9         [ 1]  277 	ld	0x50c9, a
      008583 81               [ 4]  278 	ret
      008584                        279 00102$:
                                    280 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 202: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOEN);
      008584 A4 FE            [ 1]  281 	and	a, #0xfe
      008586 C7 50 C9         [ 1]  282 	ld	0x50c9, a
                                    283 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 204: }
      008589 81               [ 4]  284 	ret
                                    285 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 213: void CLK_ClockSwitchCmd(FunctionalState NewState)
                                    286 ;	-----------------------------------------
                                    287 ;	 function CLK_ClockSwitchCmd
                                    288 ;	-----------------------------------------
      00858A                        289 _CLK_ClockSwitchCmd:
                                    290 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 216: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      00858A 0D 03            [ 1]  291 	tnz	(0x03, sp)
      00858C 27 14            [ 1]  292 	jreq	00107$
      00858E 7B 03            [ 1]  293 	ld	a, (0x03, sp)
      008590 4A               [ 1]  294 	dec	a
      008591 27 0F            [ 1]  295 	jreq	00107$
      008593 4B D8            [ 1]  296 	push	#0xd8
      008595 5F               [ 1]  297 	clrw	x
      008596 89               [ 2]  298 	pushw	x
      008597 4B 00            [ 1]  299 	push	#0x00
      008599 4B EC            [ 1]  300 	push	#<___str_0
      00859B 4B 80            [ 1]  301 	push	#(___str_0 >> 8)
      00859D CD 83 14         [ 4]  302 	call	_assert_failed
      0085A0 5B 06            [ 2]  303 	addw	sp, #6
      0085A2                        304 00107$:
                                    305 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
      0085A2 C6 50 C5         [ 1]  306 	ld	a, 0x50c5
                                    307 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 218: if (NewState != DISABLE )
      0085A5 0D 03            [ 1]  308 	tnz	(0x03, sp)
      0085A7 27 06            [ 1]  309 	jreq	00102$
                                    310 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
      0085A9 AA 02            [ 1]  311 	or	a, #0x02
      0085AB C7 50 C5         [ 1]  312 	ld	0x50c5, a
      0085AE 81               [ 4]  313 	ret
      0085AF                        314 00102$:
                                    315 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 226: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWEN);
      0085AF A4 FD            [ 1]  316 	and	a, #0xfd
      0085B1 C7 50 C5         [ 1]  317 	ld	0x50c5, a
                                    318 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 228: }
      0085B4 81               [ 4]  319 	ret
                                    320 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 238: void CLK_SlowActiveHaltWakeUpCmd(FunctionalState NewState)
                                    321 ;	-----------------------------------------
                                    322 ;	 function CLK_SlowActiveHaltWakeUpCmd
                                    323 ;	-----------------------------------------
      0085B5                        324 _CLK_SlowActiveHaltWakeUpCmd:
                                    325 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 241: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      0085B5 0D 03            [ 1]  326 	tnz	(0x03, sp)
      0085B7 27 14            [ 1]  327 	jreq	00107$
      0085B9 7B 03            [ 1]  328 	ld	a, (0x03, sp)
      0085BB 4A               [ 1]  329 	dec	a
      0085BC 27 0F            [ 1]  330 	jreq	00107$
      0085BE 4B F1            [ 1]  331 	push	#0xf1
      0085C0 5F               [ 1]  332 	clrw	x
      0085C1 89               [ 2]  333 	pushw	x
      0085C2 4B 00            [ 1]  334 	push	#0x00
      0085C4 4B EC            [ 1]  335 	push	#<___str_0
      0085C6 4B 80            [ 1]  336 	push	#(___str_0 >> 8)
      0085C8 CD 83 14         [ 4]  337 	call	_assert_failed
      0085CB 5B 06            [ 2]  338 	addw	sp, #6
      0085CD                        339 00107$:
                                    340 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
      0085CD C6 50 C0         [ 1]  341 	ld	a, 0x50c0
                                    342 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 243: if (NewState != DISABLE)
      0085D0 0D 03            [ 1]  343 	tnz	(0x03, sp)
      0085D2 27 06            [ 1]  344 	jreq	00102$
                                    345 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
      0085D4 AA 20            [ 1]  346 	or	a, #0x20
      0085D6 C7 50 C0         [ 1]  347 	ld	0x50c0, a
      0085D9 81               [ 4]  348 	ret
      0085DA                        349 00102$:
                                    350 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 251: CLK->ICKR &= (uint8_t)(~CLK_ICKR_SWUAH);
      0085DA A4 DF            [ 1]  351 	and	a, #0xdf
      0085DC C7 50 C0         [ 1]  352 	ld	0x50c0, a
                                    353 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 253: }
      0085DF 81               [ 4]  354 	ret
                                    355 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 263: void CLK_PeripheralClockConfig(CLK_Peripheral_TypeDef CLK_Peripheral, FunctionalState NewState)
                                    356 ;	-----------------------------------------
                                    357 ;	 function CLK_PeripheralClockConfig
                                    358 ;	-----------------------------------------
      0085E0                        359 _CLK_PeripheralClockConfig:
      0085E0 89               [ 2]  360 	pushw	x
                                    361 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 266: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      0085E1 0D 06            [ 1]  362 	tnz	(0x06, sp)
      0085E3 27 14            [ 1]  363 	jreq	00113$
      0085E5 7B 06            [ 1]  364 	ld	a, (0x06, sp)
      0085E7 4A               [ 1]  365 	dec	a
      0085E8 27 0F            [ 1]  366 	jreq	00113$
      0085EA 4B 0A            [ 1]  367 	push	#0x0a
      0085EC 4B 01            [ 1]  368 	push	#0x01
      0085EE 5F               [ 1]  369 	clrw	x
      0085EF 89               [ 2]  370 	pushw	x
      0085F0 4B EC            [ 1]  371 	push	#<___str_0
      0085F2 4B 80            [ 1]  372 	push	#(___str_0 >> 8)
      0085F4 CD 83 14         [ 4]  373 	call	_assert_failed
      0085F7 5B 06            [ 2]  374 	addw	sp, #6
      0085F9                        375 00113$:
                                    376 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 267: assert_param(IS_CLK_PERIPHERAL_OK(CLK_Peripheral));
      0085F9 0D 05            [ 1]  377 	tnz	(0x05, sp)
      0085FB 27 67            [ 1]  378 	jreq	00118$
      0085FD 7B 05            [ 1]  379 	ld	a, (0x05, sp)
      0085FF 4A               [ 1]  380 	dec	a
      008600 27 62            [ 1]  381 	jreq	00118$
      008602 7B 05            [ 1]  382 	ld	a, (0x05, sp)
      008604 A0 03            [ 1]  383 	sub	a, #0x03
      008606 26 02            [ 1]  384 	jrne	00262$
      008608 4C               [ 1]  385 	inc	a
      008609 21                     386 	.byte 0x21
      00860A                        387 00262$:
      00860A 4F               [ 1]  388 	clr	a
      00860B                        389 00263$:
      00860B 4D               [ 1]  390 	tnz	a
      00860C 26 56            [ 1]  391 	jrne	00118$
      00860E 4D               [ 1]  392 	tnz	a
      00860F 26 53            [ 1]  393 	jrne	00118$
      008611 4D               [ 1]  394 	tnz	a
      008612 26 50            [ 1]  395 	jrne	00118$
      008614 7B 05            [ 1]  396 	ld	a, (0x05, sp)
      008616 A0 04            [ 1]  397 	sub	a, #0x04
      008618 26 04            [ 1]  398 	jrne	00268$
      00861A 4C               [ 1]  399 	inc	a
      00861B 97               [ 1]  400 	ld	xl, a
      00861C 20 02            [ 2]  401 	jra	00269$
      00861E                        402 00268$:
      00861E 4F               [ 1]  403 	clr	a
      00861F 97               [ 1]  404 	ld	xl, a
      008620                        405 00269$:
      008620 9F               [ 1]  406 	ld	a, xl
      008621 4D               [ 1]  407 	tnz	a
      008622 26 40            [ 1]  408 	jrne	00118$
      008624 7B 05            [ 1]  409 	ld	a, (0x05, sp)
      008626 A0 05            [ 1]  410 	sub	a, #0x05
      008628 26 02            [ 1]  411 	jrne	00272$
      00862A 4C               [ 1]  412 	inc	a
      00862B 21                     413 	.byte 0x21
      00862C                        414 00272$:
      00862C 4F               [ 1]  415 	clr	a
      00862D                        416 00273$:
      00862D 4D               [ 1]  417 	tnz	a
      00862E 26 34            [ 1]  418 	jrne	00118$
      008630 4D               [ 1]  419 	tnz	a
      008631 26 31            [ 1]  420 	jrne	00118$
      008633 9F               [ 1]  421 	ld	a, xl
      008634 4D               [ 1]  422 	tnz	a
      008635 26 2D            [ 1]  423 	jrne	00118$
      008637 7B 05            [ 1]  424 	ld	a, (0x05, sp)
      008639 A1 06            [ 1]  425 	cp	a, #0x06
      00863B 27 27            [ 1]  426 	jreq	00118$
      00863D 7B 05            [ 1]  427 	ld	a, (0x05, sp)
      00863F A1 07            [ 1]  428 	cp	a, #0x07
      008641 27 21            [ 1]  429 	jreq	00118$
      008643 7B 05            [ 1]  430 	ld	a, (0x05, sp)
      008645 A1 17            [ 1]  431 	cp	a, #0x17
      008647 27 1B            [ 1]  432 	jreq	00118$
      008649 7B 05            [ 1]  433 	ld	a, (0x05, sp)
      00864B A1 13            [ 1]  434 	cp	a, #0x13
      00864D 27 15            [ 1]  435 	jreq	00118$
      00864F 7B 05            [ 1]  436 	ld	a, (0x05, sp)
      008651 A1 12            [ 1]  437 	cp	a, #0x12
      008653 27 0F            [ 1]  438 	jreq	00118$
      008655 4B 0B            [ 1]  439 	push	#0x0b
      008657 4B 01            [ 1]  440 	push	#0x01
      008659 5F               [ 1]  441 	clrw	x
      00865A 89               [ 2]  442 	pushw	x
      00865B 4B EC            [ 1]  443 	push	#<___str_0
      00865D 4B 80            [ 1]  444 	push	#(___str_0 >> 8)
      00865F CD 83 14         [ 4]  445 	call	_assert_failed
      008662 5B 06            [ 2]  446 	addw	sp, #6
      008664                        447 00118$:
                                    448 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008664 7B 05            [ 1]  449 	ld	a, (0x05, sp)
      008666 A4 0F            [ 1]  450 	and	a, #0x0f
      008668 88               [ 1]  451 	push	a
      008669 A6 01            [ 1]  452 	ld	a, #0x01
      00866B 6B 03            [ 1]  453 	ld	(0x03, sp), a
      00866D 84               [ 1]  454 	pop	a
      00866E 4D               [ 1]  455 	tnz	a
      00866F 27 05            [ 1]  456 	jreq	00293$
      008671                        457 00292$:
      008671 08 02            [ 1]  458 	sll	(0x02, sp)
      008673 4A               [ 1]  459 	dec	a
      008674 26 FB            [ 1]  460 	jrne	00292$
      008676                        461 00293$:
                                    462 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008676 7B 02            [ 1]  463 	ld	a, (0x02, sp)
      008678 43               [ 1]  464 	cpl	a
      008679 6B 01            [ 1]  465 	ld	(0x01, sp), a
                                    466 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 269: if (((uint8_t)CLK_Peripheral & (uint8_t)0x10) == 0x00)
      00867B 7B 05            [ 1]  467 	ld	a, (0x05, sp)
      00867D A5 10            [ 1]  468 	bcp	a, #0x10
      00867F 26 15            [ 1]  469 	jrne	00108$
                                    470 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008681 C6 50 C7         [ 1]  471 	ld	a, 0x50c7
                                    472 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 271: if (NewState != DISABLE)
      008684 0D 06            [ 1]  473 	tnz	(0x06, sp)
      008686 27 07            [ 1]  474 	jreq	00102$
                                    475 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008688 1A 02            [ 1]  476 	or	a, (0x02, sp)
      00868A C7 50 C7         [ 1]  477 	ld	0x50c7, a
      00868D 20 1A            [ 2]  478 	jra	00110$
      00868F                        479 00102$:
                                    480 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      00868F 14 01            [ 1]  481 	and	a, (0x01, sp)
      008691 C7 50 C7         [ 1]  482 	ld	0x50c7, a
      008694 20 13            [ 2]  483 	jra	00110$
      008696                        484 00108$:
                                    485 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008696 C6 50 CA         [ 1]  486 	ld	a, 0x50ca
                                    487 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 284: if (NewState != DISABLE)
      008699 0D 06            [ 1]  488 	tnz	(0x06, sp)
      00869B 27 07            [ 1]  489 	jreq	00105$
                                    490 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      00869D 1A 02            [ 1]  491 	or	a, (0x02, sp)
      00869F C7 50 CA         [ 1]  492 	ld	0x50ca, a
      0086A2 20 05            [ 2]  493 	jra	00110$
      0086A4                        494 00105$:
                                    495 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 292: CLK->PCKENR2 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      0086A4 14 01            [ 1]  496 	and	a, (0x01, sp)
      0086A6 C7 50 CA         [ 1]  497 	ld	0x50ca, a
      0086A9                        498 00110$:
                                    499 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 295: }
      0086A9 85               [ 2]  500 	popw	x
      0086AA 81               [ 4]  501 	ret
                                    502 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 309: ErrorStatus CLK_ClockSwitchConfig(CLK_SwitchMode_TypeDef CLK_SwitchMode, CLK_Source_TypeDef CLK_NewClock, FunctionalState ITState, CLK_CurrentClockState_TypeDef CLK_CurrentClockState)
                                    503 ;	-----------------------------------------
                                    504 ;	 function CLK_ClockSwitchConfig
                                    505 ;	-----------------------------------------
      0086AB                        506 _CLK_ClockSwitchConfig:
      0086AB 88               [ 1]  507 	push	a
                                    508 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 316: assert_param(IS_CLK_SOURCE_OK(CLK_NewClock));
      0086AC 7B 05            [ 1]  509 	ld	a, (0x05, sp)
      0086AE A1 E1            [ 1]  510 	cp	a, #0xe1
      0086B0 27 1B            [ 1]  511 	jreq	00140$
      0086B2 7B 05            [ 1]  512 	ld	a, (0x05, sp)
      0086B4 A1 D2            [ 1]  513 	cp	a, #0xd2
      0086B6 27 15            [ 1]  514 	jreq	00140$
      0086B8 7B 05            [ 1]  515 	ld	a, (0x05, sp)
      0086BA A1 B4            [ 1]  516 	cp	a, #0xb4
      0086BC 27 0F            [ 1]  517 	jreq	00140$
      0086BE 4B 3C            [ 1]  518 	push	#0x3c
      0086C0 4B 01            [ 1]  519 	push	#0x01
      0086C2 5F               [ 1]  520 	clrw	x
      0086C3 89               [ 2]  521 	pushw	x
      0086C4 4B EC            [ 1]  522 	push	#<___str_0
      0086C6 4B 80            [ 1]  523 	push	#(___str_0 >> 8)
      0086C8 CD 83 14         [ 4]  524 	call	_assert_failed
      0086CB 5B 06            [ 2]  525 	addw	sp, #6
      0086CD                        526 00140$:
                                    527 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 317: assert_param(IS_CLK_SWITCHMODE_OK(CLK_SwitchMode));
      0086CD 7B 04            [ 1]  528 	ld	a, (0x04, sp)
      0086CF 4A               [ 1]  529 	dec	a
      0086D0 26 05            [ 1]  530 	jrne	00309$
      0086D2 A6 01            [ 1]  531 	ld	a, #0x01
      0086D4 6B 01            [ 1]  532 	ld	(0x01, sp), a
      0086D6 C1                     533 	.byte 0xc1
      0086D7                        534 00309$:
      0086D7 0F 01            [ 1]  535 	clr	(0x01, sp)
      0086D9                        536 00310$:
      0086D9 0D 04            [ 1]  537 	tnz	(0x04, sp)
      0086DB 27 13            [ 1]  538 	jreq	00148$
      0086DD 0D 01            [ 1]  539 	tnz	(0x01, sp)
      0086DF 26 0F            [ 1]  540 	jrne	00148$
      0086E1 4B 3D            [ 1]  541 	push	#0x3d
      0086E3 4B 01            [ 1]  542 	push	#0x01
      0086E5 5F               [ 1]  543 	clrw	x
      0086E6 89               [ 2]  544 	pushw	x
      0086E7 4B EC            [ 1]  545 	push	#<___str_0
      0086E9 4B 80            [ 1]  546 	push	#(___str_0 >> 8)
      0086EB CD 83 14         [ 4]  547 	call	_assert_failed
      0086EE 5B 06            [ 2]  548 	addw	sp, #6
      0086F0                        549 00148$:
                                    550 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 318: assert_param(IS_FUNCTIONALSTATE_OK(ITState));
      0086F0 0D 06            [ 1]  551 	tnz	(0x06, sp)
      0086F2 27 14            [ 1]  552 	jreq	00153$
      0086F4 7B 06            [ 1]  553 	ld	a, (0x06, sp)
      0086F6 4A               [ 1]  554 	dec	a
      0086F7 27 0F            [ 1]  555 	jreq	00153$
      0086F9 4B 3E            [ 1]  556 	push	#0x3e
      0086FB 4B 01            [ 1]  557 	push	#0x01
      0086FD 5F               [ 1]  558 	clrw	x
      0086FE 89               [ 2]  559 	pushw	x
      0086FF 4B EC            [ 1]  560 	push	#<___str_0
      008701 4B 80            [ 1]  561 	push	#(___str_0 >> 8)
      008703 CD 83 14         [ 4]  562 	call	_assert_failed
      008706 5B 06            [ 2]  563 	addw	sp, #6
      008708                        564 00153$:
                                    565 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 319: assert_param(IS_CLK_CURRENTCLOCKSTATE_OK(CLK_CurrentClockState));
      008708 0D 07            [ 1]  566 	tnz	(0x07, sp)
      00870A 27 14            [ 1]  567 	jreq	00158$
      00870C 7B 07            [ 1]  568 	ld	a, (0x07, sp)
      00870E 4A               [ 1]  569 	dec	a
      00870F 27 0F            [ 1]  570 	jreq	00158$
      008711 4B 3F            [ 1]  571 	push	#0x3f
      008713 4B 01            [ 1]  572 	push	#0x01
      008715 5F               [ 1]  573 	clrw	x
      008716 89               [ 2]  574 	pushw	x
      008717 4B EC            [ 1]  575 	push	#<___str_0
      008719 4B 80            [ 1]  576 	push	#(___str_0 >> 8)
      00871B CD 83 14         [ 4]  577 	call	_assert_failed
      00871E 5B 06            [ 2]  578 	addw	sp, #6
      008720                        579 00158$:
                                    580 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 322: clock_master = (CLK_Source_TypeDef)CLK->CMSR;
      008720 C6 50 C3         [ 1]  581 	ld	a, 0x50c3
      008723 90 97            [ 1]  582 	ld	yl, a
                                    583 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
      008725 C6 50 C5         [ 1]  584 	ld	a, 0x50c5
                                    585 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 325: if (CLK_SwitchMode == CLK_SWITCHMODE_AUTO)
      008728 0D 01            [ 1]  586 	tnz	(0x01, sp)
      00872A 27 38            [ 1]  587 	jreq	00122$
                                    588 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
      00872C AA 02            [ 1]  589 	or	a, #0x02
      00872E C7 50 C5         [ 1]  590 	ld	0x50c5, a
      008731 C6 50 C5         [ 1]  591 	ld	a, 0x50c5
                                    592 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 331: if (ITState != DISABLE)
      008734 0D 06            [ 1]  593 	tnz	(0x06, sp)
      008736 27 07            [ 1]  594 	jreq	00102$
                                    595 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 333: CLK->SWCR |= CLK_SWCR_SWIEN;
      008738 AA 04            [ 1]  596 	or	a, #0x04
      00873A C7 50 C5         [ 1]  597 	ld	0x50c5, a
      00873D 20 05            [ 2]  598 	jra	00103$
      00873F                        599 00102$:
                                    600 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 337: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
      00873F A4 FB            [ 1]  601 	and	a, #0xfb
      008741 C7 50 C5         [ 1]  602 	ld	0x50c5, a
      008744                        603 00103$:
                                    604 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 341: CLK->SWR = (uint8_t)CLK_NewClock;
      008744 AE 50 C4         [ 2]  605 	ldw	x, #0x50c4
      008747 7B 05            [ 1]  606 	ld	a, (0x05, sp)
      008749 F7               [ 1]  607 	ld	(x), a
                                    608 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 344: while((((CLK->SWCR & CLK_SWCR_SWBSY) != 0 )&& (DownCounter != 0)))
      00874A 5F               [ 1]  609 	clrw	x
      00874B 5A               [ 2]  610 	decw	x
      00874C                        611 00105$:
      00874C C6 50 C5         [ 1]  612 	ld	a, 0x50c5
      00874F 44               [ 1]  613 	srl	a
      008750 24 06            [ 1]  614 	jrnc	00107$
      008752 5D               [ 2]  615 	tnzw	x
      008753 27 03            [ 1]  616 	jreq	00107$
                                    617 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 346: DownCounter--;
      008755 5A               [ 2]  618 	decw	x
      008756 20 F4            [ 2]  619 	jra	00105$
      008758                        620 00107$:
                                    621 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 349: if(DownCounter != 0)
      008758 5D               [ 2]  622 	tnzw	x
      008759 27 05            [ 1]  623 	jreq	00109$
                                    624 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 351: Swif = SUCCESS;
      00875B A6 01            [ 1]  625 	ld	a, #0x01
      00875D 97               [ 1]  626 	ld	xl, a
      00875E 20 37            [ 2]  627 	jra	00123$
      008760                        628 00109$:
                                    629 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 355: Swif = ERROR;
      008760 4F               [ 1]  630 	clr	a
      008761 97               [ 1]  631 	ld	xl, a
      008762 20 33            [ 2]  632 	jra	00123$
      008764                        633 00122$:
                                    634 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 361: if (ITState != DISABLE)
      008764 0D 06            [ 1]  635 	tnz	(0x06, sp)
      008766 27 07            [ 1]  636 	jreq	00112$
                                    637 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 363: CLK->SWCR |= CLK_SWCR_SWIEN;
      008768 AA 04            [ 1]  638 	or	a, #0x04
      00876A C7 50 C5         [ 1]  639 	ld	0x50c5, a
      00876D 20 05            [ 2]  640 	jra	00113$
      00876F                        641 00112$:
                                    642 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 367: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
      00876F A4 FB            [ 1]  643 	and	a, #0xfb
      008771 C7 50 C5         [ 1]  644 	ld	0x50c5, a
      008774                        645 00113$:
                                    646 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 371: CLK->SWR = (uint8_t)CLK_NewClock;
      008774 AE 50 C4         [ 2]  647 	ldw	x, #0x50c4
      008777 7B 05            [ 1]  648 	ld	a, (0x05, sp)
      008779 F7               [ 1]  649 	ld	(x), a
                                    650 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 374: while((((CLK->SWCR & CLK_SWCR_SWIF) != 0 ) && (DownCounter != 0)))
      00877A 5F               [ 1]  651 	clrw	x
      00877B 5A               [ 2]  652 	decw	x
      00877C                        653 00115$:
      00877C C6 50 C5         [ 1]  654 	ld	a, 0x50c5
      00877F A5 08            [ 1]  655 	bcp	a, #0x08
      008781 27 06            [ 1]  656 	jreq	00117$
      008783 5D               [ 2]  657 	tnzw	x
      008784 27 03            [ 1]  658 	jreq	00117$
                                    659 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 376: DownCounter--;
      008786 5A               [ 2]  660 	decw	x
      008787 20 F3            [ 2]  661 	jra	00115$
      008789                        662 00117$:
                                    663 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 379: if(DownCounter != 0)
      008789 5D               [ 2]  664 	tnzw	x
      00878A 27 09            [ 1]  665 	jreq	00119$
                                    666 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 382: CLK->SWCR |= CLK_SWCR_SWEN;
      00878C 72 12 50 C5      [ 1]  667 	bset	20677, #1
                                    668 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 383: Swif = SUCCESS;
      008790 A6 01            [ 1]  669 	ld	a, #0x01
      008792 97               [ 1]  670 	ld	xl, a
      008793 20 02            [ 2]  671 	jra	00123$
      008795                        672 00119$:
                                    673 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 387: Swif = ERROR;
      008795 4F               [ 1]  674 	clr	a
      008796 97               [ 1]  675 	ld	xl, a
      008797                        676 00123$:
                                    677 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 390: if(Swif != ERROR)
      008797 9F               [ 1]  678 	ld	a, xl
      008798 4D               [ 1]  679 	tnz	a
      008799 27 2E            [ 1]  680 	jreq	00136$
                                    681 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 393: if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSI))
      00879B 0D 07            [ 1]  682 	tnz	(0x07, sp)
      00879D 26 0C            [ 1]  683 	jrne	00132$
      00879F 90 9F            [ 1]  684 	ld	a, yl
      0087A1 A1 E1            [ 1]  685 	cp	a, #0xe1
      0087A3 26 06            [ 1]  686 	jrne	00132$
                                    687 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 395: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
      0087A5 72 11 50 C0      [ 1]  688 	bres	20672, #0
      0087A9 20 1E            [ 2]  689 	jra	00136$
      0087AB                        690 00132$:
                                    691 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 397: else if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_LSI))
      0087AB 0D 07            [ 1]  692 	tnz	(0x07, sp)
      0087AD 26 0C            [ 1]  693 	jrne	00128$
      0087AF 90 9F            [ 1]  694 	ld	a, yl
      0087B1 A1 D2            [ 1]  695 	cp	a, #0xd2
      0087B3 26 06            [ 1]  696 	jrne	00128$
                                    697 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 399: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
      0087B5 72 17 50 C0      [ 1]  698 	bres	20672, #3
      0087B9 20 0E            [ 2]  699 	jra	00136$
      0087BB                        700 00128$:
                                    701 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 401: else if ((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSE))
      0087BB 0D 07            [ 1]  702 	tnz	(0x07, sp)
      0087BD 26 0A            [ 1]  703 	jrne	00136$
      0087BF 90 9F            [ 1]  704 	ld	a, yl
      0087C1 A1 B4            [ 1]  705 	cp	a, #0xb4
      0087C3 26 04            [ 1]  706 	jrne	00136$
                                    707 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 403: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
      0087C5 72 11 50 C1      [ 1]  708 	bres	20673, #0
      0087C9                        709 00136$:
                                    710 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 406: return(Swif);
      0087C9 9F               [ 1]  711 	ld	a, xl
                                    712 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 407: }
      0087CA 5B 01            [ 2]  713 	addw	sp, #1
      0087CC 81               [ 4]  714 	ret
                                    715 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 415: void CLK_HSIPrescalerConfig(CLK_Prescaler_TypeDef HSIPrescaler)
                                    716 ;	-----------------------------------------
                                    717 ;	 function CLK_HSIPrescalerConfig
                                    718 ;	-----------------------------------------
      0087CD                        719 _CLK_HSIPrescalerConfig:
                                    720 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 418: assert_param(IS_CLK_HSIPRESCALER_OK(HSIPrescaler));
      0087CD 0D 03            [ 1]  721 	tnz	(0x03, sp)
      0087CF 27 21            [ 1]  722 	jreq	00104$
      0087D1 7B 03            [ 1]  723 	ld	a, (0x03, sp)
      0087D3 A1 08            [ 1]  724 	cp	a, #0x08
      0087D5 27 1B            [ 1]  725 	jreq	00104$
      0087D7 7B 03            [ 1]  726 	ld	a, (0x03, sp)
      0087D9 A1 10            [ 1]  727 	cp	a, #0x10
      0087DB 27 15            [ 1]  728 	jreq	00104$
      0087DD 7B 03            [ 1]  729 	ld	a, (0x03, sp)
      0087DF A1 18            [ 1]  730 	cp	a, #0x18
      0087E1 27 0F            [ 1]  731 	jreq	00104$
      0087E3 4B A2            [ 1]  732 	push	#0xa2
      0087E5 4B 01            [ 1]  733 	push	#0x01
      0087E7 5F               [ 1]  734 	clrw	x
      0087E8 89               [ 2]  735 	pushw	x
      0087E9 4B EC            [ 1]  736 	push	#<___str_0
      0087EB 4B 80            [ 1]  737 	push	#(___str_0 >> 8)
      0087ED CD 83 14         [ 4]  738 	call	_assert_failed
      0087F0 5B 06            [ 2]  739 	addw	sp, #6
      0087F2                        740 00104$:
                                    741 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 421: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      0087F2 C6 50 C6         [ 1]  742 	ld	a, 0x50c6
      0087F5 A4 E7            [ 1]  743 	and	a, #0xe7
      0087F7 C7 50 C6         [ 1]  744 	ld	0x50c6, a
                                    745 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 424: CLK->CKDIVR |= (uint8_t)HSIPrescaler;
      0087FA C6 50 C6         [ 1]  746 	ld	a, 0x50c6
      0087FD 1A 03            [ 1]  747 	or	a, (0x03, sp)
      0087FF C7 50 C6         [ 1]  748 	ld	0x50c6, a
                                    749 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 425: }
      008802 81               [ 4]  750 	ret
                                    751 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 436: void CLK_CCOConfig(CLK_Output_TypeDef CLK_CCO)
                                    752 ;	-----------------------------------------
                                    753 ;	 function CLK_CCOConfig
                                    754 ;	-----------------------------------------
      008803                        755 _CLK_CCOConfig:
                                    756 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 439: assert_param(IS_CLK_OUTPUT_OK(CLK_CCO));
      008803 0D 03            [ 1]  757 	tnz	(0x03, sp)
      008805 27 57            [ 1]  758 	jreq	00104$
      008807 7B 03            [ 1]  759 	ld	a, (0x03, sp)
      008809 A1 04            [ 1]  760 	cp	a, #0x04
      00880B 27 51            [ 1]  761 	jreq	00104$
      00880D 7B 03            [ 1]  762 	ld	a, (0x03, sp)
      00880F A1 02            [ 1]  763 	cp	a, #0x02
      008811 27 4B            [ 1]  764 	jreq	00104$
      008813 7B 03            [ 1]  765 	ld	a, (0x03, sp)
      008815 A1 08            [ 1]  766 	cp	a, #0x08
      008817 27 45            [ 1]  767 	jreq	00104$
      008819 7B 03            [ 1]  768 	ld	a, (0x03, sp)
      00881B A1 0A            [ 1]  769 	cp	a, #0x0a
      00881D 27 3F            [ 1]  770 	jreq	00104$
      00881F 7B 03            [ 1]  771 	ld	a, (0x03, sp)
      008821 A1 0C            [ 1]  772 	cp	a, #0x0c
      008823 27 39            [ 1]  773 	jreq	00104$
      008825 7B 03            [ 1]  774 	ld	a, (0x03, sp)
      008827 A1 0E            [ 1]  775 	cp	a, #0x0e
      008829 27 33            [ 1]  776 	jreq	00104$
      00882B 7B 03            [ 1]  777 	ld	a, (0x03, sp)
      00882D A1 10            [ 1]  778 	cp	a, #0x10
      00882F 27 2D            [ 1]  779 	jreq	00104$
      008831 7B 03            [ 1]  780 	ld	a, (0x03, sp)
      008833 A1 12            [ 1]  781 	cp	a, #0x12
      008835 27 27            [ 1]  782 	jreq	00104$
      008837 7B 03            [ 1]  783 	ld	a, (0x03, sp)
      008839 A1 14            [ 1]  784 	cp	a, #0x14
      00883B 27 21            [ 1]  785 	jreq	00104$
      00883D 7B 03            [ 1]  786 	ld	a, (0x03, sp)
      00883F A1 16            [ 1]  787 	cp	a, #0x16
      008841 27 1B            [ 1]  788 	jreq	00104$
      008843 7B 03            [ 1]  789 	ld	a, (0x03, sp)
      008845 A1 18            [ 1]  790 	cp	a, #0x18
      008847 27 15            [ 1]  791 	jreq	00104$
      008849 7B 03            [ 1]  792 	ld	a, (0x03, sp)
      00884B A1 1A            [ 1]  793 	cp	a, #0x1a
      00884D 27 0F            [ 1]  794 	jreq	00104$
      00884F 4B B7            [ 1]  795 	push	#0xb7
      008851 4B 01            [ 1]  796 	push	#0x01
      008853 5F               [ 1]  797 	clrw	x
      008854 89               [ 2]  798 	pushw	x
      008855 4B EC            [ 1]  799 	push	#<___str_0
      008857 4B 80            [ 1]  800 	push	#(___str_0 >> 8)
      008859 CD 83 14         [ 4]  801 	call	_assert_failed
      00885C 5B 06            [ 2]  802 	addw	sp, #6
      00885E                        803 00104$:
                                    804 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 442: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOSEL);
      00885E C6 50 C9         [ 1]  805 	ld	a, 0x50c9
      008861 A4 E1            [ 1]  806 	and	a, #0xe1
      008863 C7 50 C9         [ 1]  807 	ld	0x50c9, a
                                    808 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 445: CLK->CCOR |= (uint8_t)CLK_CCO;
      008866 C6 50 C9         [ 1]  809 	ld	a, 0x50c9
      008869 1A 03            [ 1]  810 	or	a, (0x03, sp)
      00886B C7 50 C9         [ 1]  811 	ld	0x50c9, a
                                    812 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 448: CLK->CCOR |= CLK_CCOR_CCOEN;
      00886E 72 10 50 C9      [ 1]  813 	bset	20681, #0
                                    814 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 449: }
      008872 81               [ 4]  815 	ret
                                    816 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 459: void CLK_ITConfig(CLK_IT_TypeDef CLK_IT, FunctionalState NewState)
                                    817 ;	-----------------------------------------
                                    818 ;	 function CLK_ITConfig
                                    819 ;	-----------------------------------------
      008873                        820 _CLK_ITConfig:
      008873 88               [ 1]  821 	push	a
                                    822 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 462: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      008874 0D 05            [ 1]  823 	tnz	(0x05, sp)
      008876 27 14            [ 1]  824 	jreq	00115$
      008878 7B 05            [ 1]  825 	ld	a, (0x05, sp)
      00887A 4A               [ 1]  826 	dec	a
      00887B 27 0F            [ 1]  827 	jreq	00115$
      00887D 4B CE            [ 1]  828 	push	#0xce
      00887F 4B 01            [ 1]  829 	push	#0x01
      008881 5F               [ 1]  830 	clrw	x
      008882 89               [ 2]  831 	pushw	x
      008883 4B EC            [ 1]  832 	push	#<___str_0
      008885 4B 80            [ 1]  833 	push	#(___str_0 >> 8)
      008887 CD 83 14         [ 4]  834 	call	_assert_failed
      00888A 5B 06            [ 2]  835 	addw	sp, #6
      00888C                        836 00115$:
                                    837 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 463: assert_param(IS_CLK_IT_OK(CLK_IT));
      00888C 7B 04            [ 1]  838 	ld	a, (0x04, sp)
      00888E A0 0C            [ 1]  839 	sub	a, #0x0c
      008890 26 04            [ 1]  840 	jrne	00174$
      008892 4C               [ 1]  841 	inc	a
      008893 6B 01            [ 1]  842 	ld	(0x01, sp), a
      008895 C1                     843 	.byte 0xc1
      008896                        844 00174$:
      008896 0F 01            [ 1]  845 	clr	(0x01, sp)
      008898                        846 00175$:
      008898 7B 04            [ 1]  847 	ld	a, (0x04, sp)
      00889A A0 1C            [ 1]  848 	sub	a, #0x1c
      00889C 26 02            [ 1]  849 	jrne	00177$
      00889E 4C               [ 1]  850 	inc	a
      00889F 21                     851 	.byte 0x21
      0088A0                        852 00177$:
      0088A0 4F               [ 1]  853 	clr	a
      0088A1                        854 00178$:
      0088A1 0D 01            [ 1]  855 	tnz	(0x01, sp)
      0088A3 26 14            [ 1]  856 	jrne	00120$
      0088A5 4D               [ 1]  857 	tnz	a
      0088A6 26 11            [ 1]  858 	jrne	00120$
      0088A8 88               [ 1]  859 	push	a
      0088A9 4B CF            [ 1]  860 	push	#0xcf
      0088AB 4B 01            [ 1]  861 	push	#0x01
      0088AD 5F               [ 1]  862 	clrw	x
      0088AE 89               [ 2]  863 	pushw	x
      0088AF 4B EC            [ 1]  864 	push	#<___str_0
      0088B1 4B 80            [ 1]  865 	push	#(___str_0 >> 8)
      0088B3 CD 83 14         [ 4]  866 	call	_assert_failed
      0088B6 5B 06            [ 2]  867 	addw	sp, #6
      0088B8 84               [ 1]  868 	pop	a
      0088B9                        869 00120$:
                                    870 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 465: if (NewState != DISABLE)
      0088B9 0D 05            [ 1]  871 	tnz	(0x05, sp)
      0088BB 27 13            [ 1]  872 	jreq	00110$
                                    873 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 467: switch (CLK_IT)
      0088BD 0D 01            [ 1]  874 	tnz	(0x01, sp)
      0088BF 26 09            [ 1]  875 	jrne	00102$
      0088C1 4D               [ 1]  876 	tnz	a
      0088C2 27 1D            [ 1]  877 	jreq	00112$
                                    878 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 470: CLK->SWCR |= CLK_SWCR_SWIEN;
      0088C4 72 14 50 C5      [ 1]  879 	bset	20677, #2
                                    880 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 471: break;
      0088C8 20 17            [ 2]  881 	jra	00112$
                                    882 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 472: case CLK_IT_CSSD: /* Enable the clock security system detection interrupt */
      0088CA                        883 00102$:
                                    884 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 473: CLK->CSSR |= CLK_CSSR_CSSDIE;
      0088CA 72 14 50 C8      [ 1]  885 	bset	20680, #2
                                    886 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 474: break;
      0088CE 20 11            [ 2]  887 	jra	00112$
                                    888 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 477: }
      0088D0                        889 00110$:
                                    890 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 481: switch (CLK_IT)
      0088D0 0D 01            [ 1]  891 	tnz	(0x01, sp)
      0088D2 26 09            [ 1]  892 	jrne	00106$
      0088D4 4D               [ 1]  893 	tnz	a
      0088D5 27 0A            [ 1]  894 	jreq	00112$
                                    895 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 484: CLK->SWCR  &= (uint8_t)(~CLK_SWCR_SWIEN);
      0088D7 72 15 50 C5      [ 1]  896 	bres	20677, #2
                                    897 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 485: break;
      0088DB 20 04            [ 2]  898 	jra	00112$
                                    899 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 486: case CLK_IT_CSSD: /* Disable the clock security system detection interrupt */
      0088DD                        900 00106$:
                                    901 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 487: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSDIE);
      0088DD 72 15 50 C8      [ 1]  902 	bres	20680, #2
                                    903 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 491: }
      0088E1                        904 00112$:
                                    905 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 493: }
      0088E1 84               [ 1]  906 	pop	a
      0088E2 81               [ 4]  907 	ret
                                    908 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 500: void CLK_SYSCLKConfig(CLK_Prescaler_TypeDef CLK_Prescaler)
                                    909 ;	-----------------------------------------
                                    910 ;	 function CLK_SYSCLKConfig
                                    911 ;	-----------------------------------------
      0088E3                        912 _CLK_SYSCLKConfig:
      0088E3 89               [ 2]  913 	pushw	x
                                    914 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 503: assert_param(IS_CLK_PRESCALER_OK(CLK_Prescaler));
      0088E4 0D 05            [ 1]  915 	tnz	(0x05, sp)
      0088E6 27 51            [ 1]  916 	jreq	00107$
      0088E8 7B 05            [ 1]  917 	ld	a, (0x05, sp)
      0088EA A1 08            [ 1]  918 	cp	a, #0x08
      0088EC 27 4B            [ 1]  919 	jreq	00107$
      0088EE 7B 05            [ 1]  920 	ld	a, (0x05, sp)
      0088F0 A1 10            [ 1]  921 	cp	a, #0x10
      0088F2 27 45            [ 1]  922 	jreq	00107$
      0088F4 7B 05            [ 1]  923 	ld	a, (0x05, sp)
      0088F6 A1 18            [ 1]  924 	cp	a, #0x18
      0088F8 27 3F            [ 1]  925 	jreq	00107$
      0088FA 7B 05            [ 1]  926 	ld	a, (0x05, sp)
      0088FC A1 80            [ 1]  927 	cp	a, #0x80
      0088FE 27 39            [ 1]  928 	jreq	00107$
      008900 7B 05            [ 1]  929 	ld	a, (0x05, sp)
      008902 A1 81            [ 1]  930 	cp	a, #0x81
      008904 27 33            [ 1]  931 	jreq	00107$
      008906 7B 05            [ 1]  932 	ld	a, (0x05, sp)
      008908 A1 82            [ 1]  933 	cp	a, #0x82
      00890A 27 2D            [ 1]  934 	jreq	00107$
      00890C 7B 05            [ 1]  935 	ld	a, (0x05, sp)
      00890E A1 83            [ 1]  936 	cp	a, #0x83
      008910 27 27            [ 1]  937 	jreq	00107$
      008912 7B 05            [ 1]  938 	ld	a, (0x05, sp)
      008914 A1 84            [ 1]  939 	cp	a, #0x84
      008916 27 21            [ 1]  940 	jreq	00107$
      008918 7B 05            [ 1]  941 	ld	a, (0x05, sp)
      00891A A1 85            [ 1]  942 	cp	a, #0x85
      00891C 27 1B            [ 1]  943 	jreq	00107$
      00891E 7B 05            [ 1]  944 	ld	a, (0x05, sp)
      008920 A1 86            [ 1]  945 	cp	a, #0x86
      008922 27 15            [ 1]  946 	jreq	00107$
      008924 7B 05            [ 1]  947 	ld	a, (0x05, sp)
      008926 A1 87            [ 1]  948 	cp	a, #0x87
      008928 27 0F            [ 1]  949 	jreq	00107$
      00892A 4B F7            [ 1]  950 	push	#0xf7
      00892C 4B 01            [ 1]  951 	push	#0x01
      00892E 5F               [ 1]  952 	clrw	x
      00892F 89               [ 2]  953 	pushw	x
      008930 4B EC            [ 1]  954 	push	#<___str_0
      008932 4B 80            [ 1]  955 	push	#(___str_0 >> 8)
      008934 CD 83 14         [ 4]  956 	call	_assert_failed
      008937 5B 06            [ 2]  957 	addw	sp, #6
      008939                        958 00107$:
                                    959 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      008939 C6 50 C6         [ 1]  960 	ld	a, 0x50c6
                                    961 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 505: if (((uint8_t)CLK_Prescaler & (uint8_t)0x80) == 0x00) /* Bit7 = 0 means HSI divider */
      00893C 0D 05            [ 1]  962 	tnz	(0x05, sp)
      00893E 2B 15            [ 1]  963 	jrmi	00102$
                                    964 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      008940 A4 E7            [ 1]  965 	and	a, #0xe7
      008942 C7 50 C6         [ 1]  966 	ld	0x50c6, a
                                    967 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 508: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_HSIDIV);
      008945 C6 50 C6         [ 1]  968 	ld	a, 0x50c6
      008948 6B 02            [ 1]  969 	ld	(0x02, sp), a
      00894A 7B 05            [ 1]  970 	ld	a, (0x05, sp)
      00894C A4 18            [ 1]  971 	and	a, #0x18
      00894E 1A 02            [ 1]  972 	or	a, (0x02, sp)
      008950 C7 50 C6         [ 1]  973 	ld	0x50c6, a
      008953 20 13            [ 2]  974 	jra	00104$
      008955                        975 00102$:
                                    976 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 512: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_CPUDIV);
      008955 A4 F8            [ 1]  977 	and	a, #0xf8
      008957 C7 50 C6         [ 1]  978 	ld	0x50c6, a
                                    979 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 513: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_CPUDIV);
      00895A C6 50 C6         [ 1]  980 	ld	a, 0x50c6
      00895D 6B 01            [ 1]  981 	ld	(0x01, sp), a
      00895F 7B 05            [ 1]  982 	ld	a, (0x05, sp)
      008961 A4 07            [ 1]  983 	and	a, #0x07
      008963 1A 01            [ 1]  984 	or	a, (0x01, sp)
      008965 C7 50 C6         [ 1]  985 	ld	0x50c6, a
      008968                        986 00104$:
                                    987 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 515: }
      008968 85               [ 2]  988 	popw	x
      008969 81               [ 4]  989 	ret
                                    990 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 523: void CLK_SWIMConfig(CLK_SWIMDivider_TypeDef CLK_SWIMDivider)
                                    991 ;	-----------------------------------------
                                    992 ;	 function CLK_SWIMConfig
                                    993 ;	-----------------------------------------
      00896A                        994 _CLK_SWIMConfig:
                                    995 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 526: assert_param(IS_CLK_SWIMDIVIDER_OK(CLK_SWIMDivider));
      00896A 0D 03            [ 1]  996 	tnz	(0x03, sp)
      00896C 27 14            [ 1]  997 	jreq	00107$
      00896E 7B 03            [ 1]  998 	ld	a, (0x03, sp)
      008970 4A               [ 1]  999 	dec	a
      008971 27 0F            [ 1] 1000 	jreq	00107$
      008973 4B 0E            [ 1] 1001 	push	#0x0e
      008975 4B 02            [ 1] 1002 	push	#0x02
      008977 5F               [ 1] 1003 	clrw	x
      008978 89               [ 2] 1004 	pushw	x
      008979 4B EC            [ 1] 1005 	push	#<___str_0
      00897B 4B 80            [ 1] 1006 	push	#(___str_0 >> 8)
      00897D CD 83 14         [ 4] 1007 	call	_assert_failed
      008980 5B 06            [ 2] 1008 	addw	sp, #6
      008982                       1009 00107$:
                                   1010 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
      008982 C6 50 CD         [ 1] 1011 	ld	a, 0x50cd
                                   1012 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 528: if (CLK_SWIMDivider != CLK_SWIMDIVIDER_2)
      008985 0D 03            [ 1] 1013 	tnz	(0x03, sp)
      008987 27 06            [ 1] 1014 	jreq	00102$
                                   1015 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
      008989 AA 01            [ 1] 1016 	or	a, #0x01
      00898B C7 50 CD         [ 1] 1017 	ld	0x50cd, a
      00898E 81               [ 4] 1018 	ret
      00898F                       1019 00102$:
                                   1020 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 536: CLK->SWIMCCR &= (uint8_t)(~CLK_SWIMCCR_SWIMDIV);
      00898F A4 FE            [ 1] 1021 	and	a, #0xfe
      008991 C7 50 CD         [ 1] 1022 	ld	0x50cd, a
                                   1023 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 538: }
      008994 81               [ 4] 1024 	ret
                                   1025 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 547: void CLK_ClockSecuritySystemEnable(void)
                                   1026 ;	-----------------------------------------
                                   1027 ;	 function CLK_ClockSecuritySystemEnable
                                   1028 ;	-----------------------------------------
      008995                       1029 _CLK_ClockSecuritySystemEnable:
                                   1030 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 550: CLK->CSSR |= CLK_CSSR_CSSEN;
      008995 72 10 50 C8      [ 1] 1031 	bset	20680, #0
                                   1032 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 551: }
      008999 81               [ 4] 1033 	ret
                                   1034 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 559: CLK_Source_TypeDef CLK_GetSYSCLKSource(void)
                                   1035 ;	-----------------------------------------
                                   1036 ;	 function CLK_GetSYSCLKSource
                                   1037 ;	-----------------------------------------
      00899A                       1038 _CLK_GetSYSCLKSource:
                                   1039 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 561: return((CLK_Source_TypeDef)CLK->CMSR);
      00899A C6 50 C3         [ 1] 1040 	ld	a, 0x50c3
                                   1041 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 562: }
      00899D 81               [ 4] 1042 	ret
                                   1043 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 569: uint32_t CLK_GetClockFreq(void)
                                   1044 ;	-----------------------------------------
                                   1045 ;	 function CLK_GetClockFreq
                                   1046 ;	-----------------------------------------
      00899E                       1047 _CLK_GetClockFreq:
      00899E 52 05            [ 2] 1048 	sub	sp, #5
                                   1049 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 576: clocksource = (CLK_Source_TypeDef)CLK->CMSR;
      0089A0 C6 50 C3         [ 1] 1050 	ld	a, 0x50c3
      0089A3 6B 01            [ 1] 1051 	ld	(0x01, sp), a
                                   1052 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 578: if (clocksource == CLK_SOURCE_HSI)
      0089A5 7B 01            [ 1] 1053 	ld	a, (0x01, sp)
      0089A7 A1 E1            [ 1] 1054 	cp	a, #0xe1
      0089A9 26 26            [ 1] 1055 	jrne	00105$
                                   1056 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 580: tmp = (uint8_t)(CLK->CKDIVR & CLK_CKDIVR_HSIDIV);
      0089AB C6 50 C6         [ 1] 1057 	ld	a, 0x50c6
      0089AE A4 18            [ 1] 1058 	and	a, #0x18
                                   1059 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 581: tmp = (uint8_t)(tmp >> 3);
      0089B0 44               [ 1] 1060 	srl	a
      0089B1 44               [ 1] 1061 	srl	a
      0089B2 44               [ 1] 1062 	srl	a
                                   1063 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 582: presc = HSIDivFactor[tmp];
      0089B3 5F               [ 1] 1064 	clrw	x
      0089B4 97               [ 1] 1065 	ld	xl, a
      0089B5 1C 80 E0         [ 2] 1066 	addw	x, #_HSIDivFactor
      0089B8 F6               [ 1] 1067 	ld	a, (x)
                                   1068 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 583: clockfrequency = HSI_VALUE / presc;
      0089B9 5F               [ 1] 1069 	clrw	x
      0089BA 97               [ 1] 1070 	ld	xl, a
      0089BB 90 5F            [ 1] 1071 	clrw	y
      0089BD 89               [ 2] 1072 	pushw	x
      0089BE 90 89            [ 2] 1073 	pushw	y
      0089C0 4B 00            [ 1] 1074 	push	#0x00
      0089C2 4B 24            [ 1] 1075 	push	#0x24
      0089C4 4B F4            [ 1] 1076 	push	#0xf4
      0089C6 4B 00            [ 1] 1077 	push	#0x00
      0089C8 CD 9A BE         [ 4] 1078 	call	__divulong
      0089CB 5B 08            [ 2] 1079 	addw	sp, #8
      0089CD 1F 04            [ 2] 1080 	ldw	(0x04, sp), x
      0089CF 20 1A            [ 2] 1081 	jra	00106$
      0089D1                       1082 00105$:
                                   1083 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 585: else if ( clocksource == CLK_SOURCE_LSI)
      0089D1 7B 01            [ 1] 1084 	ld	a, (0x01, sp)
      0089D3 A1 D2            [ 1] 1085 	cp	a, #0xd2
      0089D5 26 0B            [ 1] 1086 	jrne	00102$
                                   1087 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 587: clockfrequency = LSI_VALUE;
      0089D7 AE F4 00         [ 2] 1088 	ldw	x, #0xf400
      0089DA 1F 04            [ 2] 1089 	ldw	(0x04, sp), x
      0089DC 90 AE 00 01      [ 2] 1090 	ldw	y, #0x0001
      0089E0 20 09            [ 2] 1091 	jra	00106$
      0089E2                       1092 00102$:
                                   1093 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 591: clockfrequency = HSE_VALUE;
      0089E2 AE 24 00         [ 2] 1094 	ldw	x, #0x2400
      0089E5 1F 04            [ 2] 1095 	ldw	(0x04, sp), x
      0089E7 90 AE 00 F4      [ 2] 1096 	ldw	y, #0x00f4
      0089EB                       1097 00106$:
                                   1098 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 594: return((uint32_t)clockfrequency);
      0089EB 1E 04            [ 2] 1099 	ldw	x, (0x04, sp)
                                   1100 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 595: }
      0089ED 5B 05            [ 2] 1101 	addw	sp, #5
      0089EF 81               [ 4] 1102 	ret
                                   1103 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 604: void CLK_AdjustHSICalibrationValue(CLK_HSITrimValue_TypeDef CLK_HSICalibrationValue)
                                   1104 ;	-----------------------------------------
                                   1105 ;	 function CLK_AdjustHSICalibrationValue
                                   1106 ;	-----------------------------------------
      0089F0                       1107 _CLK_AdjustHSICalibrationValue:
                                   1108 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 607: assert_param(IS_CLK_HSITRIMVALUE_OK(CLK_HSICalibrationValue));
      0089F0 0D 03            [ 1] 1109 	tnz	(0x03, sp)
      0089F2 27 38            [ 1] 1110 	jreq	00104$
      0089F4 7B 03            [ 1] 1111 	ld	a, (0x03, sp)
      0089F6 4A               [ 1] 1112 	dec	a
      0089F7 27 33            [ 1] 1113 	jreq	00104$
      0089F9 7B 03            [ 1] 1114 	ld	a, (0x03, sp)
      0089FB A1 02            [ 1] 1115 	cp	a, #0x02
      0089FD 27 2D            [ 1] 1116 	jreq	00104$
      0089FF 7B 03            [ 1] 1117 	ld	a, (0x03, sp)
      008A01 A1 03            [ 1] 1118 	cp	a, #0x03
      008A03 27 27            [ 1] 1119 	jreq	00104$
      008A05 7B 03            [ 1] 1120 	ld	a, (0x03, sp)
      008A07 A1 04            [ 1] 1121 	cp	a, #0x04
      008A09 27 21            [ 1] 1122 	jreq	00104$
      008A0B 7B 03            [ 1] 1123 	ld	a, (0x03, sp)
      008A0D A1 05            [ 1] 1124 	cp	a, #0x05
      008A0F 27 1B            [ 1] 1125 	jreq	00104$
      008A11 7B 03            [ 1] 1126 	ld	a, (0x03, sp)
      008A13 A1 06            [ 1] 1127 	cp	a, #0x06
      008A15 27 15            [ 1] 1128 	jreq	00104$
      008A17 7B 03            [ 1] 1129 	ld	a, (0x03, sp)
      008A19 A1 07            [ 1] 1130 	cp	a, #0x07
      008A1B 27 0F            [ 1] 1131 	jreq	00104$
      008A1D 4B 5F            [ 1] 1132 	push	#0x5f
      008A1F 4B 02            [ 1] 1133 	push	#0x02
      008A21 5F               [ 1] 1134 	clrw	x
      008A22 89               [ 2] 1135 	pushw	x
      008A23 4B EC            [ 1] 1136 	push	#<___str_0
      008A25 4B 80            [ 1] 1137 	push	#(___str_0 >> 8)
      008A27 CD 83 14         [ 4] 1138 	call	_assert_failed
      008A2A 5B 06            [ 2] 1139 	addw	sp, #6
      008A2C                       1140 00104$:
                                   1141 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 610: CLK->HSITRIMR = (uint8_t)( (uint8_t)(CLK->HSITRIMR & (uint8_t)(~CLK_HSITRIMR_HSITRIM))|((uint8_t)CLK_HSICalibrationValue));
      008A2C C6 50 CC         [ 1] 1142 	ld	a, 0x50cc
      008A2F A4 F8            [ 1] 1143 	and	a, #0xf8
      008A31 1A 03            [ 1] 1144 	or	a, (0x03, sp)
      008A33 C7 50 CC         [ 1] 1145 	ld	0x50cc, a
                                   1146 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 611: }
      008A36 81               [ 4] 1147 	ret
                                   1148 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 622: void CLK_SYSCLKEmergencyClear(void)
                                   1149 ;	-----------------------------------------
                                   1150 ;	 function CLK_SYSCLKEmergencyClear
                                   1151 ;	-----------------------------------------
      008A37                       1152 _CLK_SYSCLKEmergencyClear:
                                   1153 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 624: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWBSY);
      008A37 72 11 50 C5      [ 1] 1154 	bres	20677, #0
                                   1155 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 625: }
      008A3B 81               [ 4] 1156 	ret
                                   1157 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 634: FlagStatus CLK_GetFlagStatus(CLK_Flag_TypeDef CLK_FLAG)
                                   1158 ;	-----------------------------------------
                                   1159 ;	 function CLK_GetFlagStatus
                                   1160 ;	-----------------------------------------
      008A3C                       1161 _CLK_GetFlagStatus:
      008A3C 88               [ 1] 1162 	push	a
                                   1163 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 641: assert_param(IS_CLK_FLAG_OK(CLK_FLAG));
      008A3D 1E 04            [ 2] 1164 	ldw	x, (0x04, sp)
      008A3F A3 01 10         [ 2] 1165 	cpw	x, #0x0110
      008A42 27 47            [ 1] 1166 	jreq	00119$
      008A44 1E 04            [ 2] 1167 	ldw	x, (0x04, sp)
      008A46 A3 01 02         [ 2] 1168 	cpw	x, #0x0102
      008A49 27 40            [ 1] 1169 	jreq	00119$
      008A4B 1E 04            [ 2] 1170 	ldw	x, (0x04, sp)
      008A4D A3 02 02         [ 2] 1171 	cpw	x, #0x0202
      008A50 27 39            [ 1] 1172 	jreq	00119$
      008A52 1E 04            [ 2] 1173 	ldw	x, (0x04, sp)
      008A54 A3 03 08         [ 2] 1174 	cpw	x, #0x0308
      008A57 27 32            [ 1] 1175 	jreq	00119$
      008A59 1E 04            [ 2] 1176 	ldw	x, (0x04, sp)
      008A5B A3 03 01         [ 2] 1177 	cpw	x, #0x0301
      008A5E 27 2B            [ 1] 1178 	jreq	00119$
      008A60 1E 04            [ 2] 1179 	ldw	x, (0x04, sp)
      008A62 A3 04 08         [ 2] 1180 	cpw	x, #0x0408
      008A65 27 24            [ 1] 1181 	jreq	00119$
      008A67 1E 04            [ 2] 1182 	ldw	x, (0x04, sp)
      008A69 A3 04 02         [ 2] 1183 	cpw	x, #0x0402
      008A6C 27 1D            [ 1] 1184 	jreq	00119$
      008A6E 1E 04            [ 2] 1185 	ldw	x, (0x04, sp)
      008A70 A3 05 04         [ 2] 1186 	cpw	x, #0x0504
      008A73 27 16            [ 1] 1187 	jreq	00119$
      008A75 1E 04            [ 2] 1188 	ldw	x, (0x04, sp)
      008A77 A3 05 02         [ 2] 1189 	cpw	x, #0x0502
      008A7A 27 0F            [ 1] 1190 	jreq	00119$
      008A7C 4B 81            [ 1] 1191 	push	#0x81
      008A7E 4B 02            [ 1] 1192 	push	#0x02
      008A80 5F               [ 1] 1193 	clrw	x
      008A81 89               [ 2] 1194 	pushw	x
      008A82 4B EC            [ 1] 1195 	push	#<___str_0
      008A84 4B 80            [ 1] 1196 	push	#(___str_0 >> 8)
      008A86 CD 83 14         [ 4] 1197 	call	_assert_failed
      008A89 5B 06            [ 2] 1198 	addw	sp, #6
      008A8B                       1199 00119$:
                                   1200 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 644: statusreg = (uint16_t)((uint16_t)CLK_FLAG & (uint16_t)0xFF00);
      008A8B 4F               [ 1] 1201 	clr	a
      008A8C 97               [ 1] 1202 	ld	xl, a
      008A8D 7B 04            [ 1] 1203 	ld	a, (0x04, sp)
      008A8F 95               [ 1] 1204 	ld	xh, a
                                   1205 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 647: if (statusreg == 0x0100) /* The flag to check is in ICKRregister */
      008A90 A3 01 00         [ 2] 1206 	cpw	x, #0x0100
      008A93 26 05            [ 1] 1207 	jrne	00111$
                                   1208 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 649: tmpreg = CLK->ICKR;
      008A95 C6 50 C0         [ 1] 1209 	ld	a, 0x50c0
      008A98 20 21            [ 2] 1210 	jra	00112$
      008A9A                       1211 00111$:
                                   1212 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 651: else if (statusreg == 0x0200) /* The flag to check is in ECKRregister */
      008A9A A3 02 00         [ 2] 1213 	cpw	x, #0x0200
      008A9D 26 05            [ 1] 1214 	jrne	00108$
                                   1215 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 653: tmpreg = CLK->ECKR;
      008A9F C6 50 C1         [ 1] 1216 	ld	a, 0x50c1
      008AA2 20 17            [ 2] 1217 	jra	00112$
      008AA4                       1218 00108$:
                                   1219 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 655: else if (statusreg == 0x0300) /* The flag to check is in SWIC register */
      008AA4 A3 03 00         [ 2] 1220 	cpw	x, #0x0300
      008AA7 26 05            [ 1] 1221 	jrne	00105$
                                   1222 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 657: tmpreg = CLK->SWCR;
      008AA9 C6 50 C5         [ 1] 1223 	ld	a, 0x50c5
      008AAC 20 0D            [ 2] 1224 	jra	00112$
      008AAE                       1225 00105$:
                                   1226 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 659: else if (statusreg == 0x0400) /* The flag to check is in CSS register */
      008AAE A3 04 00         [ 2] 1227 	cpw	x, #0x0400
      008AB1 26 05            [ 1] 1228 	jrne	00102$
                                   1229 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 661: tmpreg = CLK->CSSR;
      008AB3 C6 50 C8         [ 1] 1230 	ld	a, 0x50c8
      008AB6 20 03            [ 2] 1231 	jra	00112$
      008AB8                       1232 00102$:
                                   1233 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 665: tmpreg = CLK->CCOR;
      008AB8 C6 50 C9         [ 1] 1234 	ld	a, 0x50c9
      008ABB                       1235 00112$:
                                   1236 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 668: if ((tmpreg & (uint8_t)CLK_FLAG) != (uint8_t)RESET)
      008ABB 88               [ 1] 1237 	push	a
      008ABC 7B 06            [ 1] 1238 	ld	a, (0x06, sp)
      008ABE 6B 02            [ 1] 1239 	ld	(0x02, sp), a
      008AC0 84               [ 1] 1240 	pop	a
      008AC1 14 01            [ 1] 1241 	and	a, (0x01, sp)
      008AC3 27 03            [ 1] 1242 	jreq	00114$
                                   1243 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 670: bitstatus = SET;
      008AC5 A6 01            [ 1] 1244 	ld	a, #0x01
                                   1245 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 674: bitstatus = RESET;
      008AC7 21                    1246 	.byte 0x21
      008AC8                       1247 00114$:
      008AC8 4F               [ 1] 1248 	clr	a
      008AC9                       1249 00115$:
                                   1250 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 678: return((FlagStatus)bitstatus);
                                   1251 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 679: }
      008AC9 5B 01            [ 2] 1252 	addw	sp, #1
      008ACB 81               [ 4] 1253 	ret
                                   1254 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 687: ITStatus CLK_GetITStatus(CLK_IT_TypeDef CLK_IT)
                                   1255 ;	-----------------------------------------
                                   1256 ;	 function CLK_GetITStatus
                                   1257 ;	-----------------------------------------
      008ACC                       1258 _CLK_GetITStatus:
                                   1259 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 692: assert_param(IS_CLK_IT_OK(CLK_IT));
      008ACC 7B 03            [ 1] 1260 	ld	a, (0x03, sp)
      008ACE A0 1C            [ 1] 1261 	sub	a, #0x1c
      008AD0 26 02            [ 1] 1262 	jrne	00143$
      008AD2 4C               [ 1] 1263 	inc	a
      008AD3 21                    1264 	.byte 0x21
      008AD4                       1265 00143$:
      008AD4 4F               [ 1] 1266 	clr	a
      008AD5                       1267 00144$:
      008AD5 88               [ 1] 1268 	push	a
      008AD6 7B 04            [ 1] 1269 	ld	a, (0x04, sp)
      008AD8 A1 0C            [ 1] 1270 	cp	a, #0x0c
      008ADA 84               [ 1] 1271 	pop	a
      008ADB 27 14            [ 1] 1272 	jreq	00113$
      008ADD 4D               [ 1] 1273 	tnz	a
      008ADE 26 11            [ 1] 1274 	jrne	00113$
      008AE0 88               [ 1] 1275 	push	a
      008AE1 4B B4            [ 1] 1276 	push	#0xb4
      008AE3 4B 02            [ 1] 1277 	push	#0x02
      008AE5 5F               [ 1] 1278 	clrw	x
      008AE6 89               [ 2] 1279 	pushw	x
      008AE7 4B EC            [ 1] 1280 	push	#<___str_0
      008AE9 4B 80            [ 1] 1281 	push	#(___str_0 >> 8)
      008AEB CD 83 14         [ 4] 1282 	call	_assert_failed
      008AEE 5B 06            [ 2] 1283 	addw	sp, #6
      008AF0 84               [ 1] 1284 	pop	a
      008AF1                       1285 00113$:
                                   1286 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 694: if (CLK_IT == CLK_IT_SWIF)
      008AF1 4D               [ 1] 1287 	tnz	a
      008AF2 27 0D            [ 1] 1288 	jreq	00108$
                                   1289 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 697: if ((CLK->SWCR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
      008AF4 C6 50 C5         [ 1] 1290 	ld	a, 0x50c5
      008AF7 14 03            [ 1] 1291 	and	a, (0x03, sp)
                                   1292 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 699: bitstatus = SET;
      008AF9 A0 0C            [ 1] 1293 	sub	a, #0x0c
      008AFB 26 02            [ 1] 1294 	jrne	00102$
      008AFD 4C               [ 1] 1295 	inc	a
      008AFE 81               [ 4] 1296 	ret
      008AFF                       1297 00102$:
                                   1298 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 703: bitstatus = RESET;
      008AFF 4F               [ 1] 1299 	clr	a
      008B00 81               [ 4] 1300 	ret
      008B01                       1301 00108$:
                                   1302 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 709: if ((CLK->CSSR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
      008B01 C6 50 C8         [ 1] 1303 	ld	a, 0x50c8
      008B04 14 03            [ 1] 1304 	and	a, (0x03, sp)
                                   1305 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 711: bitstatus = SET;
      008B06 A0 0C            [ 1] 1306 	sub	a, #0x0c
      008B08 26 02            [ 1] 1307 	jrne	00105$
      008B0A 4C               [ 1] 1308 	inc	a
      008B0B 81               [ 4] 1309 	ret
      008B0C                       1310 00105$:
                                   1311 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 715: bitstatus = RESET;
      008B0C 4F               [ 1] 1312 	clr	a
                                   1313 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 720: return bitstatus;
                                   1314 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 721: }
      008B0D 81               [ 4] 1315 	ret
                                   1316 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 729: void CLK_ClearITPendingBit(CLK_IT_TypeDef CLK_IT)
                                   1317 ;	-----------------------------------------
                                   1318 ;	 function CLK_ClearITPendingBit
                                   1319 ;	-----------------------------------------
      008B0E                       1320 _CLK_ClearITPendingBit:
                                   1321 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 732: assert_param(IS_CLK_IT_OK(CLK_IT));
      008B0E 7B 03            [ 1] 1322 	ld	a, (0x03, sp)
      008B10 A0 0C            [ 1] 1323 	sub	a, #0x0c
      008B12 26 02            [ 1] 1324 	jrne	00127$
      008B14 4C               [ 1] 1325 	inc	a
      008B15 21                    1326 	.byte 0x21
      008B16                       1327 00127$:
      008B16 4F               [ 1] 1328 	clr	a
      008B17                       1329 00128$:
      008B17 4D               [ 1] 1330 	tnz	a
      008B18 26 19            [ 1] 1331 	jrne	00107$
      008B1A 88               [ 1] 1332 	push	a
      008B1B 7B 04            [ 1] 1333 	ld	a, (0x04, sp)
      008B1D A1 1C            [ 1] 1334 	cp	a, #0x1c
      008B1F 84               [ 1] 1335 	pop	a
      008B20 27 11            [ 1] 1336 	jreq	00107$
      008B22 88               [ 1] 1337 	push	a
      008B23 4B DC            [ 1] 1338 	push	#0xdc
      008B25 4B 02            [ 1] 1339 	push	#0x02
      008B27 5F               [ 1] 1340 	clrw	x
      008B28 89               [ 2] 1341 	pushw	x
      008B29 4B EC            [ 1] 1342 	push	#<___str_0
      008B2B 4B 80            [ 1] 1343 	push	#(___str_0 >> 8)
      008B2D CD 83 14         [ 4] 1344 	call	_assert_failed
      008B30 5B 06            [ 2] 1345 	addw	sp, #6
      008B32 84               [ 1] 1346 	pop	a
      008B33                       1347 00107$:
                                   1348 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 734: if (CLK_IT == (uint8_t)CLK_IT_CSSD)
      008B33 4D               [ 1] 1349 	tnz	a
      008B34 27 05            [ 1] 1350 	jreq	00102$
                                   1351 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 737: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSD);
      008B36 72 17 50 C8      [ 1] 1352 	bres	20680, #3
      008B3A 81               [ 4] 1353 	ret
      008B3B                       1354 00102$:
                                   1355 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 742: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIF);
      008B3B 72 17 50 C5      [ 1] 1356 	bres	20677, #3
                                   1357 ;	../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c: 745: }
      008B3F 81               [ 4] 1358 	ret
                                   1359 	.area CODE
                                   1360 	.area CONST
      0080E0                       1361 _HSIDivFactor:
      0080E0 01                    1362 	.db #0x01	; 1
      0080E1 02                    1363 	.db #0x02	; 2
      0080E2 04                    1364 	.db #0x04	; 4
      0080E3 08                    1365 	.db #0x08	; 8
      0080E4                       1366 _CLKPrescTable:
      0080E4 01                    1367 	.db #0x01	; 1
      0080E5 02                    1368 	.db #0x02	; 2
      0080E6 04                    1369 	.db #0x04	; 4
      0080E7 08                    1370 	.db #0x08	; 8
      0080E8 0A                    1371 	.db #0x0a	; 10
      0080E9 10                    1372 	.db #0x10	; 16
      0080EA 14                    1373 	.db #0x14	; 20
      0080EB 28                    1374 	.db #0x28	; 40
      0080EC                       1375 ___str_0:
      0080EC 2E 2E 2F 2E 2E 2F 2E  1376 	.ascii "../../../Libraries/STM8S_StdPeriph_Driver/src/stm8s_clk.c"
             2E 2F 4C 69 62 72 61
             72 69 65 73 2F 53 54
             4D 38 53 5F 53 74 64
             50 65 72 69 70 68 5F
             44 72 69 76 65 72 2F
             73 72 63 2F 73 74 6D
             38 73 5F 63 6C 6B 2E
             63
      008125 00                    1377 	.db 0x00
                                   1378 	.area INITIALIZER
                                   1379 	.area CABS (ABS)
