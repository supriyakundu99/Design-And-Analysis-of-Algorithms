#include <stdio.h>
#include <stdlib.h>
int g[100][100],n,m,x[100],flag = 0;;
void mcoloring(int);
void NextValue(int);
void display();
int main() 
{
	int i,j,val;
	printf("Insert number of vertices : ");
	scanf("%d",&n);
	printf("Insert the adj matrix of the graph : \n");
	for(i = 1; i<= n; i++)
	{
		for(j=1; j<=n; j++)
			scanf("%d",&g[i][j]);
        x[i] = 0;
    }
	printf("The matrix is : \n");
	for(i = 1; i<= n; i++)
	{
		for(j=1; j<=n; j++)
		    printf("%d ",g[i][j]);
		printf("\n");
	}
    while(flag == 0)
    {
        printf("\nInsert number of colors : ");
        scanf("%d",&m);
        mcoloring(1);
        if(flag == 0)
        {
            printf("\nMore than %d colour is needed.",m);
            printf("\nInsert '0' to continue or '1' to exit : ");
            scanf("%d",&flag);
        }
    }
    return 0;
}
void mcoloring(int k)
{
    while(k <= n)
    {
        NextValue(k);
        if(x[k] == 0)
            return;
        if(k == n)
            display();
        else
            mcoloring(k+1);
    }
}
void NextValue(int k)
{
    int j;
    while(1)
    {
        x[k] = (x[k] + 1) % (m+1);
        if(x[k] == 0)
            return;
        for(j = 1; j<=n ;j++)
        {
            if(g[k][j] == 1 && x[k] == x[j])
                break;
        }
        if(j == n+1)
            return;
    }
}
void display()
{
    int i;
    flag = 1;
    printf("Result is :\n");
    for(i=1;i<=n;i++)
        printf("For Vertex-%d color code is : C%d\n",i,x[i]);
}