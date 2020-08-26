/*
Enter Individual Digits and convert that to a number
*/
#include <stdio.h>
int main(void)
{
int value,Total;
char size;
    printf("Enter Total Digit:");
    scanf("%d",&size);
for(int count=1;count<=size;count++){
    printf("Enter %d\'s digit:",count);
    scanf("%d",&value);
    Total=(Total*10)+value;
}
printf("Value is :%d",Total);
return 0;
}

/*
ip:
2
3
4

op:
234
*/
