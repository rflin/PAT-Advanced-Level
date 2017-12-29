/*考察set*/
#include <bits/stdc++.h>
using namespace std;
vector<set<int>> v;
double Similarity(set<int> &a,set<int> &b)
{
	auto x=a.begin(),y=b.begin();
	int samecnt=0;
	while(x!=a.end()&&y!=b.end())
	{
		if(*x==*y)
		{
			samecnt++;
			++x;++y;
		}
		else if(*x<*y) ++x;
		else ++y;
	}
	double ret=1.0*samecnt/(a.size()+b.size()-samecnt);
	return ret;
}
int main()
{
	int n,q;
	scanf("%d",&n);
	v.resize(n+1);
	for(int i=1;i<=n;++i)
	{
		int m;
		scanf("%d",&m);
		while(m--)
		{
			int x;
			scanf("%d",&x);
			v[i].insert(x);
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		double ret=Similarity(v[x],v[y])*100;
		printf("%.1lf%%\n",ret);
	}
	return 0;
}
