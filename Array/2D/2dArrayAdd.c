#include <stdio.h>
int arr[1000][1000],row,column,i,j,row_add,column_add,sum_row=0,sum_column=0,control=6;
int fun_sum_column(void);
int fun_sum_row(void);
int main(){
    printf("Enter number of rows:\n");
    scanf("%d",&row);
    printf("Enter number of columns:\n");
    scanf("%d",&column);
    printf("Enter 2D Array:\n");
    for(i=1;i<=row;i++){
        for(j=1;j<=column;j++){
           printf("\nrow:%d column:%d ",i,j); 
            scanf("%d",&arr[i][j]); 
        }
    }
        for(i=1;i<=row;i++){
        for(j=1;j<=column;j++){
           printf("\nrow:%d column:%d --",i,j); 
           printf("%d",arr[i][j]); 
        }
    }
    while(control>=4 || control <=0){
    printf("\nPlease Enter one:\n 1.Row addition\n 2.Column addition\n 3.Both Row and Column addition\n");
    scanf("%d",&control);
    if(control==2){
        fun_sum_column();
        }
    else if(control==1 || control==3){
        fun_sum_row();
        if(control==3){
        fun_sum_column();
        }
        else{}
    }
    else{
        printf("\nRead the above details carefully and Enter again!");
    }
    }
    return 0;
}
int fun_sum_column(void){
    printf("\nEnter the column you need to add:\n");
    scanf("%d",&column_add);
    for(i=1;i<=row;i++){
        j=column_add;
        sum_column=sum_column+arr[i][j];
    }
    printf("\nThe sum of column=%d",sum_column);
}
int fun_sum_row(void){
    printf("\nEnter the row you need to add:\n");
    scanf("%d",&row_add);
    for(j=1;j<=column;j++){
        i=row_add;
        sum_row=sum_row+arr[i][j];
    }
    printf("\nThe sum of row is=%d",sum_row);
}
