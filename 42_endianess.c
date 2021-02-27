#include<stdio.h>
int main()
{
    int i;
    char *ptr;
    ptr = (char *) &i;

    printf("Enter a number : ");
    scanf("%d", &i);
    if (*ptr)
        printf("\nLittle Endian system");
    else
        printf("\nBig Endian system");

    return 0;
}


