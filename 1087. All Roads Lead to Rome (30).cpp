#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define Inf 9999999
using namespace std;
vector<vector<int>> v(256,vector<int>(256,Inf));
vector<vector<int>> ans(256);
vector<int> ps,p;
unordered_map<string,int> nametoidx;
unordered_map<int,string> idxtoname;
int idx,n,k,s,e,happiness[256],mincnt=Inf,happcnt=0,leastcostcnt=0,totalcost=0;
void dijkstra(int s,int e)
{
	bool visit[256]={0};
	vector<int> dis=v[s];
	for(int i=0;i<n;++i) if(v[i][s]<Inf) ans[i].push_back(s);
	visit[s]=1;
	while(true)
	{
		int minv=Inf,u=-1;
		for(int i=0;i<n;++i) if(!visit[i]&&dis[i]<minv) minv=dis[u=i];
		if(u==-1) break;
		visit[u]=1;
		for(int w=0;w<n;++w)
		{
			if(!visit[w]&&dis[w]>dis[u]+v[u][w])
			{
				ans[w].clear();
				ans[w].push_back(u);
				dis[w]=dis[u]+v[u][w];
			}
			else if(!visit[w]&&dis[w]==dis[u]+v[u][w])
				ans[w].push_back(u);
		}
	}
}
void dfs(int u,int reccost,int dep,int happ,vector<int> &p)
{
	if(u==s)
	{
		++leastcostcnt;
		totalcost=reccost;
		if(happ>happcnt||(happ==happcnt&&dep<mincnt))
		{
			happcnt=happ;
			mincnt=dep;
			ps=p;
		}
		return;
	}
	for(auto x:ans[u])
	{
		p.push_back(u);
		dfs(x,reccost+v[u][x],dep+1,happ+happiness[x],p);
		p.pop_back();
	}
}
int main()
{
	string st;
	cin>>n>>k>>st;
	nametoidx[st]=idx;
	idxtoname[idx]=st;
	s=idx++;
	for(int i=0;i<n-1;++i)
	{
		string str;
		int happy;
		cin>>str>>happy;
		nametoidx[str]=idx;
		idxtoname[idx]=str;
		happiness[idx++]=happy;
	}
	for(int i=0;i<k;++i)
	{
		string str1,str2;
		int idx1,idx2,cost;
		cin>>str1>>str2>>cost;
		idx1=nametoidx[str1];
		idx2=nametoidx[str2];
		v[idx1][idx2]=v[idx2][idx1]=cost;
	}
	e=nametoidx["ROM"];
	dijkstra(s,e);
	dfs(e,0,0,happiness[e],p);
	cout<<leastcostcnt<<" "<<totalcost<<" "<<happcnt<<" "<<happcnt/mincnt<<endl;
	cout<<st;
	for(auto it=ps.rbegin();it!=ps.rend();++it)
		cout<<"->"<<idxtoname[*it];
	return 0;
}
