/*
Supression of a variable during scanf
*/
#include <stdio.h>
void suppression(void);
int main(void){
  suppression();
  return 0;
}
void suppression(void){
  int d,m,y;
  printf("Enter today's date in dd/mm/yy format:\t");
  scanf("%d%*c%d%*c%d",&d,&m,&y);
  printf("%d/%d/%d",d,m,y);
}