//Perfect number or not
#include <stdio.h>
int main(){
    int input,rem,add=0,ip;
    printf("ENter a number\n");
    scanf("%d",&input);
    ip=input;
    while(input){
        rem=input%10;
        input=input/10;
        add=rem+add;
    }
    add==ip ? printf("Perfect number") : printf("Not a Perfect number");
    return 0;
}
