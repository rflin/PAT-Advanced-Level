#include <iostream>
#include <vector>
#include <string>
using namespace std;
int vn,an,k;
vector<vector<int>> v;
bool judge(vector<int> &ph)
{
	if(ph[0]!=ph.back()||ph.size()!=vn+1) return false;
	vector<bool> visit(vn+1,0);
	for(unsigned int i=0;i<ph.size()-1;++i)
	{
		int cur=ph[i],tag=0;
		for(auto x:v[cur])
		{
			if(x==ph[i+1]&&!visit[x])
			{
				tag=1;visit[x]=true;
				break;
			}
		}
		if(tag==0) return false;
	}
	return true;
}
int main()
{
	cin>>vn>>an;
	v.resize(vn+1);
	for(int i=0;i<an;++i)
	{
		int u,w;
		cin>>u>>w;
		v[u].push_back(w);
		v[w].push_back(u);
	}
	cin>>k;
	while(k--)
	{
		int m;
		cin>>m;
		vector<int> ph(m);
		for(int i=0;i<m;++i)cin>>ph[i];
		judge(ph)?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
} 
