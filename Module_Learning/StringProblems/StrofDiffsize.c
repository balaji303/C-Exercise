#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *pointer;
    printf("Enter a string\n");
    pointer=(char *)malloc(1*(sizeof(char)));
    scanf("%s",pointer);
    pointer=(char *)realloc(pointer,1*sizeof(char)+1);
    printf("\nThe string is %s",pointer);
    free(pointer);
    return 0;
}
