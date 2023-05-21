#include <stdio.h>
int main (void) {
   FILE *fptr;
   char word[20];
   fptr = fopen("file.txt", "w");
   printf("Enter string(To terminate press Tab followed by Enter):\n");
   scanf("%[^\t]s",word);
   fputs("Hello World!\n", fptr);
   fputs("This is c programming language\n", fptr);
   fputs(word,fptr);
   fclose(fptr);
   return(0);
}
