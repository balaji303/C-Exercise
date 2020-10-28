#include <stdio.h>

void printArray(int arr[], int length){
        for(int i = 0; i < length; i++){
                printf("%d ", arr[i]);
        }
        
        printf("\n");
}

void main(){        
        int length = 10;
        int arr[length];
        
        for(int i = 0; i < length; i++){
            arr[i] = i;
        }
        
        printArray(arr, length);
}
