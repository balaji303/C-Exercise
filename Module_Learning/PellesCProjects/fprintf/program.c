#include <stdio.h>
int main(void){
   FILE *fp;
	char name[100];
	int age;
	int c;
    fp=fopen("file.txt","w+");
	printf("Enter the name:\n");
	scanf(" %s",name);
	printf("Enter age:\n");
	scanf("%d",&age);
    fprintf(fp,"My name is%s and my age is %d",name,age);
    fclose(fp);
	fp=fopen("file.txt","r");
	while(c=fgetc(fp)!=EOF){
     printf("%d",c);
	}
	fclose(fp);
	return 0;
}
