#include <bits/stdc++.h>
using namespace std;
vector<int> convert(int n,int b)
{
	if(n==0) return vector<int>{0};
	vector<int> v;
	while(n)
	{
		v.push_back(n%b);
		n/=b;
	}
	return v;
}
int main()
{
	int n,b;
	cin>>n>>b;
	vector<int> rv=convert(n,b),v=rv;
	reverse(v.begin(),v.end());
	rv==v?cout<<"Yes\n":cout<<"No\n";
	for(size_t i=0;i<v.size();++i)
		i==v.size()-1?cout<<v[i]:cout<<v[i]<<" ";
	return 0;
}
