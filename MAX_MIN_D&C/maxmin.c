#include <stdio.h>
#include <stdlib.h>
int max1,min1,finalmax,finalmin,c1 = 0,c2 = 0,a[100];

void maxmin(int n)  //Normal Method
{
	int i;
	max1 = a[0];
	min1 = a[0];
	for(i=1;i<n;i++)
	{
		c1 ++;
		if(a[i] > max1)
			max1 = a[i];
		if(a[i] < min1)
			min1 = a[i];	
	}
}

void maxmin_dc(int i,int j) // D & C rule
{
	int k,mid,lmax,lmin,rmax,rmin;
	c2++;
	if (i == j)
	{
		finalmax = a[i];
		finalmin = a[i];
	}
	else if (i+1 == j)
	{
		finalmax = (a[i]>a[j])?a[i]:a[j];
		finalmin = (a[i]<a[j])?a[i]:a[j];
	}
	else
	{
		mid = (i+j)/2;
		maxmin_dc(i,mid);
		lmax = finalmax;
		lmin = finalmin;
		maxmin_dc(mid+1,j);
		rmax = finalmax;
		rmin = finalmin;
		finalmax = (lmax>rmax)?lmax:rmax;
		finalmin = (lmin<rmin)?lmin:rmin;
		
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
	maxmin(n);
	printf("\nNot using D and C:");
	printf("\nMaximum is : %d",max1);
	printf("\nMinimum is : %d",min1);
	printf("\nNumber of steps : %d\n",c1);
	maxmin_dc(0,n-1);
	printf("\nUsing D and C method :");
	printf("\nMaximum is : %d",finalmax);
	printf("\nMinimum is : %d",finalmin);
	printf("\nNumber of steps : %d\n",c2);
	return 0;
}
