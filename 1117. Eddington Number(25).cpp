/*
题目地址：https://www.patest.cn/contests/pat-a-practise/1117
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k=0,days=0;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i) cin>>v[i];
	sort(v.begin(),v.end(),greater<int>());
	while(k<n)
	{
		++days;
		if(v[k]<=days) break;
		++k;
	}
	k==n?cout<<n:cout<<days-1;
	return 0;
}
