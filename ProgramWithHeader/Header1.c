#include <stdio.h>
#include "abc.h"
int main()
{
    int a;
    printf("Enter a number\n");
    scanf("%d",&a);
    a=sq(a);
    printf("Square of the given number is %d",a);
    return 0;
}
