#include <iostream>
#include <vector>
using namespace std;
int n,s;
vector<int> ino,pos;
vector<vector<int>> lev; 
void build(int posL,int posR,int inoL,int inoR,int dep)
{
	if(posL>posR) return;
	int e=pos[posR],idx=inoR,pdx=posR;
	while(idx>=inoL&&e!=ino[idx]) idx--,pdx--;
	if(dep+1>lev.size()) lev.resize(dep+1);
	lev[dep].push_back(e);
	build(posL,pdx-1,inoL,idx-1,dep+1);
	build(pdx,posR-1,idx+1,inoR,dep+1);
}
int main()
{
	cin>>n;
	ino.resize(n);
	pos.resize(n);
	for(int i=0;i<n;++i) cin>>pos[i];
	for(int i=0;i<n;++i) cin>>ino[i];
	build(0,n-1,0,n-1,0);
	for(auto xv:lev)
	{
		for(auto x:xv) ++s==n?cout<<x:cout<<x<<" ";
	}
	return 0;
}
