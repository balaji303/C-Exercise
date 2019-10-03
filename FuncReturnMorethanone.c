#include <stdio.h>
int func_return_more_value(int a,int b, int *add,int *sub, int *mul);
int main()
{
    int x=3,y=2,sum,pro,diff;
    func_return_more_value(x,y,&sum,&diff,&pro);
    printf("Sum=%d Diff= %d mul=%d",sum,diff,pro);
    return 0;
}
int func_return_more_value(int a,int b, int *add,int *sub, int *mul){
    *add=a+b;
    *sub=a-b;
    *mul=a*b;
}
