#include <stdio.h>
#include <string.h>

int main (void) {
   const char src[50] = "123456789";
   char dest[50];
   strcpy(dest,"abcdef");
   printf("Before memcpy src = %s\n", src);
   printf("Before memcpy dest = %s\n", dest);
   memcpy(dest, src, 3);
   printf("After memcpy src = %s\n", src);
   printf("After memcpy dest = %s\n", dest);
   return(0);
}


/******
Before memcpy src = 123456789
Before memcpy dest = abcdef
After memcpy src = 123456789
After memcpy dest = 123def
*******/