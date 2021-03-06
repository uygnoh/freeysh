#include "./stm8s.h"
#define __nop() __asm nop __endasm

void delay() 
{
    unsigned int a, b;
    for (a = 1000; a > 0; a--) 
    {   
        for (b = 200; b > 0; b--) 
        {
            __nop();
        }
    }
}



int main() 
{
    while (1) 
    {

    }
}



