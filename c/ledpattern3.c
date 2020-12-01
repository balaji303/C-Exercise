#include <stdio.h>
int main(void){
   int row;
   printf("Enter the no. of row:\t");
   scanf("%d",&row);
   for(int i=1;i<=row;i++){ //number of row
        for(int j=i;j<=(row-1);j++){ //number of space
           printf(" ");
        }
        for(int j=1;j<=2*i-1;j++){//number of LED's to glow
           printf("*"); 
        }
        printf("\n"); //Enter next line
   }
   return 0;
}