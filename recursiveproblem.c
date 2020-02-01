/*
Try this program,
Print square of a number using a recursive function and not using multiplication operation.
*/
#include <stdio.h>
int recursion(int sum,int count,int x);
int main()
{
    int input,c,output,xval;
    printf("Enter a number:\n");
    scanf("%d",&input);
    c=input;
    xval=input-1;
    output=recursion(input,c,xval);
    printf("Answer = %d",output);
    return 0;
}
int recursion(int sum,int count, int x){
    if(count==0){
        return sum;
    }
    else{
        sum=sum+x;
        printf("%d\n",sum);
        count--;
        recursion(sum,count,x);
    }
}

/*
Enter a number:
3
5
7
9
Answer = 9
*/
