#include <stdio.h>
int main(void){
    int a,b,c,d,e,f,g,h,led[31];
    a=30;
    b=30;
    c=30;
    d=30;
    for(int z=1;z<=a;z++){
        led[z]=0;
    }
    h=d;
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
            if(i==a){
                led[x]=1;
            }
            else{
                led[x]=0;
            }
        }
        printf("\n");
        h=h+1;
        
    }
    for(int z=1;z<=a;z++){//Glowing LED's of last column
        printf("LED %d = %d\n",z,led[z]);
    }
    return 0;
}