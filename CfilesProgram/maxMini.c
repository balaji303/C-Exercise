#include <stdio.h>
#include <conio.h>
int main(void){
  int value,max,min;
  char answer;
  printf("Enter a number: ");
  scanf("%d",&value);
  max=min=value;
  printf("Do you want to continue");
  answer=getche();
  while(answer=='y'|| answer=='Y'){
      printf("Enter a number: ");
      scanf("%d",&value);
      if (value>max)
      {
          
          max=value;
      }
      if (value<min)
      {
          /* code */
          min=value;
      }
      printf("Do you want to continue");
      answer=getche();
  }
  printf("Maximum number is %d\n",max);
  printf("Minimum number is %d",min);
  return 0;
}
