//check whether the date is valid or not. If valid print thr next date
#include<stdio.h>
int main()
{
	int date , month , year;
	printf("Enter the date : \n");
	scanf("%d" , &date);
	printf("Enter the month : \n");
	scanf("%d" , &month);
	printf("Enter the year : \n");
	scanf("%d" , &year);
	if ((month > 12)||(month < 0))
	{
		printf("Invalid\n");
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
	{
		if ((date > 31)||(date < 0))
		{
			printf("Invalid\n");
		}
		else if (date == 31)
		{
			date = 1;
			month++;
		}
		else 
		{
			date++;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if ((date > 30)||(date < 0))
		{
			printf("Invalid\n");
		}
		else if (date == 30)
		{
			date = 1;
			month++;
		}
		else
		{
			date++;
		}
	}
	else if (month == 12)
	{
		
		if ((date > 31)||(date < 0))
		{
			printf("Invalid\n");
		}
		else if (date == 31)
		{
			date = 1;
			month = 1;
			year++;
		}
		else 
		{
			date++;
		}	
	}
	else if (month == 2)
	{
		if (year%4 == 0 && year%100 != 0 || year%400 == 0)
		{
			if ((date > 29)||(date < 0))
			{
				printf("Invalid\n");
			}
			else if (date == 29)
			{
				date = 1;
				month++;
			}
			else
			{
				date++;
			}
		}
		else
		{
			if ((date > 28)||(date < 0))
			{
				printf("Invalid\n");
			}
			else if (date == 28)
			{
				date = 1;
				month++;
			}
			else
			{
				date++;
			}
		}
	}
	printf("%d/%d/%d\n",date,month,year);
	return 0;
}
