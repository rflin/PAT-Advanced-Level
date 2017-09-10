#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
vector<vector<int>> v; 
vector<int> lev;
void solve(int r,int dep)
{
	if(dep+1>lev.size())lev.resize(dep+1);
	lev[dep]++;
	for(auto x:v[r])
	{
		solve(x,dep+1);
	}
}
int main()
{
	cin>>n>>m;
	v.resize(n+1);
	for(int i=0;i<m;++i)
	{
		int id,k,idx;
		cin>>id>>k;
		for(int i=0;i<k;++i)
		{
			cin>>idx;
			v[id].push_back(idx);
		}
	}
	solve(1,0);
	int l=0,maxgen=-1;
	for(unsigned int i=0;i<lev.size();++i)
	{
		if(maxgen<lev[i]) maxgen=lev[l=i];
	}
	cout<<maxgen<<" "<<l+1;
	return 0;
}
