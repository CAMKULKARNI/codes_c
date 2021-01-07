#include <stdio.h>
#include "week_11_4_server.h"
void complex_add(struct complex s_1, struct complex s_2)
{
    printf("\nEnter the first complex number : ");
    printf("\nReal part : ");
    scanf("%f", &s_1.real);
    printf("\nImaginary part : ");
    scanf("%f", &s_1.im);
    printf("\nEnter the second complex number : ");
    printf("\nReal part : ");
    scanf("%f", &s_2.real);
    printf("\nImaginary part : ");
    scanf("%f", &s_2.im);
    printf("\nThe sum is : %f + (%f)i", s_1.real + s_2.real, s_1.im + s_2.im);
}
void complex_subtract(struct complex s_1, struct complex s_2)
{
    printf("\n\nEnter the first complex number : ");
    printf("\nReal part : ");
    scanf("%f", &s_1.real);
    printf("\nImaginary part : ");
    scanf("%f", &s_1.im);
    printf("\nEnter the second complex number : ");
    printf("\nReal part : ");
    scanf("%f", &s_2.real);
    printf("\nImaginary part : ");
    scanf("%f", &s_2.im);
    printf("\nThe difference is : %f + (%f)i", s_1.real - s_2.real, s_1.im - s_2.im);
}
void complex_multiply(struct complex s_1, struct complex s_2)
{
    printf("\n\nEnter the first complex number : ");
    printf("\nReal part : ");
    scanf("%f", &s_1.real);
    printf("\nImaginary part : ");
    scanf("%f", &s_1.im);
    printf("\nEnter the second complex number : ");
    printf("\nReal part : ");
    scanf("%f", &s_2.real);
    printf("\nImaginary part : ");
    scanf("%f", &s_2.im);
    printf("\nThe product is : %f + (%f)i", s_1.real * s_2.real, s_1.im * s_2.im * -1);
}