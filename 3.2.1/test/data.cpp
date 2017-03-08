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
    k=0;
    n=rand()%1000+3000;
    m=rand()%1000+3000;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
        {
            a[i][j]=rand()%2;
            if (a[i][j]==1) k++;
        }
    printf("%d %d %d\n",k,n,m);
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++) 
        if (a[i][j]==1)
            printf("%d %d\n",i,j);
    printf("0\n");
}
