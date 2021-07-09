//Fibonacci series till Input number
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,i=0,temp1=1,temp2=0;
    printf("ENter a number\n");
    scanf("%d",&a);
    printf("%d %d ",i ,temp1);
    while(a){
        temp2=i+temp1;
        i=temp1;
        temp1=temp2;
        temp2<a ? printf("%d ",temp2): exit(1);
    }
    return 0;
}
