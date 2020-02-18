#include <stdio.h>
#include <stdlib.h>

int main(int argc, int *argv[])
{
    int i;
    for (i = 0; i < argc; i++) {
        printf("ARGC===>%d  ARGV===>%s\n", i+1,  argv[i]);
    }
    printf("hello, world\n");
    return 0;
}
