#include <stdio.h>
#include <stdlib.h>
int main()
{
   int c=0,i,first,last,middle,n,search,ar[100];
   printf("Enter number of elements : ");
   scanf("%d",&n);
   printf("Enter integers : " );
   for (i = 0; i < n; i++)
      scanf("%d",&ar[i]);
   printf("Enter value to find : ");
   scanf("%d", &search);

   //Algorithm Part
   first = 0;
   last = n - 1;
   middle = (first+last)/2;
   while (first <= last)
   {
      if (ar[middle] < search)
      {
         first = middle + 1;
         c++;
      }
      else if (ar[middle] == search)
      {
         c++;
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
      {
         last = middle - 1;
         c++;
      }
      middle = (first + last)/2;
   }

   //Display
   if (first > last)
      printf("Not found! %d is not present in the list.\n", search);
   printf("Number of loop operation is %d.\n",c);
   return 0;
}	

//    --- By Supriya Kundu
