#include <stdio.h>
#include <stdlib.h>
#include <ctime>
int a[100],b[100],l[100];
char male[100],female[100];

int main()
{
    int k,n,i,j,s,m;
    freopen("1.txt","w",stdout);
    srand((unsigned)time(0));
    m=3;
    printf("%d\n",m);
    while (m!=0)
    {
        m--;
        n=rand()%20+1;
        printf("%d\n",n);
        for (i=1; i<=26; i++) a[i]=0;
        k=0;
        for (i=1; i<=n; i++)
        {
            s=rand()%26+1;
            while (a[s]!=0) s=s%26+1;
            a[s]=1;
            printf("%c ",s-1+'a');
            k++;
            male[k]=s-1+'a';
        }
        for (i=1; i<=26; i++) b[i]=0;
        k=0;
        for (i=1; i<=n; i++)
        {
            s=rand()%26+1;
            while (b[s]!=0) s=s%26+1;
            b[s]=1;
            printf("%c ",s-1+'A');
            k++;
            female[k]=s-1+'A';
        }
        printf("\n");
        for (i=1; i<=n; i++)
            {
                printf("%c:",male[i]);
                for (j=1; j<=n; j++) l[j]=0;
                for (j=1; j<=n; j++)
                {
                    s=rand()%n+1;
                    while(l[s]!=0) s=s%n+1;
                    l[s]=1;
                    printf("%c",female[s]);
                }
                printf("\n");
            }
        for (i=1; i<=n; i++)
            {
                printf("%c:",female[i]);
                for (j=1; j<=n; j++) l[j]=0;
                for (j=1; j<=n; j++)
                {
                    s=rand()%n+1;
                    while(l[s]!=0) s=s%n+1;
                    l[s]=1;
                    printf("%c",male[s]);
                }
                printf("\n");
            }
    }
}
