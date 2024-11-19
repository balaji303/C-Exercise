#include <stdio.h>
void printArray(uint8_t *arrayVar);
int main()
{
    uint8_t arr1[]={1,-2,-4,55,3,4,9,-2,5};
    printArray(&arr1);

    return 0;
}

void printArray(uint8_t *arrayVar)
{
    for(int i=0;i<37;i=i+4)
    {
        if(*(arrayVar+i) > *(arrayVar+i+4))
        {
            print("%d",*arrayVar);
        }
    }
}

// This is the program I wrote for print array. The question had pass array to function

#include <stdio.h>
#include <stdint.h>

void printArray(uint8_t *arrayVar);

int main() {
    int8_t arr1[] = {1, -2, -4, 55, 3, 4, 9, -2, 5};
    printArray(arr1); // Pass array name directly

    return 0;
}

void printArray(int8_t *arrayVar) {
    for (int i = 0; i < 8 - 1; i++) { // Loop over array elements, excluding the last one
        if (*(arrayVar + i) > *(arrayVar + i + 1)) {
            printf("%d ", *(arrayVar + i)); // Print the current element
        }
    }
}
