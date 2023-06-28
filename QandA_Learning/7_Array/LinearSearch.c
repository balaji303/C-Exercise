/**
 * @file LinearSearch.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief LinearSearch in an array
 * @version 1
 * @date 23-06-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */
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
    // Get the value to search
    scanf("%d",&valueToSearch);
    //Search
    indexOfValueReq = LinearSearch( inputArray, valueToSearch );
    //Process the result
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