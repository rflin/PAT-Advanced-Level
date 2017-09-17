#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
struct edge
{
	int u,w;
	edge(int x,int y):u(x),w(y){}
};
vector<edge> v;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		int u,w;
		cin>>u>>w;
		v.push_back(edge(u,w));
	}
	int k;
	cin>>k;
	while(k--)
	{
		int num,visit[10000]={0},ret=1,idx;
		set<int> s;
		cin>>num;
		for(int i=0;i<num;++i)
		{
			cin>>idx;
			s.insert(idx);
		}
		for(auto x:v)
		{
			if(visit[x.u]||visit[x.w]) continue;
			if(s.find(x.u)!=s.end()) visit[x.u]=1;
			else if(s.find(x.w)!=s.end()) visit[x.w]=1;
			else {ret=0;break;}
		}
		ret==1?cout<<"Yes\n":cout<<"No\n";
	}
	return 0;
}
