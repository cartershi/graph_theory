//hdu 2255
//O(n^3) n=4000 takes 1.8s in my computer
//The previous match is still a match after modifying label,which helps accelarate the algorithm.
//reference http://www.cse.ust.hk/~golin/COMP572/Notes/Matching.pdf
#include <stdio.h>
#include <ctime>
#define NN 4510
int n,m;
int weight[NN][NN]; //bigraph x-y,with size n*n
int lx[NN],ly[NN],slack[NN],visit[NN],s[NN],match[NN],fatherx[NN],fathery[NN];
int ls,rs;    //locate set s
void aug(int);
bool add_new(int);
void findaug(int,int);

int main()
{
    clock_t ss=clock();
    int i,j,ans;
    freopen("1.txt","r",stdin);
    while (scanf("%d",&n)!=EOF)
    {
    m=n;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++) scanf("%d",&weight[i][j]);
    if (n<m) n=m;   //make n the bigger one
    for (i=1; i<=n; i++) lx[i]=0;   //lable of x
    for (i=1; i<=n; i++) ly[i]=0;   //lable of y
    for (i=1; i<=n; i++)    //lx starts from a feasible slution
        for (j=1; j<=n; j++)
            if (lx[i]<weight[i][j]) 
                lx[i]=weight[i][j];
    for (i=1; i<=n; i++) match[i]=fatherx[i]=fathery[i]=0;
    ans=0;
    for (i=1; i<=n; i++)    //match vertex i
        aug(i);
    for (i=1; i<=n; i++) ans+=lx[i];    //dual:perfect match=maximum match
    for (i=1; i<=n; i++) ans+=ly[i];
    printf("%d\n",ans);
    printf("time used %fs\n",(double)(clock()-ss)/CLOCKS_PER_SEC);
    //for (i=1; i<=n; i++) printf("%d %d\n",lx[i],ly[i]);
    }
}

void aug(int u)
{
    int i,x,vare;
    for (i=1; i<=n; i++) visit[i]=0;    //only y need to record whether visited or not
    for (i=1; i<=n; i++) slack[i]=200000000;
    rs=ls=1;
    s[1]=u;
    while (1)
    {
        while (ls<=rs)  //update augment tree rooted at u
        {
            x=s[ls];    //s[ls] is the vertex to find its neighbours
            for (i=1; i<=n; i++)
                if (visit[i]==0)
                    if (lx[x]+ly[i]-weight[x][i]<slack[i])  //update slack of Y-T
                    {
                        slack[i]=lx[x]+ly[i]-weight[x][i];
                        fathery[i]=x;
                    }
            for (i=1; i<=n; i++)
                if (visit[i]==0&&lx[x]+ly[i]-weight[x][i]==0)   //add vertex i to T
                {
                    fathery[i]=x;
                    if (add_new(i)) {findaug(u,i); return;}
                }
            ls++;
        }
        vare=200000000;
        for (i=1; i<=n; i++)    //modify label to add edge from S to Y-T
            if (visit[i]==0&&vare>slack[i])
                vare=slack[i];
        for (i=1; i<=rs; i++) lx[s[i]]-=vare;
        for (i=1; i<=n; i++) 
        {
            if (visit[i]==1) ly[i]+=vare;
            else slack[i]-=vare;
        }
        for (i=1; i<=n; i++)    //find the new edges added
            if (visit[i]==0&&slack[i]==0)
                if (add_new(i)) {findaug(u,i); return;}
    }
}

bool add_new(int y) //add new vertex to T
{
    visit[y]=1;
    if (match[y]==0) return true;
    s[++rs]=match[y];
    fatherx[match[y]]=y;
    return false;
}

void findaug(int u,int vy) //when finding an augmenting path,update the match
{
    int vx;
    vx=fathery[vy];
    while (vx!=u)
    {
        match[vy]=vx;
        vy=fatherx[vx];
        vx=fathery[vy];
    }
    match[vy]=u;
}
