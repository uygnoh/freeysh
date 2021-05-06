###########################################################
### % RISC-V  RV32I
###########################################################
1 % RV32I寄存器为 x0~x31
    其中x0寄存器比较特殊，它的值恒为0


2 % RV32I指令格式
    R     用于寄存器-寄存器操作的R类型指令
    I     用于短立即数和访存load操作的I型指令
    S     用于访存store操作的S型指令
    B     用于条件跳转操作的B类型指令
    U     用于长立即数的U型指令
    J     用于无条件跳转的J型指令


3 % Big Endian & Little Endian
    大端与小端是指字节在存储器中存储顺序的两种方式
    大端是将一个字数据的最低位字节存储在最高字节地址上
    小端是将一个字数据的最低位字节存储在最低字节地址上
    
    
4 %     
    
    
###########################################################
### % RISC-V  加减指令
###########################################################
% Syntax of Instructions:
% 加法指令语法构成{ add x1, x2, x3 }
    -One    =operation by name
    -two    =operand getting result("destination")
    -three  =1st operand for operation("source1")
    -four   =2st operand for operation("source2")


% 加法 RISC-V与C语言对比
    add x1, x2, x3  # (in RISC-V) =>x1=x2+x3
    a = b + c       # (in C)
    ---where C variables <==> RISC-V Registers are:
    a<=>x1, b<=>x2, c<=>x3


% 减法 RISC-V与C语言对比
    sub x1, x2, x3  # (in RISC-V) =>x1=x2-x3
    a = b - c       # (in C)
    ---where C variables <==> RISC-V Registers are:
    a<=>x1, b<=>x2, c<=>x3



###########################################################
### % RISC-V  加载存储指令
###########################################################
0 % Load from Memory to Register，将数据从存储器装载到寄存器
C code, c语言代码
    int A[100];
    g = h + A[3];
Using Load Word(lw) in RISC-V:
    lw x10, 12(x15)     # Reg x10 gets A[3]
    add x11, x12, x10   # g = h + A[3]
% Note: 
    x15 ->base register(pointer to A[0])
    x12 ->offset in bytes
    


1 % Store form Register to Memory，将数据从寄存器存储到存储器中
C code, c语言代码
    int A[100];
    A[10] = h + A[3]
Using Store Word(sw) in RISC-V:
    lw  x10, 12(x15)    # Temp reg x10 gets A[3]
    add x10, x12, x10   # Temp reg x10 gets h + A[3]
    sw  x10, 40(x15)    # A[10] = h + A[3]
% Note:
    x15    ->base register(pointer)
    12, 40 ->offsets in bytes
x15+2 and x15+40 must be multiples of 4




###########################################################
### % RISC-V  条件判断指令
###########################################################
0 % RISC-V: if-statment instruction is 条件判断指令
% BEQ表示相等跳转到标号处执行处理，否则顺序执行下面的语句
% New Instructions: beq, bne, blt, bltu, bge, j
beq register1, register2, Lable
f->x10, g->x11, h->x12, i->x13, j->x14
# C语言
    if (i == j)
        f = g + h;
    esle
        f = g -h;
# RISC-V语法
    bne x13, x14, Else
    add x10, x11, x12
    j Exit
    Else:
        sub x10, x11, x12
    Exit:
        

1 % C Loop Mapped to RISC-V Assembly
    int a[20];
    int i;
    int sum = 0;
    for (i = 0; i < 20; i++)
        sum += A[i];

add  x9, x8, x0             # x9=&A[0]，给寄存器x9赋数组A【0】的地址
add  x10, x0, x0            # sum=0
add  x11, x0, x0            # i=0
addi x13, x0, 20            # x13=20，x13赋循环次数值为20
Loop:
    bge  x11, x13, Done     # bge大于等于指令
    lw   x12, 0(x9)         # x12=A[i]，A[i]值从内存中装载到寄存器x12中
    add  x10, x10, x12      # sum+=
    addi x9, x9, 4          # &A[i+1]
    addi x11, x11, 1        # i++
    j Loop
Done:



###########################################################
### % RISC-V  逻辑运算指令
###########################################################
% Language                  C          RISC-v
% Logical operations    operators   instructions
% Bit-by-bit AND            &           and
% Bit-by-bit OR             |           or
% Bit-by-bit XOR            ^           xor
% Shift left logical        <<          sll
% Shift right logical       >>          srl
Register:
    and x5, x6, x7      # x5 = x6 & x7
Immediate:
    andi x5, x6, 3      # x5 = x6 & 3
% Note:
在RISC-V指令集中没有专门的逻辑非指令，
可以使用逻辑异或指令xor与0x1111_1111按位异或即可得到逻辑非的结果


% 算术移位指令， sra, srai



###########################################################
### % RISC-V  程序段与类函数调用的方法
###########################################################
1 发生函数调用时，在执行函数功能前，先将这次调用中
  需要用到的参数保存，方便取用
2 将控制权移交给这次调用的功能函数
3 根据情况为函数申请一定的本地存储空间，以满足函数
  执行过程中需要的存储需求
4 执行该函数的功能操作
5 在函数执行完成后，将得到的结果数据存放好，便于
  主里程来获取，同时还原函数执行过程中使用到的
  寄存器值，释放分配给函数的本地存储空间
6 将控制权返回给还进程

% a0~a7 编号x10~x17的寄存器，用来向调用的函数传递参数
% a0和a1寄存器常用于传递返回值

% ra，即x1寄存器，用来保存返回时的返回地址值

% s0~s11，对应的编号x8-x9和x18~x27的寄存器用来作为保存寄存器，
% 保存原进程中的关键数据避免在函数调用过程中被破坏


jal指令意为“跳转并链接”
通过jal指令，可以形成指向调用点的地址或链接，从而使函数能返回正确的地址。
跳转则会使PC跳转指向被调用函数的地址，并且将链接得到的下一指令的地址作为返回地址，
保存在ra寄存器中。




###########################################################
### % RISC-V  STACK栈
###########################################################
% 栈也是存储系统的一部分，因此需要一个指向的的寄存器
% 来保存它的基地址，sp寄存器(x2)就是RISC-V中的栈寄存器
我们通常沿着高地址向低地址的方向来扩展栈空间，通过递减
sp值为断压入(PUSH)数据，通过递增sp来弹出(POP)数据。

Leaf:
    addi sp, sp, -8     # adjust stack for 2 items
    sw s1, 4(sp)        # save s1 for use afterwards
    sw s0, 0(sp)        # save s0 for use afterwards
    
    add s0, a0, a1      # f = g + h
    add s1, a2, a3      # s1 = i + j
    sub a0, s0, s1      # return value (g+h) - (i+j)
    
    lw s0, 0(sp)        # restore register s0 for caller
    lw s1, 4(sp)        # restore register s1 for caller
    addi sp, sp, 8      # adjust stack to delete 2 items
    jr ra               # jump back to calling routine
    
    




###########################################################
### % RISC-V  R型指令
### % R-Format for register-register arithmetic operations
###########################################################
% RISC-V汇编 & 机器码
add x18, x19, x10   =>00000 01010 10011 000 10010 0110011
%   7bits   5bits   5bits    3bits    5bits   7bits
%   funct7  rs2     rs1      funct3   rd      opcode
    00000   01010   10011    000      10010   0110011
    add     rs2=10  rs1=19   add      rd=18   Reg-Reg





###########################################################
### % RISC-V  I型指令
### % I-Format for register-immediate arithmetic 
### % operations and loads
###########################################################
% 12bits        5bits       3bits       5bits       7bits
% Imm[11:0]     rs1         funct3      rd          opcode
imm[11:0] can hold values in range [-2048, +2047]


addi x15, x1, -50   =>111111001110,00001,000,01111,0010011
111111001110    00001       000         01111       0010011
imm=-50         rs1=1       add         rd=15       OP-Imm




###########################################################
### % RISC-V  S型指令
### % S-format for stores
###########################################################





###########################################################
### % RISC-V  B型指令
### % B-format for branches(minor variant of S-format,
### % called SB before)
###########################################################





###########################################################
### % RISC-V  U型指令
### % U-format for 20-bit upper immediate instructions
###########################################################





###########################################################
### % RISC-V  J型指令
### % J-format for jumps(minor variant of U-format,
### % called UJ before)
###########################################################



