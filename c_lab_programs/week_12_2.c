#include <stdio.h>
#include <stdlib.h>
#include "week_12_2_server.h"
int main()
{
    int n;
    printf("\nEnter the number of employees : ");
    scanf("%d", &n);
    struct employee *p = (struct employee *)malloc(n * sizeof(struct employee));
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the details of employee %d : ", i + 1);
        read_details(p + i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nThe details of employee %d : ", i + 1);
        print_details(p + i);
        printf("\n");
    }
    free(p->name);
    free(p->dep);
    free(p->emp_id);
    return 0;
}