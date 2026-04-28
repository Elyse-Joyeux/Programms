#include <stdio.h>

int factorial(int num)
{
    if (num <= 0)
        return 1;

    return num * factorial(num - 1);
}

int main()
{
    int num;
    int result = factorial(5);
    printf("the factorial of 5 is: %d", result);
    return 0;
}