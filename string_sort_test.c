#include<stdio.h>
#include<string.h>
int main()
{
    int num, i, j;
    int size; 
    printf("\nEnter number of elements : ");
    scanf("%d", &num);
    char str[num][20], temp[num];
    printf("\nEnter %d strings\n", num);
    for ( i = 0; i < num; i++ )
    {
        printf("str[%d] --> ", i);
        scanf("%s", str[i]);
    }
    for (i = 0; i < num-1; i++)
    {
        for (j = 0; j < num-1-i; j++)
        {
            if (strcmp(str[j],str[j+1]) < 0)
            {
                strcpy(temp,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],temp);

            }
        }
    }
    printf("After sorting : ");
    for ( i = 0; i < num; i++)
    {
        printf("%s ", str[i]);
    }
    printf("\n");
    return 0;
}



