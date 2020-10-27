#include <stdio.h>

int add(int a, int b) 
{
    return a + b;
}
 
typedef int (PTypeFun1)(int, int);      /* 声明一个函数类型 */
typedef int (*PTypeFun2)(int, int);     /* 声明一个函数指针类型 */
int (*padd)(int, int);                  /* 传统形式，定义一个函数指针变量 */
  
int main() 
{
    PTypeFun1 * pTypeAdd1 = add;        /* 函数类型    声明并初始化函数指针，加* */
    PTypeFun2   pTypeAdd2 = add;        /* 函数指针类型 声明并初始化函数指针 */
                     padd = add;        /* 函数名为函数入口地址 */
    printf("%d\n", pTypeAdd1(1, 2));
    printf("%d\n", pTypeAdd2(1, 2));
    printf("%d\n", padd(1, 2));
    return 0;
}
