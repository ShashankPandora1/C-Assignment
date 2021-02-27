#include<stdio.h>
#include<string.h>

//function prototype defination
void non_rec( char *);
void rec(char *, int);

int main()
{
    int option, i = 0;
    char str[100];
    printf("\nEnter a string : ");
    scanf("%100[^\n]", str);
    printf("\nSelect any one method to reverse string\n1. Recursive Methodn\n2. Non-Recursive Method\n");
    printf("Enter your option : ");
    scanf("%d", &option);
    switch (option)
    {
        case 1:
            rec(str,i);
            printf("\nReverse String : %s\n", str);
            break;
    }

    return 0;
}
void rec( char *str, int i )
{
    static int var;
    var = i;
    char *p = str + strlen(str) - var++, temp;
    if( p > str)
    {
        temp = *str;     //Swapping first and last address string value
        *str = *p;
        *p = temp;
        str++;
        rec(str, i);
    }
}


