/*
#include <stdio.h>
int main(void){
    int row,col,r,c,MaxCol,MaxRow;
    printf("Enter hte Max number of Rows and Column:\t");
    scanf("%d %d",&MaxRow,&MaxCol);
    printf("Enter the row and column to glow with:\t");
    scanf("%d %d",&row,&col);
    r=row;
    c=col;
    //printf("%d-%d\n",r,c);//Glow LED
    for(int i=r;i<=MaxRow;i++){//row count
        for (int j=c;j<=MaxCol;j++)//col count
        {
            if(j<=0){
                //Skip
            }
            else
            {
             printf("row=%d and col=%d\n",i,j);
            }
        }
        c--;
    }
    return 0;
}
*/