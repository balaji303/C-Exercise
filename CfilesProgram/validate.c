#include <stdlib.h>
#include <stdio.h>

int validate(const char *username)
{
    int firstletter,i=0,result1, result2;
    firstletter=*username;
    if((firstletter>65 && firstletter<90)||(firstletter>97 && firstletter<122)){
        result1=1;
    }
    while(*username!='\0'){
        if(*username+i==)
        {
            result2= 1;
        }
        i++;
    }
    if (result1&&result2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
    
}

#ifndef RunTests
int main()
{
    
    printf("%d\n", validate("Mike_Standish")); // Valid username
    printf("%d", validate("Mike Standish")); // Invalid username
}
#endif