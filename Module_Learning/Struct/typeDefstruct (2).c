#include <stdio.h>
typedef struct 
{
    int marks;
    float rollnumber;
}student;
int main(){
    student welcome;
    welcome.marks=12;
    welcome.rollnumber=1.2;
    printf("%d and %0.1f",welcome.marks,welcome.rollnumber);
    return 0;
}