#include <iostream>
#include <vector>
using namespace std;
vector<int> v[128],ans;
void countLeaves(int r,unsigned int lev)
{
	if(lev+1>ans.size()) ans.push_back(0);
	if(v[r].size()==0) ans[lev]++;
	for(auto x:v[r])
		countLeaves(x,lev+1);
}
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		int id,k,idx;
		cin>>id>>k;
		for(int j=0;j<k;++j)
		{
			cin>>idx;
			v[id].push_back(idx);
		}
	}
	countLeaves(1,0);
	for(unsigned int i=0;i<ans.size();++i)
	{
		i!=ans.size()-1?cout<<ans[i]<<" ":cout<<ans[i];
	}
	return 0;
}
