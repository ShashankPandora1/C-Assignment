/*
Author Name	:-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:- 5 May 2020
Description	:-To find factorial for given number using the recursive method and without using any other function than main function
Input		:-Integers num
Output      :-./factorial
               Enter the value num: 7
               Factorial of 7 is   : 5040
*/
#include<stdio.h>
int main()
{
    char c;
    static int flag = 0, fact, num, print_fact = 0,var;     //satic variable preserve their previous value in previous scope 
    if (flag == 0)      // initialy  flag is set to 0 
    {
        printf("Enter a number num: ");     
        scanf("%d", &num);      //taking i/p from user
        if (num < 0)
        {
            printf("Invalid input\n");
        }
        if (num == 0 || num ==1)
        {
            print_fact = 1;
        }
        fact = num;
        var = num;      //here var is only to store the orignal value. i used it for printing purpose only in line 30.
        flag = 1;      //After initializing one time flag will set to 1
    }
    if (print_fact == 1)
    {
        if (num == 0 || num == 1)
        {
            printf("\nFactorial of %d is : 1\n", num);
        }
        else
        {
            printf("\nFactorial of %d is : %d\n", var, num);     //printing the factorial
        }
        printf("\nDo you want to continue? (y/n): ");         //user prompt. to re-run the program
        scanf("\n%c", &c);
        if (c == 'y')       //if user want to continue
        {
            flag = 0;     //flag will become 0 
            print_fact = 0;
            main();      // call the main function again
        }
        else
        {
            return 0;
        }
    }
    if ( fact > 1)
    {
        num = num * --fact;  //fact is first decrement and than assign
        if (fact == 1)
        {
            print_fact = 1; //it will be checked in next instance when main() is called.
        }
        main();      // recursion main() will be called again
    }
}
