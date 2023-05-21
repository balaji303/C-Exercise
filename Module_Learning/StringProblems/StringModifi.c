#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
char *p,y[100];
int x=0,i=0,countLine=1,countSpecialChar=0;
printf("Enter the string (End it with a tab button):");
p=(char*)malloc(100);
scanf("%[^\t]s",p);
while(*p!='\0'){
if( ((int *)*p >= 33 && (int *)*p <= 47) || (((int *)*p >= 58 && (int *)*p <= 64)) || ((int *)*p >= 91 && (int *)*p <= 96) || ((int *)*p >= 122 && (int *)*p <= 126) ) {
countSpecialChar++;
x=1;
}
if(x==0){ //Not a special Char
    y[i]=*p;
    i++;
}
if(*p=='\n'){ //New line count
  countLine++;
    }
x=0;p++;
}//while end
printf("\n                    Number of Special char   :\t%d",countSpecialChar);
printf("\n                           Number of  line   :\t%d",countLine);
printf("\nThe user input without Special character are :");
for(int j=0;j<i;j++){
    printf("%c",y[j]);
}
return 0;
}
/*
////Output:

Enter the string (End it with a tab button):goo*&(D m$ornin/g ##hav!|\e a
nic)(E
^%da*y 12345	
gooD morning have a
nicE
day 12345
Number of Special char:	15
Number of New line    :	2
The user input without Special character are:gooD morning have a
nicE
day 12345

*/
