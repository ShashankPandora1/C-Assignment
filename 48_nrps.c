/*
Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-5 jun 2020
Description	    :-WAP to take n and k (1 <= k <= 10) as inputs. Generate consecutive NRPS of length n using k distinct character (0 <= k <= 9)
Input		    :-Enter length of string 'n'
                  Enter number of distinct character 'k'
                  Enter 3 distinct character
Output		    :-./nrps
        		    Enter length of string 'n' : 6
                    Enter number of distinct character 'k' : 3
                    Enter 3 distinct character : a b c

                    NRPS ---> abcbca

*/
#include<stdio.h>
#include<stdlib.h>

void nrps(char *dist, int len, int k); //function prototype

int main()
{
    char ch;
    do      //user prompt do while body
    {
        int n, k, i, j;

        printf("\nEnter the length of string 'n' : ");
        scanf("%d", &n);

        printf("\nEnter number of distinct character 'k' : ");
        scanf("%d", &k);
        //initialising array to store k distinct characters
        char dist[k];
        //error checking 
        if ( (k < 1) || (k > 10) )
        {
            printf("\nInvalid input try again !! *check range of k\n");
            return 1;
        }
        printf("\nEnter k distinct characters\n");
        for (i = 0; i < k; i++)
            scanf("\n%c", &dist[i]);
        // checking for distinct characters
        for (i = 0; i < k; i++)
        {
            for (j = (i+1); j < k; j++)
            {
                if (dist[j] == dist[i]) //if 1st character is equal to 2nd character
                {
                    printf("\nEnter k distinct character *Error --> character are not distinct\n");
                    return 1;
                }
            }
        }
        nrps(dist, n, k);
        printf("\n\nDo you want to continue again (y/n) ? : ");
        scanf("\n%c", &ch);
    }
    while (ch == 'y'); //user prompt do while ending
    return 0;
}
void nrps(char *dist, int n, int k)
{
    int i, val = 0;
    printf("\nNRPS ---> ");
    for (i = 0; i < n; i++)
    {
        if (i%k == 0 && i != 0)
            val++;
        printf("%c", *(dist + ((i+val)%k)));
    }
    printf("\n");
} 

