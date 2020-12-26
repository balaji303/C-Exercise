#include <stdio.h>
int main(){
    int mat[10][10];
    int i,j,row,col,dig1=0,dig2=0;
    printf("Enter the number of rows and column\n");
    scanf("%d",&row);
    col=row;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("\nEnter element for row-%d column-%d --",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
    for(i=0;i<row;i++){
        dig1=dig1+mat[i][i];
        dig2=dig2+mat[i][row-i-1];
    }
    printf("\nFirst diagonal sum=%d",dig1);
    printf("\nSecond diagonal sum=%d",dig2);
    return 0;
}
