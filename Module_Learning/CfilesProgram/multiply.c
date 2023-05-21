/*
Multiply a given number by 2 without using the multiplication operator
*/
#include <stdio.h>
int multiply(int num);
int main(void){
   int input,output;
   //printf("Enter a number:");
   //scanf("%d",&input);
   output=multiply(2);
   printf("%d",output);
   return 0;
}
int multiply(int num){
    for (int i = 1; i <= num; i++)
    {
        num=num+2;
        printf("%d",num);
    }
    return num;
}