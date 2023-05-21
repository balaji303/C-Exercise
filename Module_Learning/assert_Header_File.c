#include <assert.h>
#include <stdio.h>
int main () {
   int a;
   char str[50];
	 
   printf("Enter an integer value: ");
   scanf("%d", &a);
   assert(a >= 10);
   printf("Integer entered is %d\n", a);
    
   printf("Enter string: ");
   scanf("%s", str);
   assert(str != NULL);
   printf("String entered is: %s\n", str);
	
   return(0);
}


/*
OUTPUT
3
ASSERT FAILED
*/