#include <stdio.h>

bool IsPrime(int a)
{
    for (int i=2; i<a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int a = 0;

    printf ("Enter the number");
    scanf ("%d",&a);

    if (IsPrime(a))
        printf ("Prime");
    else
        printf("Not Prime");


    return 0;
}