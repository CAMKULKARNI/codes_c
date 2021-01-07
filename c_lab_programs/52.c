#include<stdio.h>
#include<math.h>
int perfect(int);
int armstrong(int);
int main()
{
	int num;
	printf("\nEnter a number : ");
	scanf("%d",&num);
	if(num == armstrong(num))
		printf("%d is a armstrong number ",num);
	if(num == perfect(num))
		printf("%d is a perfect number ",num);
	return 0;
}
int perfect(int n)
{
	int r,sum=0;
	while(n)
	{
		r=n%10;
		sum=sum+r;
		n=n/10;
	}
	return sum;
}
int armstrong(int n)
{
	int ref = n,count=0,sum=0,r;
	while(ref)
	{
		count++;
		ref=ref/10;
	}
	while(n)
	{
		r=n%10;
		sum=sum+pow(r,count);
		n=n/10;
	}
	return sum;
}

