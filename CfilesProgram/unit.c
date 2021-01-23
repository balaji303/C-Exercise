#include <stdio.h>
#include <stdlib.h>

int symbolic_to_octal(const char *perm_string)
{
     int firstvalue;
     char first=*perm_string+0;
     char second=*(perm_string+1);
     char third=*(perm_string+2);
     if(first=='r'){
         firstvalue=4;
     }
     if(first=='w'){
         firstvalue=2;
     }
     if(first=='x'){
         firstvalue=1;
     }
     if(first=='-'){
         firstvalue=0;
     }
     return first;
}

#ifndef RunTests
int main()
{
    // Should write 752
    printf("%d", symbolic_to_octal("rwxr-x-w-"));
}
#endif