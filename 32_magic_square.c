/*
Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date	    	:-5 jun 2020
Description	    :-WAP to generate n*n magic square (n is odd +ve number)
Input		    :-n positive odd integer
Output		:-./magic_square
                Enter order of matrix : 3
                8   1   6
                3   5   7  
                4   9   2

                do you want to continue (y/n) ? : 

*/

#include<stdio.h>
#include<stdlib.h>
void magic_square(int **arr, int n);    //function prototype
int main()
{
    char c; 
    do          //user prompt
    {
        int **arr,n;
        printf("\nEnter order of matrix : ");
        scanf("%d", &n);
        if(n%2)
        {
            printf("\n\nMAGIC SQUARE\n\n");
            magic_square(arr, n);
        }
        else
            printf("\nInvalid input!!! *Note - enter odd number for magic square\n");
        printf("\n\nDo you want to run the code again ? (y/n) :  ");
        scanf("\n%c", &c);
    }
    while (c == 'y');   //to re- run the prog. user prompt do while body ending
    return 0;
}

void magic_square(int **arr, int n)
{
    int i,j, row, col;

    //dynmaically allocating memory to the row
    arr = malloc(n * sizeof(int *)); // each row is pointer to int

    //for each row allocate col int
    for (i = 0; i < n; i++)
    {
        arr[i] = malloc( n * sizeof(int));
    }
    /*for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            arr[i][j] = 0;      //1st initialising all the elements of array as 0
   */
    //initialize pos for 1
    row = n/2;
    col = n-1;
    int num;
    //putting all the elements one by one in matrix
    for (num = 1; num <= n*n; num++)
    {
        arr[row][col] = num;  //first 1 will be placed at row = n/2 and col = n-1
        row--;
        col++;
        // if row = -1 and col = oder of matrix
        if (row == -1 && col == n)
        {
            col = n-2;
            row = 0;
        }
        // pos of next number if anytime cal pos become n it will become 0 
        // if at anytime row pos become -1 it will become n -1.
        else
        {
            if (col == n)
                col = 0;
            if (row < 0)
                row = n - 1;
        }
        // condition if a number is alredy present at the position
        if (arr[row][col])
        {
            col -= 2;
            row++;
            continue;
        }
    }       
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
