#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n,x[100],count = 1;
void nqueen(int,int);
int place(int,int);
void display(int);
int main()
{
    printf("Insert number of Queens : ");
    scanf("%d",&n);
    nqueen(1,n);
	printf("\n");
	return 0;
}
int place(int k, int i)
{
	int j;
	for(j = 1; j < k; j++)
	{
		if ((x[j] == i) || (abs(x[j]-i) == abs(j-k)))
			return 0;
	}
	return 1;
}
void nqueen(int k, int n)
{
	int i;
	for(i =1;i<=n;i++)
	{
		if(place(k,i) == 1)
		{
			x[k] = i;
			if(k==n)
				display(n);
			else 
			 	 nqueen(k+1,n);
		}
	}
}
void display(int n)
{
	int i,j,c;
	printf("\n\nSolution->%d is : ",count++);
	for(c=1;c<=n;c++)
		printf("%d ",x[c]);
	for(i=1;i<=n;i++)
	{
		printf("\n");
		for(j=1;j<=n;j++)
		{
			if(j == x[i])
				printf("\tQ%d",i);
			else
				printf("\t*");
		}
		printf("\n\n");
	}
}
