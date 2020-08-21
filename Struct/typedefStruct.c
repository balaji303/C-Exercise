#include <stdio.h>

int main()
{
    struct bj{
        int rollno;
        float fees;
    };
    typedef struct bj bal;
    bal bl;
    printf("Hello World");
    scanf("%d",&bl.rollno);
    printf("%d",bl.rollno);
    return 0;
}

/*
 //This is same as above
#include <stdio.h>

int main()
{
    typedef struct bj{
        int rollno;
        float fees;
    }bal;
    bal bl;
    printf("Hello World");
    scanf("%d",&bl.rollno);
    printf("%d",bl.rollno);
    return 0;
}
*/

/*
//This is same as above
#include <stdio.h>

int main()
{
    typedef struct{
        int rollno;
        float fees;
    }bal;
    bal bl;
    printf("Hello World");
    scanf("%d",&bl.rollno);
    printf("%d",bl.rollno);
    return 0;
}
*/
