#include<stdio.h>
void count_and_sum(int);
int main()
{
	int num;
	printf("\nEnter a number : ");
	scanf("%d",&num);
	printf("%d",num);
	count_and_sum(num);
	return 0;	
}
void count_and_sum(int n)
{
	int count=0,sum=0,r;
	while(n)
	{
		r=n%10;
		count++;
		sum=sum+r;
		n=n/10;
	}
	printf("\nThe number of digits is %d and the sum of digits is %d\n",count,sum);
}
