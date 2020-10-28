//Array of structure
#include <stdio.h>
#include <string.h>
struct school{
    char name[20];
    int employeeNo;
    float salary;
}class[3];
int main(void){
    int i;
    for(i=0;i<3;i++){
    printf("Class %d details\n",i);
    printf("Enter name of Teacher- ");
    scanf("%s",class[i].name);
    printf("Enter Employee Number of Teacher- ");
    scanf("%d",&class[i].employeeNo);
    printf("Enter Salary of Teacher- ");
    scanf("%f",&class[i].salary);
    }
    printf("--Data Base--\n");
    for(i=0;i<3;i++){
    printf("Class %d details:\tName of the Teacher-%s Employee Number-%d Salary-%.2f\n",i,class[i].name, class[i].employeeNo, class[i].salary);
    }
    return 0;
}
