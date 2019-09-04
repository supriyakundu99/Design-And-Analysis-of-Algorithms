#include <stdio.h>
#include <stdlib.h>
int a[100];

int part(int p,int q)
{
	int i,j,piv,temp;
 	i=p;
 	j=q;
 	piv = a[p];
 	while(i<j)
 	{
  		while(piv >= a[i])
   			i++;
  		while(piv < a[j])
   			j--;
  		if(i<j)
  		{
   			temp = a[i];
   			a[i] = a[j];
   			a[j] = temp;
  		}
 	}
 	temp = a[p];
 	a[p] = a[j];
 	a[j] = temp;
 	return j;
}
void qcsort(int lo,int hi)
{
 	int piv;
 	if(lo<hi)
 	{
  		piv = part(lo,hi);
  		qcsort(lo,piv-1);
  		qcsort(piv+1,hi);
 	}
}

int main() 
{
 	int i,n;
 	printf("Insert number of elements : ");
 	scanf("%d",&n);
 	printf("Insert %d elements : ",n);
 	for(i=0;i<n;i++)
  		scanf("%d",&a[i]);
 	qcsort(0,n-1);
 	printf("\nAfter sorting : ");
 	for(i=0;i<n;i++)
  		printf("%d ",a[i]);
    printf("\n");
 	return 0;
}
