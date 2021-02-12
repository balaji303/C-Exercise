#include <stdio.h>

int main() {
   int y = 28; // 11100
   int i = 0;

   for(i;i<=3;++i)
   printf("Left shift by %d: %d\n", i, y<<i);

   return 0;
}

#include <stdio.h>
int main()
{
	int x = 19;
	unsigned long long y = 19;
	printf("x << 1 = %d\n", x << 1);
	printf("x >> 1 = %d\n", x >> 1);
	// shift y by 61 bits left
	printf("y << 61 = %lld\n", y << 61);
	return 0;
}

#include<stdio.h>
int main()
{ 
int i = 3; 
printf("pow(2, %d) = %d\n", i, 1 << i);
i = 4; 
printf("pow(2, %d) = %d\n", i, 1 << i);
return 0;
}

