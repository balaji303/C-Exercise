#include <stdio.h>
#include <stdlib.h>
int find_max_sum(int *numbers, int size);

int main(void)
{
    int v[] = { 2, 10, 10, 7 };
    printf("%d", find_max_sum(v, 4));
}
int find_max_sum(int *numbers, int size)
{
    int i, max1, max2,sum;
    max1 = max2 = *numbers;
    for (i = 0; i < size; i++) {
        if (*(numbers+i) > max1) {
            max2 = max1;
            max1 = *(numbers+i); //Finding largest number in an array
        }
        else if (*(numbers+i) > max2 && *(numbers+i) != max1)
            max2 = *(numbers+i); //Finding largest number skiping the first array
    }
    sum=max1+max2;
    return sum;
}
