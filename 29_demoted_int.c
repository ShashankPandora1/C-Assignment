/*
   Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-5 Jun 2020
Description	    :-WAP to demote the type of given foat number to integer using bitwise operators and bitfelds.
Input           :- input float number
Output		    :-./demoted_int
                    Enter any foat numer : 23.7,
                    Demoted value is 23.000000 
 */
 union FLOATNUM
 {
	float FLOATNUM;
	// creating structure and defining the range
	struct FLOATRANGE
	{
		unsigned int MANTESSA : 23;
		unsigned int EXPONENT : 8;
		unsigned char SIGN : 1;
		
		 
	} floatRange;
	
 } floatNum;

#include <stdio.h>

int main()
{
    char ch;
    do      //user prompt do while
    {
    int exp, mask;
    
    // Swap int values
    printf("\nEnter a float value: ");
    scanf("%f", &floatNum.FLOATNUM ); 
    
    if (floatNum.floatRange.EXPONENT >= 127)
    {
        exp = floatNum.floatRange.EXPONENT - 127;
        
        mask = (~((1 << (23 - exp)) - 1));
        
        floatNum.floatRange.MANTESSA &= mask;
        
        printf("\nDemoted int value is : %f \n",  floatNum.FLOATNUM);
        
    }
    else
    {
        exp = 127 - floatNum.floatRange.EXPONENT;
        floatNum.floatRange.SIGN &= 0;
        floatNum.floatRange.EXPONENT &= 0;
        floatNum.floatRange.MANTESSA &= 0;
        printf("\nDemoted int value: %f \n",  floatNum.FLOATNUM);
    }
   printf("\n\nDo you want to run again (y/n) ? : ");
   scanf("\n%c%*c", &ch);
    }
    while (ch == 'y');   //user prompt do while body ending
    return 0;
}
