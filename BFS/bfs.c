#include <stdio.h>
#include <stdlib.h>
int g[100][100],n,visited[100],q[100],f = 0,r = 0,prev = 0;
void BFT();
void BFS(int);

int main() 
{
	int i,j;
	printf("Insert number of vertices : ");
	scanf("%d",&n);
	printf("Insert the adj matrix of the graph (For edge 1, no edge 0): \n");
	for(i = 1; i<= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	printf("\nThe matirx is : \n");
	for(i = 1; i<= n; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
	printf("\nResult is : \n");
	BFT();
	printf("\n");
	return 0;
}

void BFT()
{
	int i;
	for(i = 0; i<=n;i++)
		visited[i] = 0;
	for(i = 1; i<=n;i++)
	{
		if(visited[i] == 0)
		{
			q[r++] = i;
			BFS(i);
			prev = i;
		}
	}
	
}
void BFS(int v)
{
	int w,u = v;
	visited[v] = 1;
	f++;
	printf(" -> For vertex.%d ,predecessor: %d\n",v,prev);
	while(1)
	{
		for(w = 1; w <= n ; w++)
		{
			if(g[v][w] == 1 && visited[w] == 0)
			{
				q[r++] = w;
				visited[w] = 1;
				printf(" -> For vertex.%d ,predecessor: %d\n",w,v);
			}
		}
		if(f>r)
			return;
		v = q[f++];
	}
}