#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n,cnt,md=0x7fffffff;
double p,r; 
vector<vector<int>> v;
void mindepth(int r,int dep)
{
	if(v[r].size()==0)
	{
		if(dep==md)cnt++;
		else if(dep<md) cnt=1,md=dep;
	}
	for(auto x:v[r]) mindepth(x,dep+1);
}
int main()
{
	cin>>n>>p>>r;
	v.resize(n);
	for(int i=0;i<n;++i)
	{
		int k,idx;
		cin>>k;
		for(int j=0;j<k;++j)
		{
			cin>>idx;
			v[i].push_back(idx);
		}
	}
	mindepth(0,0);
	printf("%.4lf %d",p*pow((1+r/100),md),cnt);
	return 0;
}
