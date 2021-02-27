/*
Author Name	:-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:-12 Mar 2020
Description	:-WAP to implement fragments using Array of Pointers (First Static Second Dynamic).
Output		:-./fragments
Enter no.of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 3
Enter no of columns in row[2] : 5
Enter 4 values for row[0] : 1 2 3 4
Enter 3 values for row[1] : 2 5 9
Enter 5 values for row[2] : 1 3 2 4 1
After Sorting output is:
1 3 2 4 1 2.22
1 2 3 4 2.5
2 5 9 5.33
Do you want to continue(Y/y) : N
*/

#include <stdio.h>
#include <stdlib.h>

//defining macros
#define ARR_ROW 20
#define ARR_COL 20
#define MAXVAL 200

void sortintNumbers(float array[], int intCount);
void swap_generic(void * aptr, void * bptr, int size);
float averageOfArray(float intArray[], int intCount);
int medianOfArray(float intArray[], int intCount);

int main()
{
    int no_of_fragments, i, no_of_elements_in_each_fragment, j;
	
	printf("Enter the number of rows.\n");
	scanf("%d", &no_of_fragments);
	
	float ** const dp = (float **) malloc(no_of_fragments * sizeof(float *));
	float avgbuffer[MAXVAL], fragment_length_buffer[MAXVAL];
	float median_buffer[MAXVAL];
	
	if (NULL == dp)
	{
		printf("Error: Malloc allocation failed\n");
		return 1;
	}
    
	for(i = 0; i < no_of_fragments; i++)
	{
	
		printf("Enter the number of columns in row[%d]: ", i);
		scanf("%d", &no_of_elements_in_each_fragment);
		fragment_length_buffer[i] = no_of_elements_in_each_fragment;
		
		dp[i] = (float *) malloc((no_of_elements_in_each_fragment+1) * sizeof(float));
		
		if (NULL == dp[i])
		{
			printf("Error: Malloc allocation failed for fragment[%d].\n", i);
			return 1;
		}
		
		for(j = 0; j < no_of_elements_in_each_fragment; j++)
		{
            printf("element [%d][%d] --> ", i, j); 
			scanf("%f", &dp[i][j]);
		}
		
		//sort the numbers
		sortintNumbers(dp[i], no_of_elements_in_each_fragment);
        //to get median
		median_buffer[i] = medianOfArray(dp[i], no_of_elements_in_each_fragment);
		
		//to get the average
		dp[i][j] = averageOfArray(dp[i], no_of_elements_in_each_fragment);
		avgbuffer[i] = dp[i][j];
	}
	
	float *tempptr;
	float tempval;
	
	printf("entered elements after sort and average \n");
	for(i = 0; i < no_of_fragments; i++)
	{
		
		for( j = 0; j < (no_of_fragments-1-i); j++)
		{
			
			// based on median value
			if (median_buffer[j] > median_buffer[j+1])
			{
				//swap fragment_length_buffer
				tempval = fragment_length_buffer[j];
				fragment_length_buffer[j] = fragment_length_buffer[j+1];
				fragment_length_buffer[j+1] = tempval;
				
				//swap actual arrays
				tempptr = dp[j];
				dp[j] = dp[j+1];
				dp[j+1] = tempptr;

				//swap median to correspond to the same arrangement
				tempval = median_buffer[j];
				median_buffer[j] = median_buffer[j+1];
				median_buffer[j+1] = tempval;
				
				//swap avg to correspond to same arrangement
				tempval = avgbuffer[j];
				avgbuffer[j] = avgbuffer[j+1];
				avgbuffer[j+1] = tempval;
			}		
		}
		printf("\n");
		
		printf("Output \n");
		for(i = 0; i < no_of_fragments; i++)
		{
			for( j = 0; j < (fragment_length_buffer[i]+1); j++)
			{
				printf("%f  ", dp[i][j]);
			}
			printf("\n");
		}
		
	}
	
    return 0;
}


void sortintNumbers(float array[], int intCount)
{
    int i, j;
    
    for (i = 0; i < intCount; i++)
    {
        for (j = 0; j < intCount - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                swap_generic((array+j), (array+j+1), sizeof(int));
            }
        }
    }
}


void swap_generic(void * aptr, void * bptr, int size)
{
    int i;
    char temp;
    
    for ( i = 0; i < size; i++ )
    {
        temp = * (char *) aptr;
        * (char *) aptr++ = * (char *) bptr;
        * (char *) bptr++ = temp;
    }
}

float averageOfArray(float intArray[], int intCount)
{
    int i;
	float average = 0, sum = 0;
	
	// Compute the mean of all elements
    for (i = 0; i < intCount; i++)
    {
        sum += intArray[i];
    }
    average = (float) sum / intCount;
    sum = 0;
	
	return average;
}

int medianOfArray(float intArray[], int intCount)
{
	int median;
	
	// To get the median
    // if intCount is odd, median is the middle number in sorted array
    if ( ( intCount % 2) != 0)
    {
        median = intArray[intCount/2];
    }
    /* if intCount is even, take the 2 middle numbers ((intCount / 2) and (intCount / 2) - 1 elements) and median will be average of them. */
    else
    {
        median = ((intArray[intCount/2] + intArray[(intCount/2)-1])/2);
    }
	return median;
}
