/*
Multiply a given number by 2 without using the multiplication operator
*/
#include <stdio.h>
int multiply(int input);
int main(void){
   int input,output;
   printf("Enter a number:");
   scanf("%d",&input);
	printf("%d",input);
   output=multiply(input);
   printf("%d",output);
   return 0;
}
int multiply(int input){
    int i;
    int j=input;   
	for (i = 1; i <= j; i++)
    {
        input=input+2;
    }
    return input;
}
