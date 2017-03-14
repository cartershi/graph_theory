//hdu 2063 fast bfs version
//O(n^0.5*m)
//reference https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm
#include<stdio.h>
#include <vector>
#include <ctime>
using namespace std;
#define NN 2510
vector<int>edge[NN];
vector<int>edge_verse[NN];
int n1, n2, m, ans;
int match1[NN], match2[NN], father[NN],dis[NN],augmented[NN],visit[NN],queue[NN];
void aug();
bool dfs(int,int);

int main()
{
    int x, y, i;
 clock_t ss=clock();
    freopen("1.txt","r",stdin);
    scanf("%d", &m);
    while (m != 0)
    {
        scanf("%d%d", &n1, &n2);
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            edge[x].push_back(y);
            edge_verse[y].push_back(x);
        }
        ans = 0;
        for (i = 1; i <= n1; i++) match1[i] = 0;
        for (i = 1; i <= n2; i++) match2[i] = 0;
        aug();
        printf("%d\n", ans);
        for (i = 1; i <= n1; i++) edge[i].clear();
        for (i = 1; i <= n2; i++) edge_verse[i].clear();
        scanf("%d", &m);
    }
printf("bfs time used %fs\n",(double)(clock()-ss)/CLOCKS_PER_SEC);
}

void aug()
{
    int u, l,r, num,i,flag;
    while (1)
    {
        l=r=0;
        for (i = 1; i <= n2; i++) father[i] = 0;
        for (i=1; i<=n1; i++) visit[i]=dis[i]=0;
        for (i=1; i<=n1; i++)   //unmatched vertex inqueue
            if (match1[i]==0) 
            {
                r++;
                queue[r]=i; 
            }
        flag=n1+n2;
        num=0;
        while (l<r)
        {
            if (flag<=dis[queue[++l]]) break;    //longer than the shortest path
            u=queue[l];
            for (vector<int>::iterator it = edge[u].begin(); it != edge[u].end(); it++)
                if (father[*it] == 0)   //*it not visited
                {
                    father[*it] = u;
                    if (match2[*it] != 0) 
                    {
                        queue[++r]=match2[*it];  //if *it matchted,add it to the queue
                        dis[match2[*it]]=dis[u]+2;
                    }
                    else
                    {   
                        flag=dis[u]+1;  //shrotest path is found
                        augmented[++num]=*it;
                        break;
                    }
                }
        }
        if (num==0) return; //no augmenting path
        //printf("%d ",num);
        for (i=1; i<=num; i++)
            if (dfs(augmented[i],flag)) //dfs to find the augmenting path
                ans++;
    }
}

bool dfs(int u,int disu)
{
    if (u==0) return true;
    if (disu<0) return false;
    for (vector<int>::iterator it = edge_verse[u].begin(); it != edge_verse[u].end(); it++)
        if (visit[*it]==0&&dis[*it]+1==disu)
        {
            visit[*it]=1;
            if (dfs(match1[*it],disu-2))
            {
                match2[u]=*it;  //change the match
                match1[*it]=u;
                return true;
            }
        }
    return false;
}
