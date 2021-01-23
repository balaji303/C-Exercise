#include <stdlib.h>
#include <stdio.h>

int minimal_number_of_packages(int items, int available_large_packages, int available_small_packages)
{
    int large_holds,max_large_hold;
    large_holds=5;
    if(max_large_hold=items/available_large_packages){
    return max_large_hold;    
    }
    else{
        return -1;
    }
    
}

#ifndef RunTests
int main()
{
    
    printf("%d", minimal_number_of_packages(16, 0, 1));
}
#endif