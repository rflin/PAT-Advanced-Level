#include <bits/stdc++.h>
using namespace std;
vector<int> v[1024];
int indegree[1024];
bool isTopological(vector<int> &vx)
{
	int n=vx.size();
	vector<int> in(indegree,indegree+n+1);
	for(int x:vx){
		if(in[x]!=0) return 0;
		for(int y:v[x]){
			in[y]--;
		}
	}
	return 1;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		indegree[y]++;
	}
	int k;
	scanf("%d",&k);
	vector<int> res;
	for(int i=0;i<k;++i){
		vector<int> vx;
		for(int i=0;i<n;++i){
			int x;
			scanf("%d",&x);
			vx.push_back(x);
		}
		if(!isTopological(vx)) res.push_back(i);
	}
	int w=res.size();
	for(int x:res)
		--w?printf("%d ",x):printf("%d\n",x);
	return 0;
}
