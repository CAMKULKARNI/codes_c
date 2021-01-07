#include<stdio.h>
int fact(int);
int main()
{
	int n, r;
	printf("Enter the value of n and r : \n");
	scanf("%d%d", &n, &r);
	printf("\nThe factorial of the number n is : %d",fact(n));
	printf("\nThe factorial of the number r is : %d",fact(r));
	printf("\nThe factorial of the number n-r is : %d",fact(n-r));
	printf("\nThe value of nCr is : %d\n",fact(n)/(fact(n-r)*fact(r)));
	return 0;
}
int fact(int n)
{ 
	if(n==0 || n==1)
		return 1;
	else
		return n*fact(n-1);
}

