#include <stdio.h>
#include <stdlib.h>
#include "week_12_4_server.h"
int main()
{
    int n;
    struct course *c, *cd;
    c = (struct course *)malloc(6 * sizeof(struct course));
    for (int i = 0; i < 6; i++)
        read_courses(c + i);
    printf("\nThe courses registered are : ");
    for (int i = 0; i < 6; i++)
        print_courses(c + i);
    printf("\nEnter the number of courses you wish to drop : ");
    scanf("%d", &n);
    realloc(c, 6 - n);
    for (int i = 0; i < 6 - n; i++)
        read_courses(c + i);
    printf("\nThe courses registered after dropping are : ");
    for (int i = 0; i < n; i++)
        print_courses(c + i);
    return 0;
}