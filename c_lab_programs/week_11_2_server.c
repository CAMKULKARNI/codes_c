#include <stdio.h>
#include <stdlib.h>
#include "week_11_2_server.h"
void read_student_details(struct student *s)
{
    s->name = (char *)malloc(25 * sizeof(char *));

    printf("\nEnter the name : ");
    scanf("%s", s->name);
    printf("\nEnter the roll number : ");
    scanf("%d", &s->roll_num);
    printf("\nEnter the physics marks : ");
    scanf("%f", &s->phy_marks);
    printf("\nEnter the maths marks : ");
    scanf("%f", &s->math_marks);
    printf("\nEnter the electronics marks : ");
    scanf("%f", &s->ec_marks);
    printf("\nEnter the pwsc marks : ");
    scanf("%f", &s->pswc_marks);
    printf("\nEnter the mechanical marks : ");
    scanf("%f", &s->mech_marks);
}
void print_student_details(struct student *s)
{
    printf("\nThe name is : %s", s->name);
    printf("\nThe roll number is %d", s->roll_num);
    printf("\nThe physics marks are %f", s->phy_marks);
    printf("\nThe maths marks are %f", s->math_marks);
    printf("\nThe electronics marks are %f", s->ec_marks);
    printf("\nThe pswc marks are %f", s->pswc_marks);
    printf("\nThe mechanical marks are %f", s->mech_marks);
    (s->total) = (s->phy_marks) + (s->math_marks) + (s->ec_marks) + (s->pswc_marks) + (s->mech_marks);
    (s->average) = (s->total) / 5;
    printf("\nThe total marks are %f", (s->total));
    printf("\nThe average marks are %f", (s->average));
    if (85 <= (s->average) && (s->average) <= 100)
        printf("\nFIRST CLASS WITH DISTINCTION\nPASS");
    else if (60 <= (s->average) && (s->average) <= 84)
        printf("\nFIRST CLASS\nPASS");
    else if (50 <= (s->average) && (s->average) <= 59)
        printf("\nSECOND CLASS\nPASS");
    else if (40 <= (s->average) && (s->average) <= 49)
        printf("\nTHIRD CLASS\nPASS");
    if ((s->average) < 49)
        printf("\nF GRADE\nPASS");
}
