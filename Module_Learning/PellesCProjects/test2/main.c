#include <stdio.h>
void fun(char input,char position);
int main(void)
{
    //set a position based on user input
	//variable, position should be argument to function
	char ip=0xaa;
	char posi=2;
    fun(ip,posi);
	return 0;
}
void fun(char input,char position)
{
	input |=(1<<position);
    printf("%x\n",input);
}
