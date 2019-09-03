#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int n)
{
    int i,j,k,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {       //Swap
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

int main()
{
    int i,ar[100],n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter integers : ");
    for (i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    bubble_sort(ar,n);      //Function called
    printf("\nAfter Sorting : ");
    for (i = 0; i < n; i++)
        printf("%d ", ar[i]);
    printf("\n");
    return 0;
}

//    --- By Supriya Kundu
