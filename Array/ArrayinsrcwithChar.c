#include <stdio.h>
#include <string.h>
struct r1{
  int rollno[5];
  char arr[10];
};
int main(){
    int i;
    struct r1 balaji;
    struct r1 bala;
    for(i=0;i<3;i++){
        printf("ENter %d varible rollno\n",i);
        scanf("%d %d",&balaji.rollno[i],&bala.rollno[i]);
    }
    for(i=0;i<3;i++){
        balaji.arr[i]='w';
        bala.arr[i]='c';
    }
    printf("The output\n");
    for(i=0;i<3;i++){
        printf("ENtered %d \t",i);
        printf("%d %d %c ",balaji.rollno[i],bala.rollno[i],balaji.arr[i]);
        printf("%c\n",bala.arr[i]);
    }
    return 0;
}
