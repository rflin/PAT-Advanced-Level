#include <iostream>
#include <vector>
#include <algorithm>
#define Inf 9999999
using namespace std;
vector<vector<int>> v(512,vector<int>(512,Inf));
vector<int> vtx;
vector<vector<int>> ap(512);
int n,m,s,e,maxamount,diffpath;
void dijkstra()
{
	vector<int> dis=v[s];
	bool visit[512]={0};
	visit[s]=1;
	for(int i=0;i<n;++i)
	{
		if(dis[i]<Inf) ap[i].push_back(s);
	}
	while(true)
	{
		int mindis=Inf,u=-1;
		for(int i=0;i<n;++i)
		{
			if(!visit[i]&&dis[i]<mindis) mindis=dis[u=i];
		}
		if(u==-1) break;
		visit[u]=1;
		for(int w=0;w<n;++w)
		{
			if(!visit[w]&&dis[w]>dis[u]+v[u][w])
			{
				ap[w].clear();
				ap[w].push_back(u);
				dis[w]=dis[u]+v[u][w];
			}
			else if(!visit[w]&&dis[w]==dis[u]+v[u][w])
				ap[w].push_back(u);
		}
	}
}
void dfs(int r,int rescuecpt)
{
	if(r==s)
	{
		++diffpath;
		maxamount=max(maxamount,rescuecpt);
		return;
	}
	for(auto x:ap[r]) dfs(x,rescuecpt+vtx[x]);
}
int main()
{
	cin>>n>>m>>s>>e;
	vtx.resize(n);
	for(int i=0;i<n;++i)
		cin>>vtx[i];
	for(int i=0;i<m;++i)
	{
		int u,w,length;
		cin>>u>>w>>length;
		v[u][w]=v[w][u]=length;
	}
	dijkstra();
	dfs(e,vtx[e]);
	cout<<diffpath<<" "<<maxamount;
	return 0;
}
