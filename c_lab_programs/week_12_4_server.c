#include <stdio.h>
#include <stdlib.h>
#include "week_12_4_server.h"
void read_courses(struct course *c)
{
    c->course_code = (char *)malloc(9 * sizeof(char));
    c->course_name = (char *)malloc(30 * sizeof(char));
    printf("\nEnter the course names and course codes : ");
    printf("\nEnter the course name : ");
    scanf("%s", c->course_name);
    printf("\nEnter the course code : ");
    scanf("%s", c->course_code);
}
void print_courses(struct course *c)
{
    printf("\nThe course name is : %s", c->course_name);
    printf("\nThe course code is : %s", c->course_code);
}