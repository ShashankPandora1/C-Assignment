/*
Author Name             :-Shashank Pandora
Organisation            :-Emertxe Information Technologies (p) Ltd.
Date                    :-10 Mar 2020
Description             :-Give the number from 1 to 365, WAP tofind which day of the year
Input                   :-Positive integer say 'N'. Where 1 <= 'N' <= 365.
                          Option to set the first day.
Output                  :-Choose the first day: 
                          1. Sunday
			  2. Monday
			  3. Tuesday
			  4. Wednesday
			  5. Thursday
			  6. Friday
			  7. Saturday
			  Enter the option to set the first day : 2
			  Enter the value of num : 9
			  The 9th day is Tuesday
*/
#include<stdio.h>

int main()
{
    char c;
    do                 
    {
    int num,day,i;

    printf("1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");
    printf("Enter the option to set the first day: ");
    scanf("%d",&day);
    printf("Enter the number (1 to 365): ");
    scanf("%d", &num);
    for(i = 1; i <= num; i++)          //Loop to count days
    {
	if(day > 0 && day <= 7)       //condition to count days from the set day
	{
	    day++;
	}
	else
	{
	    day = 1;
	}
    }
    switch( day )
    {
	case 1:
	    printf("The %dth day is Sunday\n",num);
	    break;
	case 2:
	    printf("The %dth day is Monday\n",num);
	    break;
	case 3:
	    printf("The %dth day is Tuesday\n",num);
	    break;
	case 4:
	    printf("The %dth day is Wednesday\n",num);
	    break;
	case 5:
	    printf("The %dth day is Thursday\n",num);
	    break;
	case 6:
	    printf("The %dth day is Friday\n",num);
	    break;
	case 7:
	    printf("The %dth day is Saturday\n",num);
	    break;
    }
    printf("Do you want to continue (y/n): ");
    scanf("\n%c", &c);
    }
    while( c == 'y' );   //to re-run the program user intractive prompt. do while body ending
return 0;
}
