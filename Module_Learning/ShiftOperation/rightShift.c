#include <stdio.h>

int main() {
   int x = 10; // 1010
   int i = 0;

   for(i;i<2;i++){
   printf("Right shift by %d: %d\n", i, x>>i);
   }
   return 0;
}
