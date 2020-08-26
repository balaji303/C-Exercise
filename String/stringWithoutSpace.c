/*Printing a para without Space*/
#include <stdio.h>
#include <string.h>
int main(void){
char str1[100];
int size;
char space=32;
printf("Enter a string(Press tab to terminate)\n");
scanf("%[^\t]s",str1);
size=strlen(str1);
for(int i=0;i<=size;i++){
       if(str1[i]==space){
             continue;
		}
        else{
            printf("%c",str1[i]);
		}

}
return 0;
}
