#include<stdio.h>
void read_array(int [], int);
void print_array(int [], int);
void reverse_array(int [], int);
int main()
{
	int n, a[100];
	printf("\nEnter the size of the array : \n");
	scanf("%d", &n);
	read_array(a,n);
	print_array(a,n);
	printf("\nThe array in reverse order : \n");
	reverse_array(a,n);
	print_array(a,n);
	return 0;
}
void read_array(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nEnter element %d of the array : ",i);
		scanf("%d",&a[i]);
	}
}
void print_array(int a[], int n)
{
	printf("\nThe required array is : \n");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
void reverse_array(int a[], int n)
{
	int beg=0,end=n-1,temp;
	while(beg<end)
	{
		temp = a[beg];
		a[beg] = a[end];
		a[end] = temp;
		beg++;
		end--;
	}
}
