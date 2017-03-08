#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
#define NN 100
char female[NN],male[NN];
int x[NN][NN],y[NN][NN];    //x record man's preference lis
//while y[i][j] records woman i's preference of man j
int invitey[NN],possx[NN];  //invitey record woman's favourite man who invites her
//possx record man's next goal
int localm[NN],localf[NN];
queue<int>s;
int n;
void stable_match();

int main()
{
    int i,k,j,xx,yy;
    char ch;
    freopen("1.txt","r",stdin);
    scanf("%d",&k);
    while (k!=0)
    {
        for (i=0; i<=50; i++) localm[i]=0;
        for (i=0; i<=50; i++) localf[i]=0;
        k--;
        scanf("%d\n",&n);
        for (i=1; i<=n; i++)
        {
            scanf("%c",&ch);
            while (ch==' ') scanf("%c",&ch);
            male[i]=ch;
            localm[ch-'a']=i;
        }
        for (i=1; i<=n; i++)
        {
            scanf("%c",&ch);
            while (ch==' ') scanf("%c",&ch);
            female[i]=ch;
            localf[ch-'A']=i;
        }
        scanf("\n");
        for (i=1; i<=n; i++)
        {
            cin>>ch;
            xx=localm[ch-'a'];
            scanf("%c",&ch);
            for (j=1; j<=n; j++)
            {
                scanf("%c",&ch);
                yy=localf[ch-'A'];
                x[xx][j]=yy;
            }
        }
        scanf("\n");
        for (i=1; i<=n; i++)
        {
            cin>>ch;
            xx=localf[ch-'A'];
            scanf("%c",&ch);
            for (j=1; j<=n; j++)
            {
                scanf("%c",&ch);
                yy=localm[ch-'a'];
                y[xx][yy]=j;
            }
        }
        stable_match();
        for (j=0; j<=26; j++)
            if (localm[j]!=0)
            {
                i=localm[j];
                printf("%c %c\n",male[i],female[x[i][possx[i]]]);
            }
        if (k>0) printf("\n");
    }
}

void stable_match()
{
    int i,k,iny;
    for (i=1; i<=n; i++) possx[i]=1;    //man i possibly invite woman poss[i]
    for (i=1; i<=n; i++) invitey[i]=n+1;    //woman haven't receive invite
    for (i=1; i<=n; i++) s.push(i);
    while (!s.empty())
    {
        i=s.front();
        s.pop();
        iny=x[i][possx[i]];  //man i wants to invite iny
        if (invitey[iny]==n+1) //no guy invite iny
        {
            invitey[iny]=i;
            continue;
        }
        if (y[iny][i]<y[iny][invitey[iny]]) //man i is woman iny's favourite so far
        {
            possx[invitey[iny]]++;  //reject other man
            s.push(invitey[iny]);
            invitey[iny]=i;
            continue;
        }
        possx[i]++;
        s.push(i);
    }
}
