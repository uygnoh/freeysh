/*
汉诺塔问题
	印度神话，上帝创造世界时制作了 3 根金钢石柱子，
	第一根上从下向上按大小顺序摞着 64片黄金圆盘，
	上帝命婆罗门把圆盘从下开始按大小顺序重新摆放在第 2根柱子上，
	规定每次只能移动 1个圆盘，在小圆盘上不能放大圆盘。
	
较为简单的形式： N==2
	1,将1号圆盘从A移动到C
	2,将2号圆盘从A移动到B
	3,将1号圆盘从C移动到B
	
数学归纳法：
A1,假设 N-1个圆盘的汉诺塔问题已经解决
A2,将上面“N-1个圆盘”看成一个整体
	1,将上面“N-1个圆盘”从A移动到C
	2,将 N号圆盘从A移动到B
	3,将上面“N-1个圆盘”C移动到B
移动N个圆盘的->移动N-1个圆盘



*/
#include <stdio.h>
void move(int n, char a, char b);
void hanoi(int n, char a, char b, char c);

//将 “N个圆盘”借助于C从A移动到B
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
		move(n, a, b);
	else
	{
		hanoi(n-1, a, c, b);
		move(n, a, b);
		hanoi(n-1, c, b, a);
	}
}

void move(int n, char a, char b)
{
	printf("move %d: from %c to from %c\n", n, a, b);
}

int main(void)
{
	int n;
	printf("Input the number of disks:");
	scanf("%d", &n);
	printf("Steps of moving %d disks form A to B by means of C:\n", n);
	hanoi(n, 'A', 'B', 'C');
}
