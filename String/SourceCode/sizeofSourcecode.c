#include <stdio.h>
void MYsizeof(int x);
int main(void){
    int a;
    MYsizeof(a);
    return 0;
}
void MYsizeof(int x){
    x=((char *)(&x+1)-(char *)(&x));
    printf("MYsizeof a =%d ",x);
}
