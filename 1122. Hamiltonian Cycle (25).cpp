#include <iostream>
#include <vector>
using namespace std;
int vn,an,k;
vector<vector<int>> v;
bool isHamiltonian(vector<int> &ph)
{
	if(ph[0]!=ph.back()||(int)ph.size()!=vn+1) return false;
	vector<bool> visit(vn+1,0);
	for(size_t i=0;i<ph.size()-1;++i)
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
	scanf("%d %d",&vn,&an);
	v.resize(vn+1);
	for(int i=0;i<an;++i)//储存邻接表
	{
		int u,w;
		scanf("%d %d",&u,&w);
		v[u].push_back(w);
		v[w].push_back(u);
	}
	scanf("%d",&k);
	while(k--)
	{
		int m;
		scanf("%d",&m);
		vector<int> ph(m);
		for(int i=0;i<m;++i)
			scanf("%d",&ph[i]);
		isHamiltonian(ph)?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
} 
