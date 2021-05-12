#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    //Pointer
    char *p="Balaji"; //Only one byte is given
    p=malloc(7);      //7=6+1(''\0') byte given
    strcpy(p,"Balaji");//copy string
    //Array 
    char arr[10]={'B','a','l','a','j','i'};
    arr[2]='x'; //changing elements 
    *(p+2)='z'; //changing elements
    puts(p);    //print
    puts(arr);  //print
    free(p);    //free memory because of dynamic allogation
    return 0;
}

