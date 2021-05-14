//words in str
#include <stdio.h>
#include <string.h>
int main(){
    int i,l,count=0;;
    char a[100];
    printf("Enter a string\n");
    scanf("%[^\n]s",a);
    l=strlen(a);
    for(i=0;i<=l;i++){
        if(a[i]==' ' || a[i]=='\0'){count++;}
        else{}
    }
    printf("Number of words in a string = %d",count);
    return 0;
}
