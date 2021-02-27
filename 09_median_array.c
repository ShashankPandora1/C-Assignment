/*WAP to find the median of 2 arrays*/
#include<stdio.h>
int main()
{
    int size1,i,j,var;
   double mid1,mid2,median;
    printf("enter size of 1st array: ");
    scanf("%d",&size1);
    int arr1[size1];
    printf("enter elements of 1st array: \n");
    for(i=0;i<size1;i++)
    {
	scanf("%d",&arr1[i]);
    }
    for(i=0;i<size1;i++)
    {
	for(j=0;j<size1-i;j++)
	{
		var=arr1[j];
	    if(arr1[j]>arr1[j+1])
	    {
		arr1[j]=arr1[j+1];
		arr1[j+1]=var;
	    }
	}
    }
    for(i=0;i<size1;i++)
    {
	printf("%d",arr1[i]);
    }
    printf("\n");
    /*2nd array*/
   int size2;
    printf("enter size of 2nd array: ");
    scanf("%d",&size2);
    int arr2[size2];
    printf("enter elements of 2nd array: \n");
    for(i=0;i<size2;i++)
    {
	scanf("%d",&arr2[i]);
    }
    for(i=0;i<size2;i++)
    {
	for(j=0;j<size2-i;j++)
	{
		var=arr2[j];
	    if(arr2[j]>arr2[j+1])
	    {
		arr2[j]=arr2[j+1];
		arr2[j+1]=var;
	    }
	}
    }
    for(i=0;i<size2;i++)
    {
	printf("%d",arr2[i]);
    }
    printf("\n");
    if(size1%2==0)
    {
	mid1=arr1[(size1/2)]+arr1[(size1/2)-1];
    }
    else
    {
	mid1=arr1[(size1-1)/2];
    }
if(size2%2==0)
{
mid2=arr2[(size2/2)]+arr2[(size2/2)-1];
}
else
{
    mid2=arr2[(size2-1)/2];
}
median=(mid1+mid2)/2;
printf("Median = %f",median);
printf("\n");
    return 0;
}
