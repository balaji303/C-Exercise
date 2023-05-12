/**
 * @file Multiply2NumWithoutOpertor.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Multiply 2 numbers without using * operator
 * @version 1
 * @date 11-05-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */
#include <stdio.h>
#include <stdint.h>
int main(void)
{
    uint32_t value1, value2;
    uint64_t productOfValues = 0;
    scanf("%d %d",&value1, &value2);
    // printf("%d %d",value1, value2);
    for(int i=1;i<=value2;i++)
    {
        productOfValues = productOfValues + value1;
    }
    printf("%d",productOfValues);
    return 0;
}