#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int equalStacks(int h1_count, int *h1, int h2_count, int *h2, int h3_count, int *h3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0, top1 = 0, top2 = 0, top3 = 0;
    for (int i = 0; i < h1_count; i++)
    {
        sum1 += *(h1 + i);
    }
    for (int i = 0; i < h2_count; i++)
    {
        sum2 += *(h2 + i);
    }
    for (int i = 0; i < h3_count; i++)
    {
        sum3 += *(h3 + i);
    }
    printf("\n%d\t%d\t%d\n", sum1, sum2, sum3);
    int result /* = sum1*/;
    while (sum1 != sum2 && sum2 != sum3 && sum3 != sum1)
    {
        if (sum1 - (*(h1 + top1)) == sum2 && sum2 == sum3 && sum3 == sum1 - (*(h1 + top1)))
        {
            sum1 = sum1 - (*(h1 + top1));
            top1++;
            result = sum2;
        }
        else if (sum1 == sum2 - (*(h2 + top2)) && sum2 - (*(h2 + top2)) == sum3 && sum3 == sum1)
        {
            sum2 = sum2 - (*(h2 + top2));
            top2++;
            result = sum1;
        }
        else if (sum1 - (*(h1 + top1)) == sum2 - (*(h2 + top2)) && sum2 - (*(h2 + top2)) == sum3 && sum3 == sum1 - (*(h1 + top1)))
        {
            sum1 = sum1 - (*(h1 + top1));
            top1++;
            sum2 = sum2 - (*(h2 + top2));
            top2++;
            result = sum3;
        }
        else if (sum1 == sum2 && sum2 == sum3 - (*(h3 + top3)) && sum3 - (*(h1 + top3)) == sum1)
        {
            sum3 = sum3 - (*(h3 + top3));
            top3++;
            result = sum1;
        }
        else if (sum1 - (*(h1 + top1)) == sum2 && sum2 == sum3 - (*(h3 + top3)) && sum3 - (*(h3 + top3)) == sum1 - (*(h1 + top1)))
        {
            sum1 = sum1 - (*(h1 + top1));
            top1++;
            sum3 = sum3 - (*(h3 + top3));
            top3++;
            result = sum2;
        }
        else if (sum1 == sum2 - (*(h2 + top2)) && sum2 - (*(h2 + top2)) == sum3 - (*(h3 + top3)) && sum3 - (*(h3 + top3)) == sum1)
        {
            sum2 = sum2 - (*(h2 + top2));
            top2++;
            sum3 = sum3 - (*(h3 + top3));
            top3++;
            result = sum1;
        }
        else if (sum1 - (*(h1 + top1)) == sum2 - (*(h2 + top2)) && sum2 - (*(h2 + top2)) == sum3 - (*(h3 + top3)) && sum3 - (*(h3 + top3)) == sum1 - (*(h1 + top1)))
        {
            sum1 = sum1 - (*(h1 + top1));
            top1++;
            sum2 = sum2 - (*(h2 + top2));
            top2++;
            sum3 = sum3 - (*(h3 + top3));
            top3++;
            result = sum1;
        }
        else
        {
            sum1 = sum1 - (*(h1 + top1));
            top1++;
            sum2 = sum2 - (*(h2 + top2));
            top2++;
            sum3 = sum3 - (*(h3 + top3));
            top3++;
        }
    }
    return result;
}

int main()
{
    int *h1[] = {3, 2, 1, 1, 1}, *h2[] = {4, 3, 2}, *h3[] = {1, 1, 4, 1}, n1 = 5, n2 = 3, n3 = 4;

    int result = equalStacks(n1, h1, n2, h2, n3, h3);
    printf("%d\n", result);
    return 0;
}
