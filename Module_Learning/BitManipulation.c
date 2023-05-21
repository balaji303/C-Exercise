#include <stdio.h>
typedef unsigned char BYTE;
int main(){
unsigned long int value=0x12345678; //4Bytes
BYTE Byte1,Byte2,Byte3,Byte4;         //to store Byte by byte value
Byte1=((value>>24)&0xFF); //Extract first byte
Byte2=((value>>16)&0xFF); //Extract Second Byte
Byte3=((value>>8)&0xFF); //Extract Third Byte
Byte4=(value&0xFF); //Extract fourth Byte

printf("Byte1=0x%X\n",Byte1);
printf("Byte2=0x%X\n",Byte2);
printf("Byte3=0x%X\n",Byte3);
printf("Byte4=0x%X\n",Byte4);

return 0;
}


/***
OUTPUT

Byte1=0x12
Byte2=0x34
Byte3=0x56
Byte4=0x78

***/