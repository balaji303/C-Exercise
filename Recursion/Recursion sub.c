#include <stdio.h>
void find(int a);
int main(void){
    int n,r;
    printf("Enter a number");
    scanf("%d",&n);
    find(n);
    return 0;
}
void find(int a){
    if(a==1){
        printf("%d",1);
    }
    else if(a<=0){
        printf("Thinking your funny??");
    }
    else{
        printf("%d",a);
        a=a-1;
        find(a);
    }
    
}
