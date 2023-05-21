#include <stdio.h>

void status_variable_position(char var, char posi)
{

	char status=0;
	if(var&(1<<posi))
	{
		status=1;
		printf("status is %d\n",status);
	}
	else
		printf("status is %d\n",status);
}
int main()
{
    char var=0xAA;//(1111 1111)
	
	status_variable_position(var,1);
	
 return 0;   
}
