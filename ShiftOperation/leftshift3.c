#include<stdio.h>
int main()
{ 
int i = 3; 
printf("pow(2, %d) = %d\n", i, 1 << i);
i = 4; 
printf("pow(2, %d) = %d\n", i, 1 << i);
return 0;
}

