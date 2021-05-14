/*
memset function
output:
This Hello
*his Hello
*/
#include <stdio.h>
#include <string.h>
int main(){
    char val[10]="This Hello";
    printf("%s",val);
    memset(val,'*',sizeof(val[10]));
    printf("\n%s",val);
    return 0;
}
/*
// C program to demonstrate working of memset()
#include <stdio.h>
#include <string.h>

int main()
{
	char str[27] = "abcdefghijklmnopqrstuvwxyz.";
	printf("\nBefore memset(): %s\n", str);

	// Fill 8 characters starting from str[13] with '.'
	memset(str+8, '@', 8*sizeof(char));

	printf("After memset(): %s", str);
	return 0;
}

*/

