//Factorial of a given number
#include <stdio.h>
int rec(int a);
int main(){
    int ip,op;
    printf("Enter a number\n");
    scanf("%d",&ip);
    op=rec(ip);
    printf("The factorial of a given number is %d",op);
    return 0;
}
int rec(int a){
    if(a==1){ return 1; }
    else{
      return (a*rec(a-1));
    }
}
