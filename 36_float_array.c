/*
Author Name	:-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:-12 Mar 2020
Description	:-To execute, read and store float numbers in array and sort them without modification and copying to array.
Input		:-User will enter floating values and store in array, pass in function to sort without modification of original array.
Output		:-./Enter size of array : 4
		  [0] = 3.54
		  [1] = 5.344
		  [2] = 1.45
		  [3] = 8.3
		  After sorting : 1.45  3.54  5.344  8.3
*/

#include<stdio.h>

void sort_arr(float*,int);	//Function prototype defination

int main()
{
    char c;		//User prompt defination;
    do
    {
	int i, j, size, flag=0;
	printf("Enter a size of float array :");
	scanf("%d",&size);
	float array[size];
	printf("\n");
	for (i=0; i<size; i++)	//Loop to read array from user
	{
	    printf("Enter %dth index element : ",i);
	    scanf("%g",&array[i]);
	    for (j=0; j<i; j++)		//Loop to check for Duplicates elements
	    {
		if (array[j] == array[i])
		{
		    printf("\nArray has Duplicate elements\n");
		    flag = 1;
		}
	    }
	    if (flag)
		break;
	}
	sort_arr(array,size);	//Invoking function to pass array to sort, but not returning anything
	printf("\n\nDo you want to continue again? (y/n) ");
	scanf("\n%c",&c);
    } while (c == 'y');		//User prompt do while body ending
    return 0;
} 
void sort_arr(float *ptr_arr, int size)
{
    int i, j, k, count2 = size - 1;
    float max;
    printf("\n\n");
    for (k=0; k<size; k++)	//Loop to run through elements untill last element is fetched
    {
	for (i=0; i<size; i++)
	{
	    int count = 0;
	    for (j=0; j<size; j++)	//Loop to compare elements
	    {
		if (ptr_arr[i] < ptr_arr[j])	//Condition to sort in asscending order
		{
		    max = ptr_arr[i];
		    ++count;	//Increamenting each time codition becomes true
		}
		else if (!count)	//If count remain zero
		    max = ptr_arr[i];
	    }
	    if (count == count2)	//Comparing no of times count increamentd with count2
	    {
		printf("%g  ",max);
		count2--;	//After each successful execution decreamenting count2
	    }
	}
    }
}

