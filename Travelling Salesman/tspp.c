#include <stdio.h>
#include <stdlib.h>
int g[100][100],set[100],visited[100];
int n,count=0,mincost=0,source;
int TSP(int);
int gofront(int);
int goback(int);
int extract_min(int);
void dis();
int main() 
{
	int i,j;
	printf("Insert number of vertices : ");
	scanf("%d",&n);
	printf("Insert the adj matrix of the graph : \n");
	for(i = 1; i<= n; i++)
	{
		for(j=1; j<=n; j++)
			scanf("%d",&g[i][j]);
        visited[i] = 0;
	}
	printf("The matrix is : \n");
	for(i = 1; i<= n; i++)
	{
		for(j=1; j<=n; j++)
				printf("%d ",g[i][j]);
		printf("\n");
	}
    printf("Insert the source vertex : ");
    scanf("%d",&source);
    if(TSP(source) == 0)
        printf("\nThis graph can not be salved.");
    printf("\n\nThe Result is :\n");
    for(i=1;i<count;i++)
        printf("For Edge(V%d-->V%d) cost : %d\n",set[i],set[i+1],g[set[i]][set[i+1]]);
    printf("\nTotal cost is %d.\n",mincost);
    return 0;
}
int TSP(int start)
{
    if(gofront(start) == 1) //Solution found without backtracking
        return 1; //True
    else //Backtracking required
    {
        if(goback(set[count]) == 0) // Not possible
            return 0; //False
        else   //Solution found using backtracking.
            return 1; //True
    }
}
int gofront(int sc)
{
    int val;
    printf("\n//////// gofront called for %d",sc);
    visited[sc] = 1;
    set[++count] = sc;
    dis();
    if(count == n) // All vertices are visited.
    {
        if(g[sc][source] != 0) // Connection between starting and end.
        {
            set[++count] = source;
            mincost = mincost + g[sc][source];
            dis();
            return 1 ; //True
        }
        else
            return 0 ; //False
    }
    else
    {
        val = extract_min(sc);
        if(val != 0)
        {
            mincost = mincost + g[sc][val];
            gofront(val);
        }
        else
            return 0; //False
    }
}
int goback(int current)
{
    int i,goval,temp ;
    while(1)
    {
        temp = set[count--];
        visited[temp] = 0;
        current = set[count];
        printf("\n~~~~~~~~~~~ Goback is working for : %d",temp);
        dis();
        goval = count;
        mincost = mincost - g[current][temp];
        for(i = 1;i <= n; i++)
        {
            if(g[current][i] != 0 && i != temp && visited[i] == 0)
            {
                printf("\n-------Now gofront posible for %d-----",current);
                if(gofront(i) == 1)
                    return 1;// True
                else
                {
                    printf("\n>>>>>> gofront stopped for %d",set[count]);
                    while(count > goval)
                    {
                        visited[set[count]] = 0;
                        mincost = mincost - g[current][set[count]];
                        count--;
                    }
                }
            }
        }
        if(count == 0)
            return 0; //False
    }

}
int extract_min(int u)
{
    int min = 9999,pos = 0,v;
    for(v = 1; v<=n; v++)
    {
        if(g[u][v] != 0 && min > g[u][v] && visited[v] == 0)
        {
            pos = v;
            min = g[u][v];
        }
    }
    return pos;     
}
void dis()
{
    int i;
    printf("\nSet is :");
    for(i = 1; i <= count ; i++)
        printf("%d ",set[i]);
    printf("\nVisited is :");
    for(i = 1; i <= n ; i++)
        printf("%d ",visited[i]);
    printf("\n-------------------------------------------------\n");
}