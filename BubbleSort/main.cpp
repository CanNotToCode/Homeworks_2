#include <stdio.h>

void Swap(int &a, int &b)
{
    int c=a;
    a = b;
    b = c;
}

int main ()
{
    int a[10]={4,4,1,2,4,6,7,8,5,1};
    for(int i=0;i<10;i++)
    {
        for(int j=0; j<i; j++)
            if(a[i]<a[j])
                Swap(a[i],a[j]);
    }
    for(int i=0; i<10; i++)
        printf ("%d ", a[i]);
    return 0;
}