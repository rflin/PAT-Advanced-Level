/*dfs判断连通*/
#include <bits/stdc++.h>
using namespace std;
vector<int> v[1024];
void dfs(int u,bool visit[])
{
	visit[u]=true;
	for(auto x:v[u])
	{
		if(!visit[x])
			dfs(x,visit);
	}
}
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;++i)
	{
		int u,w;
		scanf("%d %d",&u,&w);
		v[u].push_back(w);
		v[w].push_back(u);
	}
	while(k--)
	{
		int cur;
		scanf("%d",&cur);
		bool visit[1024]={0};
		int cnt=0;
		visit[cur]=true;
		for(int i=1;i<=n;++i)
		{
			if(!visit[i])
			{
				dfs(i,visit);
				++cnt;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}
