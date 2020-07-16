#include <stdio.h>
int main(){
    int a[100],j,var,temp,i=0;
    printf("Enter a number in decimal form:");
    scanf("%d",&var);
    temp=var;
    while(temp){
        a[i]=temp%2;
        temp=temp/2;
        i++;
    }
    printf("The Binary form of entered number is: ");
    for(j=(i-1);j>=0;j--){
        printf("%d",a[j]);
    }
    return 0;
}
/*

Output:

Enter a number in decimal form:45                                                                                                    
The Binary form of entered number is: 101101




*/
