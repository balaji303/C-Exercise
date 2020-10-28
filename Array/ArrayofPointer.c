#include <stdio.h>
int main(void){
    int *pa[3];
    int i,a=2,b=3,c=4;
    pa[0]=&a;
    pa[1]=&b;
    pa[2]=&c;
    for(i=0;i<3;i++){
    printf("pa[%d]=%d\n",i,*pa[i]);
    }
    return 0;
}
