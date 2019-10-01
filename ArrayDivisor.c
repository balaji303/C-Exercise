#include <stdio.h>

int main()
{
    int arr[1000],size,i,count=0,n,elements[1000];
    printf("Enter size of the  Array:\n");
    scanf("%d",&size);
    printf("Enter Array elements:\n");
    for(i=0;i<size;i++){
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter divisor:\n");
    scanf("%d",&n);
    for(i=0;i<size;i++){
        if(arr[i]%n==0){
            elements[count]=arr[i];
            count=count+1;
            
        }
        else{
            //do nothing;
        }
        
    }
    printf("Number of elements divisible by %d=%d\n",n,count);
    for(i=0;i<count;i++){
        printf("elements[%d]=%d\n",i,elements[i]);
    }
    return 0;
}
