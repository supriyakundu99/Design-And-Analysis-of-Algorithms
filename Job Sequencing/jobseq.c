#include <stdio.h>
#include <stdlib.h>
int p[100],d[100],job[100],sol[100];
void sort(int*,int);
void swap(int*,int*);
int jobs(int,int);
int main() 
{
	int i,n,md,maxprof;
	printf("Insert number of jobs : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Insert profit and deadline for job %d : ",i+1);
		scanf("%d%d",&p[i],&d[i]);
		job[i]=i+1;
		sol[i+1] = -1;
	}
	sort(d,n);
	md  = d[0];// maximum deadline calculation.
	sort(p,n);
	printf("\nAfter sorting w.r.t profit : ");
	for(i=0;i<n;i++)
		printf("\nJob%d : profit : %d , Deadline : %d",job[i],p[i],d[i]);
	printf("\n\nMax deadline is : %d ",md);
	maxprof = jobs(n,md);
	printf("\n\nSolution is : ");
	for(i=1;i<=md;i++)
		printf("\nSlot : %d-%d --> J%d ",i-1,i,sol[i]);
	printf("\n\nMaximum profit is : %d\n",maxprof);
	return 0;
}
int jobs(int sz,int mdl)
{
	int i,r,mp=0;
	for(i = 0;i<sz;i++)
	{
		for(r = d[i];r > 0;r--)
		{
			if(sol[r] == -1)
			{
				sol[r] = job[i];
				mp = mp + p[i];
				break;
			}
		}	
	}
	return mp;	
}
void sort(int *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				swap(&p[i],&p[j]);
				swap(&d[i],&d[j]);
				swap(&job[i],&job[j]);
			}
			
		}
	}
}
void swap(int *p,int *q)
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
}
