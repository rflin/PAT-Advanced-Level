#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v;
	vector<pair<int,int>> ret(100000+1);
	int n,amount,L=1,R=1,sum=0;
	scanf("%d %d",&n,&amount);
	v.resize(n+1);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&v[i]);
		if(sum<amount)
		{
			sum+=v[i];
			R=i;
		}
	}
	int minamt=999999999;
	while(R<=n)
	{
		if(sum>=amount)
		{
			ret[L]=make_pair(R,sum);
			minamt=min(sum,minamt);
		}
		sum-=v[L++];
		while(R<=n&&sum<amount)sum+=v[++R];
	}
	for(int i=1;i<=n;++i)
		if(ret[i].second==minamt)
			printf("%d-%d\n",i,ret[i].first);
	return 0;
}
