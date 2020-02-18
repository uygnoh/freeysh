#include<stdio.h>
int main(void)
{
	
	int a[6][3] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	int (*p)[3];
	
	p = a;
	int i,j;
	for (i=0;i<6;i++) {
		for (j=0;j<3;j++) {
			printf("%d,",p[i][j]);
		}
		printf("\n");
	}
	//printf("%d %d",&p[0][0],&p[0][1]);
	return 0;
}
