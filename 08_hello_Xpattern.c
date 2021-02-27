/*
Author Name             :-Shashank Pandora
Organisation            :-Emertxe Information Technologies (p) Ltd.
Date                    :-8 Mar 2020
Description             :-To print "Hello" in x format.
Input                   :-A positive integer say 'N'.Where N < 2^5
*/

#include<stdio.h>
int main()
{
    char c;
    do                       
    {
	int i,j,num,mid;                  //i = rows, j = col.
	printf("enter the number of lines: ");
	scanf("%d",&num);
	mid = num/2+1;
	if (num >= 3 && num <= 32)          //to check the range of number    
	{
	    for ( i = 1; i <= num; i++)
	    {
		for ( j = 1; j <= num; j++)
		{
		    if ( i == j || num+1 == i+j )
		    {
			printf("Hello");    
			if( num%2 != 0 )    //cond. for odd number 
			{
			    if ( i == mid )
			    {
				printf("Hello");
			    }
			    else
			    {
				printf(" ");
			    }
			}
		    }
		    else
			printf(" ");
		}
		printf ("\n");
	    }
	}
	else
	{
	    printf("Number out of range\n");
	}
	printf("Do you want to continue (y/n): ");
	scanf("\n%c", &c);
    }
    while( c == 'y' );        //to re-run the program. do while body ending 
    return 0;
}
