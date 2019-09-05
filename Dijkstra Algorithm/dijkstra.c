#include <stdio.h>
#include <stdlib.h>
#define INF  9999
int g[100][100],d[100],pi[100],set[100],q_ar[100];
void dijkstra(int,int);
void I_S_S(int,int);
int extract_min(int* ,int);
void relax(int ,int);
void disv(int);
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
    dijkstra(n,sc);
    printf("\n\nThe result is : \n");
    for(i=0; i<n; i++)
    {
        printf("For the vertex %d , ",set[i]);
        printf("Cost is %d , ",d[set[i]]);
        printf("Predecessor is %d \n",pi[set[i]]);
    }
    return 0;
}
void dijkstra(int n,int s)
{
    int count = 0,i,u;
    I_S_S(s,n);
    for(i = 1; i<=n; i++)
        q_ar[i] = d[i];
    disv(n);
    while(count<n)
    {
        u = extract_min(q_ar,n);
        set[count++] = u;
        q_ar[u] = -1;
        for(i=1; i <= n; i++)
        {
            if(g[u][i] != INF)
                relax(u,i);
        }
        for(i = 1; i<=n; i++)
        {
            if (q_ar[i] != -1)
                q_ar[i] = d[i];
        }
        disv(n);
    }
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
    }
}
int extract_min(int* a ,int n) 
{
    int i,min = INF;
    for(i=1; i<=n; i++)
    {
        if(a[i] < min && a[i] != -1)
            min = a[i];
    }
    for(i=1; i<=n; i++)
    {
        if(a[i] == min)
            break;
    }
    return i;
}
void disv(int n)
{
    int i;
    printf("\nCurrent status is : \n");
    for(i =1; i<=n ;i++)
        printf("V%d.d = %d , V%d.pi = %d\n",i,d[i],i,pi[i]);
    printf("The Queue is : ");
    for(i=1; i<=n; i++)
        printf("%d ",q_ar[i]);
    printf("\nSet is : ");
    for(i =0; i<n ;i++)
        printf("%d ",set[i]);
    printf("\n\n");
}