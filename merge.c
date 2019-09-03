#include <stdio.h>
#include <stdlib.h>
int a[100];
int b[100];

void merge_sort(int, int);
void merge(int, int, int);

int main()
{
    int i, n;
    printf("Insert number of elements : ");
    scanf("%d", &n);
    printf("Insert %d elements : ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(0, n - 1);
    printf("Sorted dataset is : ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n\n");
    return (0);
}

void merge_sort(int lo, int hi)
{
    int mid;
    if (lo < hi)
    {
        mid = (lo + hi) / 2;
        merge_sort(lo, mid);
        merge_sort(mid + 1, hi);
        merge(lo, mid, hi);
    }
}

void merge(int l, int mid, int h)
{
    int i, j, k, val;
    i = l;
    j = mid + 1;
    k = l;
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= h)
        b[k++] = a[j++];
    for (val = l; val <= h; val++)
        a[val] = b[val];
}
