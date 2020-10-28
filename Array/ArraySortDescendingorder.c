#include <stdio.h>
int main(){
    int i,j,arr[1000],size,temp;
    printf("Enter the size of Array:\n");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size;i++){
        for(j=(i+1);j<size;j++){
            if(arr[i]>arr[j]){
                
            }
            else{
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    printf("Array in descending order\n");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
