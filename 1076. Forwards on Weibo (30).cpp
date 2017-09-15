#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<vector<int>> v;
int n,L,k,idx,q;
int main()
{
	scanf("%d %d",&n,&L);
	v.resize(n+1);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&k);
		for(int j=0;j<k;++j)
		{
			scanf("%d",&idx);
			v[idx].push_back(i);
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&idx);
		bool visit[1024]={0};
		int first=0,last=1,cnt=1,lev=0;
		queue<int> q;
		q.push(idx);
		visit[idx]=1;
		while(!q.empty())
		{
			int s=q.front();
			q.pop();++first;
			for(auto x:v[s])
			{
				if(!visit[x])
				{
					q.push(x);
					visit[x]=1;
					++cnt;
				}
			}
			if(first==last)
			{
				++lev;
				last=cnt;
			}
			if(lev==L) break;
		}
		cout<<cnt-1<<endl;
	}
	return 0;
}
