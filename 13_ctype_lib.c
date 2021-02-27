/*
Author Name     :-Shashank Pandora
Organisation	:-Emertxe Information Technologies (P) Ltd.
Date		:-28 April 2020
Description	:-To execute and Implement ctype library to check for input is valid or not using ctype lib function.
Input		:-User will enter the Character to check if its a valid under ctype library.
Output		:-./ctype_lib
		  Enter a Character : a
		  Select option
		  1.isalpha
		  2.isalnum
		  3.isascii
		  4.isblank
		  Enter your choice : 2
		  Character 'a' is Alphabet and of Lower Case
*/
#include<stdio.h>
//Function prototype 
int is_alpha (char);
int is_alnum(char);
int is_ascii(char);
int is_blank(char);

int main()
{
    char c;         //user prompt defination
    do
    {
        char ch;
        int n,var;
        printf("Select any option:\n1. isalpha\n2. isalnum\n3. isascii\n4. isblank\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        printf("Enter a character: ");
        scanf("\n%c",&ch);
        switch (n)
        {
            case 1:     //case for is_alpha() function
                if (is_alpha(ch) == 1)  //checking if return is 1
                    printf("Character '%c' is an alphabet of upper case\n",ch);
                else if (is_alpha(ch) == 2)     //checking if return is 2
                    printf("Character '%c' is an alphabet of lower case\n",ch);
                else
                    printf("Character '%c' is Not an alphabet\n",ch);
                break;
            case 2:     //case for is_alnum() funtion
                if (is_alnum(ch) == 1)   //checking for return 1
                    printf("Characteer '%c' is alphanumeric of digit\n",ch);
                else if (is_alnum(ch) == 2)      //checking for return  2
                    printf("Character '%c' is alphabet of upper case\n",ch);
                else if (is_alnum(ch) == 3)      //checking for return 3
                    printf("Character '%c' is alphabet of lower case\n",ch);
                else
                    printf("Character '%c' is Not a alpanumeric\n",c);
                break;
            case 3:     //Case for is_ascii() function
                if (is_ascii(ch) == 0)
                    printf("Character '%c' is Ascii character\n",ch);
                break;
            case 4:     //Case for is_blank() function
                if (is_blank(ch) == 1)
                    printf("Character '%c' is a blank character\n",ch);
                else
                    printf("Character '%c' is Not a blank character\n",ch);
                break;
            default :
                printf("Invalid Choice\n");
        }
        printf("Do you want to continue again ? (y/n) ");
        scanf("\n%c",&c);
    }
    while (c == 'y');      //to re-run the program. do while body ending
    return 0;
}

int is_alpha (char ch)
{
    if ( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) )   //for alphabets
    {
        if (ch >= 65 && ch <= 90)     //condition for upper case alphabets
        {
            return 1;          
        }
        else                         //else for lower case alphabets
            return 2;            
    }
    else        //it user enter non alphabet
        return 0;
}
int is_alnum (char ch)
{
    if (ch >= 48 && ch <= 57)      //check for digits
        return 1;
    else if (ch >= 65 && ch <= 90)     //checks for upper case alphabets
        return 2;
    else if (ch >= 97 && ch <= 122)    //check for lower case alphabets
        return 3;
    else
        return 0;
}
int is_ascii (char ch)
{
    if (ch >= 0 && ch <= 127)     //checks for all ascii
        return 0;
}
int is_blank (char ch)
{
    if (ch == ' ' || ch == '\t'  )  //checks for blank spaces
        return 1;
    else
        return 0;
}
