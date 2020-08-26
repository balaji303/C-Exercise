
/*
Structure is given a whole values to the variable
*/
#include <stdio.h>
typedef struct{
  int rollno;
  char name[10];
  float fees;
}student;
student std[2]={{},{1,"balaji",2.3}};//Values at whole can be given only at the time of declaration
int main(void){
 printf("%d",std[1].rollno);
 return 0;
}
