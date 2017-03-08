
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=30;
int pref[maxn][maxn],ord[maxn][maxn],fum[maxn],fuw[maxn],nex[maxn];
int t,n;
char ch[30],s[35],x;
int nu[30];
map<char,int>vm,vw;
map<int,char>um,uw;
bool cmp(int x,int y)
{
    return ch[x]<ch[y];
}
queue<int>q;
void engage(int m,int w)
{
    int pm=fum[w];
    if(pm){
        fuw[pm]=0;
        q.push(pm);
    }
    fuw[m]=w;
    fum[w]=m;
}
int main()
{
freopen("1.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        memset(pref,0,sizeof(pref));
        vm.clear();vw.clear();um.clear();uw.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            cin>>ch[i];
            nu[i]=i;
        }
        sort(nu+1,nu+1+n,cmp);
        for(int i=1;i<=n;i++){
            int tmp=nu[i];
            vm[ch[tmp]]=tmp;
            um[tmp]=ch[tmp];
            fuw[tmp]=0;
            nex[tmp]=1;
            q.push(tmp);
        }
        for(int i=1;i<=n;i++){
            cin>>x;
            vw[x]=i;
            uw[i]=x;
            fum[i]=0;
        }
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            int tmp=vm[s[0]];
            for(int j=2;j<n+2;j++){
                pref[tmp][j-1]=vw[s[j]];
            }
        }
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            int tmp=vw[s[0]];
            for(int j=2;j<n+2;j++){
                ord[tmp][vm[s[j]]]=j-1;
            }
        }
        while(!q.empty()){
            int m=q.front();
            q.pop();
            int w=pref[m][nex[m]++];
            if(w==0) continue;
            if(!fum[w])
                engage(m,w);
            else if(ord[w][m]<ord[w][fum[w]])
                engage(m,w);
            else q.push(m);
        }
        while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++){
            int tmp=nu[i];
            printf("%c %c\n",um[tmp],uw[fuw[tmp]]);
        }
        if(t!=0) printf("\n");
    }
    return 0;
}
