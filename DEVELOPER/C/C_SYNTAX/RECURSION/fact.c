/** N!=1x2x3x4...
  * 1, 基本条件({N=0,1} 1)
  * 2, 一般条件({N>=2} Nx(N-1)!)
  * A1,基本条件控制递归调用的结束
  * A2,一般条件控制递归调用向基本条件转化
  * 函数直接或间接调用自己，称为递归调用(Recursive Call)
  */
  
#include <stdio.h>
long fact(int n)
{
	if (n < 0)
		return -1;
	else if (n==0 || n==1)
		return 1;
	else
		return n * fact(n-1);
}
int main(void)
{
	printf("fact(3)=%d\n", fact(3));
	return 0;
}
