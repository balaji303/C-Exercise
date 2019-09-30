#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000],b[1000],c[10];
    int i;
    // printf("Enter");
    scanf("%s",b);
    // for(i=0;a[i];i++){
    // b[i]=a[i];
    // // printf("%c\n",b[i]);
    // }
    for(i=0;i<10;i++){
        c[i]=0;
    }
    for(i=0;b[i];i++){
        if(b[i]=='0'){
            c[0]=c[0]+1;
        }
        else if(b[i]=='1'){
            c[1]=c[1]+1;
        }
        else if(b[i]=='2'){
            c[2]=c[2]+1;
        }
        else if(b[i]=='3'){
            c[3]=c[3]+1;
        }
        else if(b[i]=='4'){
            c[4]=c[4]+1;
        }
        else if(b[i]=='5'){
            c[5]=c[5]+1;
        }
        else if(b[i]=='6'){
            c[6]=c[6]+1;
        }
        else if(b[i]=='7'){
            c[7]=c[7]+1;
        }
        else if(b[i]=='8'){
            c[8]=c[8]+1;
        }
        else if(b[i]=='9'){
            c[9]=c[9]+1;
        }
        else{
            
        }
    }
    for(i=0;i<10;i++){
        printf("%d ",c[i]);
    }
    return 0;
}
