//Leap year or not
#include <stdio.h>
int main(){
 int input_year;
 printf("Enter year\n");
 scanf("%d",&input_year);
if(input_year%4==0 || input_year%400==0 && input_year%100!=0){
    printf("Leap year\n");
}
else{
    printf("Not a Leap year");
}
return 0;
}
