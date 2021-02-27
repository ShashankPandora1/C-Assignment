#include<stdio.h>
#include<string.h>
void binary_search(void *, int num, int choice, void *find, int *val);        //function defination prototype

int main()
{
    char c;
    do          //user defination prompt 
    {
        int choice,i,num, val;
        printf("Select option\n");
        printf("1. int\n2. char\n3. float\n4. double\n5. String\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        printf("\nEnter number of elements : ");
        scanf("%d", &num);

        switch ( choice )
        {
            case 1:     //case for int
                {
                    int arr[num], find;       //initialising array of integer type where num is the size of array
                    printf("\nEnter %d elements of type int\n",num);
                    for (i = 0; i < num; i++)
                    {
                        printf("num[%d] --> ",i);
                        scanf("%d", &arr[i]);       //populating array with integer type values
                    }
                    printf("\nEnter value you want to find : ");
                    scanf("%d", &find);
                    binary_search(arr, num, choice, &find, &val);     //calling the binary_search funtion
                    if (val == -1)      //checking if search element is present or not in the array
                        printf("\n\nSearch element %d is not found !!!", find);
                    else
                        printf("\n\nSearch element %d is present at index  %d  of array", find, val);    //printing the index value of the search element
                    break;
                }
            case 2:
                {
                    char arr[num], find;
                    printf("\nEnter %d elements of type short\n", num);
                    for (i = 0; i < num; i++)
                    {
                        printf("num[%hhd] --> ", i);
                        scanf("%hhd", &arr[i]);     //populating array
                    }
                    printf("\nEnter value you want to find : ");
                    scanf("%hhd", &find);
                    binary_search(arr, num, choice, &find, &val);
                    if (val == -1)
                        printf("\n\nSearch element %d is not found !!!", find);
                    else
                        printf("\n\nSearch element %d is present at index  %d  of array", find, val);
                    break;
                }
            case 3:
                {
                    float arr[num], find;
                    printf("\nEnter %d elements of type float\n", num);
                    for (i = 0; i < num; i++)
                    {
                        printf("num[%d] --> ", i);
                        scanf("%f", &arr[i]);
                    }
                    printf("\nEnter value you want to find : ");
                    scanf("%f", &find);
                    binary_search(arr, num, choice, &find, &val);
                    if (val == -1)
                        printf("\n\nSearch element %lf is not found !!!", find);
                    else
                        printf("\n\nSearch element %lf is present at index  %d  of array", find, val);
                    break;
                }
            case 4:
                {
                    double arr[num], find;
                    printf("\nEnter %d elements of type double\n", num);
                    for (i = 0; i < num; i++)
                    {
                        printf("num[%d] --> ", i);
                        scanf("%lf", &arr[i]);
                    }
                    printf("\nEnter value you want to find : ");
                    scanf("%lff", &find);
                    binary_search(arr, num, choice, &find, &val);
                    if (val == -1)
                        printf("\n\nSearch element %lf is not found !!!", find);
                    else
                        printf("\n\nSearch element %lf is present at index  %d  of array", find, val);
                    break;
                }
            case 5:
                {
                    char arr[num][20], find;
                    printf("\nEnter %d string\n", num);
                    for (i = 0; i < num; i++)
                    {
                        printf("str[%d] --> ", i);
                        scanf("%s", arr[i]);
                    }
                    binary_search(arr, num, choice, &find, &val);
                   break;
                }
        }
        printf("\n\nDo you want to continue? (y/n) : ");
        scanf("\n%c", &c);
    }
    while ( c == 'y' );         //user defination prompt. do while body ending.
    return 0;
}

void binary_search(void *arr, int num, int choice, void *find, int *val)
{
    int i, j, last = num -1, first = 0, mid;
    if ( choice == 1 )    //case for int
    {
        int arr1[num], temp; 
        for ( i = 0; i < num; i++ )
        {
            for (j = i+1; j < num; j++ )
            {
                if ( *((int *)arr + j) < *((int *)arr + i) )
                {
                    temp = *((int *)arr + i);
                    *((int *)arr + i) = *((int *)arr + j);
                    *((int *)arr + j) = temp;
                }
            }
        }
        printf("\nAFTER SORTING : ");
        for (i = 0; i < num; i++)
        {
            arr1[i] = *((int *)arr + i);
            printf("%d ", arr1[i]);
        }
        while (first <= last)
        {
            mid = (first + last) / 2;
            if ( arr1[mid] == *((int *)find) )
            {
                *val = mid;
                break;
            }
            else if ( arr1[mid] < *((int *)find) )
            {
                first = mid + 1;
            }
            else
            {
                last = mid - 1;
            }
            if (first > last)
            {
                *val = -1;
                break;
            }
        }
    }
    else if ( choice == 2 )  //case for char
    {
        char arr1[num], temp;
        for (i = 0; i < num; i++)
        {
            for (j = i+1; j < num; j++)
            {
                if ( *((char *)arr + j) < *((char *)arr + i) )
                {
                    temp = *((char *)arr + i);
                    *((char *)arr + i) = *((char *)arr + j);
                    *((char *)arr + j) = temp;
                }
            }
        }
        printf("AFTER SORTING : ");
        for (i = 0; i < num; i++)
        {
            arr1[i] = *((char *)arr + i);
            printf("%d ", arr1[i]);
        }
        while (first <= last)
        {
            mid = (first + last) / 2;
            if ( arr1[mid] == *((char *)find) )
            {
                *val = mid;
                break;
            }
            else if ( arr1[mid] < *((char *)find) )
            {
                first = mid + 1;
            }
            else
            {
                last = mid -1;
            }
            if (first > last)
            {
                *val = -1;
                break;
            }
        }
    }
    else if ( choice == 3 )         //case for float
    {
        float arr1[num], temp;
        for (i = 0; i < num; i++)
        {
            for (j = i+1; j < num; j++)
            {
                if ( *((float *)arr + j) < *((float *)arr + i) )
                {
                    temp = *((float *)arr + i);
                    *((float *)arr + i) = *((float *)arr + j);
                    *((float *)arr + j) = temp;
                }
            }
        }
        printf("AFTER SORTING : ");
        for (i = 0; i < num; i++)
        {
            arr1[i] = *((float *)arr + i);
            printf("%f ", arr1[i]);
        }
        while (first <= last)
        {
            mid = (first + last) / 2;
            if ( arr1[mid] == *((float *)find) )
            {
                *val = mid;
                break;
            }
            else if ( arr1[mid] < *((float *)find) )
            {
                first = mid + 1;
            }
            else
            {
                last = mid -1;
            }
            if (first > last)
            {
                *val = -1;
                break;
            }
        }
    }
    else if ( choice == 4 )             //case for double
    {
        double arr1[num], temp;
        for (i = 0; i < num; i++)
        {
            for (j = i+1; j < num; j++)
            {
                if ( *((double *)arr + j) < *((double *)arr + i) )
                {
                    temp = *((double *)arr + i);
                    *((double *)arr + i) = *((double *)arr + j);
                    *((double *)arr + j) = temp;
                }
            }
        }
        printf("AFTER SORTING : ");
        for (i = 0; i < num; i++)
        {
            arr1[i] = *((double *)arr + i);
            printf("%lf ", arr1[i]);
        }
        while (first <= last)
        {
            mid = (first + last) / 2;
            if ( arr1[mid] == *((double *)find) )
            {
                *val = mid;
                break;
            }
            else if ( arr1[mid] < *((double *)find) )
            {
                first = mid + 1;
            }
            else
            {
                last = mid -1;
            }
            if (first > last)
            {
                *val = -1;
                break;
            }
        }
    }
    else if (choice == 5)
    {
        char temp[20];
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < num-i-1; j++)
            {
                if ( strcmp(((char *)arr + j*20), ((char *)arr + 20*(j+1))) > 0 )
                {
                    strcpy(temp,((char *)arr + j*20));
                    strcpy(((char *)arr + j*20),((char *)arr + (j+1)*20));
                    strcpy(((char *)arr + (j+1)*20),temp);
                }
            }
        }
        printf("\nAfter Sorting : ");
        for (i = 0; i < num; i++)
        {
            printf("%s ", ((char *)arr + i*20));
        }
        printf("\n");
    }
}
