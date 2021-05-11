#include <stdio.h>

struct book {
    int a[2];
};

typedef struct book * ptrs;
int main()
{
    ptrs ptr;
    struct book k;
    ptr = &k;
    ptr->a[0] = 321;

    k.a[1] = 123;
    printf("%d\n", k.a[1]);
    printf("%d\n", ptr->a[0]);
	printf("Hello World.");
	return 0;
}
