/*
斐波那契数列,1 1 2 3 5 8 13 21...
f(1)=f(2)=1
f(n)=f(n-1)+f(n-2)
*/

#include <stdio.h>
int fibo(int n)
{
	if (n <= 0)
		return -1;
	else if (n==1 || n==2)
		return 1;
	else
		return fibo(n-1)+fibo(n-2);
}
int main(void)
{
	printf("%d\n", fibo(5));
	return 0;
}
