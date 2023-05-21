#include <stdio.h>
int main (void) {
   FILE *fptr;
   char word[100];
   fptr = fopen("file.txt", "w");
   gets(word);
   fputs("Hello World!\n", fptr);
   fputs("This is c programming language\n", fptr);
   fputs(word,fptr);
   fclose(fptr);
   return(0);
}
