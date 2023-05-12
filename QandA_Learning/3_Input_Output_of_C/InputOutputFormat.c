/**
 * @file InputOutputFormat.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Input and output of different datatypes are explained
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
    // IO format for integer
    printf("Enter integer\n");
    uint8_t variable;
    scanf("%d",&variable);
    printf("%d\n",variable);
    // IO format for string
    printf("Enter string\n");
    uint8_t name[10];
    scanf("%s",&name);
    printf("%s\n",name);
    // IO format for floating point
    printf("Enter float\n");
    float floatVar;
    scanf("%e",&floatVar);
    printf("%2.2f\n",floatVar);
    // IO format for string
    printf("Enter another string\n");
    uint8_t name2[10];
    scanf("%s",&name2);
    printf("%3s\n",name2);   //Prints exactly
    printf("%.3s\n",name2);  //first 3 char
    printf("%2.3s\n",name2); //first 3 char

    return 0;
}