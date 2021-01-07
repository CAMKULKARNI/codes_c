#include <stdio.h>
#include "week_11_3_server.h"
void distance_add(struct feet_inch s_1, struct feet_inch s_2)
{
    printf("\nEnter the first distance : ");
    printf("\nFeet : ");
    scanf("%f", &s_1.feet);
    printf("\nInch : ");
    scanf("%f", &s_1.inch);
    printf("\nEnter the second distance : ");
    printf("\nFeet : ");
    scanf("%f", &s_2.feet);
    printf("\nInch : ");
    scanf("%f", &s_2.inch);
    if (s_1.inch + s_2.inch >= 12)
        printf("\nThe total distance is %f feet and %f inch", s_1.feet + s_2.feet + 1, s_1.inch + s_2.inch - 12);
    else
        printf("\nThe total distance is %f feet and %f inch", s_1.feet + s_2.feet, s_1.inch + s_2.inch);
}