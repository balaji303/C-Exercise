#include <stdio.h>

int main (void) {
   FILE *fptr;
   fptr = fopen("file.txt", "w");
   fputs("Hello World!\n", fptr);
   fputs("This is c programming language", fptr);
   fclose(fptr);
   return(0);
}
