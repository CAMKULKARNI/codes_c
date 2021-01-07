#include <stdio.h>
#include <stdlib.h>
#include "week_11_2_server.h"
int main()
{
    int n;
    printf("\nEnter the number of students : ");
    scanf("%d", &n);
    struct student *s = (struct student *)malloc(n * sizeof(struct student));
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Student %d details : ", i + 1);
        read_student_details(s + i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n\nStudent details : ");
        print_student_details(s + i);
    }
    free(s);
    free(s->name);
    return 0;
}
