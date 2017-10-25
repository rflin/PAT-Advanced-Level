#include <bits/stdc++.h>
using namespace std;
int n,amount[101024];
double p,r,total;
vector<vector<int>> v;
void dfs(int u,int dep)
{
	if(v[u].size()==0)
	{
		total+=amount[u]*p*pow((1+r/100),dep);
		return;
	}
	for(size_t i=0;i<v[u].size();++i)
	{
		dfs(v[u][i],dep+1);
	}
}
int main()
{
	scanf("%d %lf %lf",&n,&p,&r);
	v.resize(n);
	for(int i=0;i<n;++i)
	{
		int k;
		scanf("%d",&k);
		if(k>0)
		{
			int id;
			while(k--)
			{
				scanf("%d",&id);
				v[i].push_back(id);
			}
		}
		else scanf("%d",&amount[i]);
	}
	dfs(0,0);
	printf("%.1lf\n",total);
	return 0;
}
