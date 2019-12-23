//Clock angle between hour and minute hand with high accuracy
#include <stdio.h>
int main(void){
printf("Clock Problem\n");
int countm=0,counth=0,hour,min,cmin,chour;
float angle,angle2;
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
	//printf("The Enered Hour and the minute is:\n%d;%d",hour,min);
cmin=min/5;
chour=hour;
if(hour>=cmin)
  {
	angle=((hour-cmin)*30);
  }  
else{
        angle=((hour-cmin)*30);
		angle=angle*(-1);
	}
	   /*
 while(cmin<=12){
		  countm++;
		  cmin++;
		}
	    while(chour>=0){
          counth++;
          chour--;                           
        }
        angle=((countm-counth)*30);
	}*/
while(cmin>=1)
{
    angle=angle+2.5;
    cmin--;
}
angle2=(360-(angle));
printf("The angles at the time %d:%d is\t%.2f and %.2f\n",hour,min,angle,angle2);  
return 0;
}

