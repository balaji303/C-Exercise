/**
 * @file 2_1_PrintSizeAndLimits.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief Print the size and limits of the data types
 * @version 1
 * @date 27-04-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */
#include <stdio.h>
#include <stdint.h>
#include <limits.h>


int main(void)
{
   printf("****** Size of ******\n");
   printf("sizeof(int8_t):%lu\n",sizeof(int8_t));
	printf("sizeof(uint8_t):%lu\n",sizeof(uint8_t));
	printf("sizeof(int16_t):%lu\n",sizeof(int16_t));
	printf("sizeof(uint16_t):%lu\n",sizeof(uint16_t));
	printf("sizeof(int32_t):%lu\n",sizeof(int32_t));
	printf("sizeof(uint32_t):%lu\n",sizeof(uint32_t));
	printf("sizeof(int64_t):%lu\n",sizeof(int64_t));
	printf("sizeof(uint64_t):%lu\n",sizeof(uint64_t));

	printf("****** MIN and MAX ******\n");
	printf("int8_t MIN:%d and MAX:%d\n",INT8_MIN, INT8_MAX);
	printf("uint8_t MIN:%d and MAX:%d\n\n",0, UINT8_MAX);

	printf("int16_t MIN:%d and MAX:%d\n",INT16_MIN, INT16_MAX);
	printf("uint16_t MIN:%d and MAX:%d\n\n",0, UINT16_MAX);
   
	printf("int32_t MIN:%d and MAX:%d\n",INT32_MIN, INT32_MAX);
	printf("uint32_t MIN:%d and MAX:%lu\n\n",0, UINT32_MAX);
   
	printf("int64_t MIN:%lld and MAX:%lld\n",INT64_MIN, INT64_MAX);
	printf("uint64_t MIN:%d and MAX:%llu\n\n",0, UINT64_MAX);

	printf("Short MIN:%ld and MAX:%ld\n",SHRT_MIN, SHRT_MAX);
	printf("Unsigned Short MIN:%d and MAX:%lu\n\n",0, USHRT_MAX);

	printf("Long MIN:%ld and MAX:%ld\n",LONG_MIN, LONG_MAX);
	printf("Unsigned long MIN:%d and MAX:%llu\n\n",0, ULONG_MAX);

	printf("Long Long MIN:%lld and MAX:%lld\n",LLONG_MIN, LLONG_MAX);
	printf("Unsigned long long MIN:%d and MAX:%llu\n\n",0, ULLONG_MAX);
	
	return 0;
}