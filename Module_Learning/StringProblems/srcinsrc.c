//structure inside structure
#include <stdio.h>
struct school{ 
    char name[20];
    int rollno;
    struct subject{
        int tamil,english,maths;
    }marks;
}government;
int main(){
    int i;
    printf("Enter student name:\n");
    scanf("%s",government.name);
    printf("Enter roll number:\n");
    scanf("%d",&government.rollno);
    printf("Enter tamil marks:\n");
    scanf("%d",&government.marks.tamil);
    printf("Enter english marks:\n");
    scanf("%d",&government.marks.english);
    printf("Enter maths marks:\n");
    scanf("%d",&government.marks.maths);
    printf("Name- %s\n",government.name);
    printf("Roll no- %d\n",government.rollno);
    printf("Tamil marks- %d\n",government.marks.tamil);
    printf("English marks- %d\n",government.marks.english);
    printf("Marks marks- %d\n",government.marks.maths);
    return 0;
}
