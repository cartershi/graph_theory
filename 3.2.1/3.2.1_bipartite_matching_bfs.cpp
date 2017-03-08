//hdu 2063 bfs version
//O(nm)
#include<stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define NN 510
vector<int>edge[NN];
queue<int>s;
int n1, n2, m, ans;
int match1[NN], match2[NN], father[NN];
void aug();

int main()
{
	int x, y, i, j;
	scanf("%d", &m);
	while (m != 0)
	{
		scanf("%d%d", &n1, &n2);
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
		}
		ans = 0;
		for (i = 1; i <= n1; i++) match1[i] = 0;
		for (i = 1; i <= n2; i++) match2[i] = 0;
		for (i = 1; i <= n1; i++)   //try to match every vertex
		if (match1[i] == 0)
		{
			for (j = 1; j <= n2; j++) father[j] = 0;
			s.push(i);
			aug();
		}
		printf("%d\n", ans);
		for (i = 1; i <= n1; i++) edge[i].clear();
		scanf("%d", &m);
	}
}

void aug()
{
	int u, v1, v2, v;
	while (!s.empty())  //s queue
	{
		u = s.front();
		s.pop();
		for (vector<int>::iterator it = edge[u].begin(); it != edge[u].end(); it++)
		if (father[*it] == 0)   //*it not visited
		{
			father[*it] = u;
			if (match2[*it] != 0) s.push(match2[*it]);  //if *it matchted,add it to s
			else
			{   
				v2 = *it;   //if *it unmatched,augmenting path found
				v1 = u;
				while (v1 != 0)
				{
					v = match1[v1];
					match1[v1] = v2;
					match2[v2] = v1;
					v2 = v;
					v1 = father[v2];
				}
				while (!s.empty()) s.pop();
				ans++;
				return;
			}
		}
	}
}
