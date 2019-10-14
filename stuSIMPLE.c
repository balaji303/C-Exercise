//structure program
#include <stdio.h>
#include <string.h>
struct tagname{
    char name[20];
    int rollno;
    float fees;
};
int main(void){
    struct tagname student2={"John",5,2800.00};
    struct tagname student3;
    struct tagname student1;
    strcpy(student1.name,"Salim");
    student1.rollno=8;
    student1.fees=1000.45;
    printf("Enter student3 details\n");
    scanf("%s %d %f",&student3.name, &student3.rollno, &student3.fees);
    printf("%s %d %f\n",student1.name, student1.rollno, student1.fees);
    printf("%s %d %f\n",student2.name, student2.rollno, student2.fees);
    printf("%s %d %f\n",student3.name, student3.rollno, student3.fees);    
    return 0;
}
