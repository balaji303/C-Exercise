#include <stdio.h>

int main(void)
{
int a=0x10;
int b=10;
printf("The value of a =%x\n",a);
printf("The value of b =%d\n",b);
a=a>>1;
b=b>>1;
printf("The value of a =%x\n",a);
printf("The value of b =%d",b);
return 0;
}