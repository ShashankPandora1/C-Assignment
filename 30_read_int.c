#include<stdio.h>
int read_int(char *ch);     //function defination prototype
int main()
{
    char c;
    do
    {
    char ch[20];            //initializing string of length 20
    int res;
    printf("\nENTER  A NUMBER : ");
    fgets(ch,20,stdin);     //reading values from user 
    res = read_int(ch);     //calling the read_int function and storing value in some var
    printf("\nThe Number is  : %d",res);      //printing the result 
    printf("\n\nDo you want to continue? (y/n) : ");
    scanf("\n%c%*c",&c);
    }
    while ( c == 'y' );
    return 0;
}

int read_int(char *ch)
{
    int sign = 1, result = 0,var;       
    if ( *ch == '-' )       //condition to cehck if sign is -ve
    {
        ch++;       //increment the index of of ch
        sign = -1;  //if number is negative sign is set to -1
    }
    if ( *ch == '+' )       //if the sign is +ve
    { 
        ch++;           //increment the ch 
    }
    while ( *ch != '\0' && *ch != '\n')         //checking for null character and enter. 
    {
        if (*ch >= '0' && *ch <= '9')           //ascii value for digit
        {
            result = (result * 10) + (*ch - '0');
            ch++;
        }
        else 
        {
            break ;         //if not a digit terminate the loop come out of the loop
        }
    }
    var = result * sign;
    return var;
}


