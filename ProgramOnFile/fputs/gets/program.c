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
   FILE *fp;
   //char word[20];
   fp = fopen("file.txt", "w");
   //gets(word);
   fputs("This is c programming.", fp);
   fputs("This is a system programming language.", fp);
  // fputs(word,fp);
   fclose(fp);
   
   return(0);
}
