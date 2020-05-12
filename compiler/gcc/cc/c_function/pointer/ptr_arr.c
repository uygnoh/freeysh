#include<stdio.h>
int main(void)
{

	//int a[3][6] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	int a[3][6] = {{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};

	int i, j;
	int *p[3];

	for (i = 0; i < 3; i++) {
	    p[i] = a[i];
		for (j = 0; j < 6; j++) {
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}

	printf("hello.world\n");

	return 0;

}
