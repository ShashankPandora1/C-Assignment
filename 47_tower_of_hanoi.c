/*
Author Name	    :- Shashank Pandora
Organisation	:- Emertxe Information Technologies (P) Ltd.
Date		    :- 09/05/2020
Description	    :- C program to implement solution for tower of hanoi.
Input		    :- Enter the number of disks that you want the sequence of tower of hanoi
Output		    :-  Enter number of disks N: 3

                    Sequence is:
                    Make a legal move from rod A to C
                    Make a legal move from rod A to B
                    Make a legal move from rod C to B
                    Make a legal move from rod A to C
                    Make a legal move from rod B to A
                    Make a legal move from rod B to C
                    Make a legal move from rod A to C


		            Do you want to continue? (y/n): n
*/

#include<stdio.h>

void tow_of_hanoi(int ndisk, char src, char tmp, char dest);    //function prototype

int main()
{
    int ndisk;
    char src = 'A', tmp = 'B', dest = 'C', ch;      //definition of 3 rod i.e., source, destination and temporary
    do
    {
        printf("\nEnter number of disks N: ");
        scanf("%d", &ndisk);                        //taking total disks input from the user
        printf("\nSequence is:\n");
        tow_of_hanoi(ndisk, src, tmp, dest);        //function call passing total disks, source temp and destination rod
        printf("\n\nDo you want to continue? (y/n): ");
        scanf("\n%c", &ch);
    }
    while ( ch == 'y' );                            //checking if user enters 'y' to re-run the program

    return  0;
}

void tow_of_hanoi(int ndisk, char src, char temp, char dest)
{
    if ( ndisk == 1 )
    {
        printf("Make a legal move from rod %c to %c\n", src, dest); //printing last legal move
        return;                                 //stops the execution one the ndisks become one
    }
    tow_of_hanoi(ndisk - 1, src, dest, temp);   //function call changing decrementing ndisk by 1 and swapping temp and dest disk
    printf("Make a legal move from rod %c to %c\n", src, dest);     //print sequence
    tow_of_hanoi(ndisk - 1, temp, src, dest);   //function call decrementing disk by 1 and swapping src and temp disk
}

