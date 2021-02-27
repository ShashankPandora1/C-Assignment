/*
Author Name             :-Shashank Pandora
Organisation            :-Emertxe Information Technologies (p) Ltd.
Date                    :-10 Mar 2020
Description             :-To print all ascii character
Input                   :-None
*/
#include<stdio.h>

int main()
{
    int i;

    printf("dec oct hex char\n");
    for(i=0;i<=127;i++)
    {
	if (i<=32)
	{
	    printf("non printabale\n");
	}
	else if (i<127)
	{
	    printf("%d %o %x %c \n",i,i,i,i);   //to print decimal, octal, hexa values and corresponding character   
	}
	else 
	{
	    printf("non printable\n");
	}
    }
    return 0;
}
