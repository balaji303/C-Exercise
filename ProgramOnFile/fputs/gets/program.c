/*#include <stdio.h>
int main(void){
 FILE *fptr;
 char str[80]; 
	if((fptr=fopen("testfile.txt","w"))==NULL){
        printf("Error in opening file\n");
		return(1);
	}
	printf("Enter data, to terminate press ctrl+D\n");
	while(gets(str)!= NULL){
       fputs(str,fptr);
	}
	fclose(fptr);
    return 0;
}
*/
#include <stdio.h>

int main () {
   FILE *fptr;
   //char word[20];
   fptr = fopen("file.txt", "w");
   //gets(word);
   fputs("Hello World!\n", fptr);
   fputs("This is c programming language", fptr);
   //fputs(word,fptr);
   fclose(fptr);
   
   return(0);
}
