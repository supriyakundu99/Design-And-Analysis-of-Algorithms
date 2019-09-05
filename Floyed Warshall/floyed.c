#include <stdio.h>
#include <stdlib.h>
#define INF 9999
int g[100][100],d[100][100][100],p[100][100][100];
void floyd(int);
int main() 
{
	int n,i,j,val,k;
	printf("Insert number of vertices : ");
	scanf("%d",&n);
	printf("Insert the adj matrix of the graph : \n");
	for(i = 1; i<= n; i++)
	{
		for(j=1; j<=n; j++)
		{
			scanf("%d",&val);
			if (val == 0 && i != j)
				g[i][j] = d[0][i][j] = INF;
			else
				g[i][j] = d[0][i][j] = val;
		}
	}
	floyd(n);
	printf("\n\nD%d matrix is : \n",n);
	for(i=1; i<=n; i++)
	{
		for(j = 1; j<=n; j++ )
			printf("%d\t",d[n][i][j]);
		printf("\n");
	}
	printf("\nP%d matrix is : \n",n);
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++ )
		{
			if(p[n][i][j] != 0)
		        printf("%d\t",p[n][i][j]);
    		else
    			printf("*\t");
    	}
		printf("\n");
	}
    return 0;
}
void floyd(int n)
{
	int i,j,k,val,c1,c2;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<n;j++)
		    p[0][i][j] = 0;
	}
	for (k = 1; k <= n; k++)
	{
		for(c1 = 1 ; c1<=n ; c1++)
		{
			for(c2=1; c2 <=n ; c2++)
			{
				d[k][c1][c2] = d[k-1][c1][c2];
				p[k][c1][c2] = p[k-1][c1][c2];
			}
		}
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(d[k][i][j] > (d[k-1][i][k] + d[k-1][k][j]))
				{
					d[k][i][j] = d[k-1][i][k] + d[k-1][k][j] ;
					p[k][i][j] = k;
				}
			}
		}
	}
}




