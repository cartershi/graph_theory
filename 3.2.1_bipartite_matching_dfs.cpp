//hdu 2063 dfs version
#include <stdio.h>
#define NN 510
int edge[NN][NN];
int visited[NN],match[NN];
int n1, n2;
bool dfs(int);

int main()
{
	int i, j, m,x,y,ans;
	scanf("%d", &m);
	while (m != 0)
	{
		ans = 0;
		scanf("%d%d", &n1, &n2);
		for (i = 1; i <= n1; i++)
		for (j = 1; j <= n2; j++)
			edge[i][j] = 0;
		for (i = 1; i <= n2; i++) match[i] = -1;
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			edge[x][y] = 1;
		}
		for (i = 1; i <= n1; i++)
		{
			for (j = 1; j <= n2; j++) visited[j] = 0;
			if (dfs(i)) ans++;
		}
		printf("%d\n",ans);
		scanf("%d", &m);
	}
}

bool dfs(int u)
{
	int j;
	for (j = 1; j <= n2; j++)
	if (edge[u][j]!=0&&visited[j]==0)
	{
		visited[j] = 1;
		if (match[j]==-1||dfs(match[j]))
		{
			match[j] = u;
			return true;
		}
	}
	return false;
}
