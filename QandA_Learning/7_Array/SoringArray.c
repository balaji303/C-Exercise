/**
 * @file SoringArray.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Sorting the array
 * @version 1
 * @date 23-06-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_INDEX 10


void Sorting_Array_Ascending(uint32_t originalArray[0]);
void Sorting_Array_Descending(uint32_t originalArray[0]);

int main(void)
{
    // Declare the array
    uint32_t arr[MAX_INDEX] = {1,2,99,4,5,6,7,88,3,0};
    //Sort in ascending order
    Sorting_Array_Ascending(arr);
    //print the result
    for( int i=0; i<MAX_INDEX; i++)
    {
        printf("%d ",arr[i]);
    }
    //New Line
    printf("\n");
    //Sort in Descending order
    Sorting_Array_Descending(arr);
    //Print the result
    for( int i=0; i<MAX_INDEX; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

/**
 * @brief Sort in ascending order
 * 
 * @param originalArray 
 */
void Sorting_Array_Ascending(uint32_t originalArray[0])
{
    uint32_t tempVar;
    for( int i=0; i<MAX_INDEX; i++)
    {
        for( int j = (i+1); j< MAX_INDEX; j++)
        {
            //Sort in Ascending order
            if( originalArray[i] > originalArray[j] )
            {
                // swap
                tempVar = originalArray[i];
                originalArray[i] = originalArray[j];
                originalArray[j] = tempVar;
            }
        }
    }
}

/**
 * @brief Sort in Descending order
 * 
 * @param originalArray 
 */
void Sorting_Array_Descending(uint32_t originalArray[0])
{
    uint32_t tempVar;
    for( int i=0; i<MAX_INDEX; i++)
    {
        for( int j = (i+1); j< MAX_INDEX; j++)
        {
            //Sort in descending order
            if( originalArray[i] < originalArray[j] )
            {
                // swap
                tempVar = originalArray[i];
                originalArray[i] = originalArray[j];
                originalArray[j] = tempVar;
            }
        }
    }    
}