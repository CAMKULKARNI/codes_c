#include<stdio.h>

struct point
{
int x;
int y;
char name[20];
};

int main()
{
struct point p1 ={10,20};
struct point p2={.y=99};
 
printf("\n enter the x component for p1");
scanf("%d",&p1.x);
p1.name="ddd";
printf("Enter string");
scanf("%s",p1.name);
printf("The string is %s",p1.name);
printf("\n x=%d,y=%d",p1.x,p1.y);
printf("\n x=%d,y=%d",p2.x,p2.y);
}
