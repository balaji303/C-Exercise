#include <stdio.h>
#include <string.h>
int str_spn(char *a,char *b);
int main(){
    int e;
    char *p,*q,arr[50],brr[50];
    p=arr;
    q=brr;
    printf("ENter a string\n");
    scanf("%s",p);
    printf("Enter 2ed string\n");
    scanf("%s",q);
    e=str_spn(p,q);
    printf("\n%d",e);
    return 0;
}
int str_spn(char *a,char *b){
    int i;
    for(i=0;a[i];i++){
            if(a[i]==b[i]){}
            else{
                return i;
            }
    }
}
