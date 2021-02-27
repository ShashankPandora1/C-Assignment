#include<stdio.h>
#include<string.h>

char *squeeze(char *, char *);      //function prototype defination
int main()
{
    char c;         //user prompt defination
    do
    {
    char str1[100], str2[100];
    printf("\nEnter String1 : ");
    scanf("%100[^\n]", str1);   //can read max of 100 character and it read untill enter is pressed 
    while(getchar() != '\n');   //To neglect \n from stdin buffer
    printf("\nEnter String2 : ");
    scanf("%100[^\n]", str2);

    printf("\nAfter string squeezed : %s\n", squeeze(str1, str2));      //invoking function call and returning string address
    printf("\n\nDo you want to continue? (y/n): ");
    scanf("\n%c%*c", &c);
    }
    while (c == 'y');       //user prompt do while body ending 
    return 0;
}

char *squeeze(char *str1, char *str2)
{
    static char str3[100];      //To store string into the data segment
    char *ptr = str3;
    int i, j, len1, len2;
    len1 =  strlen(str1);       //finding length of string 1
    len2 = strlen(str2);        //finding length of string 2

    for (i = 0; i < len1; i++)
    {
        int f = 0;
        for (j = 0; j < len2; j++)
        {
            if (str1[i] == str2[j])         //checking if string character is matched 
                f = 1;
        }
        if ( f == 0 )
        {
            sprintf(ptr++,"%c", str1[i]);      //checking if string is not matched read in string
        }
    }
    return str3;        //returning string address
}
    

