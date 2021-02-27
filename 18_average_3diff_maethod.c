/*
Author Name	    :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		    :-1 jun 2020
Description	    :-To find the average of n numbers by taking input in 3 different ways
Input		    :-take num integer
Output		:-./avg
                Test Case 1:
                            Select the method to calculate average:
                            1. Scan from keyboard.
                            2. Proceed with environment variable arguments.
                            Enter you choice: 1
                            Enter the total number of integers : 4
                            Enter the elements: 3 5 10 7
                            The average of entered numbers: 6.25
               Test Case 2:
                ./avg 3 5 10 7
                Select the method to calculate average:
                1. Scan from keyboard.
                2. Proceed with provided command line arguments.
                3. Proceed with environment variable arguments.
                Enter you choice: 2
                The average of entered numbers : 6.25
               Test Case 3:
                export arr="1 2 3 4"
                ./avg
                Select the method to calculate average:
                1. Scan from keyboard.
                2. Proceed with environment variable arguments.
                Enter you choice: 2
                The average of entered numbers : 6.25
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float average(int *arr, int num);     //function prototype

int main(int argc, char *argv[], char *envp[]) //taking input through command line argument
{
    char ch;
    do      //user prompt do while body
    {
        int num, i, option;
        float res;
        printf("\nSelect option to calculate average:-\n1. scan from keyboard\n2. proceed with provided command line argument\n");
        printf("3. proceed with environment variable arguments\n\nSelect your option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                {
                    printf("\nEnter total number of integers: ");
                    scanf("%d", &num);
                    //initialising array
                    int arr[num];
                    printf("Enter the elements : ");
                    //populating the array element 
                    for(i = 0; i < num; i++)
                        scanf("%d", &arr[i]);
                    res = average(arr, num); //function call
                    printf("\nThe average of entered number : %.3f\n", res);
                    break;
                }
            case 2:     //case for command line
                {
                    //initialising array
                    // argc is used to count number of arguments passed
                    int arr[argc-1];    // argc -1 neglecting ./a.out
                    for(i = 0; i < argc-1; i++)
                        //atoi converting string to integer
                        //i+1 to neglect 1st argument that is ./a.out
                        arr[i] = atoi(argv[i+1]); //argv[] argument vector is 1-d array
                    res = average(arr, argc-1);
                    printf("\nThe average of entered number : %.3f\n", res); //printing upto 3 decimal
                    break;
                }
            case 3:     //case for environment list
                {
                    int count = 0, i, number[15];
                    float sum = 0;
                    char *arr;
                    const char  del[2] = " "; //delimiter
                    char *token;
                    arr = getenv("arr"); //getting data from environment variable
                    printf("\narr = %s.\n", arr);
                    token = strtok(arr,del); // getting the first tokken
                    while (token != NULL)   //taking the same string until null
                    {
                        count++;
                        number[count] = atoi(token); //converting string to integer
                        sum = sum + number[count];
                        token = strtok(NULL, del);
                    }
                    res = sum / count;
                    printf("\nThe average of entered number : %.3f\n", res); //printing upto 3 decimal
                    break;
                }
            default:
                printf("\nInvalid Input try again !!!\n");
        }
        printf("\n\nDO you want to continue again ? (y/n) : ");
        scanf("\n%c", &ch);
    }
    while (ch == 'y');  //user prompt do while body ending
    return 0;
}
float average(int *arr, int num)
{
    int i, sum = 0;
    float avg;
    for (i = 0; i < num; i++)
        sum = sum + arr[i];
    avg = (float) sum / num;
    return avg;
}
