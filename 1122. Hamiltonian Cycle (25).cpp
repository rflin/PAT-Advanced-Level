#include <bits/stdc++.h>
using namespace std;
bool A[256][256];
int n,m;
bool isHamiltonianCycle(vector<int> &v)
{
	if(v[0]!=v.back()||(int)v.size()!=n+1) return 0;
	vector<bool> visit(v.size()+1,0);
	for(int i=0;i<(int)v.size()-1;++i){
		if(A[v[i]][v[i+1]]==0||visit[v[i]]) return 0;
		else visit[v[i]]=1;
	}
	return 1;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		A[a][b]=A[b][a]=1;
	}
	int k,n;
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		vector<int> v(n);
		for(int i=0;i<n;++i){
			scanf("%d",&v[i]);
		}
		isHamiltonianCycle(v)?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
