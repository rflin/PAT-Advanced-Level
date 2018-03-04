#include <bits/stdc++.h>
using namespace std;
vector<int> v[512];
int n,m,vertexNums,odd;
bool visit[512];
void dfs(int x){
	visit[x]=1;
	vertexNums++;
	for(int y:v[x]){
		if(!visit[y])dfs(y);
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for(int i=1;i<=n;++i){
		if(v[i].size()%2) ++odd;
		i==n?printf("%lld\n",v[i].size()):printf("%lld ",v[i].size());
	}
	if(odd==0&&vertexNums==n) printf("Eulerian\n");
	else if(odd==2&&vertexNums==n) printf("Semi-Eulerian\n");
	else printf("Non-Eulerian\n");
	return 0;
}
