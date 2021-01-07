#include<stdio.h>
int main()
{
	int roll_num , sem ;
	char sec , name[50];
	double marks;
	float perc;
	long int ph_num;
	printf("\nEnter the name : \n");
	scanf("%s" , name);
	printf("\nEnter the roll number : \n");
	scanf("%d" , &roll_num);
	printf("\nEnter the semester : \n");
	scanf("%d" , &sem);
	printf("\nEnter the section : \n");
	scanf(" %c" , &sec);
	printf("\nEnter the phone number : \n");
	scanf("%ld", &ph_num);
	printf("\nEnter the marks : \n");
	scanf("%lf" , &marks);
	printf("\nEnter the corresponding pecentage : \n");
	scanf("%f" , &perc);
	printf("\nThe details of the student : ");
	printf("\nRoll no : %d" , roll_num);
	printf("\nName : %s" , name);
	printf("\nSemester : %d" , sem);
	printf("\nSection : %c" , sec);
	printf("\nPhone_no : %ld" , ph_num);
	printf("\nMarks : %lf" , marks);	
	printf("\nPercentage : %f\n" , perc);	
	return 0;
}
