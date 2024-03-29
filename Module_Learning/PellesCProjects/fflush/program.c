// C program to illustrate flush(stdin) 
// This program works as expected only 
// in certain compilers like Microsoft 
// visual studio. 
#include <stdio.h> 
#include<stdlib.h> 
int main() 
{ 
	char str[20]; 
	int i; 
	for (i = 0; i<2; i++) 
	{ 
		scanf("%[^\n]s", str); 
		printf("%s\n", str); 

		// used to clear the buffer 
		// and accept the next string 
		fflush(stdin); 
	} 
	return 0; 
} 
/*
// C program to illustrate situation 
// where flush(stdin) is required only 
// in certain compilers. 
#include <stdio.h> 
#include<stdlib.h> 
int main() 
{ 
	char str[20]; 
	int i; 
	for (i=0; i<2; i++) 
	{ 
		scanf("%[^\n]s", str); 
		printf("%s\n", str); 
		// fflush(stdin); 
	} 
	return 0; 
} 

*/
