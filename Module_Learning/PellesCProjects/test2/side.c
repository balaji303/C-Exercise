
#include <stdio.h>
#pragma pack(2)
struct def
{
	char ch1[2];
	int idata;
};

struct def define;
int main()
{
    printf("%d\n",sizeof(define));
    
}
//************************************************
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
	
    
}
//************************************************
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
	
    
}
//************************************************
#include <stdio.h>
void fun(int input,int position);
int main(void)
{
    //set a position based on user input
	//variable, position should be argument to function
	int ip=0xaa;
	int posi=1;
    fun(ip,posi);
	return 0;
}
void fun(int input,int position)
{
//	input |=(1<<position); // set a position
//    printf("%x\n",input);
    input &=~(1<<position); // Clear a position
    printf("%x\n",input);
}
//************************************************
//************************************************
