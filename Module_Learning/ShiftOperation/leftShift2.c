
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