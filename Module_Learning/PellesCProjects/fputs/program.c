/*#include <stdio.h>
int main(void){
 FILE *fptr;
 char str[80]; 
	int i=0;
	fptr=fopen("testfile.txt","w");
	printf("Enter data, to terminate press ctrl+D\n");
	while(getc(str[i])!= NULL){
       fputs(str,fptr);
		i++;
	}
	fclose(fptr);
    return 0;
}
*/
#include <stdio.h>

int main () {
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
