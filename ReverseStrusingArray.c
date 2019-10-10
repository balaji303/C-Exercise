#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    int i;
    printf("Enter string\n");
    scanf("%[^\n]s",a);
    i=strlen(a);
    printf("Reverse string\n");
    while(i>=0){
        printf("%c",a[i]);
        i--;
    }
    return 0;
}
