#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<int> v,maxl,minr,ans;
int main()
{
	cin>>n;
	v.resize(n);
	maxl.resize(n);
	minr.resize(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	maxl[0]=v[0];
	for(int i=1;i<n;++i) maxl[i]=max(maxl[i-1],v[i]); 
	minr[n-1]=v[n-1];
	for(int i=n-2;i>=0;--i) minr[i]=min(minr[i+1],v[i]);
	for(int i=0;i<n;++i)
	{
		if(maxl[i]<=v[i]&&v[i]<=minr[i]) ans.push_back(v[i]); 
	}
	sort(ans.begin(),ans.end());
	int k=0;
	cout<<ans.size()<<endl;
	for(auto x:ans) ++k==ans.size()?cout<<x:cout<<x<<" ";
	cout<<endl;
	return 0;
}
