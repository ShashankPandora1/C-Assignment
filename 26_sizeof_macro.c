/*
Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-5 Jun 2020
Description	    :-To defne a macro SIZEOF(x), where x is a variable, without using sizeof
operator
Output		    :-./read_int
                Size of int: 4 bytes
                Size of char: 1 bytes
                Size of foat: 4 bytes
                Size of double: 8 bytes
                Size of unsigned int: 4 bytes
                Size of long int : 8 bytes
 */
#include<stdio.h>
#include<stdlib.h>
//macro where x is variable
#define SIZEOF(x) (char *)(&x+1) - (char *)(&x) 
int main()
{
    int num = 8;
    float f =8.9;
    char ch = 'y';
    double d = 0.7;
    unsigned int un = 5;
    long int ln = 6;

    //sizeof int values 
    printf("\nSize of int : \t%lu", SIZEOF(num));
    
    //sizeof char values
    printf("\nSize of char : \t%lu", SIZEOF(ch));

    //sizeof float values
    printf("\nSize of float : \t%lu", SIZEOF(f));

    //sizeof double vlaues
    printf("\nSize of double : \t%lu", SIZEOF(d));

    //sizeof unsigned int 
    printf("\nSize of unsigned int : \t%lu", SIZEOF(un));

    //sizeof long int
    printf("\nSize of long int : \t%lu", SIZEOF(ln));

    printf("\n");

    return 0;
}
