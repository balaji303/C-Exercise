#include <stdio.h>
void fun(int x,int y,int *ps,int *pd,int *pm);
int main(){
    int a,b,sum,diff,mul;
    printf("Enter value for a:");
    scanf("%d",&a);
    printf("Enter value for b:");
    scanf("%d",&b);
    fun(a,b,&sum,&diff,&mul);
    printf("Sum=%d\tDifference=%d\tMultiplication=%d",sum,diff,mul);
    return 0;
}
void fun(int x,int y,int *ps,int *pd,int *pm){
    *ps=x+y;
    *pd=x-y;
    *pm=x*y;
}
