#include <stdio.h>
#include <stdlib.h>
float p[100],w[100],ratio[100],x[100],pro[100];//,*p
float knapsack(float,int);
void sort(float*,int);
void swap(float*,float*);
int main() 
{
	int i,j,n;
	float ms,val;
	printf("Insert number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Insert profit and weight for item %d : ",i+1);
		scanf("%f%f",&p[i],&w[i]);
		ratio[i]=p[i]/w[i];
		pro[i]=i+1;
	}
	printf("Insert the maxsize of knapsack : ");
	scanf("%f",&ms);
	sort(ratio,n);
	val = knapsack(ms,n);
	for(i=0;i<n;i++)
		printf("\nItem %d. Ratio : %f , X : %f ",(int)pro[i],ratio[i],x[i]);
	printf("\n\nRatio based solution is : %f\n",val);
	return 0;
}
void sort(float*a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				swap(&ratio[i],&ratio[j]);
				swap(&p[i],&p[j]);
				swap(&w[i],&w[j]);
				swap(&pro[i],&pro[j]);
			}
		}
	}
}	
float knapsack(float m,int n)
{
	int i;
	float u;
	float sum =0;
	for(i=0;i<n;i++)
		x[i]=0;
	u=m;
	for(i=0;i<n;i++)
	{
		if(w[i]>u)
			break;
		x[i]=1;
		u=u-w[i];
		sum = sum + p[i]*x[i];	
	}
	if (i<n)
	{
		x[i]=u/w[i];
		sum = sum + p[i]*x[i];
	}
	return sum;
}
void swap(float*p,float*q)
{
	float temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
