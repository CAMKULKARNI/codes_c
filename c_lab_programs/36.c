//write a c program using bitwise operator for the following:
//check whether the specified is set or not set
//set the specified bit and print the result
//clear the specified bit and print the result
#include<stdio.h>
int main()
{
	int a , i;
	printf("Enter a number : \n");
	scanf("%d" , &a);
	printf("Enter the position of the bit \n");
	scanf("%d" , &i);
	if (a&(1<<i))
	{
		printf("The specified bit is Set\n");
	}
	else
	{
		printf("The specified bit is not Set\n");
	}
	printf("The result after setting the specified bit is %d\n",(a|(1<<i)));
	printf("The result after clearing the specified bit if %d\n",(a&(~(1<<i))));
	return 0;
}
