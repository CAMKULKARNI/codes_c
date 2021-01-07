#include<stdio.h>
#include<string.h>

void print(int m,struct student s[]);
struct 	student	
{	
	int rnum;	// these three are members of the structure
	
	char name[20];
	int marks;
};	

int main()
{
struct student s[100];
int i,n;
printf("Enter the no of students");
scanf("%d",&n);

printf("Enter the details of students\n");
for (i=0;i<n;i++)

{
scanf("%d",&s[i].rnum);
scanf("%s",s[i].name);
scanf("%d",&s[i].marks);
}


print(n,s);
return 0;
}
void print(int m,struct student s[])
{int i;

for(i=0;i<m;i++)
{
printf("id=%d",s[i].rnum);
printf("name=%s",s[i].name);
printf("marks=%d",s[i].marks);
}
}
