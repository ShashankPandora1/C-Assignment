/*
Author Name             :-Shashank Pandora
Organisation            :-Emertxe Information Technologies (p) Ltd.
Date                    :-12 Mar 2020
Description             :-To check a given number is even or odd using bitwise operators
Input                   :-Integer N.
*/                          

#include<stdio.h>

int main()
{
    char c;
    do      
    {
    int num;
    printf("enter a number: ");
    scanf("%d",&num);
    if(num >> 31)                     //to check MSB bit if its 1 than its -ve number
    {
	if(num & 1)                  
	{
	    printf("%d is -ve odd number\n",num);
	}
	else 
	{
	    printf("%d is -ve even number\n",num);
	}
    }
    else 
    {
	if(num & 1) 
	{
	    printf("%d is +ve odd number\n",num);
	}
	else
	{
	    printf("%d is +ve even number\n",num);
	}
    }
    printf("Do you want to continue (y/n): ");
    scanf("\n%c", &c);
    }
    while ( c == 'y' );     //to re-run the program user interactive prompt. do while body ending
    return 0;
}

