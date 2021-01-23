#include <stdio.h>
int main(void){
    int a,b,c,d,e,f,g,h;
    a=30;
    b=30;
    printf("Enter the row and column to start with:\t");
    scanf("%d %d",&c,&d);
    h=d;//
    e=d-1;
    for(int i=c;i<=a;i++){
        for(f=1;f<=e;f++){
            printf(" ");
        }
        e--;
        g=f;//while exiting for loop spacebegin will be same as starbegin
        if (h>=b)
        {
            h=b;
        }
        for(int x=g;x<=h;x++){
            printf("*");
        }
        printf("\n");
        h=h+1;
        
    }
    return 0;
}