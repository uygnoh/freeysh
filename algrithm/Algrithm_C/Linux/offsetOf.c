#include <stdio.h>
#ifndef container_of
#define container_of(ptr, type, member) ({ \
    const typeof(((type*)0)->member)* __mptr = (ptr); \
    (type*)((char*)__mptr - offsetof(type, member)); })
#endif


//offset用于计算TYPE结构体中MEMBER成员的偏移位置
//这里利用编译器此时不会访问0地址处的，这里它只做了个加法
#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE*)0)->MEMBER)
#endif


struct ST {
    int i;  //0
    int j;  //4
    char c; //8
};


//({})是GNU C编译器语法的扩展
//与逗号表达式类似，结果为最后一个语句的值
void method()
{
    int a = 0;
    int b = 0;
    int r = (
        a = 1,
        b = 2,
        a + b
    );
    //和下面语句相同
    int x = ({
        int y = 1;
        int z = 2;
        y + z;
    });
}


//typeof是GNU—C编译器的特有关键字
//typeof只在编译期生效，用于得到变量的类型
void gnu_c()
{
    int i = 100;
    typeof(i) j = i;            //int j = i;
    const typeof(i)* p = &j;    //const int *p = &j;
    printf("sizeof(j) = %d\n", sizeof(j));
    printf("j = %d\n", j);
    printf("*p = %d\n", *p);
}





void func(struct ST *pst)
{
    int *pi = &(pst->i);
    int *pj = &(pst->j);
    char *pc = &(pst->c);
    printf("pst = %p\n", pst);
    printf("pi = %p\n", pi);
    printf("pj = %p\n", pj);
    printf("pc = %p\n", pc);
}

int main()
{
    struct ST s = {0};
    func(&s);
    func(NULL);
    
    printf("offset i: %d\n", offsetof(struct ST, i));
    printf("offset j: %d\n", offsetof(struct ST, j));
    printf("offset c: %d\n", offsetof(struct ST, c));
}




