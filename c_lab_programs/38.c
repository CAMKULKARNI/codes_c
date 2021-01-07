//time taken for the execution of the program
#include<stdio.h>
#include<time.h>
int main()
{	
	int i , j , n;
	clock_t start , end;
	printf("Enter a number : ");
	scanf("%d" , &n);
	start = clock();
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < i;j++)
		{
			printf("%d " , i);
		}	
		printf("\n");
	}
	end = clock();
	printf("%lf" , (double)((end - start)/CLOCKS_PER_SEC));
	return 0;
}
