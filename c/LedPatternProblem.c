/*
Consider a 30x30 LED Display, the input must be a LED to start with followed by lighting all the LEDs in the diagonal
*/
#include <stdio.h>
int main(void){
    int maxrow,maxcol,row,col,spaceend,spacebegin,starbegin,starend;
    maxrow=30;
    maxcol=30;
    printf("Enter the row and column to start with:\t");
    scanf("%d %d",&row,&col);
    starend=col;//
    spaceend=col-1;
    for(int i=row;i<=maxrow;i++){
        for(spacebegin=1;spacebegin<=spaceend;spacebegin++){
            printf(" ");
        }
        spaceend--;
        starbegin=spacebegin;//while exiting for loop spacebegin will be same as starbegin
        //printf(" starbegin=%d ",starbegin);
        if (starend>=maxcol)
        {
            starend=maxcol;
        }
        //printf("StarEND= %d",starend);
        for(int x=starbegin;x<=starend;x++){
            printf("*");
        }
        printf("\n");
        starend=starend+1;
        
    }
    return 0;
}
