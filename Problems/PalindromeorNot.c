//Palindrome or Not
#include <stdio.h>
int main(){
    int i, input,rem,ip,op=0;
    printf("Enter the input\n");
    scanf("%d",&input);
    ip=input;
    while(input){
        rem=input%10;
        op=(rem+op)*10;
        input=input/10;
    }
    op=op/10;
    op==ip ? printf("Palindrome\n") : printf("Not a Palindrome");
    return 0;
}
