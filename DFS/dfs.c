#include <stdio.h>
#include <stdlib.h>
int g[100][100],n,visited[100],prev = 0;
void DFS(int);

int main() 
{
	int i,j,s;
	printf("Insert number of vertices : ");
	scanf("%d",&n);
	for(i = 0; i<=n;i++)
		visited[i] = 0;
	printf("Insert the adj matrix of the graph (For edge 1, no edge 0): \n");
	for(i = 1; i<= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	printf("Insert the starting vertex : ");
	scanf("%d",&s);
	printf("\nResult is : \n");
	DFS(s);
	return 0;
}
void DFS(int v)
{
	int w;
	visited[v] = 1;
	printf(" -> For vertex.%d ,predecessor: %d\n",v,prev);
	for(w = 1; w <=n; w++ )
	{
		if(g[v][w] == 1 && visited[w] == 0)
		{
			prev = v;
			DFS(w);
		}
	}
}