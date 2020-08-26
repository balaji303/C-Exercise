/*Printing a para*/
#include <stdio.h>
#include <string.h>
int main(void){
char str1[100];
printf("Enter a string(Press Enter to terminate)\n");
scanf("%[^\n]s",str1);
	printf("%s",str1);
return 0;
}
