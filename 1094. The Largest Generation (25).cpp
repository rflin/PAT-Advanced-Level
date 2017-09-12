#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
vector<vector<int>> v;
vector<int> lev;
void largestGeneration(int r,int dep)
{
	if(dep+1>lev.size()) lev.push_back(0);
	lev[dep]++;
	for(auto x:v[r]) largestGeneration(x,dep+1);
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	v.resize(n+1);
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
	largestGeneration(1,0);
	int maxlev=-1,maxcnt=-1;
	for(int i=0;i<lev.size();++i) if(maxcnt<lev[i]) maxcnt=lev[maxlev=i];
	cout<<maxcnt<<" "<<maxlev+1;
	return 0;
}
