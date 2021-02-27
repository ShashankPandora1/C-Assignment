/*
Author Name             :-Shashank Pandora
Organisation            :-Emertxe Information Technologies (p) Ltd.
Date                    :-15 Mar 2020
Description             :-To print all primes smaller than or equal to number. using sieve of eratosthenes method
Input                   :-Integer N. N < 2^20
*/                          
/*WAP to print prime numbers*/


#include<stdio.h>
#include<math.h>            //To use the power function to convert the binary value to decimal.

int main()
{
    char c;
    do
    {
	int num,i,j;
	printf("Enter the number: ");
	scanf("%d", &num);
	if(num > 1 && num < pow(2,20)) 
	{
	    int arr[num];
	    for(i = 2; i <= num; i++)   //0 and 1 is not included in the array.
	    {
		arr[i] = i;    	//To populate the array with the natural numbers
	    }
	    i = 2;
	    while((i*i) <= num)         //will go upto sq. root of the number
	    {
		if (arr[i] != 0)
		{
		    for(j = 2; j < num; j++)
		    {
			if (arr[i]*j > num)
			{
			    break;      //for loop break
			}
			else
			{
			    arr[arr[i] * j] = 0;  //making the multiple of i = 0
			}
		    }
		}
		i++;
	    }
	    for(i = 2; i <= num; i++)
	    {
		if(arr[i] != 0)              
		    printf("%d, ", arr[i]);   //to print prime numbers
	    }
	}
	else 
	{
	    printf("Number is out of range\n");
	}
	printf("Do you want to continue (y/n): ");
	scanf("\n%c", &c);
    }
    while( c == 'y' );            //To re-run the program if user want to . do whle body ending
	return 0;
}
