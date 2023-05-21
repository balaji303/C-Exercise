//Prime or Not
#include <stdio.h>
int main(){
    int i,c=0,input,output;
    printf("Enter a number:\n");
    scanf("%d",&input);
    for(i=2;i<input;i++){
        if(input%i==0){
          c=1;
          break;
        }
        else{
            c=c;
        }
    }
    if(c==1){
        printf("\nThe entered number is a Non-Prime number\n");
    }
    else{
        printf("\nThe entered number is a Prime number\n");
    }
    return 0;
}
