/**
 * @file DateValidOrNot.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Date valid or not
 * @version 1
 * @date 13-05-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

static bool Leap_YearOrNot( uint32_t year )
{
    // scanf("%d",&year);
    bool leapYear = false;
    if ( ( (year % 100 != 0)&&(year % 4 == 0)) || (year % 400 ==0) )
    {
        // printf("leap year");
        leapYear = true;
    }
    else
    {
        // printf("not a leap year");
        leapYear = false;
    }

    return leapYear;
}

int main(void)
{
    uint32_t date, month, year;
    bool leapYear = false;
    scanf("%d/%d/%d",&date,&month,&year);
    // printf("%d/%d/%d",date,month,year);
    leapYear = Leap_YearOrNot(year);
    // Check if inputs are valid or not
    if ( (year < 1800) || (year > 2050) )
    {
        printf("Invalid Date");
    }
    else if ( (month >= 13) || (month == 0) )
    {
        printf("Invalid Date");
    }
    else if ( (date > 31) || (date == 0) )
    {
        printf("Invalid Date");
    }
    else
    {
        // Check for 31 dates in month
        if ( (leapYear == true) && (month == 2) && (date != 29) )
        {
            printf("Invalid Date");
        }
        else if( ( month != 8 ) && ( month % 2 == 0 ) && (date >= 31) )
        {
            printf("Invalid Date");
        }
        else if( (date >= 29) && (month == 2) && (leapYear == false) )
        {
            printf("Invalid Date");
        }
        else
        {
            printf("Valid Date");
        }
    }


    return 0;
}