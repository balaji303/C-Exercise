#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int str_len(char *p);
int main(){
    int count,i;
    char *pointer;
    printf("Enter a string\n");
    pointer=(char *)malloc(1*(sizeof(char)));
    scanf("%s",pointer);
    pointer=(char *)realloc(pointer,1*sizeof(char)+1);
    count=str_len(pointer);
    printf("\nstring length =%d",count);
    free(pointer);
    return 0;
}
int str_len(char *p){
    int i=0;
    while(p[i]!='\0'){
        i++;
    }
    return i;
}
