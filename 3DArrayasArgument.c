#include <stdio.h>
void func(int a[2][2][5]);
int main(void){
    int k,j,i,arr[2][2][5]={
                  {{1,2,3,4,5},
                   {6,7,8,9,10}},
                  {{2,4,6,8,10},
                   {1,3,5,7,9}}
                  };
    func(arr);
    for(k=0;k<2;k++){
     for(i=0;i<2;i++){
        for(j=0;j<5;j++){
        printf("%d ",arr[k][i][j]);
      }
     printf("\n");
     }
    }
    return 0;
}
void func(int a[2][2][5]){
    int i,j,k;
    for(k=0;k<2;k++){
     for(i=0;i<2;i++){
        for(j=0;j<5;j++){
        a[k][i][j]=a[k][i][j]+5;
        }
      }
    }
}
