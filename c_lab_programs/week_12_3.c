#include <stdio.h>
#include <stdlib.h>
#include "week_12_3_server.h"
int main()
{
    int n;
    printf("\nEnter the number of students : ");
    scanf("%d", &n);
    struct student *p = (struct student *)malloc(n * sizeof(struct student));
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the details of student %d : ", i + 1);
        read_details(p + i);
    }
    printf("\nThe details before sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("\nThe details of student %d : ", i + 1);
        print_details(p + i);
        printf("\n");
    }
    sort_details(p, n);
    printf("\nThe details after sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("\nThe details of student %d : ", i + 1);
        print_details(p + i);
        printf("\n");
    }
    free(p);
    return 0;
}