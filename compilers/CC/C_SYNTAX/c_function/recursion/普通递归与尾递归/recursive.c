/*
1. 1		n=0,1
2. nx(n-1)!	n>=2
普通递归
A.递推阶段
	Fact(3)=3*Fact(2)
		Fact(2)=3*Fact(1)
			Fact(1)=1	终止条件
			========================
B.回归阶段		========================
		Fact(2)=2*1
	Fact)3)=3*2
返回结果：6
*/
unsigned long Fact(unsigned int n)
{
	if (n==0 || n==1)
		return 1;
	else
		return n * Fact(n-1);
}



/*
1. a		n=0,1
2. f(n-1, nxa)	n>=2
尾递归
A.递推阶段
	Fact(3, 1)=Fact(2, 3)
		Fact(2, 3)=Fact(1, 6)
			Fact(1, 6)=6	终止条件
			=======================
	Fact(3, 1) a=3*1=3
	Fact(2, 3) a=2*3=6
	Fact(1, 6) 终止条件

*/

unsigned long Fact(unsigned int n, unsigned int a)
{
	if (n==0 || n==1)
		return 1;
	else
		return Fact(n-1, n*a);
}


