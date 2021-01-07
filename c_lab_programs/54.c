#include<stdio.h>
int conversion(int,int);
int main()
{
	int num,base=1;
	while(base)
	{
		printf("\n\nEnter a number : ");
		scanf("%d",&num);
		printf("\nEnter the base (example 2 for binary and 8 for octal) or press 0 to exit : ");
		scanf("%d",&base);
		printf("\n%d is the required equivalent of %d",conversion(num,base),num);
	}
	return 0;
}
int conversion(int n, int b)
{
	int binary=0,temp=1;
	while(n)
	{
		binary = binary + (n%b)*temp;
		n=n/b;
		temp=temp*10;
	}
	return binary;
}
