/* 
Toggle bit
#include <stdio.h>
void set_clear(int);
void Toggle(int num);
int main(void){
	int num=0;
	//set_clear(num);
	Toggle(num);
}

void set_clear(int num)
{
	while(1)
	{
		printf("%d\n",num|(1<<0));
		for(long long int i=0;i<99000000;i++);
		printf("%d\n",num&(~(1<<0)));
	}

}
void Toggle(int num)
{
	while(1)
	{
		num^=(1<<0);
		printf("%d",num);
		for(long long int i=0;i<99000000;i++);
	}
}
*/




