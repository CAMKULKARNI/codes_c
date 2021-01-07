#include<stdio.h>
int main(void)
{
	float x,y,ratio;
	printf("Enter the x and y value to find ratio\n");
	scanf("%f%f",&x,&y);
	ratio=(x+y)/(x-y);
	printf("Result of ratio=%f\n",ratio);
	return 0;
}
