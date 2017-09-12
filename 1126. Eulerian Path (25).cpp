#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <map> 
using namespace std;
vector<vector<int>> v; 
vector<bool> visit;
int cnt;
void dfs(int u)
{
	visit[u]=true;++cnt;
	for(auto x:v[u]) if(!visit[x]) dfs(x);
} 
int main()
{
    int n,m;
    cin>>n>>m;
    v.resize(n+1);
    visit.resize(n+1);
    for(int i=0;i<m;++i)
    {
    	int u,w;
    	cin>>u>>w;
    	v[u].push_back(w);
    	v[w].push_back(u);
	}
	dfs(1);
	int odd=0;
	for(int i=1;i<=n;++i)
	{
		i==n?cout<<v[i].size()<<endl:cout<<v[i].size()<<" ";
		if(v[i].size()%2==1) odd++;
	} 
	if(odd==0&&cnt==n) cout<<"Eulerian";
	else if(odd==2&&cnt==n) cout<<"Semi-Eulerian";
	else cout<<"Non-Eulerian";
    return 0;
}
