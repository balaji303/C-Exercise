
#include <stdio.h>
void func(int a[][5]);
int main(void){
    int j,i,arr[2][5]={
                  {1,2,3,4,5},
                  {6,7,8,9,10}
                  };
    func(arr);
    for(i=0;i<2;i++){
        for(j=0;j<5;j++){
        printf("%d ",arr[i][j]);
     }
     printf("\n");
    }
    return 0;
}
void func(int a[][5]){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<5;j++){
        a[i][j]=a[i][j]+5;
        }
    }
}
