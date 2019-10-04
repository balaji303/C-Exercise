#include <stdio.h>

#include <stdlib.h>

int main(){

    int (*a)[4],column,j,i;

    printf("Enter column\n");

    scanf("%d",&column);

     a=malloc(column*sizeof(column));

     for(i=0;i<column;i++){

         for(j=0;j<4;j++){

             printf("row -%d column-%d\n",i,j);

             scanf("%d",&a[i][j]);

         }

     }

     for(i=0;i<column;i++){

         for(j=0;j<4;j++){

            //  printf("row -%d column-%d ",i,j);

             printf("%d",a[i][j]);

         }

         printf("\n");

     }
     free(a);

    return 0;

}
