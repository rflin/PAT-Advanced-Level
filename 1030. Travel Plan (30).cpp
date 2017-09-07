#include <iostream>
#include <vector>
using namespace std;
const int Inf=999999;
vector<vector<int>> v(512,vector<int>(512,Inf)),cost(512,vector<int>(512,Inf));
vector<vector<int>> ph(512);
vector<int> ans;
int vn,an,s,d,mincost=Inf,ansdis;
void dijkstra()
{
	vector<int> dis(v[s]);
	vector<bool> vis(vn,false);
	vis[s]=true;
	while(true)
	{
		int mindis=Inf,u=-1;
		for(int i=0;i<vn;++i)
		{
			if(!vis[i]&&dis[i]<mindis) mindis=dis[u=i];
		}
		if(u==-1) return;
		vis[u]=true;
		for(int w=0;w<vn;++w)
		{
			if(!vis[w]&&dis[w]>dis[u]+v[u][w])
			{
				dis[w]=dis[u]+v[u][w];
				ph[w].clear();
				ph[w].push_back(u);
			}
			else if(!vis[w]&&dis[w]==dis[u]+v[u][w])
				ph[w].push_back(u);
		}
	}
}
void dfs(int cur,vector<int> &rp,int costcnt,int distan)
{
	if(cur==s&&costcnt<mincost)
	{
		mincost=costcnt;
		ansdis=distan;
		ans=rp;
		return;
	}
	for(auto pre:ph[cur])
	{
		rp.push_back(pre);
		dfs(pre,rp,costcnt+cost[cur][pre],distan+v[cur][pre]);
		rp.pop_back();
	}
}
int main(int argc, char const *argv[])
{
	cin>>vn>>an>>s>>d;
	for(int i=0;i<an;++i)
	{
		int u,w,c,dis;
		cin>>u>>w>>dis>>c;
		v[u][w]=v[w][u]=dis;
		cost[u][w]=cost[w][u]=c;
	}
	for(int i=0;i<vn;++i)
		if(v[s][i]<Inf) ph[i].push_back(s);
	dijkstra();
	vector<int> rp;
	dfs(d,rp,0,0);
	for(auto it=ans.rbegin();it!=ans.rend();++it)
		cout<<*it<<" ";
	cout<<d<<" "<<ansdis<<" "<<mincost;
	return 0;
}
