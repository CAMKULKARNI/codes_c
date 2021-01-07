#include<stdio.h>
int main()
{
	int a , b , c;
	printf("\nEnter the value of first number : ");
	scanf("%d" , &a);
	printf("\nEnter the value of second number : ");
	scanf("%d" , &b);
	printf("\nThe value of the first number before swapping is %d\n" , a);
	printf("\nThe value of the second number before swapping is %d\n" , b);
	c = a;
	a = b;
	b = c;
	printf("\nThe value of the first number after swapping is %d\n" , a);
	printf("\nThe value of the second number after swapping is %d\n" , b);
	return 0;
} 
