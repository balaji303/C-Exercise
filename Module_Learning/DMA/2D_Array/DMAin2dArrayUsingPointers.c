#include <stdio.h>
#include <stdlib.h>
int main(){
    int (*a)[4],row,j,i;
    printf("Enter row\n");
    scanf("%d",&row);
     a=malloc(row*sizeof(row));
     for(i=0;i<row;i++){
         for(j=0;j<4;j++){
             printf("row -%d column-%d\n",i,j);
             scanf("%d",&a[i][j]);
         }
     }
     for(i=0;i<row;i++){
         for(j=0;j<4;j++){
            //  printf("row -%d column-%d ",i,j);
             printf("%d",a[i][j]);
         }
         printf("\n");
     }
    return 0;
}
