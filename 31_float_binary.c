/*
   Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-5 Jun 2020
Description	    :-Print bits of foat & double. Check IEEE std.i
Input           :-ENter float or double .
Output		    :-./print_fd_bits
Enter the Choice:
1. foat
2. double

Choice: 1

Enter the foat value: 2.3

Sign    Mantissa                         Exponent

------------------------------------------------------------------------------------
0       1 0 0 0 0 0 0 0                 0 0 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 
 */
#include <stdio.h>
#include <stdlib.h>
//function prototype
void print_nbits(unsigned int num, int n);
int main()
{
    char ch;
    do      //user prompt
    {
        int i;
        //declaring variable for float datatype
        unsigned int num, mantissa, exponent, sign;
        //declaring variables for double datatype
        unsigned long int long_num, lmantissa, temp;

        int choice;
        char option;

        float actualnum;
        double actualdoublenum;


        printf("\nEnter the Choice:\n1. float\n2. double\n");

        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the float value: ");
                scanf("%f", &actualnum);

                // actual number 
                num = *((unsigned int *)&actualnum);

                mantissa = ( num & 0x7FFFFF);      // and with mask to get only 23 mantissa bits 

                num = num >> 23;        // remove the 23 mantessa bits by shift right

                exponent = ( num  & 0xFF );     // and with mask to get only 8 exponent bits

                num = num >> 8;      // remove the 8 exponent bits by shift right 

                sign = ( num & 0x01 );  // and with mask = 0x01 to get only 1 sign bits 

                // print the values 
                printf("\nSign\tExponent\t\t\tMantissa\n");
                for (i = 0; i < 100; i++)
                    printf("-");
                printf("\n");
                printf("%x\t", sign);
                print_nbits(exponent,8);
                printf("\t\t");
                print_nbits(mantissa,23);
                break;

            case 2:
                printf("\nEnter the double value: ");
                scanf("%lf", &actualdoublenum);


                // actual number
                long_num = *((unsigned long int *)&actualdoublenum);

                lmantissa = ( long_num & 0xFFFFFFFFFFFFF);    // and with mask to get only 52 mantissa bits

                long_num = long_num >> 52;    // remove the 52 mantessa bits by shift right

                exponent = ( long_num  & 0x7FF );     // and with mask to get only 11 exponent bits

                long_num = long_num >> 11;     // remove the 11 exponent bits by shift right

                sign = ( long_num & 0x01 );    // and with mask = 0x01 to get only 1 sign bits

                printf("\nsign\tExponent\t\t\tMentissa\n");
                for (i = 0; i < 144; i++)
                    printf("-");
                printf("\n");
                printf("%x\t", sign);
                print_nbits(exponent,11);       
                printf("\t\t");
                temp = lmantissa;   //storing mantisaa bits in temp

                //print_nbits can handle only 32 bits at a time 
                temp = temp >> 31;      // right shifting temp to print msb bit of mantissa first
                print_nbits(temp,21); 
                print_nbits(lmantissa, 31);     //to print remaining 31 bits
                break;

            default:
                printf("\nIvalid Input\n");
                break;
        }
    printf("\n\nDo you want to run again (y/n)? : ");
    scanf("\n%c%*c", &ch);
    }
    while (ch == 'y');      //user promt do while body ending
    return 0;
}

void print_nbits(unsigned int num, int n)
{
    int i, iter = num, bit, mask;
    int bits[31] = {0};
    //print the n bit binary representation of num
    for (i = 0; iter != 0; i++)
    {
        bits[i] = (iter & 01);
        iter>>=1;  //right shift by one bit
    }
    for (i = (n-1); i >= 0; i--)
    {
        printf("%d ", bits[i]);
    }
}

