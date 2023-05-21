
#include <stdio.h>
void MaxPrint(int row, int MaxRow, int col,int MaxCol);
int main(void){
    int row,col,r,c,co,MaxCol,MaxRow;
    printf("Enter the Max number of Rows and Column:\t");
    scanf("%d %d",&MaxRow,&MaxCol);
    printf("Enter the row and column to glow with:\t");
    scanf("%d %d",&row,&col);
    r=row;
    c=col;
    co=col;
    if(row<=MaxRow && col<=MaxCol){
    printf("row=%d and col=%d\n",r,c);
    for(int i=(r+1);i<=MaxRow;i++){
        for (int j = --c; j<=(co+1); j++)
        {

            if(i==j){
                MaxPrint(i,MaxRow,j,MaxCol);
            }
            else if(j>=1){
            printf("row=%d and col=%d\n",i,j);
            }
            else
            {
                //Do nothing
            }
        }   
    }
   }//End of if
   else
   {
       printf("Row and Column exicts Max. Row and Max.Col\n");
   }
    return 0;
}
void MaxPrint(int row, int MaxRow, int col,int MaxCol){
    for (int i = row,j=col; i <=MaxRow && j<=MaxCol; i++,j++)
    {
        printf("row = %d and col = %d\n",i,j);
    }
}