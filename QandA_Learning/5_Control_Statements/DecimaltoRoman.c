/**
 * @file DecimaltoRoman.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Convert Decimal to Roman number
 * @version 1
 * @date 30-06-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */
/**
 * Decimal - Roman
 * 1       - i
 * 4       - iv
 * 5       - v
 * 9       - ix
 * 10      - x
 * 50      - l
 * 100     - c
 * 500     - d
 * 1000    - m
 * 
*/

#include <stdio.h>
#include <stdint.h>

uint8_t number_of_digits(uint32_t decimalNumber);
void    decimal_to_roman(uint32_t decimalNumber, uint8_t numberOfDigit);

int main(void)
{
    uint32_t decimalNumber;
    uint8_t numOfDigits;
    // Get the number
    scanf("%d",&decimalNumber);
    //Find the number of digits
    numOfDigits = number_of_digits(decimalNumber);
    // printf("decimalNumber:%d, numOfDigits:%d",decimalNumber,numOfDigits);
    //Compare number of digits to nearest Roman Number
    decimal_to_roman(decimalNumber,numOfDigits);
    return 0;
}

uint8_t number_of_digits(uint32_t decimalNumber)
{
    uint8_t numberOfDigits = 0;
    if(decimalNumber == 0)
    {
        return 1;
    }
    while(decimalNumber > 0)
    {
        decimalNumber = decimalNumber / 10;
        numberOfDigits++;
        // printf("decimalNumber:%d, numOfDigits:%d",decimalNumber,numberOfDigits);
    }
    return numberOfDigits;
}

void decimal_to_roman(uint32_t decimalNumber, uint8_t numberOfDigit)
{ 
    while(decimalNumber)
    {
    // printf("\ndecimalNumber:%d",decimalNumber);
        if (decimalNumber >= 1000)
        {
            printf("M");
            decimalNumber = decimalNumber - 1000;
            continue;
        }
        //Compare with D
        if (decimalNumber >= 500)
        {
            printf("D");
            decimalNumber = decimalNumber - 500;
            continue;
        }
        //Compare with C
        if (decimalNumber >= 100)
        {
            printf("C");
            decimalNumber = decimalNumber - 100;
            continue;
        }
        if (decimalNumber >= 50)
        {
            printf("L");
            decimalNumber = decimalNumber - 50;
            continue;
        }
        if (decimalNumber >= 10)
        {
            printf("X");
            decimalNumber = decimalNumber - 10;
            continue;
        }
        if (decimalNumber >= 9)
        {
            printf("IX");
            decimalNumber = decimalNumber - 9;
            continue;
        } 
        if (decimalNumber >= 5)
        {
            printf("V");
            decimalNumber = decimalNumber - 5;
            continue;
        }  
        if (decimalNumber >= 4)
        {
            printf("IV");
            decimalNumber = decimalNumber - 4;
            continue;
        }
        if (decimalNumber >= 1)
        {
            printf("I");
            decimalNumber = decimalNumber - 1;
            continue;
        }        
        if (decimalNumber == 0)
        {
            return;
        }
    }
}   