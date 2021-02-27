#include<stdio.h>

int my_strcmp(char x[], char y[])
{
    int i = 0;
  
    while (x[i] != '\0' || y[i] != '\0')
    {
        if (x[i] != y[i])       //condtion to check the both are not equall 
            return (x[i] - y[i]);       //function will terminate and return the differrnce 
        i++;
    }
    return 0;
}
int main()
{
    int num, val;
    printf("Enter num : ");
    scanf("%d", &num);

    char s1[num], s2[num];
        printf("string1 --> ");
        scanf("%s[^\n] ", s1); 
        printf("string2 --> ");
        scanf("%s[^\n] ", s2);

    val = my_strcmp(s1,s2);
    if (val == 0)
    {
        printf("\nBoth string are equal\n");
    }
    else
        printf("\nBoth string are different\n");
    
    return 0;
}

