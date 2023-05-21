//Program to find transpose of a matrix

#include <stdio.h>
void main()
{
    int m, n, i, j;

    //Entering number of rows and columns
    printf("Enter the number of rows:\n");
    scanf("%d", &m);
    printf("Enter the number of columns:\n");
    scanf("%d", &n);
    int a[m][n], b[n][m];

    //Entering elements into the array
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\nEnter the a[%d][%d] element ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            b[i][j] = a[j][i];
        }
    }

    //Displaying the enetered matrix
    printf("\nThe matrix you enteredis:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }

    //Displaying transpose matrix
    printf("\nThe transpose of the matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("\t%d", b[i][j]);
        }
        printf("\n");
    }
}