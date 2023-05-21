//Pointer to an aray
#include <stdio.h>
int main(){
    char b[3]={'x','y','z'};
    char (*p)[3]=b,c,i;
    c=b[0];
    printf("%p\n",&p);
    printf("%p\n",&p+1);
    printf("%p\n",&p+2);
    printf("%p\n",&b[1]);
    for(i=0;i<3;i++)
    {
        printf("%c\n",(*p)[i]); 
    }
    
    printf("%c\n",p);
    printf("%c",c);
    return 0;
}
