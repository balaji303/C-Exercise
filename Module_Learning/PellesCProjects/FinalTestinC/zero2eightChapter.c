/*//101 elements in an array
// known: 1 to 100 elements are there
// 1 number repeated ?
#include <stdio.h>
int main(void){
    int i=0,j,arr[10]={1,2,3,4,5,6,7,8,9,6},num;
	while(i<10){
	//for(i=0;i<10;i++){
      for(j=i+1;j<10;j++){
		//j=i+1;
		if(arr[i]==arr[j]){
				num=arr[i];
				//goto end;
				break;
			}
			else{
				//Do nothing
			}
		}
	i++;
	}
	//end:
	printf("The repeated number is %d\n",num);
	return 0;
}
*/
//Pattern
/*
#include <stdio.h>
int main(void){
	int i,j;
	for(i=1;i<4;i++){
        for(j=1;j<(4-i);j++){
                printf(" ");
		}
		for(j=1;j<=((2*i)-1);j++){
                printf("*");
		}
		printf("\n");
	}
    for(i=2;i>0;i--){
          for(j=1;j<(4-i);j++){
		    printf(" ");
          }
		  for(j=1;j<=((2*i)-1);j++){
		   printf("*");
		  }
		printf("\n");
	}
	return 0;

}
*/
