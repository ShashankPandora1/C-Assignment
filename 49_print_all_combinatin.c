/*
Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-5 jun 2020
Description	    :-WAP to print all possible combinations of given string.
Input		    :-Read string
Output		    :-./combination
        	Enter a string: abc
abc
acb
bca
bac
cab
cba
Do you want to continue (Y/y) : y

*/
#include <stdio.h>
#include <string.h>

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
	int i;
	if (l == r)
		printf("%s\n", a);
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a+l), (a+i));
			permute(a, l+1, r);
			swap((a+l), (a+i)); //backtrack
		}
	}
}

int main()
{
	char ch;
do 	//user prompt do while body
{
	char str[200];	//initialising the string of max 200 char
	printf("Enter string : ");
	scanf("%[^\n]%*c", str); //reading the string toll enter
	int n = strlen(str);
	permute(str, 0, n-1);
printf("\n\nDo you want to continue (y/n)? : ");
scanf("\n%c%*c", &ch);
}
while (ch == 'y'); //user promot do while ending
	return 0;
}
