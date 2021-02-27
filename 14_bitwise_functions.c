/*
   Author Name	:-Shashank Pandora
Organisation	:Emertxe Information Technologies (P) Ltd.
Date		:-14 Mar 2020
Description	:-To execute and perform bitwise functions to do various operations.
Input		:-User will give the value for Input to perform bitwise operation defined under function body.
Output		:-Select bitwise operation from below lists
1. get_nbits
2. set_nbits
3. get_nbits_from_pos
4. set_nbits_from_pos
5. toggle_bits_from_pos
6. print_bits
Enter your choice : 3
Enter a num : 12
Enter n : 3
Enter pos : 5
value at 12[5,3] is 1
 */		  
#include<stdio.h>
//function prototype definiation
int get_nbits(int num1, int n1);
int replace_nbits(int num, int n, int val);
int get_nbits_from_pos(int num, int n, int pos);
int replace_nbits_from_pos(int num, int n, int pos, int val);
int toggle_bits_from_pos(int num, int n, int pos);
int print_bits(unsigned int num, int n);
int main()
{
    char c;	//User prompt defination
    do
    {
	int num, n, val, pos, option;
	printf("Select bit operation from below list\n1. get_nbits\n2. replace_nbits\n3. get_nbits_from_pos\n");
	printf("4. replace_nbits_from_pos\n5. toggle_bits_from_pos\n6. print_bits\n");
	printf("Enter your choice : ");
	scanf("%d",&option);
	switch (option)
	{
	    case 1:	//Case for get_nbits
		printf("Enter num\t: ");
		scanf("%d",&num);
		printf("Enter n\t: ");
		scanf("%d",&n);
		if (num > 0 && n > 0)
		    printf("%d bit(s) of Decimal number %d is : %d",n,num,get_nbits(num,n));	//Invoking function and printing output
		else
		    printf("Inavlid Input\n");
		break;
	    case 2:	//Case for replace_nbits
		printf("Enter num\t: ");
		scanf("%d",&num);
		printf("Enter n\t\t: ");
		scanf("%d",&n);
		printf("Enter Val\t: ");
		scanf("%d",&val);
		//Invoking function and printing output
		printf("After replacing Number %d by %d in %d bit(s) is : %d",num,val,n,replace_nbits(num,n,val));
		break;
	    case 3:	//Case for get_nbits_from_pos
		printf("Enter num\t: ");
		scanf("%d",&num);
		printf("Enter n\t\t: ");
		scanf("%d",&n);
		printf("Enter Postion\t: ");
		scanf("%d",&pos);
		//Invoking function and printing its return output
		printf("%d bit(s) from %d positon of Number %d is : %d",n,pos,num,get_nbits_from_pos(num,n,pos));
		break;
	    case 4:	//Case for replace_nbits_from_pos
		printf("Enter num\t: ");
		scanf("%d",&num);
		printf("Enter n\t\t: ");
		scanf("%d",&n);
		printf("Enter Postion\t: ");
		scanf("%d",&pos);
		printf("Enter Val\t: ");
		scanf("%d",&val);	
		//Invoking function and printing its retrun output
		printf("After replacing Number %d by %d with %d bit(s) from position %d is : %d",num,val,n,pos,replace_nbits_from_pos(num,n,pos,val));
		break;
	    case 5:	//Case for toggel_nbits_from_pos
		printf("Enter num\t: ");
		scanf("%d",&num);
		printf("Enter n\t\t: ");
		scanf("%d",&n);
		printf("Enter Postion\t: ");
		scanf("%d",&pos);
		//Invoking function and printing its return output
		printf("After toggeling Number %d with %d bit(s) from %d position is : %d",num,n,pos,toggle_bits_from_pos(num,n,pos));
		break;
	    case 6:	//Case for print_bits
		printf("Enter num\t: ");
		scanf("%d",&num);
		printf("Enter n\t\t: ");
		scanf("%d",&n);
		print_bits(num,n);	//Only invoking function, not retruning output to main function
		break;
	}
	printf("\n\nDo you want to continue again? (y/n) ");
	scanf("\n%c",&c);
    } while (c == 'y');		//User prompt do while body ending
    return 0;
} 
int get_nbits(int num, int n)
{
    return (num & ((1 << n) - 1));
}
int replace_nbits(int num, int n, int val)
{
    return (num & ~((1 << n) - 1)) | (val & ((1 << n) -1)); //(1 << n) 1 will be shifted left 'n' times.
}
int get_nbits_from_pos(int num, int n, int pos)
{
    return (num & (((1 << n) - 1) << (pos - n + 1))) >> (pos - n + 1);
}
int replace_nbits_from_pos(int num, int n, int pos, int val)
{
    return (num & ~(((1 << n) - 1) << (pos - n + 1))) | (val & ((1 << n) - 1)) << (pos - n + 1);
}
int toggle_bits_from_pos(int num, int n, int pos)
{
    return (num ^ (((1 << n) - 1) << (pos - n + 1)));
}
int print_bits(unsigned int num, int n)
{
    return !!(num & 1 << n);
    //return 0;	//Function do not return value to main, instead prints output inside its body
}

