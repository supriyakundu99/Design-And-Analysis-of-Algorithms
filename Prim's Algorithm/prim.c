#include <stdio.h>
#include <stdlib.h>
#define INF  9999
int g[100][100],t[100][4];
int prims(int );
int main() 
{
	int n,i,j,val;
	printf("Insert number of vertices : ");
	scanf("%d",&n);
	printf("Insert the adj matrix of the graph (for no edge : 0) : \n");
	for(i = 1; i<= n; i++)
	{
		for(j=1; j<=n; j++)
		{
			scanf("%d",&val);
			if (val == 0)
				g[i][j] = INF;
			else
				g[i][j] = val;
		}
	}
	printf("The matrix is : \n");
	for(i = 1; i<= n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(g[i][j] == INF)
				printf("INF\t");
			else
				printf("%d\t",g[i][j]);
		}
		printf("\n");
	}  
	printf("\nMinimum cost is : %d\n",prims(n));
	printf("\nThe MST is : \nV1\tV2\tCost\tMincost\n");
	for(i = 1; i < n; i++)
		printf("%d\t%d\t%d\t%d\n",t[i][0],t[i][1],t[i][2],t[i][3]);
	return 0;
}
int prims(int n)
{
	int i,j,k,v1,v2,min,visited[100],mincost = 0;
	for(i=1; i<=n ; i++)
		visited[i] = 0;
	visited[1] = 1;
	for(k = 1; k<n ; k++)
	{
		min = INF;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(g[i][j] != INF && visited[i] == 1 && visited[j] == 0)
				{
					if(g[i][j] < min)
					{
						min = g[i][j];
						v1 = i;
						v2 = j;
						t[k][0] = v1;
						t[k][1] = v2;
						t[k][2] = min;
					}
				}
			}
		}
		mincost = mincost + min;
		t[k][3] = mincost;
		visited[v1] = 1;
		visited[v2] = 1;
	}
	return mincost;
}
