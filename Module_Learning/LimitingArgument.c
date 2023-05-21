//Limiting a argument send to a function
#include <stdio.h>
int add(int num);
int main()
{
    int a;
    printf("Hello World");
    a=add(2); //Adds number till 8 then becomes 1
    printf("\n%d",a);
    return 0;
}
int add(int num){
    num %= 9;
    num=num+1;
    return num;
}
/*
add(1)=2
add(2)=3
add(3)=4
add(4)=5
add(5)=6
add(6)=7
add(7)=8
add(8)=9
add(9)=1
*/
