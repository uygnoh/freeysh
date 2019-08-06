/*
写程序实现一个函数PrintN, 
使得传入一个正整数为N的参数后， 
能顺序打印从1到N的全部正整数。
*/

#include <stdio.h>
//循环实现
void printN(int N)
{
    int i;
    for (i=1; i<=N; i++) 
        printf("%d\n", i);
}

//递归实现
void printN1(int N)
{
    if (N) {
        printN(N - 1);
        printf("%d\n", N);
    }
    return;
}


int main(int argc, char *argv[])
{
	printN(100000);
	return 0;
}
