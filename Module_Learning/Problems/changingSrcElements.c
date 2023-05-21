#include <stdio.h>
#include <string.h>
struct class{
    char name[10];
    int marks;
    float fees;
}student1;
int main(){
    struct class student2;
    printf("Enter name\n");
    scanf("%s",&student1.name);
    printf("Marks\n");
    scanf("%d",&student1.marks);
    printf("Fees\n");
    scanf("%f",&student1.fees);
    student2.marks=student1.marks;
    student2.fees=student1.fees;
    strcpy(student2.name,student1.name);
    printf("Student 2 details\nName:%s\nMarks:%d\nFees:%.2f\n",student2.name,student2.marks,student2.fees);
    return 0;
}
