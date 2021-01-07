//design a simple calculator
#include<stdio.h>
int main()
{	
	int a , b; 
	char oper;
	printf("Enter the two numbers : ");
	scanf("%d%d" , &a , &b);
	printf("Enter the operation : ");
	scanf(" %c" , &oper);
	switch(oper)
	{
		case '+':{
             		 	printf("Addition\n");
			 	printf("Result = %d\n" , a+b);
				break;
			 }
		case '-':{
             		 	printf("Subtraction\n");
			 	printf("Result = %d\n" , a-b);
				break;
			 }
		case '*':{
             		 	printf("Multipliction\n");
			 	printf("Result = %d\n" , a*b);
				break;
			 }
		case '/':{
             		 	printf("Division");
			 	printf("Result = %d\n" , a/b);
				break;
			 }
		case '%':{
             		 	printf("Remainder");
			 	printf("Result = %d\n" , a+b);
				break;
			 }
		default:
			{
				printf("Invalid");
			}
			
		
	}
	return 0;
}
