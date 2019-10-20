//String reverse using recursion
# include <stdio.h> 
void reverse(char *str);
int main(){ 
   char a[100];
   printf("Enter a string\n");       
   scanf("%s",a);
   reverse(a); 
   return 0; 
} 
void reverse(char *str){ 
   if (*str){ 
       reverse(str+1); 
       printf("%c", *str); 
   } 
   else{}
} 
