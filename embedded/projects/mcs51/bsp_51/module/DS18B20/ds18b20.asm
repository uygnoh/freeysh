/**
  *****************************************************************************
  * 
  * 2018.10.29
  * @freeysh
  */

TEMP_FLAG   EQU	24H	
TEMPL	    EQU	25H
TEMPH      EQU	26H
TEMPHC      EQU	27H	
TEMPLC      EQU	28H

LCD_RS	   BIT	P1.0
LCD_RW      BIT	P1.1
LCD_EN      BIT	P1.2
DQ          BIT	P1.6
	
	ORG	0000H
	LJMP	START
	ORG	0030H
START:
	MOV	SP,#60H
	MOV	A,#00H
	LCALL	LCD_INIT
MAIN:
	LCALL	RST
	MOV	A,#0CCH
	LCALL	WRITE
	MOV	A,#44H
	LCALL	WRITE
	LCALL	RST
	MOV	A,#0CCH
	LCALL	WRITE
	MOV	A,#0BEH
	LCALL	WRITE
	LCALL	READ
	LCALL	BCDTEMP
	LCALL	DISP
	SJMP	MAIN


;*****1602LCDINIT*****
LCD_INIT:
	ACALL	DELAY1MS
	MOV	A,#38H
	ACALL	LCD_CMD
	ACALL	DELAY1MS
	MOV	A,#06H
	ACALL	LCD_CMD
	MOV	A,#0CH
	ACALL	LCD_CMD
	MOV	A,#01H
	ACALL	LCD_CMD
	MOV	A,#80H
	ACALL	LCD_CMD
	MOV	DPTR,#CHAR1
	ACALL	WRITE1
	RET

;*****DS18B20RESET*****
RST:
	SETB	DQ	；
	NOP
	CLR	DQ
	MOV	R0,#6BH
	MOV	R1,#04H
TSR1:	
	DJNZ	R0,$
	MOV	R0,#6BH
	DJNZ	R1,TSR1
	SETB	DQ
	NOP
	NOP
	NOP
	MOV	R0,#32H
TSR2:
	JNB	DQ,TSR3
	DJNZ	R0,TSR2
	JMP	TSR4
TSR3:
	MOV	R0,#06BH
	JMP	TSR1
TSR4:
	JMP	TSR6
TSR5:
	DJNZ	R0,$
TSR6:
	SETB	DQ
	RET

;*****DS18B20WRITE*****

WRITE:
	MOV	R2,#8
	CLR	C
WR1:
	CLR	DQ	
	MOV	R3,#07
	DJNZ	R3,$
	RRC	A
	MOV	DQ,C
	MOV	R3,#3CH
	DJNZ	R3,$
	SETB	DQ
	NOP
	DJNZ	R2,WR1
	SETB	DQ
	RET


;*****DS18B20READ*****

READ:
	MOV	R4,#2
	MOV	R1,#TEMPL
RE00:	
	MOV	R2,#8
RE01:
	CLR	CY
	SETB	DQ
	NOP
	NOP
	CLR	DQ	
	NOP
	NOP
	NOP
	SETB	DQ
	MOV	R3,#09
	DJNZ	R3,$
	MOV	C,DQ
	MOV	R3,#3CH
	DJNZ	R3,$
	RRC	A
	DJNZ	R2,RE01
	MOV	@R1,A
	INC	R1
	DJNZ	R4,RE00
	RET

;*****BCD*****

BCDTEMP:
	MOV	A,TEMPH
	ANL	A,#08H
	JZ	TEMPC1
	CLR	C
	MOV	A,TEMPL
	CPL	A
	ADD	A,#01H
	MOV	TEMPL,A
	MOV	A,TEMPH
	CPL	A
	MOV	TEMP_FLAG,#0BH
	SJMP	TEMPC11
TEMPC1:
	MOV	TEMP_FLAG,#0AH
TEMPC11:
	SWAP	A
	MOV	TEMPHC,A
	MOV	A,TEMPL
	ANL	A,#0FH
	MOV	DPTR,#TEMPTAB
	MOVC	A,@A+DPTR
	MOV	TEMPLC,A
	MOV	A,TEMPL
	ANL	A,#0F0H
	SWAP	A
	MOV	TEMPL,A
	MOV	A,TEMPH
	ANL	A,#0FH
	SWAP	A
	ORL	A,TEMPL
	LCALL	HEX2BCD1
	MOV	TEMPL,A
	ANL	A,#0F0H
	SWAP	A
	ORL	A,TEMPHC
	MOV	TEMPHC,A
	MOV	A,TEMPL
	ANL	A,#0FH
	SWAP	A
	ORL	A,TEMPLC
	MOV	TEMPLC,A
	MOV	A,R4
	ANL	A,#0FH
	SWAP	A
	MOV	R4,A
	MOV	A,TEMPHC
	ANL	A,#0FH
	ORL	A,R4
	MOV	TEMPHC,A
	MO
	RET
;*****DISPLAY*****

DISP:
	MOV	A,#0C6H
	ACALL	LCD_CMD
	MOV	A,TEMPHC
	SWAP	A
	ANL	A,#0FH
	DA	A
	ADD	A,#30H
	ACALL	LCD_WDATA
	MOV	A,TEMPHC
	ANL	A,0FH
	DA	A
	ADD	A,#30H
	ACALL	LCD_WDATA
	MOV	A,TEMPLC
	SWAP	A
	ANL	A,0FH
	DA	A
	ADD	A,#30H

	ACALL	LCD_WDATA
	MOV	A,'.'
	
	ACALL	LCD_WDATA
	MOV	A,TEMPLC
	ANL	A,#0FH
	DA	A
	ADD	A,#30H
	ACALL	LCD_WDATA
	RET


;*****HEXBCD*****

HEX2BCD1:
	MOV	B,#100
	DIV	AB
	MOV	R4,A
	MOV	A,#0AH
	XCH	A,B
	DIV	AB
	SWAP	A
	ORL	A,B
	RET

;*****LCD_CMD*****

LCD_CMD:
	CLR	LCD_RS
	CLR	LCD_RW
	CLR	LCD_EN
	MOV	P0,A
	LCALL	DELAY1MS
	SETB	 LCD_EN
	LCALL	DELAY1MS
	CLR	LCD_EN
	RET

;*****LCD_WDATA*****

LCD_WDATA:
	SETB	LCD_RS
	CLR	LCD_RW
	CLR	LCD_EN
	MOV	P0,A
	LCALL	DELAY1MS
	SETB	LCD_EN
	LCALL	DELAY1MS
	CLR	LCD_EN
	RET


TEMPTAB:
	DB	00H,00H,01H,01H,02H,03H,03H,04H
	DB	05H,05H,06H,06H,07H,08H,08H,09H

WRITE1:
	MOV	R0,#16
WRITE0:
	CLR	A
	MOVC	A,@A+DPTR
	INC	DPTR
	ACALL	LCD_WDATA
	DJNZ	R0,WRITE0
	RET
DELAY1MS:
	MOV	R6,#14H
DL8:
	MOV	R7,#19H
DL9:
	DJNZ	R7,DL9
	DJNZ	R6,DL8
	RET
CHAR1:
DB"WELCOME TO 51MCU"
	END












###############################################################################

###############################################################################
DS18B20单总线工作方式

控制器对 DS18B20 操作流程：
	1. 复位，首先我们对 DS18B20 芯片进行复位，复位就是由控制器(单片机)给 DS18b20
           单总线至少 480us 的低电平信号。
           当 DS18B20接收到此复位信号后则会在 15~60us 后回发一个芯片存在脉冲。

	2. 芯片存在脉冲，在复位电平信号结束之后，控制器应该将数据单总线拉高，以便于在 15~60 us
           后接收脉冲，存在脉冲为一个 60~240 us的低电平信号。至此，通信双方已达成基本的通信协议。
	   接下来将会是控制器与 DS18B20间的数据通信。
	   如果复位的低电平的时间不足或是单总线的电路断路都不会接收到存在脉冲，在设计时要注意
           意外的情况处理。


	3. 控制器发送 ROM指令，双方打完了招呼之后就要进行数据交流了，ROM共有5条，每一个工作周期
           只能发一条， ROM指令分别是，读ROM数据，指定匹配芯片，跳过ROM，芯片搜索，报警芯片搜索
           ROM指令为 8位长度，功能是对芯片内的 64 位光刻ROM进行操作。其主要的目的是为了分辨一条
           总线上挂接的多个器件并做处理。诚然，单总线上可以挂多个器件，并通过每个器件上多独立的 ID
           号来区分，一般只挂单个 DS18B20芯片时可以跳过ROM指令(注意！此出跳过ROM指令并非不发送
           ROM指令，而是用特有的一条“跳过指令”)

	4. 控制器发送存储器操作指令，在 ROM指令发送之后给 DS18B20之后，紧接着(不间断)就是发送存储器
           操作指令了。 操作指令同样为 8位，共6条，存储器操作指令分别是，写RAM数据，读RAM数据，
           将RAM数据复制到 EEPROM，温度转换，将 EEPROM中的报警值复制到RAM，工作方式切换。
           存储器操作指令是的功能是命令 DS18B20做什么样的工作，是芯片控制的关键


	5. 执行或存储器读写，一个存储器操作指令结束后则将进行指令执行或数据读写，这个操作要是存储器操作指令二定。
           如果指令温度转换指令则控制器(单片机)必须等待 DS18b20指行其指令，一般转换时间为 500 us.
           如果执行数据读写指令则需要严格遵循 DS18B20的读写时序来操作。








