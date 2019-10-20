//Armstrong number
#include <stdio.h>
int main(){
    int input,temp,Armstrong=0,ip;
    printf("Enter a number\n");
    scanf("%d",&input);
    ip=input;
    while(input){
        temp=input%10;
        Armstrong=(temp*temp*temp)+Armstrong;
        input=input/10;
    }
    ip==Armstrong ? printf("Armstrong number") : printf("Not an Armstrong number");
    return 0;
}
