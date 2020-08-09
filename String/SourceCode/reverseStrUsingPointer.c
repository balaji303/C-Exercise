#include <stdio.h>
#include <string.h>
int main(){
    char a[100],*p;
    int i;
    printf("Enter string\n");
    scanf("%[^\n]s",a);
    p=a;
    i=strlen(a);
    printf("Reverse string\n");
    while(i>=0){
        printf("%c",*(p+i));
        i--;
    }
    return 0;
}
