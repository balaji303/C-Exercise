#include <stdio.h>
int main(){
    int arr[5]={5,6,7,8,9},i,*pa;
    pa=arr;
    for(i=0;i<5;i++){
    printf("Value of arr[%d]=%d\n",i,*(pa+i));
    printf("Address of arr[%d]=%p\n",i,pa+i);
    }
    return 0;
}
