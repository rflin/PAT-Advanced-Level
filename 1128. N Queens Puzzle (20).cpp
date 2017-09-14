#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool nqueens(vector<int> &v)
{
	int n=v.size();
	for(int i=0;i<n-1;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(v[i]==v[j]||abs(v[j]-v[i])==abs(j-i)) return false;
		}
	}
	return true;
}
int main()
{
	int n,k,idx;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>k;
		vector<int> v;
		for(int j=0;j<k;++j)
		{
			cin>>idx;
			v.push_back(idx-1);
		}
		if(nqueens(v))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
