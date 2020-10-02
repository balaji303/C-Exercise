int main()
{
    int a = 3;
    int b = 5;
    
    printf("a=%d b=%d\n", a, b);
    
    a ^= b;
    b ^= a;
    a ^= b;
    
    printf("a=%d b=%d\n", a, b);

    return 0;
}
