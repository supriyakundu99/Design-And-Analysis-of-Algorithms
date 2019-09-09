# include <stdio.h>
# include <stdlib.h>
# include <string.h>
char p[100],t[100];
int pi[100];
void prefix_code(int);
void kmp_match(int , int);
int main()
{
    int m,n;
    char temp[100];
    p[0] = ' ';
    t[0] = ' ';
    printf("Insert text : ");
    scanf("%s",temp);
    strcat(t,temp);
    printf("Insert pattern : ");
    scanf("%s",temp);
    strcat(p,temp);
    m = strlen(p)-1;
    n = strlen(t)-1;
    kmp_match(m,n);
    printf("\n\n");
    return 0;
}

void prefix_code(int m)
{
    int k = 0,q;
    pi[1] = 0;
    for(q = 2; q<=m; q++)
    {
        while(k>0 && p[k+1] != p[q])
            k = pi[k];
        if (p[k+1] == p[q])
            k++;
        pi[q] = k;
    }
    printf("The prefix code is : ");
    for(k = 1 ; k<=m ; k++)
        printf("%d",pi[k]);
}

void kmp_match(int m, int n)
{
    int q = 0,i;
    prefix_code(m);
    for(i=1; i<= n; i++)
    {
        while(q>0 && p[q+1] != t[i])
            q = pi[q];
        if (p[q+1] == t[i])
            q++;
        if (q == m)
        {
            printf("\nPattern found with %d shift", i-m);
            q = pi[q];
        }
    }
}