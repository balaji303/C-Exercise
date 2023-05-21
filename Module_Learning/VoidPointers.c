#include <stdio.h>
int main(){
    void *vp;
    int a=3;
    float b=1.2;
    char c='h';
    vp=&a;
    printf("int format-%d \n",*(int*)vp);
    vp=&b;
    printf("float format-%.2f \n",*(float *)vp); //%.2f prints only 2 digits after decimal point
    vp=&c;
    printf("char format-%c \n",*(char *)vp);
    return 0;
}
