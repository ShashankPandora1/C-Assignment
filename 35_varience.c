/*
Author Name	:-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:- 5 May 2020
Description	:-To calculate the variance
Input		:- Array of N integers
Output		:-./variance
*/

#include<stdio.h>

float var( float arr1[], int num);      //function prototype defination

int main()
{
    char c;
    do          //user prompt defination
    {
    int i, num;
    float result;
    printf("\nEnter the N value: ");
    scanf("%d", &num);
    float arr1[num];
    printf("\nEnter %d real number\n", num);
    for (i = 0; i < num; i++)
    {
        printf("Num[%d] --> ", i); 
        scanf("%f", &arr1[i]);      //populating the array with real number
    }
    result = var(arr1,num);
    printf("\nThe variance of entered number is : %f\n", result);
    printf("\n\nDo you want to continue? (y/n): ");
    scanf("\n%c", &c);
    }
    while (c == 'y');       //user prompt do while ending
    return 0;
}

float var( float arr1[], int num)
{
    int i;
    float mean, variance, sum = 0, diff, varsum = 0;
    for (i = 0; i < num; i++)       //loop wll iterate till num times
    {
        sum = sum + arr1[i];       //sum the each element of array
    }
    mean = sum / (float)num;        //num is int type so type casting is used
    for (i = 0; i < num; i++)
    {
        diff = arr1[i] - mean;      //finding diff of array
        varsum = varsum + (diff * diff);
    }
    variance = varsum / (float) num;   //type casting

    return variance;           //returning the variance 
}
