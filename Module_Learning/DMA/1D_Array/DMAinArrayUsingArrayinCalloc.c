#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p,n,i;
    printf("Enter the size:\n");
    scanf("%d",&n);
    p=calloc(n,sizeof(int));
    if(p==NULL){
        printf("Memory full");
        exit(404);
    }
    else{
        for(i=0;i<n;i++){
            printf("Enter %d element-\n",i);
            scanf("%d",&p[i]);
        }
        for(i=0;i<n;i++){
            printf("%d element- %d\n",i,p[i]);
        }
    }
    return 0;
}
