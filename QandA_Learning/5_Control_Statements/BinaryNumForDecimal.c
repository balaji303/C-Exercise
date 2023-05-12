/**
 * @file BinaryNumForDecimal.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Find the Binary number for the decimal number
 * @version 1
 * @date 08-05-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */

#include <stdio.h>
#include <stdint.h>

uint8_t DecimalPlaceValues[4] = {1,2,4,8};
uint8_t outputValues[4] = {0,0,0,0};

int main(void)
{
    uint16_t userInput, i = sizeof(outputValues)-1, remainder, quotitent;
    // printf("Enter the decimal value:\n");
    scanf("%d",&userInput);
    do
    {
        /* code */
        quotitent = userInput / DecimalPlaceValues[i];
        outputValues[i] = quotitent;
        remainder = userInput % DecimalPlaceValues[i];
        userInput = remainder;
        i--;
    }while (userInput != 0);
    for(int i = sizeof(outputValues)-1;i>=0;i--)
    {
        printf("%d",outputValues[i]);
    }
    return 0;

}