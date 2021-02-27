/*
Author Name	:-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:- 5 May 2020
Description	:-To swap two variables by using passby reference method and using bitwise operator.
Input		:-2 integers num1 , num2.
Output		:-./swap
                Enter num1: 10
                Enter num2: 20
                after swapping
                num1 = 20
                num2 = 10
*/

#include<stdio.h>

void swap(int *num1, int *num2);        //function prototype defination

int main()
{
    char c;
    do          //user prompt defination
    {
    int num1, num2;
    printf("Enter a number num1 = ");
    scanf("%d", &num1);
    printf("Enter a number num2 = ");
    scanf("%d", &num2);

    swap(&num1, &num2);         //swap function call

    printf("\nAfter swaping\n");
    printf("num1 = %d\nnum2 = %d\n", num1, num2);
    printf("\nDO yu want to continue? (y/n) : ");
    scanf("\n%c", &c);
    }
    while (c == 'y');       //user defination prompt do while body ending
    return 0;
}
void swap(int *num1, int *num2)     //function to swap two variables using bitwise operaor
{
    *num1 = *num1 ^ *num2;      //using xor and storing the result in num1
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
