#include <stdio.h>
#include <string.h>
int main(){
    int i,len;
    char a[100];
    printf("Enter\n");
    scanf("%[^\n]s",a);
    len=strlen(a);
    for(i=0;i<len;i++){
        if(i%2!=0||a[i]=='\0'){
            printf("%c%c",a[i],a[i-1]);
        }
       else{}
    }
    return 0;
}
