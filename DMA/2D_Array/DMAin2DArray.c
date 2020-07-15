#include <stdio.h>
#include <stdlib.h>
int main(){
    int **a,i,row,column,j;
    printf("ENter row and column\n");
    scanf("%d %d",&row,&column);
    a=malloc(row*sizeof(int));
    for(i=0;i<row;i++){
        a[i]=malloc(column*sizeof(int));
    }
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            printf("row:%d column:%d-",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            // printf("row:%d column:%d",row,column);
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    free(a);
    return 0;
}
