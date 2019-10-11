#include <stdio.h>
#include <string.h>
int str_cspn(char *a,char *b);
int main(){
    int e;
    char *p,*q,arr[50],brr[50];
    p=arr;
    q=brr;
    printf("Enter a string\n");
    scanf("%s",p);
    printf("Enter 2ed string\n");
    scanf("%s",q);
    e=str_cspn(p,q);
    printf("\n%d",e);
    return 0;
}
int str_cspn(char *a,char *b){
    int i,j;
    for(j=0;b[j];j++){
      for(i=0;a[i];i++){
            if(a[i]==b[j]){
                return (i+1);
             }
            else{}
      }
    }
}
