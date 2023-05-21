#include <stdio.h>
#define A 1
#ifdef A 
    #define B 1
#endif
#if A>0
    #define C 2
#endif
int main(void){
printf("%d\n%d",B,C);
return 0;
}
/*
#include <stdio.h>
#define A 0
#ifdef A 
    #define B 1
#endif
#if A>0
    #define C 2
#endif
int main(void){
printf("%d\n",B);
return 0;
}
*/
