#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int str_compare(char *p1,char *p2);
int main(){
    int temp,i;
    char *pointer1,*pointer2;
    printf("Enter first string\n");
    pointer1=(char *)malloc(1*(sizeof(char)));
    pointer2=(char *)malloc(1*(sizeof(char)));
    scanf("%s",pointer1);
    pointer1=(char *)realloc(pointer1,1*sizeof(char)+1);
    printf("Enter second string\n");
    scanf("%s",pointer2);
    pointer2=(char *)realloc(pointer2,1*sizeof(char)+1);
    printf("%s\t%s",pointer1,pointer2);
    temp=str_compare(pointer1,pointer2);
    printf("\n%d",temp);
    free(pointer1);
    free(pointer2);
    return 0;
}
int str_compare(char *p1,char *p2){
    while(*p1==*p2){
        if(*p1=='\0'){
            return 0;
        }
        else{}
        p1++;
        p2++;
    }
    return (*p1-*p2);
}
