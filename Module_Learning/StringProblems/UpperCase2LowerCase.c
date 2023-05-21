//upper case to lower case
#include <stdio.h>
#include <string.h> 
int main(){
    char a[100],b[100];
    int i;
    printf("Enter string ");
    scanf("%s",a);
    for(i=0;i<strlen(a);i++){
        if(a[i]<91){
        b[i]=a[i]+32;
        }
        else{
            b[i]=a[i];
        }
    }
    printf("Lower case str\n");
    for(i=0;i<strlen(a);i++){
        printf("%c",b[i]);
    }
    return 0;
}
