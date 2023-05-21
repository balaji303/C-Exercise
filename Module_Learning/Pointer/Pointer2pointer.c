#include <stdio.h>
int main(){
    int a=5,*p,**pi;
    p=&a;
    pi=&p;
    printf("Value of    a= %d %d %d\n",a,*p,**pi);
    printf("Address of  a= %p %p %p\n",&a,p,*pi);
    printf("Value of    p= %d %d %d\n",&a, p, *pi);
    printf("Address of  p=    %p %p\n",&p,pi);
    printf("Value of   pi=       %p\n",pi);
    printf("Address of pi=       %p\n",&pi);
    return 0;
}
