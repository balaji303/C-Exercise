/*
uint8 ut_frame[7*TOTALBOARDS]={0,0,0,0,1,0,0,0,0,0,0,2,0,0}
uint Result[TOTALBOARDS];
*/
#define TOTALBOARDS 2
//#typedef unsigned int uint8
//#typedef 
#include <stdio.h>

int main(void){
	int j=0;
    int ut_frame[7*TOTALBOARDS]={0,0,0,0,1,0,0,0,0,0,0,2,0,0};
    for(int i=0;i<(7*TOTALBOARDS);i++){   
	//printf("ut_frame[%d]=%d\n",i,ut_frame[i]); 
    if(i=0){
			j=0;
		   }
	j++;

	if(j>7){
			j=0;
		}
	else{
          if(j==4){
			   printf("%d\n",ut_frame[i]);
			}
		  else{
					//Do nothing
				}
	    }
	}
	return 0;
}
