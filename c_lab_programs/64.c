#include<stdio.h>
int parity(int n);
int sum_of_digits(int n);
void read_array(int *, int);
void print_array(int *, int);
void calc(int *, int);
int main()
{
	int n, *a;
	printf("\nEnter the size of the array : \n");
	scanf("%d", &n);
	read_array(a,n);
	print_array(a,n); 
	calc(a,n);
	return 0;
}
void read_array(int *a, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nEnter element %d of the array : ",i);
		scanf("%d",(a+i));
	}
}
void print_array(int *a, int n)
{
	printf("\nThe required array is : \n");
	for(int i=0;i<n;i++)
		printf("%d\t",*(a+i));
	printf("\n");
}
int parity(int n)
{
	int count = 0;
	while(n)
	{
		n=n&(n-1);
		count++;
	}
	return count;
}
int sum_of_digits(int n)
{
	int sum=0;
	while(n)
	{
		sum += (n%10);
		n/=10;
	}
	return sum;
}
void calc(int *a, int n)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		(parity(*(a+i))%2) ? 0 : (sum += sum_of_digits(*(a+i)));
	}
	printf("\nThe final output is : %d\n",sum);
}
