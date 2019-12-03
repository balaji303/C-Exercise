#include <stdio.h>

int main(){

    int var1,var2,var3;

    printf("\nEnter the number: ");

    scanf("%d",&var1);

    printf("\nEnter the position to check: ");

    scanf("%d",&var2);

    // --var2;  //Due to  complier used//

    var2=1<<--var2;

    var3 = var1 | var2;

    // printf("The answer is %d",var3);

    (var3==var1) ? printf("The bit is set") : printf("The bit is not set");

 return 0;

}
