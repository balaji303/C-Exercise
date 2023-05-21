#include <stdio.h>
int main(){
    int row,column,arr[2][3]={{2,3,4},
                               {5,6,7}};
    printf("Printing array using index\n");
    for(row=0;row<2;row++){
        for(column=0;column<3;column++){
            printf("%d ",arr[row][column]);
        }
        printf("\n");
    }
    
    printf("Printing array using pointers\n");
    for(row=0;row<2;row++){
        for(column=0;column<3;column++){
            printf("%d ",*(*(arr+row)+column));        
        }
        printf("\n");
    }
    return 0;
}
