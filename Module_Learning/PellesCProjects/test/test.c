/*
#include <stdio.h>
struct school{
    int *rollno;
    char *name;
};
int main(){
    
    struct school ptosrc,*ptosrc1;
    int i=30;
	ptosrc.rollno = &i;
	ptosrc.name="jeevan";
	printf("%s\n",ptosrc.name);
	printf("%d\n",*ptosrc.rollno);

	ptosrc1=&ptosrc;
	printf("%s\n",ptosrc1->name);
	printf("%d\n",*ptosrc1->rollno);

    return 0;
}
*/
//Operation on bits
struct bit{
   unsigned a:2;
   unsigned b:3;
};
int main(void){
    struct bit ip;
	int temp;
	printf("Enter 2 bit number( 0 -3 ):\n");
	scanf("%d",&temp);
	ip.a=temp;
    printf("Enter 3 bit number(0 - 7 ):\n");
	scanf("%d",&temp);
	ip.b=temp;
	printf("The value of 2 bit is: %d\n",ip.a);
    printf("The value of 3 bit is: %d\n",ip.b);
	return 0;
}
//Odd or even

