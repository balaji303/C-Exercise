/**
 * @file PrimeOrNot.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Program that says a number is prime or not
 * @version 1
 * @date 12-05-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main(void)
{
    uint8_t userInput;
    scanf("%d",&userInput);
    for(int i = 2; i <= sqrt(userInput); i++)
    {
        if(userInput == 2)
        {
            printf("prime");
            return 0;
        }
        else if(userInput % 2 == 0)
        {
            printf("not prime");
            return 0;
        }
        else if( (userInput % i == 0) && (userInput == i) )
        {
            printf("prime");
            return 0;
        }
        else
        {
            // Do Nothing
        }
    }
    printf("not prime");
    return 0;
}

