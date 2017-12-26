/*dijkstra+回溯*/
#include <bits/stdc++.h>
using namespace std;
const int Inf=999999999;
int cmax,n,e,m;
vector<vector<int>> a(512,vector<int>(512,Inf));
vector<int> vinfo(512,0);
vector<int> path[512],ansp;
int send=Inf,back=Inf;
void dijkstra(int s,int e)
{
	vector<int> dist=a[s];
	for(int i=1;i<=n;++i)
		if(dist[i]<Inf)path[i].push_back(s);//记录路径前驱
	bool visit[512]={0};
	visit[s]=1;
	for(int i=1;i<=n;++i)
	{
		int min=Inf,x=-1;
		for(int i=1;i<=n;++i)
		{
			if(min>dist[i]&&visit[i]==0)
				min=dist[x=i];
		}
		if(x==-1)return;
		visit[x]=1;
		for(int w=1;w<=n;++w)
		{
			if(!visit[w]&&dist[w]>dist[x]+a[x][w])
			{
				dist[w]=dist[x]+a[x][w];
				path[w].clear();
				path[w].push_back(x);
			}
			else if(!visit[w]&&dist[w]==dist[x]+a[x][w])
				path[w].push_back(x);
		}
	}
}
void dfs(int u,vector<int> rp)
{
	if(u==0)
	{
		int s=0,count=0;
		for(int i=rp.size()-1;i>=0;--i)
		{
			count+=vinfo[rp[i]]-cmax/2;
			if(count<0)
			{
				s+=-count;
				count=0;
			}
		}
		if(send>s||(send==s&&count<back))
		{
			send=s;
			back=count;
			ansp=rp;
		}
		return;
	}
	for(auto x:path[u])
	{
		rp.push_back(u);
		dfs(x,rp);
		rp.pop_back();
	}
}
int main()
{
	scanf("%d %d %d %d",&cmax,&n,&e,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&vinfo[i]);
	for(int i=0;i<m;++i)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		a[u][v]=a[v][u]=w;
	}
	dijkstra(0,e);
	dfs(e,vector<int>());
	printf("%d 0",send);
	for(int i=ansp.size()-1;i>=0;--i)
		printf("->%d",ansp[i]);
	printf(" %d\n",back);
    return 0;
}
