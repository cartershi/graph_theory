#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main()
{
    int n,i,j;
    freopen("1.txt","w",stdout);
    srand((unsigned)time(0));
    n=rand()%1000+2000;
    printf("%d\n",n);
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++) printf("%d ",rand()%10000+10000);
        printf("\n");
    }
}
