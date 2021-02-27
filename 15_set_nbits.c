/*
Author Name	:-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:-24 April 2020
Description	:-To execute and print 'b'th position of 'i' by taking (b-a+1)th bit from 'n' and replacing to 'i'.
Input		:-User will enter the value to do bitwise operation for input value and replace bth bit of 'i'.
Output		:-./bitwise_function
		  Enter a Number 'n' : 11
		  Enter 'i' : 174
		  Enter 'a' : 3
		  Enter 'b' : 5
		  The binary of 'n'     : 00000000000000000000000000001011
		  The binary of 'i'     : 00000000000000000000000010101110
		  The new binary of 'i' : 00000000000000000000000010011110
		  8 is not a Perfect Number
*/

#include<stdio.h>
int set_nbits_from_pos(int, int, int);
int print_bits(int, int);
int main()
{
    char c;	//User prompt defination
    do
    {
	int n, b, a, i;
	printf("Enter value of n : ");
	scanf("%d",&n);
	printf("Enter value of i : ");
	scanf("%d",&i);
	printf("Enter value of a : ");
	scanf("%d",&a);
	if (a > 0 && a < 31)	//Condition for 'a' range
	{
	    printf("Enter value of b : ");
	    scanf("%d",&b);
	    if (b > a && b < 31)	//Condition for 'b' range
	    {
		int num=32;	//Initialising num to call print_bits function in loop
		printf("The binary form of 'n' :	");
		while (num)	//Loop to print bit
		    printf("%d ",print_bits(n, --num));		//Calling print_bits function using loop
		printf("\nThe binary form of 'i' :	");
		if (num <= 0)	//Again initialisng num, changed by loop
		    num=32;
		while (num)
		    printf("%d ",print_bits(i, --num));		//Calling print_bits function for 'i'
		int c = b-a+1;
		printf("\nThe new binary form of 'i' is : ");
		if (num <= 0)		//Again initalising num, changed by loop
		    num=32;
		while (num)	//Calling print_bits function repeatedly by loops
		    printf("%d ",print_bits(set_nbits_from_pos(i, c, n), --num));	//Inside print_bits function call returning 	
		printf("\n");								//o/p of set_nbits_from_pos to print o/p
	    }
	    else
		printf("Invalid Input of 'b'. Enter a < b < 31\n");
	}
	else
	    printf("Invalid Input of 'a'. Enter 0 < a < 31\n");
	printf("\n\nDo you want to continue again? (y/n) : ");
	scanf("\n%c",&c);
    } while (c == 'y');		//User prompt body ending
    return 0;
}
int set_nbits_from_pos(int i, int c, int n)
{
    return ((((1 << c) - 1) & n) << c) | (~(((1 << c) - 1) << c) & i);	//Getting b-a+1 LSB bit from 'n' and replacing into 'i' at  
}									// bth bit positon 
int print_bits(int n, int num)	
{
    return !!((1 << num) & n);	//Getting binary bit by repeatedly calling of print_bits function by loop
}

