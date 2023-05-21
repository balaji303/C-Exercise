#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int str_cat(char *p1,char *p2,int no);
int main(){
    int n;
    char *pointer1,*pointer2,(*temp)[100];
    printf("Enter first string\n");
    pointer1=(char *)malloc(10*(sizeof(char)));
    pointer2=(char *)malloc(1*(sizeof(char)));
    scanf("%s",pointer1);
    pointer1=(char *)realloc(pointer1,10*sizeof(char)+1);
    printf("Enter second string\n");
    scanf("%s",pointer2);
    pointer2=(char *)realloc(pointer2,1*sizeof(char)+1);
    printf("Enter number of element to be concatenat\n");
    scanf("%d",&n);
    pointer1=str_cat(pointer1,pointer2,n);
    printf("%s",pointer1);
    free(pointer1);
    free(pointer2);
    return 0;
}
int str_cat(char *p1,char *p2,int no){
    int i=0,j=0;
    while(p1[i]!='\0'){
        i++;
    }
    while(no){
        p1[i]=p2[j];
        i++;
        j++;
        no--;
    }
    return p1;
}
