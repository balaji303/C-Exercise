#include <stdio.h>

void status_variable_position(char var)
{
	char one=0,zero=0;
	char i;
	for(i=0;i<sizeof(var)*8;i++)
	{
		if(var&(1<<i))
			{
				one++;
			}
		else
			{
				zero++;
			}
	
	}
	printf("Ones:%d\tzeros:%d",one,zero);
}
int main()
{
    char var=0xAA;//(1111 1111)
	
	status_variable_position(var);
	
 return 0;   
}
