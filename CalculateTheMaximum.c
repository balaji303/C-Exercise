#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.
void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int i,j,ac=0,oc=0,xc=0,and[1000],or[1000],xor[1000];
  for(i=1;i<n;i++){
      for(j=i+1;j<=n;j++){
          if((i&j)<k){
              and[ac++]=i&j;
          }
          if((i|j)<k){
              or[oc++]=i|j;
          }
          if((i^j)<k){
              xor[xc++]=i^j;
          }
      }
  }
  for(i=0;i<ac;i++){
    //  printf("and[%d]=%d\n",i,and[i]);
      if(and[0]<and[i]){
          and[0]=and[i];
      }
  }
    for(i=0;i<oc;i++){
     // printf("or[%d]=%d\n",i,or[i]);
      if(or[0]<or[i]){
          or[0]=or[i];
      }
  }
    for(i=0;i<xc;i++){
    //  printf("xor[%d]=%d\n",i,xor[i]);
      if(xor[0]<xor[i]){
          xor[0]=xor[i];
      }
  }
//   printf("and[0]=%d\n",and[0]);
//   printf("or[0]=%d\n",or[0]);
//   printf("xor[0]=%d\n",xor[0]);
  printf("%d\n",and[0]);
  printf("%d\n",or[0]);
  printf("%d\n",xor[0]);
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
    return 0;
}


