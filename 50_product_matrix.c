/*
Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-5 jun 2020
Description	    :-WAP to find the product of matrix
Input		    :-Enter number of rows
                  Enter number of cols
Output		    :-./transpose_product
                    Enter number of rows : 3
                    Enter number of columns : 3
                    Enter values for 3 x 3 matrix :
                    1   2   3 
                    1   2   3
                    1   2   3
                    Transpose of given Matrix :
                    1   1   1
                    2   2   2
                    3   3   3
                    Product of two matrix :
                    14  14  14
                    14  14  14
                    14  14  14
                    Do you want to continue(Y/y)? : N

*/
#include<stdio.h>
#include<stdlib.h>
//function prototype
int **trans_matrix(int **arr, int row, int col);
int **product(int **arr, int **AT, int row, int col);
void my_print(int **arr, int row, int col);

int main()
{
    int i, j, row, col, **arr, **AT, **PM;
    printf("\nEnter number of rows: ");
    scanf("%d", &row);
    printf("\nEnter number of cols : ");
    scanf("%d", &col);
    //dynmaically allocating memory to the row
    arr = malloc(row * sizeof(int *)); // each row is pointer to int

    //for each row allocate col int
    for (i = 0; i < row; i++)
    {
        arr[i] = malloc( col * sizeof(int));
    }
    //populating array
    printf("\nEnter matrix\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("row[%d]col[%d] - ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nOrignal Matrix\n");
    my_print(arr, row, col);
    //transpose
    AT = trans_matrix(arr, row, col);
    printf("\nTranspose of a matrix\n");
    my_print(AT, col, row);    //calling my print function 
    //Product matrix
    PM = product(arr, AT, row, col);
    printf("\nProduct of Matrix\n");
    my_print(PM, row, row); //calling my print function
    
    return 0;
}
int **trans_matrix(int **arr, int row, int col)
{
    int i, j, **AT;
    //in transpose the row become col and col become row 
    //dynamically allocating memory for each row
    AT = malloc(col * sizeof(int *)); //each row is pointer to int
    for (i = 0; i < col; i++)
    {
        //allocating memory for each col in row
        AT[i] = malloc(row * sizeof(int));
    }
    //takin the transpose
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            AT[j][i] = arr[i][j];
        }
    }
    return AT;
}

void my_print(int **arr, int row, int col)
{
    int i,j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
           printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
int **product(int **arr, int **AT, int row, int col)
{
    int i,j, **PM, k;
    //dynamically allocating memory for each row
    PM = malloc(row * sizeof(int *));
    for ( i = 0; i < row; i++)
    {
        //allocating memory for each col in row
        PM[i] = malloc(row * sizeof(int));
    }
     for(i=0; i<row; i++)
    {
        for(j=0; j<row; j++)
        {
            PM[i][j] = 0;
            for(k = 0; k < col; k++)
            {
                PM[i][j] = PM[i][j] + arr[i][k] * AT[k][j];
            }
        }
    }
     return PM;
}
