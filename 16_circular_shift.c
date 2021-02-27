/*
Author Name	:-Shashank pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:-24 April 2020
Description	:-To execute and print circular left and right shift by 'n' bits of input value.
Input		:-User will enter the value to do left or right shift on choice at num by n bits.
Output		:-./circular_shift
		  Enter a Number 'num' : 10
		  Enter 'n' : 3
		  Possible operations
		  1. Circular Left shift
		  2. Circular right shift
		  Enter your choice : 2
		  The binary form of number : 000000000000000000000000000001010
		  After circular right shift : 01000000000000000000000000000001
*/

#include<stdio.h>
//Function protype defination
int cir_left_shift(unsigned int, int);
int cir_right_shift(unsigned int, int);
int print_bits(int, int);

int main()
{
    char c;		//User prompt defination;
    do
    {
	int num, n, choice, bit=32;
	printf("Enter a number : ");
	scanf("%d",&num);
	printf("Enter a n : ");
	scanf("%d",&n);
	printf("\n1. Circular Left Shift\n2. Circular Right Shift\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch (choice)
	{
	    case 1:	//case for circular left shift
		printf("Binary form of number %d : ",num);
		while (bit)	//Loop to print bits by print_bits function
		    printf("%d",print_bits(num, --bit));
		if (bit <= 0)
		    bit=32;	//Initialising bit, changed by loop
		printf("\nAfter Circular Left shift by n bit(s)	 : ");
		while (bit)
		    printf("%d",print_bits(cir_left_shift(num,n), --bit));	//Calling print_bits function by loop repeatedly
		break;						//and invoking cir_left_shift function to return o/p
	    case 2:	//case for circular right shift
		printf("Binary form of number %d : ",num);
		while (bit)	//Loop to print bits by print_bits function
		    printf("%d",print_bits(num, --bit));
		if (bit <= 0)	//Initialising bit, changed by loop
		    bit=32;
		printf("\nAfter Circular Right shift by %d bit(s)  : ",n);
		while (bit)
		    printf("%d",print_bits(cir_right_shift(num,n), --bit));	//Calling prin_bits function by loop repeatedly
		break;						//and invoking cir_right_shift function to return o/p
	    default:
		printf("\nInvalid choice");
	}
	printf("\n\nDo you want to continue again? (y/n) ");
	scanf("\n%c",&c);
    } while (c == 'y');		//User prompt do while body ending
    return 0;
} 
int cir_left_shift(unsigned int num, int n)
{
    return (((((1 << n) - 1) << 32-n) & num) >> 32-n) | (num << n);	//Getting MSB bit of num and doing letf shift by 'n
}									//and replacing by MSB bits into LSB
int cir_right_shift(unsigned int num, int n)
{
return ((((1 << n) - 1) & num) << 32-n) | ((num >> n) & (~(((1 << n) - 1) << 32-n))); //Getting LSB bits of num and doing right shift
}											//and replacing by LSB bits into MSB
int print_bits(int num, int bit)
{
    return !!((1 << bit) & num);	//print_bits fucntion called repeatedly by loop to print binary
}

