/*
Author Name	:-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:- 5 May 2020
Description	:-to replace each string of one or more blanks by a single blank
Input		:-strig with multispaces between words
Output		:-./remove_multi_space
              Pointers    are    sharp         knives.
              pointers are sharp knives 

*/

#include<stdio.h>
#include<ctype.h>
void remove_blank(int *ch, int i);  //function prototype defination
int main()
{
    char c;
    do          //user prompt defination
    {
    int ch,i;
    printf("Enter the main string with more spaces in b/w two words:");
    remove_blank(&ch,i);
    printf("\n");
    printf("\n\nDo you want to continue? (y/n): ");
    scanf("\n%c", &c);
    }
    while (c =='y');        //user prompt do while ending
    return 0;
}
void remove_blank (int *ch, int i)
{
    i = *ch;
    int flag = 0;
    for ( ;(i = getchar()) != '\n'; )     //get the string 
    {
        if (isblank(i) && flag == 0)    // condition to check spaces b/w characters
        {
            putchar(' ');         //for multiple blank only one space will be given
            flag = 1;             // flag will be set to 1
        }
        if (isalnum(i))          //will check for alphanumeric
        {
            putchar(i);         //charcter will be printed
            flag = 0;           //again flag will be set to 0
        }
    }
}
