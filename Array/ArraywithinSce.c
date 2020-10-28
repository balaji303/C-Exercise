//Array within Structure
#include <stdio.h>
#include <string.h>
struct school{
    char name[20];
    int rollno;
    float marks[3];
};
int main(void){
    int i,j;
    struct school class[2];
    strcpy(class[0].name,"Balaji");
    class[0].rollno=3;
    for(j=0;j<3;j++){
            printf("Enter marks %d--",j);
            scanf("%f",&class[0].marks[j]);
    }
    printf("Enter name\n");
    scanf("%s",class[1].name);
    printf("Enter rollno\n");
    scanf("%d",&class[1].rollno);
    class[1].marks[0]=33.3;
    class[1].marks[1]=44.3;
    class[1].marks[2]=55.3;
    for(i=0;i<2;i++){
        printf("class[%d].name=%s\n",i,class[i].name);
        printf("class[%d].rollno=%d\n",i,class[i].rollno);
        for(j=0;j<3;j++){
         printf("class[%d].marks[%d]=%.2f\n",i,j,class[i].marks[j]);
        }
    }
    return 0;
}
