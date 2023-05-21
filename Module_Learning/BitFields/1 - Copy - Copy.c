#include <stdio.h>
 
// A structure without forced alignment
struct test1 {
    unsigned int x : 5;
    unsigned int y : 8;
};
 
// A structure with forced alignment
struct test2 {
    unsigned int x : 5;
    unsigned int : 0;
    unsigned int y : 8;
};
 
int main()
{
    printf("Size of test1 is %lu bytes\n",
           sizeof(struct test1));
    printf("Size of test2 is %lu bytes\n",
           sizeof(struct test2));
    return 0;
}