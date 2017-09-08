#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int n,m,s;
vector<int> w;
vector<vector<int>> v,ans;
void solve(int r,int sum,vector<int> &rp)
{
	if(v[r].size()==0&&sum==s)
	{
		ans.push_back(rp);
		return;
	}
	for(auto x:v[r])
	{
		rp.push_back(w[x]);
		solve(x,sum+w[x],rp);
		rp.pop_back();
	}
}
int main(int argc, char const *argv[])
{
	cin>>n>>m>>s;
	v.resize(n);
	w.resize(n);
	for(int i=0;i<n;++i)
		cin>>w[i];
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
	vector<int> rp;
	rp.push_back(w[0]);
	solve(0,w[0],rp);
	sort(ans.begin(),ans.end(),greater<vector<int>>());
	for(auto xv:ans)
	{
		for(unsigned int i=0;i<xv.size();++i)
			i!=xv.size()-1?cout<<xv[i]<<" ":cout<<xv[i]<<endl;
	}
	return 0;
}
