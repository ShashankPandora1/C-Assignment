#include<stdio.h>
int main()
{
    int a,b,c;

    c = a!=b ?(a = 2,1) :(a = 2, b= 2);

    printf("c = %d\na = %d\nb = %d\n", c,a,b);
    return 0;
}

