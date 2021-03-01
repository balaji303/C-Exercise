#include <stdio.h>
void func(int a);
void func(float a);
int main(){
func(3);
func(0.2345);
return 0;
}
void func(int a){
    printf("%d",a);
}
void func(float a){
    printf("%0.2f",a);
}
/*
FUNCTION OVERLOAD WON'T HAPPEN in C this is the error you will get

functionOverload.c:3:6: error: conflicting types for 'func'
    3 | void func(float a);
      |      ^~~~
functionOverload.c:2:6: note: previous declaration of 'func' was here
    2 | void func(int a);
      |      ^~~~
functionOverload.c:12:6: error: conflicting types for 'func'
   12 | void func(float a){
      |      ^~~~
functionOverload.c:9:6: note: previous definition of 'func' was here
    9 | void func(int a){
*/