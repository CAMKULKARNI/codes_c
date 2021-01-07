#include <stdio.h>
#include <stdlib.h>
#include "week_12_3_server.h"
void read_details(struct student *s)
{
    s->name = (char *)malloc(20 * sizeof(char));
    printf("\nEnter the student name : ");
    scanf("%s", s->name);
    printf("\nEnter the student roll number : ");
    scanf("%d", &s->roll_num);
    printf("\nEnter the student marks : ");
    scanf("%d", &s->marks);
}
void print_details(struct student *s)
{
    printf("\nStudent name : %s", s->name);
    printf("\nStudent roll number : %d", s->roll_num);
    printf("\nStudent marks : %d", s->marks);
}
void sort_details(struct student *s, int n)
{
    struct student temp;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((s + i)->marks < (s + j)->marks)
            {
                temp = *(s + i);
                *(s + i) = *(s + j);
                *(s + j) = temp;
            }
}