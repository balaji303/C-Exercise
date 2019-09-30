#include <stdio.h>
int main(){
    int row,column,which_2d_array,arr[2][2][3]={ //two 2D array with 2 rows, 3columns
                                         {
                                         {2,3,4},
                                         {5,6,7}
                                         },
                                         { 
                                         {12,13,14},
                                         {15,16,17}
                                         }
                                          };
    printf("Printing array using index\n");
    for(which_2d_array=0;which_2d_array<2;which_2d_array++){
        for(row=0;row<2;row++){
            for(column=0;column<3;column++){
            printf("%d ",arr[which_2d_array][row][column]);
            }
        printf("\n");    
        }
        printf("\n");
    }
    printf("Printing array using pointers\n");
    for(which_2d_array=0;which_2d_array<2;which_2d_array++){
    for(row=0;row<2;row++){
        for(column=0;column<3;column++){
            printf("%d ",*(*(*(arr+which_2d_array)+row)+column));        
        }
        printf("\n");
      }
    printf("\n");
    }
    return 0;
}
