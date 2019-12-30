#include <stdio.h>


int main(int argc, const char *argv[]) 
{
    int i;
    for (i = 0; i < argc; i++) {
		printf("%d\n", i);
    }
	
	printf("%d\n", argc);
	printf("%s\n", argv[i-1]);
}













