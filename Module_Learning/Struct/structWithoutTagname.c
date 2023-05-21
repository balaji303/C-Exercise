#include <stdio.h>
struct 
{
    int marks;
    float rollnumber;
}student;
int main(){
    student.marks=12;
    student.rollnumber=1.2;
    printf("%d and %0.1f",student.marks,student.rollnumber);
    return 0;
}