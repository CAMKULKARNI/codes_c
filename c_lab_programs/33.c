//even or odd using conditional operators
#include<stdio.h>
int  main()
{
	int a = 0;
	printf("Enter a number : ");
	scanf("%d" , &a);
	printf((a%2)?"Odd\n":"Even\n");
	return 0;
}
