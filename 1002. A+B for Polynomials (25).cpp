#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
double poly[1000];
set<int,greater<int>> mst;
int main()
{
	int k,n;
	double a;
	cin>>k;
	while(k--)
	{
		cin>>n>>a;
		poly[n]+=a;
		mst.insert(n);
	}
	cin>>k;
	while(k--)
	{
		cin>>n>>a;
		poly[n]+=a;
		if(poly[n]==0) mst.erase(n);
		else mst.insert(n);
	}
	cout<<mst.size();
	for(auto x:mst)
		printf(" %d %.1lf",x,poly[x]);
	return 0;
}
