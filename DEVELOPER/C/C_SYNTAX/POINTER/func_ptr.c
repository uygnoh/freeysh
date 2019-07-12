#include <stdio.h>

int max(int x, int y) {
    return (x>y?x:y);
}

int min(int x, int y) {
    return (x<y?x:y);
}

int add(int x, int y) {
    return (x+y);
}


void pb_fun(int(*fun_ptr)(int,int),int m, int n) {
    int result;
    result = (*fun_ptr)(m,n);     
    printf("result=%d\n",result);
}


int main(void) {

    int x,y;
    scanf("%d%d",&x,&y);
    pb_fun(max, x, y);
    pb_fun(min, x, y);
    pb_fun(add, x, y);
    return 0;
    
}



