#include<stdio.h>
#include<math.h>
int main()
{
	float a , b , c , s , area;
	printf("\nEnter the three sides : \n");
	scanf("%f%f%f" , &a , &b , &c);
	s = (a + b + c)/2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));
	printf("\nThe area is : %.3f\n" , area);
	return 0;
}
