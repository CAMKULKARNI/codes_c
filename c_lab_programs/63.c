#include<stdio.h>
void delete_element(int *, int);
void read_array(int *, int);
void print_array(int *, int);
int main()
{
	int n, *a;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);	
	read_array(a,n);
	print_array(a,n);
	delete_element(a,n);
	print_array(a,n-1);
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
void delete_element(int *a, int n)
{
	int pos;
	printf("\nEnter the position at which the element is to be deleted : ");
	scanf("%d",&pos);
	printf("\nThe element deleted is %d", *(a+pos));
	for(int i=pos;i<n-1;i++)
	{
		*(a+i) = *(a+i+1);
	}
}

