/**
 * @file DifferenceBtw2Date.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Find the difference between 2 date 
 * @version 1
 * @date 16-05-2023
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
    uint32_t date1, month1, year1,date2, month2, year2,diffDays = 0;
    bool leapYear1 = false, leapYear2 = false;
    scanf("%d/%d/%d %d/%d/%d",&date1,&month1,&year1,&date2,&month2,&year2);
    leapYear1 = Leap_YearOrNot(year1);
    leapYear2 = Leap_YearOrNot(year2);
    // printf("%d %d", leapYear1, leapYear2);

    // Validate the inputs
    // if( year1 > year2 )
    // {
    //     printf("Invalid input");
    // }
    // if( month1 > month2 )
    // {
    //     printf("Invalid input");
    // }
    // if( date1 > date2 )
    // {
    //     printf("Invalid input");
    // }

    //Difference in years
    uint32_t diffYear = year2 - year1;
    diffDays = diffDays + (diffYear * 365);
    //Difference in months
    uint32_t diffMonth = month2 - month1;
    diffDays = diffDays + (diffMonth * 31);
    //Difference in days
    uint32_t diffDate = date2 - date1;
    diffDays = diffDays + diffDate;
    printf("%d",diffDays);
    return 0;
}