#include <mcs51/8052.h>

void delay(int t)
{
    while (t--);
}

void main()
{
    while (1) {
        P1_0 = 0;
        delay(20000);
        P1_0 = 1;
        delay(20000);
    }
}
