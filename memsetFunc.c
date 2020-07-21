/*
memset function
output:
This Hello
*his Hello
*/
#include <stdio.h>
#include <string.h>
int main(){
    char val[10]="This Hello";
    printf("%s",val);
    memset(val,'*',sizeof(val[10]));
    printf("\n%s",val);
    return 0;
}
