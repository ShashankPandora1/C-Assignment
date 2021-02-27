#include<stdio.h>
#include<string.h>
//function prototype defination
int my_strcmp( char x[], char y[] );
void sort_str(void *arr, int num);
int main()
{
    int num, i;

    printf("\nEnter a number : ");
    scanf("%d", &num);

    char arr[num][32];      //declaring 2D array arr[row][col]
    printf("\nEnter %d string\n", num);

    for (i = 0; i < num; i++)
    {
        printf("str[%d] --> ", i);
        scanf("%s[^\n] ", arr[i]);          //populating array with strings till eneter is not pressed
    }
    sort_str(arr, num);     //function invoking

    return 0;
}
int my_strcmp( char x[], char y[] )
{
    int i = 0;

    while (x[i] != '\0' || y[i] != '\0' )   //loop will continue till '\0' i position of both string
    {
        if ( x[i] != y[i] )
            return ( x[i] - y[i] );     //function will return. ascii value will be taken and diff will be return
        i++;    //if both character is same than i will be increment 
    }
    return 0;
}

void sort_str(void *arr, int num)
{
    int i,j;
    char temp[32];
    for ( i = 0; i < num; i++ )
    {
        for ( j = 0; j < num-1-i; j++)
        {
            if ( my_strcmp( ((char *)arr + j*32),((char *) arr + (j+1)*32 ) ) > 0 )     //invoking my_strcmp function returning integer
            {
                strcpy( temp,((char *)arr +j*32) );
                strcpy( ((char *)arr + j*32),((char *)arr +(j+1)*32) );
                strcpy( ((char *)arr + (j+1)*32),temp );
            }
        }
    }
    printf("\nAfter sorting\n");
    for ( i = 0; i < num; i++ )
    {
        printf("str[%d] --> %s \n", i, ((char *)arr + i*32) );
    }
}

