/*
Author Name	:-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:- 5 May 2020
Description	:-pre and post increment and passing int pointer as their paprameter
Input		:-2 integers num1 , num2.
Output		:-./Inc
               Enter the value of num: 5
               Enter the operation:
                 1. pre-increment
                 2. post-increment
               choice : 2
               after post increment i = 5, num = 6
*/
#include<stdio.h>
//function prototype defination
int post_inc(int *num, int i);
int pre_inc(int *num, int i);

int main()
{
    char c;
    do          //user prompt defination
    {
        int num,choice,i;
        printf("Enter the number num =  ");
        scanf("%d", &num);
        printf("\t1. PRE INCREMENT\n\t2. POST INCREMENT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:             //case for PRE INCREMENT
                i = pre_inc(&num,i);
                num = i;
                printf("\nAfter pre-increment:\ti = %d\tnum = %d\n",i,num);
                break;
            case 2:             //case for POST INCREMENT
                i = num;
                num = post_inc(&num,i);
                printf("\nAfter post increment:\ti = %d\tnum = %d\n",i,num);
                break;
            default:
                printf("Enter valid choice\n");
        }
        printf("\nDo ypu want to continue? (y/n) : ");
        scanf("\n%c",&c); 
    }
    while (c == 'y');           //user prompt defination do while boby ending
    return 0;
}

int post_inc(int *num, int i)    //fun for post increment
{
    int mask = 1;
    i = *num;       //assigning value of num to i
    while (i & mask)    
    {
        i = i & (~mask);    //inverting the bits of mask
        mask = mask << 1;   //left shift mask by 1
    }
    i = i | mask;
    return i;
}
int pre_inc(int *num, int i)    //fun for pre increment
{
    int mask = 1;
    i = *num;
    while (i & mask)
    {
        i = i & (~mask);    //inverting the bits of mask
        mask = mask << 1;  // lesft shit mask by 1
    }
    i = i | mask;
    return i;
}

