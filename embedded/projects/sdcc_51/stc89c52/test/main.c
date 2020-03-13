#include <8052.h>

void delay(int t)
{
    while (t--);
}

void main()
{
    while (1) {
        P0_0 = 0;
        delay(20000);
        P0_0 = 1;
        delay(20000);
    }
}
