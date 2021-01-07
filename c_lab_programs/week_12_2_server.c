#include <stdio.h>
#include <stdlib.h>
#include "week_12_2_server.h"
void read_details(struct employee *s)
{
    s->name = (char *)malloc(20*sizeof(char));
    s->emp_id = (char *)malloc(10*sizeof(char));
    s->dep = (char *)malloc(30 * sizeof(char));
    printf("\nEnter the employee name : ");
    scanf("%s", s->name);
    printf("\nEnter the employee id : ");
    scanf("%s", s->emp_id);
    printf("\nEnter the employee department : ");
    scanf("%s", s->dep);
}
void print_details(struct employee *s)
{
    printf("\nEmployee name : %s", s->name);
    printf("\nEmployee id : %s", s->emp_id);
    printf("\nEmployee department : %s", s->dep);
}