#include <stdio.h>
#include <string.h>
int str_tok(char *a,char *b);
int main(){
    char *e;
    char *p,*q,crr[50],arr[50],brr[50];
    p=arr;
    q=brr;
    e=crr;
    printf("ENter a string\n");
    scanf("%s",p);
    printf("Enter 2ed string\n");
    scanf("%s",q);
    e=str_tok(p,q);
    printf("\n%s",e);
    return 0;
}
int str_tok(char *a,char *b){
    int i,j,g=32;
    for(i=0;a[i];i++){
        for(j=0;b[j];j++){
            if(a[i]==b[j]){
                a[i]=(char *)g;
            }
            else{}
        }
    }
    return a;
}
