#include<stdio.h>

struct student
{
int x;
char name[20];
float marks;
};

int main()
{
struct student i={1,"abc",43};
i.x=33;
i.marks=665.3;
strcpy(i.name,"hello");
}
