#include <stdio.h>

#include <stdlib.h>

int main(){

    int *p,n,i,m;

    printf("Enter the size:\n");

    scanf("%d",&n);

    p=malloc(n*sizeof(int));

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

        printf("Enter extra size\n");

        scanf("%d",&m);

        m=m+n;

        p=realloc(p,m*sizeof(int));

        for(i=n;i<m;i++){

            printf("%d element- ",i);

            scanf("%d",&p[i]);

        }

        printf("\nAfter Realloc:\n");

        for(i=0;i<m;i++){

            printf("%d element- %d\n",i,p[i]);

        }

    }

    return 0;

}
