//read 4 points from the user. calculate the distance
#include<stdio.h>
#include<math.h>
int main()
{
	float x1 , x2 , y1 , y2 , dist;
	printf("\nEnter the co-ordinates of the first point : ");
	scanf("%f%f" , &x1 , &y1);
	printf("\nEnter the co-ordinates of the second point : ");
	scanf("%f%f" , &x2 , &y2);
	dist = sqrt(pow(x1 - x2 , 2) + pow(y1 -y2 , 2));
	printf("\nThe distance is : %f\n" , dist);
	return 0;
}
