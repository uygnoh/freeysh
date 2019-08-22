//##################################################################### 指针函数
//##################################################################### 函数指针
//##################################################################### 指针数组
//##################################################################### 数组指针
//##################################################################### 结构体
//##################################################################### 链表
//##################################################################### 关键字
auto            声明自动变量
break           跳出当前循环
case            开关语句分支
char            声明字符型变量或函数返回值类型
const           声明只读变量
continue        结束当前循环，开始下一轮循环
default         开关语句中的"其它"分支
do              循环语句的循环体
double          声明双精度浮点型变量或函数返回值类型
else            条件语句否定分支（与 if 连用）
enum            声明枚举类型
extern          声明变量或函数是在其它文件或本文件的其他位置定义
float           声明浮点型变量或函数返回值类型
for             一种循环语句
got             无条件跳转语句
if              条件语句
int             声明整型变量或函数
long            声明长整型变量或函数返回值类型
register        声明寄存器变量
return          子程序返回语句（可以带参数，也可不带参数）
short	        声明短整型变量或函数
signed	        声明有符号类型变量或函数
sizeof	        计算数据类型或变量长度（即所占字节数）
static 	        声明静态变量
struct	        声明结构体类型
switch 	        用于开关语句
typedef	        用以给数据类型取别名
unsigned	    声明无符号类型变量或函数
union	        声明共用体类型
void	        声明函数无返回值或无参数，声明无类型指针
volatile	    说明变量在程序执行中可被隐含地改变
while 	        循环语句的循环条件

// ################################################################# C 数据类型
1   基本类型    它们是算术类型，包括两种类型：整数类型和浮点类型。
2	枚举类型    它们也是算术类型，被用来定义在程序中只能赋予其一定的离散整数值的变量。
3	void类型    类型说明符 void 表明没有可用的值。
4	派生类型    它们包括：指针类型、数组类型、结构类型、共用体类型和函数类型。
// ######################################### C 中的左值（Lvalues）和右值（Rvalues）
C 中有两种类型的表达式：
左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。
右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。
//变量是左值，因此可以出现在赋值号的左边。
//数值型的字面值是右值，因此不能被赋值，不能出现在赋值号的左边。下面是一个有效的语句：
int g = 20;
// ################################################################### printf
%[flags][width][.prec][hlL]type
Flag        含义
-           左对齐
+           在前面放 +或-
(space)     正数留空
0           0填充
printf("%9d\n", 123);
printf("%-9d\n", 123);
printf("%+9d\n", 123);
printf("%09d\n", 123);

int len = 3;
printf("%9.2f\n", 123.0);
printf("%*d\n", len, 123);
// #################################################################### scanf
* 表示跳过输入的数据
scanf("%d*%d", &num);
scanf("%i", &num);
// ################################################################# C 文件读写
#include <stdio.h>
int main(int argc, const char *argv[]) 
{
    printf("Hello, World!\n");
    FILE *fp = fopen("file_name", "r");
    if (fp) {
        int num;
        fscanf(fp, "%d", $num);
        printf("%d\n", num);
        fclose(fp);
    } else {
        printf("File not Open\n");
    }
    return 0;
}
// ############################################################# 二进制文件读写
fread()
fwrite()




















