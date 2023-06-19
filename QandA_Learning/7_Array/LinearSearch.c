#include <stdio.h>
#include <stdint.h>

#define MAX_INDEX 10

int32_t LinearSearch( uint32_t array[], uint32_t value );

int main(void)
{
    //Initialization
    uint32_t inputArray[MAX_INDEX];
    uint32_t valueToSearch;
    int32_t indexOfValueReq;
    // Get Inputs
    for(int i = 0;i<MAX_INDEX;i++)
    {
        scanf("%d",&inputArray[i]);
    }
    scanf("%d",&valueToSearch);
    indexOfValueReq = LinearSearch( inputArray, valueToSearch );
    if (indexOfValueReq < 0)
    {
        printf("Value not found!");
    }
    else
    {
        printf("%d",indexOfValueReq);
    }
    return 0;
}

/**
 * @brief Search for value looping through a array
 * 
 * @param array 
 * @param value 
 * @return int32_t 
 */
int32_t LinearSearch( uint32_t array[], uint32_t value )
{
    for(int i=0; i< MAX_INDEX; i++)
    {
        if( value == array[i] )
        {
            //Value found
            return i;
        }
    }
    //Value not found
    return -1;
}