#include <stdio.h>

int main() {
   int y = 28; // 11100
   int i = 0;

   for(i;i<=3;++i)
   printf("Left shift by %d: %d\n", i, y<<i);

   return 0;
}