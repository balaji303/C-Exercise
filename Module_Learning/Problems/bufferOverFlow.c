#include <stdio.h>
int main(void){
  int a[2]={6,7};
  printf("%d\n",a[1]);
  a[5]=9;
  printf("%d",a[4]);
  return 0;
}