#include <stdio.h>
#include <stdlib.h>
#define INF  9999
int g[100][100],d[100],pi[100],change;
int bellman(int,int);
void I_S_S(int,int);
void relax(int ,int);
void disv(int,int);
int main() 
{
	int n,i,j,val,sc;
	printf("Insert number of vertices : ");
	scanf("%d",&n);
	printf("Insert the adj matrix of the graph : \n");
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
	printf("\nThe matrix is : \n");
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
    printf("Insert the source vertex : ");
    scanf("%d",&sc);
    val = bellman(n,sc);
    if(val == 1)
        printf("\nThis graph has an negative edge cycle.");
    else
        printf("\nThis graph can be solved.");
    printf("\n\nThe result is : \n");
    for(i=1; i<=n; i++)
    {
        printf("For the vertex %d , ",i);
        printf("Cost is %d , ",d[i]);
        printf("Predecessor is %d \n",pi[i]);
    }
    return 0;
}
int bellman(int n, int s)
{
    int i,u,v;
    I_S_S(s,n);
    for(i=1; i < n; i++)
    {
        change = 0;
        for(u=1; u<=n; u++)
        {
            for(v=1; v<=n; v++)
            {
                if(g[u][v] != INF)
                    relax(u,v);
            }
        }
        if(change == 0)
            break;
        disv(n,i);   
    }
    for(u=1; u<=n; u++)
    {
        for(v=1; v<=n; v++)
        {
            if(g[u][v] != INF)
            {
                if(d[v] > d[u] + g[u][v])
                    return 1;
            }
        }
    }
    return 0;
}
void I_S_S(int s,int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        d[i] = INF;
        pi[i] = 0;
    }
    d[s] = 0;
}
void relax(int u ,int v)
{
    if(d[v] > d[u] + g[u][v])
    {
        d[v] = d[u] + g[u][v];
        pi[v] = u;
        change = 1;
    }
}
void disv(int n,int ith)
{
    int i;
    printf("\nStatus after step %d : \n",ith);
    for(i =1; i<=n ;i++)
        printf("V%d.d = %d , V%d.pi = %d\n",i,d[i],i,pi[i]);
    printf("\n\n");
}