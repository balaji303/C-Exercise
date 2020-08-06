#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int str_n_cpy(char *p1,char *p2,int no);
int main(){
    int i,n;
    char *pointer1,*pointer2,*count;
    printf("Enter first string\n");
    pointer1=(char *)malloc(1*(sizeof(char)));
    pointer2=(char *)malloc(1*(sizeof(char)));
    scanf("%s",pointer1);
    pointer1=(char *)realloc(pointer1,1*sizeof(char)+1);
    printf("Enter second string\n");
    scanf("%s",pointer2);
    pointer2=(char *)realloc(pointer2,1*sizeof(char)+1);
    printf("Enter number of elements to be copied\n");
    scanf("%d",&n);
    pointer1=str_n_cpy(pointer1,pointer2,n);
    printf("\nString 1 =%s",pointer1);
    free(pointer1);
    free(pointer2);
    return 0;
}
int str_n_cpy(char *p1,char *p2,int no){
            for(int i=0;i<no;i++){
                p1[i]=p2[i];
            }
            p1[no]='\0';
    return p1;
}
