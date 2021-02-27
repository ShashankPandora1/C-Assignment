/*
   Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-5 Jun 2020
Description	    :-To defne a macro swap (t, x, y) that interchanges two arguments of type t
Output		    :-./swap
Before swap:
Enter the num1 : 10
Enter the num2 : 20
After Swapping :
num1 : 20
num2 : 10
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//defining macro to swap variables
#define SWAP(t, x, y)       \
{                           \
    t temp = x;             \
    x = y;                  \
    y = temp;               \
}

int main()
{
    //initialising array to store values of a and b
    char a[20], b[20], ch;
    do
    {
        printf("\n\nEnter the value of a: ");
        scanf("%s", a);

        printf("Enter the value of b: ");
        scanf("%s", b);

        printf("\nAfter Swapping:\n");
        // if only single char is passed 
        if ( strlen(a) == 1 )
        {
            SWAP(char, a[0], b[0]);
            printf("a: %c\nb: %c\n", a[0], b[0]);
        }

        else
        {
            int count = 0, i, j;

            for ( i = 0; a[i] != '\0'; i++ )
            {
                //reading values after decimal and inrementing the count after decimal
                if ( a[i] == '.' )
                {
                    for ( j = i + 1; a[j] != '\0'; j++ )
                        count++;
                    //if 6 val after decimal than it is float value
                    if ( count <= 6 )
                    {
                        float x, y;
                        //atof is used to convert the string into floating point numerical
                        x = atof(a);
                        y = atof(b);
                        SWAP(float, x, y);
                        printf("a: %.6f\nb: %.6f\n", x, y);
                    }
                    //if count 
                    else
                    {
                        double x, y;
                        // atof is used to convert the string into floating point
                        x = atof(a);
                        y = atof(b);
                        SWAP(double, x, y);
                        printf("a: %.15lf\nb: %.15lf\n", x, y);
                    }
                }
            }
            // condition for integer values
            if ( count == 0 )
            {
                int x, y;
                //converting dtring to integer
                x = atoi(a);
                y = atoi(b);
                SWAP(int, x, y);
                printf("a: %d\nb: %d\n", x, y);
            }
        }
        printf("\n\nDo you want to continue? (y/n): ");
        scanf("\n%c%*c", &ch);
    }
    while( ch == 'y' );

    return 0;
}

