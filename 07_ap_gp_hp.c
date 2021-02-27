/*
Author Name             :-Shashank Pandora
Organisation            :-Emertxe Information Technologies (p) Ltd.
Date                    :-8 Mar 2020
Description             :-write a program to read a, r, n to generate AP, GP, HP.
Input                   :-Positive integers say 'a', 'r' and 'n'
                          where :
			                     a = First number
			                     r = Common difference( AP & GP ), common ratio( GP )
				                 n = Number of terms
				                 a, r, and n should be < 2^10
*/

#include<stdio.h>
#include<math.h>             //to use power function to conver binary to decimal

int main()
{
    char c;
    do                //User intractive prompt
    {

    int a,r,n,i;
    printf("enter number of terms n =  ");
    scanf("%d", &n);
    printf("enter first number a = ");
    scanf("%d", &a);
    printf("enter common difference r = ");
    scanf("%d", &r);

    if( a < pow(2,10) )
    {
	if ( a > 0 ) 
	{   
	    int AP;                   //Arithmetic progression
	    printf("AP = ");
	    AP = a;
	    for (i = 0; i <n ; i++)
	    {
		printf("%d, ", AP);
		AP += r;             //AP = AP + r     
	    }
	    printf("\n");
	   
	    int GP;                  //Geometric progression
	    printf("GP = ");
	    GP = a;
	    for (i = 0; i < n; i++)
	    {
		printf("%d, ", GP);
		GP *= r;              //GP = GP * r
	    }
	    printf("\n");

	    float HP,value;        //Harmonic progression
	    printf("HP = ");
	    value = a;
	    for(i = 0; i < n; i++)
	    {
		HP= 1/value;
		printf("%f, ", HP);
		value += r;
	    }
	    printf("\n");
	}
	else
	{
	    printf("You entered negative value\n");
	}
    }
    else
    {
	printf("Invalid input out of range\n");
    }
    printf("Do you want to continue (y/n): ");
    scanf("\n%c", &c);
    }
    while ( c == 'y' );        //to re-run the program user intractive prompt.do while body ending
    return 0;
}
