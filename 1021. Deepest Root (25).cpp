#include <iostream>
#include <vector>
#include <algorithm>
#define Inf 9999999
using namespace std;
int n,k,curmaxdep,maxdep;
vector<int> parents;
vector<vector<int>> v;
vector<int> rt;
bool visit[10004];
void dfs(int r,int dep)
{
	curmaxdep=max(curmaxdep,dep);
	visit[r]=1;
	for(auto x:v[r])
	{
		if(!visit[x]) dfs(x,dep+1);
	}
	visit[r]=0;
}
int find(int x)
{
	return parents[x]==x?x:parents[x]=find(parents[x]);
}
int main()
{
	cin>>n;
	v.resize(n+1);
	parents.resize(n+1);
	rt.resize(n+1);
	for(int i=1;i<=n;++i) parents[i]=i;
	for(int i=1;i<=n-1;++i)
	{
		int u,w;
		cin>>u>>w;
		v[u].push_back(w);
		v[w].push_back(u);
		int L1=find(u),L2=find(w);
		if(L1!=L2) parents[L1]=L2;
	}
	for(int i=1;i<=n;++i)
	{
		if(parents[i]==i) ++k;
	}
	if(k>1) cout<<"Error: "<<k<<" components";
	else
	{
		for(int i=1;i<=n;++i)
		{
			curmaxdep=0;
			dfs(i,0);
			maxdep=max(maxdep,curmaxdep);
			rt[i]=curmaxdep;
		}
		for(int i=1;i<=n;++i) if(maxdep==rt[i]) cout<<i<<endl;
	}
	return 0;
}
