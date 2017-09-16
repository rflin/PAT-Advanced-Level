#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> p,v;
bool isIncrese(int L,int R)
{
	int i=L;
	while(i<R&&v[i]<v[i+1]) ++i;
	return i==R?true:false;
}
int main()
{
	cin>>n;
	p.resize(n);
	v.resize(n);
	for(int i=0;i<n;++i)
		cin>>p[i];
	for(int i=0;i<n;++i)
		cin>>v[i];
	int L=0,k=2;
	while(true)
	{
		L=0;
		while(L<n&&isIncrese(L,min(n-1,L+k-1)))L+=k;
		if(L>=n) k*=2;
		else break;
	}
	if(k>2)
	{
		cout<<"Merge Sort\n";
		L=0;
		while(L<n)
		{
			sort(v.begin()+L,v.begin()+min(n,L+k));
			L+=k;
		}
	}
	else
	{
		cout<<"Insertion Sort\n";
		int idx=0;
		while(idx<n-1&&v[idx]<=v[idx+1])++idx;
		sort(v.begin(),v.begin()+idx+2);
	}
	for(unsigned int i=0;i<v.size();++i)
		i==v.size()-1?cout<<v[i]:cout<<v[i]<<" ";
	return 0;
}
