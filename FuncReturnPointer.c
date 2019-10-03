#include <stdio.h>
int *fun(void);
int main(void){
    
    int *x;
    x=fun();
    printf("%d",*x);
    return 0;

    
}
int *fun(void){
    int a=5;
    int *ptr;
    ptr=&a;
    return ptr;

    
}
