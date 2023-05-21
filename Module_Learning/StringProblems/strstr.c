#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int j,i,begin=0,end;
    char p[100]="multinational";
    char q[100]="national";
    for(i=0;p[i];i++){
        if(p[i]==q[i]){
            begin=i;
        }
        else{}
    }
    for(i=(begin-1);p[i];i++){
        printf("%c",p[i]);
    }
    return 0;
}
