/*
Author Name             :-Shashank Pandora
Organisation            :-Emertxe Information Technologies (p) Ltd.
Date                    :-8 Mar 2020
Description             :-Write a program to generate fibbonacci numbers.
Input                   :-A positive integer say 'N'.
 */

#include<stdio.h>

int main()
{
    char c;
    do                                   
    {
    int num, first=0, sec=1, sum, i, sub;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("fabonicci series for %d is: \n", num);

    if(num == 0)
    {
	printf("%d\n",first);
    }
    else if (num > 0)
    {
	printf("%d\n%d\n", first, sec);
	sum = first + sec;
	while(sum <= num)               //loop until sum <= num
	{
	    printf("%d\n", sum);       //printing the sum
	    first = sec;              //value of sec is now stored in first
	    sec = sum;               //vlaue of sum is now in sec
	    sum = first + sec;
	}
    }
    else                           //for negative number
    {
	printf("%d\n%d\n",first,sec);
	sub = first - sec;
	while(-sub >= num && -sub <= -num)        //to set range from -ve to +ve value
	{
	    printf("%d\n", sub);
	    first = sec;
	    sec = sub;
	    sub = first - sec;

	}
    }
    printf("Do you want to continue (y/n): ");
    scanf("\n%c", &c);
 }
   while( c == 'y' );                     //to re-run the program if user enter y. do while body ending
    return 0;
}
