#include "stdio.h"
    char *strcat(char *dest, const char *src)
    {
    size_t i,j;
    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++)
    dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}
void main(void)
{
    char a[10]={"abc"}, b[10]={"def"};
    strcat(a,b);
    printf("%s",a);
    getchar();
}
