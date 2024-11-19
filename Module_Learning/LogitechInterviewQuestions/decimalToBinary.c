#include <stdio.h>
void decimalToBinary(int *refArgu);
int main()
{
    int decimalNumeber = 5;
    decimalToBinary(&decimalNumeber);

    return 0;
}

void decimalToBinary(int *refArgu)
{
    if(*refArgu == 1)
    {
        printf("1");
    }
    else if(*refArgu % 4 == 0)
    {
        printf("1");
        // int ver = *refArgu % 2;
        // decimalToBinary(&ver);
    }
    else if(*refArgu % 2 == 1)
    {
        printf("1");
        int ver = *refArgu % 2;
        decimalToBinary(&ver);
    }
    else
    {
        printf("0");
    }
}

//The above is the program I wrote for decimal to binary conversion. Below is the correct one

#include <stdio.h>

void decimalToBinary(int *refArgu);

int main() {
    int decimalNumber = 5;
    decimalToBinary(&decimalNumber);
    return 0;
}

void decimalToBinary(int *refArgu) {
    if (*refArgu == 0) {
        return;
    } else {
        decimalToBinary((*refArgu) / 2); // Divide the number by 2 for next iteration
        printf("%d", *refArgu % 2); // Print the remainder (0 or 1)
    }
}
