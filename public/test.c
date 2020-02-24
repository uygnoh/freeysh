#include <stdio.h>
#include <stdlib.h>

int main(int argc, int **argv)
{
    printf("hello,world\n");
    printf("%s\n", *argv);
    return 0;
}
