#include <bits/stdc++.h>
using namespace std;
struct person
{
	int id;
	int bestrank;
	char sym;
	int score[4],rank[4];
}v[2048];
int k=0;
vector<int> idtork(10000000,-1);
bool cmp(const person &a,const person &b)
{
	return a.score[k]>b.score[k];
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;++i)
	{
		scanf("%d %d %d %d",&v[i].id,&v[i].score[1],&v[i].score[2],&v[i].score[3]);
		v[i].score[0]=(v[i].score[1]+v[i].score[2]+v[i].score[3])/3;
	}
	while(k<4)
	{
		sort(v,v+n,cmp);
		v[0].rank[k]=1;
		for(int i=1;i<n;++i)
		{
			if(v[i].score[k]==v[i-1].score[k])
				v[i].rank[k]=v[i-1].rank[k];
			else v[i].rank[k]=i+1;
		}
		++k;
	}
	string symbol="ACME";
	for(int i=0;i<n;++i)
	{
		idtork[v[i].id]=i;
		v[i].bestrank=min(min(v[i].rank[0],v[i].rank[1]),min(v[i].rank[2],v[i].rank[3]));
		for(int j=3;j>=0;--j)
			if(v[i].rank[j]==v[i].bestrank)v[i].sym=symbol[j];
	}
	while(q--)
	{
		int id;
		scanf("%d",&id);
		if(idtork[id]==-1) printf("N/A\n");
		else
		{
			int i=idtork[id];
			printf("%d %c\n",v[i].bestrank,v[i].sym);
		}
	}
	return 0;
}
