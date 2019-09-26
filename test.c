#include <stdio.h>

int main()
{
    int i,j,n;
    printf("Hello World");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=n;j>0;j--){
            if(i==j)
            printf("");
        }
        printf("\n");
    }
    return 0;
}

