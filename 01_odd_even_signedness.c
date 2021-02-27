/*
Author Name             :-Shashank Pandora
Organisation            :-Emertxe Information Technologies (p) Ltd.
Date                    :-12 Mar 2020
Description             :-To check a given number is even or odd and its signedness
Input                   :-Integer N. N < 2^20
*/                          
#include<stdio.h>
#include<math.h>                        //To use power function to change binary to decimal

int main()
{
    char c;
    do
    {
	int num;
	printf("enter num: ");
	scanf("%d", &num);
	if (num < pow(2,20))
	{
	    if(num > 0)
	    {
		if(num%2 == 0)
		{
		    printf("%d is +ve even number\n", num);
		}
		else
		{
		    printf("%d is +ve odd number\n", num);
		}
	    }
	    else if (num < 0)                              //to check for negative numbers
	    {
		if(num%2 == 0)
		{
		    printf("%d is -ve even number\n", num);
		}
		else
		{
		    printf("%d is -ve odd number\n", num);
		}
	    }
	}
	else 
	{
	    printf("number out of range\n");
	} 
	printf("Do you want to continue (y/n): ");
	scanf("\n%c",&c);
    }
    while (c == 'y');                          //to re-run the program if user wants to. do while body ending 

    return 0;
}
