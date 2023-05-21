//triangle
#include <stdio.h>
#include <math.h>
struct triangle{
    int a;
    int b;
    int c;
    int vol;
    int p;
};
int main(){
    int n,i,j,temp,xvol[100];
    // printf("Enter\n");
    scanf("%d",&n);
    struct triangle tri[n];
    for(i=0;i<n;i++){
    scanf("%d %d %d",&tri[i].a,&tri[i].b,&tri[i].c);
    xvol[i]=0;
    }
    // for(i=0;i<n;i++){
    // printf("%d %d %d\n",tri[i].a,tri[i].b,tri[i].c);
    // }
    for(i=0;i<n;i++){
        tri[i].p=(tri[i].a+tri[i].b+tri[i].c)/2;
        tri[i].vol=sqrt(tri[i].p*(tri[i].p-tri[i].a)*(tri[i].p-tri[i].b)*(tri[i].p-tri[i].c));
        xvol[i]=tri[i].vol;
        // printf("vol=%d\n",tri[i].vol);
        // printf("p=%d\n",tri[i].p);
    }
    
    for(i=0;i<n;i++){
        for(j=(i+1);j<n;j++){
            if(xvol[i]>xvol[j]){
                temp=xvol[i];
                xvol[i]=xvol[j];
                xvol[j]=temp;
            }
        }
    }
    // for(i=0;i<n;i++){
    //     printf("%d\n",xvol[i]);
    // }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          if(tri[j].vol==xvol[i]){
              printf("%d %d %d\n",tri[j].a, tri[j].b, tri[j].c);
          }
          else{
            //   printf("else\n");
        }
      }
    }
    return 0;
}
