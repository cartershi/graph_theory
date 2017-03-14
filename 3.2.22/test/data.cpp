#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define NN 5000
int a[NN][NN];


int main()
{
    int n,m,k,i,j;
    freopen("1.txt","w",stdout);
    srand((unsigned)time(0));
    int t=10;
    while (t!=0)
    {
        t--;
    k=0;
    n=rand()%2000+500;
    m=rand()%2000+500;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            a[i][j]=rand()%100;
            if (a[i][j]==1) k++;
        }
    printf("%d %d %d\n",k,n,m);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++) 
        if (a[i][j]==1)
            printf("%d %d\n",i,j);
    }
    printf("0\n");
}
