#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,idx,root,maxdep,cnt;
double p,r;
vector<vector<int>> v;
void HighestPrice(int xr,int dep)
{
	if(v[xr].size()==0)
	{
		if(dep==maxdep) ++cnt;
		else if(dep>maxdep) maxdep=dep,cnt=1;
		return;
	}
	for(auto x:v[xr]) HighestPrice(x,dep+1);
}
int main()
{
	scanf("%d %lf %lf",&n,&p,&r);
	v.resize(n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&idx);
		if(idx==-1) root=i;
		else v[idx].push_back(i);
	}
	HighestPrice(root,0);
	printf("%.2lf %d",p*pow((1+r/100),maxdep),cnt);
	return 0;
}
