#include <stdio.h>

void select_sort(int *ptr, int len) {
	int i, j, k, tmp;
	for (i = 0; i < len-1; i++) {
		k = i;
		for (j = i+1; j < len; j++) {
			if (ptr[j] < ptr[k])
				k = j;
		}
		if (k != i) {
			tmp = ptr[i];
			ptr[i] = ptr[k];
			ptr[k] = tmp;
		}
	}
}

int main(void) {
	int i;
	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	select_sort(a, 10);
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
