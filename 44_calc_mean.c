#include<stdio.h>

void calc_mean(void *, int num, void *mean, int choice);        //function defination prototype

int main()
{
    char c;
    do              //user prompt defination
    {
        int choice,i,num;
        printf("Select option\n");
        printf("1. int\n2. short\n3. float\n4. double\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        printf("\nEnter number of elements : ");
        scanf("%d", &num);

        switch ( choice )
        {
            case 1:     //case for int
                {
                    int arr[num], mean = 0;       //initialising array of integer type where num is the size of array
                    printf("\nEnter %d elements\n",num);
                    for (i = 0; i < num; i++)
                    {
                        printf("num[%d] --> ",i);
                        scanf("%d", &arr[i]);       //populating array with integer type values
                    }
                    calc_mean(arr, num, &mean, choice);     //calling the clac_mean function
                    printf("\nThe mean value : %g\n",mean/ (double)num);    //printing the mean
                    break;
                }
            case 2:  //case for short
                {
                    short arr[num], mean = 0;       //initialising array of short type
                    printf("\nEnter %d elements\n", num);
                    for (i = 0; i < num; i++)
                    {
                        printf("num[%d] --> ",i);
                        scanf("%hd", &arr[i]);      //populating array with elements
                    }

                    calc_mean(arr, num, &mean, choice);     //calling cal_mean function
                    printf("\nThe mean value : %g\n", mean/ (double)num);   //printing mean
                    break;
                }
            case 3:     //case for float
                {
                    float arr[num], mean = 0;       //initialising array of float type
                    printf("\nEnter %d elements\n", num);
                    for (i = 0; i < num; i++)
                    {
                        printf("num[%d] --> ",i);
                        scanf("%f", &arr[i]);       //populating array with elements
                    }

                    calc_mean(arr, num, &mean, choice);         //calling calc_mean function
                    printf("\nThe mean value : %g\n", mean/ (double)num);       //printing mean
                    break;
                }
            case 4:    //case for float
                {
                    double arr[num], mean = 0;      //initialising array of double type 
                    printf("\nEnter %d elements\n", num);
                    for (i = 0; i < num; i++)
                    {
                        printf("num[%d] --> ",i);
                        scanf("%lf", &arr[i]);      //populating array with elements
                    }

                    calc_mean(arr, num, &mean, choice);       //calling calc_mean function
                    printf("\nThe mean value : %g\n", mean/ (double)num);       //printing mean
                    break;
                }
            default :
                printf("\nInvalid Option\n");
        }
        printf("\n\nDo you want to continue again ? (y/n) : ");
        scanf("\n%c", &c);
    }
    while (c == 'y');           //user prompt defination. do while body ending
    return 0;
}

void calc_mean(void *arr, int num, void *mean, int choice)
{
    int i;
    if (choice == 1)    //case for int 
    {
        for ( i = 0; i < num; i++)
        {
            *(int *)mean += *((int *)arr + i);  //typecasting from void type to integer type
        }
    }
    else if (choice == 2)
    {
        for (i = 0; i< num; i++)
        {
            *(short *)mean += *((short *)arr + i);
        }
    }
    else if (choice == 3)
    {
        for (i = 0; i < num; i++)
        {
            *(float *)mean += *((float *)arr + i);
        }
    }
    else if (choice == 4)
    {
        for (i = 0; i < num; i++)
        {
            *(double *)mean += *((double *)arr + i);
        }
    }
}


