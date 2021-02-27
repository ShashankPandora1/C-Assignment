/*
Author Name	:-Shashank Pandora
Date		:-11/03/2020
Description	:-Program to print the bits of the entered number and 2's complement of the entered number.
Input		:-Input an integer that you want print bits of that number with its 2's coplement
Output		:-Enter the number: 1
		  1	-> 00000000000000000000000000000001
		 -1	-> 11111111111111111111111111111111
*/

#include<stdio.h>

int main()
{
    char c;
    int num, i, bit;
    do                                              //user interactive
    {
        printf("Enter the number: ");
        scanf("%d", &num);
        printf("\n%d\t -> ", num);
        for ( i = 31; i >= 0; i-- )
        {
	    bit = !!(num & 1 << i);				//Operation to get the bit at particular position here from 31 to 0
	    printf("%d", bit);					//printing the bits from 31 to 0
        }

        num = ~num + 1;						//changing num to its 2's complement
        printf("\n%d\t -> ", num);
        for ( i = 31; i >= 0; i-- )
        {
	    bit =!!(num & 1 << i);
	    printf("%d", bit);					//printing the bits of 2's complement of entered number
        }
        printf("\n\nDo you want to continue? (y/n): ");
        scanf("\n%c", &c);
    }
    while ( c == 'y' );					//to re-run the program user interactive prompt.do while body ending
    return 0;
}
