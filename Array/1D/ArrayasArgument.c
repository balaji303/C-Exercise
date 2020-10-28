#include <stdio.h>
void func(int a[]);
int main(void){
    int i,arr[5]={1,2,3,4,5};
    func(arr);
    for(i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
void func(int a[]){
    int i;
    for(i=0;i<5;i++){
        a[i]=a[i]+5;
    }
}
