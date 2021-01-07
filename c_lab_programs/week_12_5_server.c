#include <stdio.h>
#include <stdlib.h>
#include "week_12_5_server.h"
void populate(int *a, int n)
{
    for (int i = 0; i < n; i++)
        *(a + i) = *(a + i) * *(a + i);
}