#include <stdio.h>
#include <limits.h>
int main(void){
    int a=4000000000;
    unsigned int b=4000000000;
    printf("The value of a: %d\n",a);
    printf("The value of b: %d\n",b);
    printf("The limit of a: %d to %d\n",INT_MIN,__INT_MAX__);
    printf("The limit of b:%d to %d",INT_MIN,UINT_MAX);
    return 0;
}