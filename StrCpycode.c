#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int str_cpy(char *p1,char *p2);
int main(){
    int count,i;
    char *pointer1,*pointer2;
    printf("Enter first string\n");
    pointer1=(char *)malloc(1*(sizeof(char)));
    pointer2=(char *)malloc(1*(sizeof(char)));
    scanf("%s",pointer1);
    pointer1=(char *)realloc(pointer1,1*sizeof(char)+1);
    printf("Enter second string\n");
    scanf("%s",pointer2);
    pointer2=(char *)realloc(pointer2,1*sizeof(char)+1);
    count=str_cpy(pointer1,pointer2);
    printf("\nString 1 =%s",pointer1);
    free(pointer1);
    free(pointer2);
    return 0;
}
int str_cpy(char *p1,char *p2){
            for(int i=0;p1[i]!='\0'||p2[i]!='\0';i++){
                p1[i]=p2[i];
            }
    return p1;
}
