#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_ARRAY_INDEX 10

void Sorting_Array_Ascending(uint32_t originalArray[0]);
int32_t BinarySearch(uint32_t originalArray[0],uint32_t valueToSearchFor);

int main(void)
{
    int32_t indexOfValue;
    uint32_t valueToSearch;
    // Declare the array
    uint32_t arr[MAX_ARRAY_INDEX] = {1,12,99,40,55,69,71,88,3,0};
    //Sort in ascending order
    Sorting_Array_Ascending(arr);
    //print the result
    for( int i=0; i<MAX_ARRAY_INDEX; i++)
    {
        printf("%d ",arr[i]);
    }
    //Value to search
    valueToSearch = 12;
    //Do Binary Search
    indexOfValue = BinarySearch(arr,valueToSearch);
    //Print Result
    if (indexOfValue < 0)
    {
        printf("\nValue not found in Array");
    }
    else
    {
        printf("\nvalueToSearch was found in Index: %d",indexOfValue);
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
    for( int i=0; i<MAX_ARRAY_INDEX; i++)
    {
        for( int j = (i+1); j< MAX_ARRAY_INDEX; j++)
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
 * @brief Binary Search
 * 
 * @param originalArray 
 * @param valueToSearchFor 
 * @return int32_t 
 */
int32_t BinarySearch(uint32_t originalArray[0],uint32_t valueToSearchFor)
{
    uint32_t lowIndex = 0;
    uint32_t highIndex = MAX_ARRAY_INDEX - 1;
    uint32_t midIndex = (lowIndex + highIndex)/2;
    bool continueLoop = true;
    int32_t indexOfValue = -1;
    uint8_t loopCount = 0;
    while(continueLoop)
    {
        midIndex = (lowIndex + highIndex)/2;
        // printf("\nlowIndex: %d, highIndex: %d, midIndex:%d",lowIndex, highIndex, midIndex);
        if( valueToSearchFor == originalArray[midIndex] )
        {
            indexOfValue = midIndex;
            continueLoop = false;
        }
        else
        {
            // Check if greater 
            if(originalArray[midIndex] > valueToSearchFor)
            {
                highIndex = highIndex - 1;
            }
            else
            {
                //Check if less than
                lowIndex = lowIndex + 1;
            }

        }
        if(loopCount > MAX_ARRAY_INDEX)
        {
            indexOfValue = -1;
            continueLoop = false;
        }
        loopCount++;
    }
    return indexOfValue;
}
