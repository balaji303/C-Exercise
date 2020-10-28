//Array of pointer
#include <stdio.h>
int main(){
    char b[2]={'x','y;};
    char *p[1];
    p[0]=&b[0];
    printf("%p\n",p[0]); //address of x
    printf("%p\n",&p[0]);
    printf("%p\n",&p[0]+1);
    printf("%p\n",&b[1]);
    printf("%c\n",b[1]);
    printf("%c",*(p[0]+1));
    return 0;
}
