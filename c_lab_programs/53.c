#include<stdio.h>
void isprime(int);
int nextprime(int);
int main()
{
	int num;
	printf("Enter a number :\n");
	scanf("%d",&num);
	isprime(num);
	return 0;
}
int nextprime(int n)
{
	while(1)
	{
		int count=0;
		for(int i=2;i<=n/2;i++)
			n%i ? 0 : count++;
		//count ? 0 : return n;
		if(count)
			n++;
		else		
			return n;
	}
}
void isprime(int n)
{
	int count=0;// prime = 0;
	for(int i=2;i<=n/2;i++)
		n%i ? 0 : count++;
	//count ? 0 : prime = 1;
	if(count)
	{	
		printf("\n%d is not prime",n);
		printf("\n%d is the next prime\n",nextprime(n));	
	}
	else
	{
		printf("\n%d is prime\n",n);
	}
}

