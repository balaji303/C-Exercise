#include <stdio.h>
int main(void){
printf("Clock Problem\n");
int hour,min,cmin,chour,angle,angle2;
int countm=0,counth=0;
printf("Enter the Hour: ");
scanf("%d",&hour);
while(hour>=13 || hour<=0)
{
  printf("Wrong Hour Please enter between 1 to 12 ");
  scanf("%d",&hour);
}
printf("Enter the Minute: ");
scanf("%d",&min);
while(min>=61 || hour<=0)
{
  printf("Wrong Minute Please enter between 1 to 60 ");
  scanf("%d",&min);
}
	//printf
cmin=min/5;
chour=hour;
if(hour>=cmin)
	{
	angle=((hour-cmin)*30);
  }  
	else{
        angle=((cmin-hour)*30);
	}
angle2=(360-(angle));
printf("The angles at the time %d:%d is\t%d and %d ",hour,min,angle,angle2);  
return 0;
}

