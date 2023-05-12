/**
 * @file ProductOfDigits.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Find the product of entered digits
 * @version 1
 * @date 09-05-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t userInput, numberOfIteration = 0, index, sum=1;
    uint32_t digits[10];
    scanf("%d",&userInput);

    while(userInput != 0)
    {
        digits[numberOfIteration] = userInput % 10;
        userInput = userInput / 10;
        numberOfIteration++;
    }
    // printf("%d\n",numberOfIteration);

    for(int i=0;i<(numberOfIteration-1);i++)
    {
        // printf("digits[%d] = %d\n",i,digits[i] );
        sum = sum * (digits[i]*digits[++i]);
        // printf("Product Sum%d\n",sum);
    }
    if(numberOfIteration != 2)
    {
        sum = sum * digits[numberOfIteration-1];
    }
    printf("%d\n",sum);

    return 0;
}