/**
 * @file commaOperator.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Explaining Comma operator
 * @version 1
 * @date 05-05-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t a,b,c;
    uint16_t sum;
    sum = (a=1, b=2, c= 7, a+b+c);
    printf("%d",sum);

    return 0;
}