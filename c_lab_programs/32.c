//swap two numbers without using third variable with bitwise operators
#include<stdio.h>
int main()
{
	int a , b;
	printf("Enter the two numbers : \n");
	scanf("%d%d" , &a , &b);
	printf("The value of first number before swapping is %d and the value of the second number before swapping is %d\n" , a , b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("The value of first number after swapping is %d and the value of the second number after swapping is %d\n" , a , b);
	return 0;
}
