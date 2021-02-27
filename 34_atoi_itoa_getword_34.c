#include<stdio.h>
#include<ctype.h>

//Function defination prototype
int my_atoi (char *str);
void my_itoa (int num, char *str);   
int my_getword(char *word);
int main()
{
    char c;
    do          //user prompt defination
    {
    int choice, num;
    char str[20], s[20];
    printf("Select your option\n");
    printf("\n1. atoi\n2. itoa\n3. getword\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:     //case for atoi
                printf("\nEnter a numeric string : ");
                scanf("%*c%[^\n]", str);        //input string of len 20 till \n
                printf("\nString to Integer is : %d\n", my_atoi(str));      //invoking function my_atoi and returning the address 
                break;
        case 2:     //case for itoa
                printf("\nEnter a numeric string : ");
                scanf("%d", &num);
                my_itoa(num, s);          //function call
                printf("\nInteger to String : %s", s);
                break;
        case 3:     //case for getword
                printf("Enter a string : ");
                while ( getchar() != '\n' );
                scanf("%20[^\n]", str);            //reading the string from user till \n of max len 20 character
                printf("\nYou entered : %.*s\n", my_getword(str), str);   //invoking the function and passing the string
                while ( getchar() != '\n' );        //to clear the stdin buffer
                break;
        default :
            printf("\nInvalid Input\n");
    }
    printf("\n\nDo you want to continue? (y/n): ");
    scanf("\n%c", &c);
    }
    while (c == 'y');           //user defined prompt. do while body ending
    return 0;
}

int my_atoi (char *str)
{
    int sign = 1, result = 0;
    if ( *str == '-' )   //checking if the numbr is negative having - ve sign at start
    {
        str++;          //incrementing the address
        sign = -1;      //than sign is set to -1
        while ( *str == '+' )   //remove + operator if it appears after - 
            str++;
    }
    if ( *str == '+' )
    {
        str++;
        while ( *str == '-' )       //remove - operator if it appears after +
        {
            sign = -1;
            str++;
        }
    }
    while (*str != '\0')
    {
        if (isdigit(*str))     //checking if digit.
        {
            result = (result * 10) + (*str - '0');    //converting the number to integer 
            str++;
        }
        else
            break;      //loop will break if not an number 
    }
    return result * sign;       //if number is negative sign will be -1, otherwise it is 1 only
}

int my_getword (char *word)
{
    int count = 0;
    while ( *word )
    {
        if (isalpha(*word))
        {
            count++;
            word++;
        }
        else
            break;
    }
    return count;
}

void my_itoa(int num, char *s)
{
    int rev = 0, n = num;
    if ( num < 0 )
    {
        *s = '-';   //adding - in the starting if number is less than 0
        s++;        //inc. the bae address
        num = num * -1;     //converting from -ve to +ve number
    }
    if (num == 0)
    {
        *s = '0';   //if user enter 0 than store 0 character and return
        return;
    }
    //reversing the number
    while (num)
    {
        rev = (rev * 10) + num % 10;
        num = num / 10;
    }
    while (1)
    {
        if (rev != 0)
        {
            *s = rev % 10 + '0';    //taking last element of reverse and adding 0 to turn into character 
            s++;
            rev = rev/10;         //after taking last than removin that element
        }
        else
            break;
    }
    while (n)
    {
        if (n%10 == 0)
        {
            *s = '0';
            s++;
            n = n/10;
        }
        else
            break;
    }
}
 

