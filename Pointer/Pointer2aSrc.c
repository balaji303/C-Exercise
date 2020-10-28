#include <stdio.h>
struct school{
    int rollno;
    float marks;
};
int main(){
    struct school balaji;
    struct school *ptosrc=&balaji;
    printf("Enter rollno and marks\n");
    scanf("%d %f",&ptosrc->rollno,&ptosrc->marks);
    printf("The OUTPUT is\n%d %.2f",(*ptosrc).rollno, ptosrc->marks);
    return 0;
}
