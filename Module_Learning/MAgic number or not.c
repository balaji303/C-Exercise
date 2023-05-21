//MAgic number or not
#include <stdio.h>
int main(){
    int input,c=0,op,rem,add=0,ip,rev=0,ad;
    printf("ENter a number\n");
    scanf("%d",&input);
    ip=input;
    while(input){
        rem=input%10;
        input=input/10;
        add=rem+add;
    }
    // printf("%d\n",add);
    ad=add;
    while(add>1){
        rem=add%10;
        add=add/10;
        c++;
        rev=rev+(rem*(10*c))+add;
    }
    // printf("%d",rev);
    op=ad*rev;
    op==ip ? printf("Magic Number\n") : printf("Not a Magic number");
    return 0;
}
