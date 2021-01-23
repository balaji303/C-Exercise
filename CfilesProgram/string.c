#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int count_letters(const char **strings, int string_count, char target)
{
    strcat(*(*strings+0),*(*strings+1));
    printf("%s",*(*strings+0));
}

#ifndef RunTests
int main()
{
    char *string_arr[] = {"Hello", "Jacqueline!"};
    int res = count_letters(string_arr, 2, 'e');
    printf("%d", res);
}
#endif