#include <stdio.h>

#define MAX 500

void cycle_sort(int *);

void main()
{
    int a[MAX], i;

    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &a[i]);
    }
    cycle_sort(a);
    printf("sorted elements are :\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d", a[i]);
    }
}

/* sorts elements using cycle sort algorithm */
void cycle_sort(int *a)
{
    int temp, item, pos, i, j, k;

    for (i = 0; i < MAX; i++)
    {
        item = a[i];
        pos = i;
        do
        {
            k = 0;
            for (j = 0; j < MAX; j++)
            {
                if (pos != j && a[j] < item)
                {
                    k++;
                }
            }
            if (pos != k)
            {
                while (pos != k && item == a[k])
                {
                    k++;
                }
                temp = a[k];
                a[k] = item;
                item = temp;
                pos = k;
            }
        } while (pos != i);
    }
}