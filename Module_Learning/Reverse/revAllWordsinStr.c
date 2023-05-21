#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    int i,j,len,temp=0;
    printf("Enter string\n");
    scanf("%[^\n]s",a);
    len=strlen(a);
    printf("The reverse string is:\n");
    for(i=0;i<=len;i++){
        if(a[i]==' '||a[i]=='\0'){
            for(j=(i-1);temp>0;j--,temp--){
                 if(temp==1){
                 printf("%c",a[j]);
                 printf(" ");
                 }
                 else{
                 printf("%c",a[j]);
                 }
            }
        }
        else{
            temp++;
        }
    }
    return 0;
}
