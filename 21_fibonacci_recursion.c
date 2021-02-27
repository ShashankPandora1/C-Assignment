/*
Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :- 5 May 2020
Description	    :-to generate fibbonacci numbers <= n using recurssion
Input	 	    :-integers num
Output		    :-./fibbonacci
                  Enter the value of Num: 8
                  fibbonacci series using recursive function is
                  0,1,1,2,3,5,8
*/

#include<stdio.h>

void fib_rec(int num, int sum);     //function prototype defination

int main()
{
    char c;
    do          //user prompt defination
    {
    int num, sum = 0;
    printf("Enter a number : ");
    scanf("%d", &num);
    printf("\nFibonacci series for %d is : ", num);
    fib_rec(num, sum);          //function call in main
    printf("\n\nDo you want to continue (y/n): ");
    scanf("\n%c", &c);
    }
    while ( c == 'y' );         //user prompt defination do while body ending 
    return 0;
}
void fib_rec(int num, int sum)
{
    static int a = 0, b = 1;
    if (num > 0)
    {
	if (sum <= num)     //condition for positive value
	{
	    printf("%d, ", sum);
	    a = b;          //assigning previous value of b 
	    b = sum;        //assigning previous value of sum
	    sum = a + b;
	    fib_rec(num, sum);      //using recursive method
	}
    }
    else
    {
	if (-sum >= num && -sum <= -num)  //condition for negative number
	{
	    printf("%d, ", sum);
	    a = b;      //previous value of b isassigned to a
	    b = sum;    //previous value of sum is assigned to b
	    sum = a - b;
	    fib_rec(num, sum);   //using recursive method
	}
    }
}
