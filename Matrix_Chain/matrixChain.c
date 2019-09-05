#include <stdio.h>
#include <stdlib.h>
int m[20][20],p[20],s[20][20];
void matrix(int);
void p_o_p(int,int);
int main() 
{
	int i,j,k,n;
	printf("Insert number of matrix : ");
	scanf("%d",&n);
	printf("Insert p vector : ");
	for(i=0;i<=n;i++)
		scanf("%d",&p[i]);
	printf("P vector is : ");
	for(i=0;i<=n;i++)
		printf("%d ",p[i]);
	matrix(n);
	printf("\nMultiplication order is : ");
	p_o_p(1,n);
	printf("\nMatrix m is :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j>=i)
				printf("%d\t",m[i][j]);
			else
				printf("\t");
		}
		printf("\n");
	}
	printf("\n\nMatrix s is :\n");
	for(i=1;i<n;i++)
	{
		for(j=2;j<=n;j++)
		{
			if(j>i)
				printf("%d\t",s[i][j]);
			else
				printf("\t");
		}
		printf("\n");
	}
	printf("\nMinimum number of multiplication is : %d\n\n",m[1][n]);
	return 0;
}
void matrix(int n)
{
	int i,j,k,l,q;
	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=9999;
			for(k=i;k<j;k++)
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				printf("\nFor k = %d, m[%d][%d] = %d.",k,i,j,q);
				if(q<m[i][j])
				{
					m[i][j]= q;
					s[i][j]=k;
					printf(".........Accepted ");
				}
				else
					printf("........Not accepted");
			}
			printf("\n");
		}
	}
}
void p_o_p(int i,int j)
{
	if (i==j)
		printf("A%d ",i);
	else
	{
		printf("(");
		p_o_p(i,s[i][j]);
		p_o_p(s[i][j]+1,j);	
		printf(")");	
	}
}
