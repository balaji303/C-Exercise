/**
 * @file LeapYearOrNot.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Leap year or not
 * @version 1
 * @date 13-05-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t year;
    scanf("%d",&year);
    if ( ( (year % 100 != 0)&&(year % 4 == 0)) || (year % 400 ==0) )
    {
        printf("leap year");
    }
    else
    {
        printf("not a leap year");
    }

    return 0;
}