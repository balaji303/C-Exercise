#include <stdio.h>
int main(){
    int mat1[2][2]={1,2,3,4},mat2[2][2]={1,2,4,4},i,j,c=0;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {    
            if(mat1[i][j]!=mat2[i][j]){
                c=1;
            }
            else{
                c=c;
                }
        }
    }
    if(c==0)
    {printf("Indetical");
    }
    else{
        printf("Not Indetical");
    }
    return 0;
}
