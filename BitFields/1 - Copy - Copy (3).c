#include <stdio.h>
struct test {
    unsigned int x : 5;
    unsigned int y : 5;
    unsigned int z;
};
int main()
{
    struct test t;
 
    // Uncommenting the following line will make
    // the program compile and run
    printf("Address of t.x is %p", &t.x);
 
    // The below line works fine as z is not a
    // bit field member
    printf("Address of t.z is %p", &t.z);
    return 0;
}