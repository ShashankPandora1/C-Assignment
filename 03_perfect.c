/*
Author Name             :-Shashank Pandora
Organisation            :-Emertxe Information Technologies (p) Ltd.
Date                    :-8 Mar 2020
Description             :-To check whether the input number is  perfect or not.
Input                   :-A positive integer say 'N' where N < 2^20.
*/

#include<stdio.h>
#include<math.h>         //to use power function pow() to convert binary to decimal

int main()
{
    char c;
    do                       
    {

	int num, i, sum=0;
	printf("enter a number: ");
	scanf("%d", &num);
	if( num > 0 )
	{
	    if(num < pow(2 ,20))
	    {
		for (i=1; i<num; i++)
		{
		    if (num % i == 0)
		    {
			sum +=i;                 //to sum all the proper divisors of num
		    }
		}
		if (sum == num)                 //comparing the sum of proper divisors with enterd number 
		{
		    printf("Yes, entered number is a perfect number\n");
		}
		else
		{
		    printf("No, entered number is not a perfect number\n");
		}
	    }
	    else
	    {
		printf("number out of range\n");    // if number is greater than pow(2,20)
	    }
	}
	else 
	{
	    printf("Invalid Input\n");       //if number is less than or equal to 0 
	}
	printf("Do you want to continue (y/n): ");
	scanf("\n%c", &c);
    }	
    while( c == 'y' );                 //re-run the program if user enter 'y', do while body ending
    return 0;
}
