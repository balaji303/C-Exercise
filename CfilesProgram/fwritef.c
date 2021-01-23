#include <stdio.h>
#include <stdlib.h>
struct class
{
    /* data */
    char name[20];
    int rollno;
    int passPercent;
}student;
int main(void){
  int i,n;
  FILE *record;
  record=fopen("class.txt","wb");
  printf("Enter number of records:\t");
  scanf("%d",&n);
  for(i=0;i<n;i++){
      printf("Enter the student name:");
      scanf("%s",student.name);
      printf("Enter the rollno of the student:");
      scanf("%d",&student.rollno);
      printf("Enter the passPercent of the student:");
      scanf("%d",&student.passPercent);
      fwrite(&student,sizeof(student),1,record);
  }
  fclose(record);
  return 0;
}