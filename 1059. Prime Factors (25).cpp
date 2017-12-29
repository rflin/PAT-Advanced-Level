#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n,m,i=2;
	map<long int,int> mp;
	cin>>n;
	m=n;
	if(n==1)
	{
		cout<<"1=1"<<endl;
		return 0;
	}
	while(n!=1)
	{
		while(n%i!=0) ++i;
		mp[i]=0;
		while(n%i==0)
		{
			n/=i;
			mp[i]++;
		}
	}
	auto x=mp.begin();
	cout<<m<<"="<<x->first;
	if(x->second>1)cout<<"^"<<x->second;
	++x;
	while(x!=mp.end())
	{
		cout<<"*"<<x->first;
		if(x->second>1)
			cout<<"^"<<x->second;
		++x;
	}
	return 0;
}
