/*#include <stdio.h>
int main(){
int var1=0x2345;
int var2=0xf,var3=0x0;
printf("var1=0x%x\tVar2=0x%x\n",var1,var2);
var3 = var1 &(var2<<8);
printf("var 2=0x%x",var3);
return 0;
}*/
/* Second program */
/*
#include <stdio.h>
#define Nibble0_Start 0
#define Nibble1_Start 4
#define Nibble2_Start 8
#define Nibble3_Start 12

#define Get_Nibble0_Value(val)	(val&(0xF<<Nibble0_Start))>>Nibble0_Start
#define Get_Nibble1_Value(val)	(val&(0xF<<Nibble1_Start))>>Nibble1_Start
#define Get_Nibble2_Value(val)	(val&(0xF<<Nibble2_Start))>>Nibble2_Start
#define Get_Nibble3_Value(val)	(val&(0xF<<Nibble3_Start))>>Nibble3_Start


int main()
{
	short int Data= 0x1234;// 2 bytes
	printf("%x\t",Get_Nibble0_Value(Data));
	printf("%x\n",Get_Nibble1_Value(Data));
	printf("%x\t",Get_Nibble2_Value(Data));
	printf("%x",Get_Nibble3_Value(Data));

}*/
/* bit fields sample program */
/*
#include<stdio.h>

struct tag
{
	unsigned int a:2;
}var1;

int main(void)
{
var1.a=5;
	printf("%d",var1.a);

}
*/
//*************************************************
/*
#include<stdio.h>
#define toggle_bit(val,bit_pos) (val^=(1<<bit_pos))
int main(void)
{
 int val=0xaa;//1010 1010
	int result=toggle_bit(val,3);
	printf("%x",result);
				
}
*/

/* Stringizing operator
#define print(var,format)  (printf("#var= %"#format"\n",var))
#include <stdio.h>
int main(){
    int a=2;
    char b='@';
    float c=5.82;
    print(a,d);
    print(b,c);
    print(c,.2f); 
	return 0;
}
*/
/* Token Pasting 
#define join(var1,var2) var1##var2
#define marks_(subject) marks_##subject
#include <stdio.h>
int main(void){
    int num1=11,num2=22;
	int marks_tamil=99,marks_english=88;
    printf("num1=%d\n",join(num,1));
    printf("num2=%d\n",join(num,2));
    printf("Tamil Marks=%d\n", marks_(tamil));
	printf("English Marks=%d\n", marks_(english));
	return 0;
}
*/
/* Predefined macro names 
#define date __DATE__
#define location __FILE__ 
#define line __LINE__
#include <stdio.h> 
int main(){
printf("%s\n",date);
	printf("%s\n",location); 
printf("%d\n",line);
return 0;
}
*/
/* ifdef 
#define num 1
#include <stdio.h>
int main(){
    int a=2;
#if num>5 
	a=a*10;
	printf("Num is bigger\n");
#endif
    printf("The value of a=%d\n",a);
	return 0;
}
*/
/* If else 
#define num 10
#include <stdio.h>
int main(){
    int a=2;
#if num>5 
	a=a*10;
	printf("If statement passed\n");
#else
	a=a+3;
	printf("Else statement passed\n");
#endif
    printf("The value of a=%d\n",a);
	return 0;
}*/

/* If else elif 
#define num 12
#include <stdio.h>
int main(){
    int a=2;
#if num<5 
	a=a*10;
	printf("If statement passed\n");
#elif num<10
    a=a+8;	
	printf("First Elif statement passed\n");
#else
#if num<15
	a=a+50;
	printf("Second else if statment passed\n");
#else
	a=a+3;
	printf("Else statement passed\n");
#endif
#endif
    printf("The value of a=%d\n",a);
	return 0;
}
*/
///////////////////////////////////////////***********************/
/*
Storage Classes

*/
/*************************************************************/
/*
#include <stdio.h>
int ga=1;
float gb=2.2;
char gc='A';
double gd=123456;
	
int main(){
	int a=10;
    float b=20.2;
    char c='%';
    double d=123460;
printf("The local variable....\n");
	printf("a=%d\nb=%.2f\nc=%c\nd=%lf\n",a,b,c,d);
 printf("The global variable....\n");
	printf("ga=%d\ngb=%.2f\ngc=%c\ngd=%lf\n",ga,gb,gc,gd);
return 0;
}
*/
//Jan=1,FEb=2,Jun=6;
/*
#include <stdio.h>
int main(){
    int a;
	printf("Enter number of month:\n");
	scanf("%d",&a);

	switch(a){
       case 1:
			printf("January\n");
			break;
	   case 2:
			printf("Febuary\n");
			break;
	   case 3:
			printf("March\n");
			break;
	   case 4:
			printf("April\n");
			break;
       case 5:
			printf("May\n");
			break;
	   case 6:
			printf("June\n");
			break;
		}

	return 0;
}*/

/*Jan=1,FEb=2,Jun=6;
#include <stdio.h>
int main(){
    int a;
	printf("Enter number of month:\n");
	scanf("%d",&a);

	switch(a){
       case 1:
			printf("January\n");
			break;
	   case 2:
			printf("Febuary\n");
			break;
	   case 3:
			printf("March\n");
			break;
	   case 4:
			printf("April\n");
			break;
       case 5:
			printf("May\n");
			break;
	   case 6:
			printf("June\n");
			break;
		}

	return 0;
}

*/


/*
//INterview question
#include <stdio.h>
int main(void)
{
    int Num=0x000000aa,pos=3;
	register i;
	int temp1=(1<<(pos-1));
	if((Num&&(1<<3))==1)
	{
		
		//for(i=0;i<=pos-(sizeof(Num)*8);i++)
		for(i=0;i<=pos-1;i++)
		{
			Num|=temp1;
			temp1=temp1>>1;
			
		}
	}
	else{
		/* Do nothing 
	}
	printf("%x",Num);
	return 0;
}
*/
#include <stdio.h>
int main(void)
{
int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}},i,j;
for(i=0;i<3;i++){
		if(i%2==0) //EVEN ROW
		{
          
		}
		else   //ODD ROW
		{
`
	     }
	}
return 0;
}













