#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,p;
	vector<long long> v;
	scanf("%lld %lld",&n,&p);
	for(int i=0;i<n;++i)
	{
		long long x;
		scanf("%lld",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	long long i=0,j=n-1,len=-1;
	while(v[j]>p*v[i])++i;
	len=max(j-i+1,len);
	while(i>=0)
	{
		--j;
		while(i>=0&&v[j]<=p*v[i])--i;
		++i;
		len=max(j-i+1,len);
		if(i==0)break;
	}
	printf("%lld\n",len);
	return 0;
}
