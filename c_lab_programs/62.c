#include<stdio.h>
void print_array(int *, int);
void fibonacci(int *, int);
int main()
{
	int *a,n;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);	
	fibonacci(a,n);
	print_array(a,n);
	return 0;
}
void print_array(int *a, int n)
{
	printf("\nThe required array is : \n");
	for(int i=0;i<n;i++)
		printf("%d\t",*(a+i));
	printf("\n");
}
void fibonacci(int *a, int n)
{
	*a = 0;
	*(a+1) = 1;
	for(int i=2;i<n;i++)
		*(a+i) = *(a+i-1) + *(a+i-2);
}
