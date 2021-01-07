#include <stdio.h>
#include <stdlib.h>
#include "week_11_1_server.h"
void date_compare(struct date d_1, struct date d_2)
{
    printf("\nEnter first date in dd/mm/yyyy format : ");
    scanf("%d/%d/%d", &d_1.dd, &d_1.month, &d_1.year);
    printf("\nEnter second date in dd/mm/yyyy format : ");
    scanf("%d/%d/%d", &d_2.dd, &d_2.month, &d_2.year);
    printf("Date1 : %d-%d-%d", d_1.dd, d_1.month, d_1.year);
    printf("\nDate2 : %d-%d-%d", d_2.dd, d_2.month, d_2.year);
    if (d_1.year == d_2.year && d_1.month == d_2.month && d_1.dd == d_2.dd)
        printf("\nDate1 is equal to Date2");
    else if ((d_1.year < d_2.year) || (d_1.year == d_2.year && d_1.month < d_2.month) || (d_1.year == d_2.year && d_1.month == d_2.month && d_1.dd < d_2.dd))
        printf("\nDate1 is greater than Date2");
    else if ((d_1.year > d_2.year) || (d_1.year == d_2.year && d_1.month > d_2.month) || (d_1.year == d_2.year && d_1.month == d_2.month && d_1.dd > d_2.dd))
        printf("\nDate1 is lesser than Date2");
}