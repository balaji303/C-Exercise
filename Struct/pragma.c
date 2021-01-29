#include <stdio.h>
#pragma pack(1)
struct def
{
	char ch1;
	int idata;
};
int main()
{
  struct def define;
  printf("%d\n",sizeof(define));
}
