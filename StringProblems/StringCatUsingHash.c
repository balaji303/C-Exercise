#include <stdio.h>
#define A(B,C) B##C
int main()
{
    printf("%d",A(2,4));
    return 0;
}
