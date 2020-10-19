#include <stdio.h>

void modify_var(int *ptr){
    *ptr = 1337;
}

int main()
{
    int num = 7;
    
    modify_var(&num);
    
    printf("%d\n", num);
}
