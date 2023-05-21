//reverse a number
#include <stdio.h>
int main(){
    int i, input,rem,op=0;
    printf("Enter the input\n");
    scanf("%d",&input);
    while(input){
        rem=input%10;
        op=(rem+op)*10;
        input=input/10;
    }
    printf("%d",op/10);
    return 0;
}
