#include <stdio.h>
#include <stdlib.h>
int main(void){
 FILE *fsptr;
 FILE *fdptr;
// FILE *p;
 int ch;
 if((fsptr=fopen("source.txt","r"))==NULL){
 printf("Error in source\n");
 exit(1);
 }
 if((fdptr=fopen("desti.txt","w"))==NULL){
 printf("Error in destination\n");
 exit(1);
 }
 while((ch=fgetc(fsptr))!=EOF){
 fputc(ch,fdptr);
	}
 fclose(fdptr);
 printf("Destination file\n");
 if((fdptr=fopen("desti.txt","r"))==NULL){
 printf("Error in desti\n");
 exit(1);
 }
	while((ch=fgetc(fdptr))!=EOF){
	printf("%c",ch);
	}
	fclose(fsptr);
	fclose(fdptr);
	return 0;
}
