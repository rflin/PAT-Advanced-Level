#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int nums[10004],n,idx;
vector<int> v;
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>idx;
		nums[idx]++;
		v.push_back(idx);
	}
	for(auto x:v)
	{
		if(nums[x]==1)
		{
			cout<<x;return 0;
		}
	}
	cout<<"None";
	return 0;
}
