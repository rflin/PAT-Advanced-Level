#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;
vector<double> v;
int main()
{
	int n;
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;++i)cin>>v[i];
	sort(v.begin(),v.end(),greater<double>());
	auto x=0.0;
	while(!v.empty())
	{
		x=v.back();
		v.pop_back();
		if(v.size()==0) break;
		v[v.size()-1]=(v.back()+x)/2;
	}
	cout<<(int)x;
	return 0;
} 
