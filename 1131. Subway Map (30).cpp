#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct node
{
	int line,s,e;
	node(int xl,int xs,int xe):line(xl),s(xs),e(xe){}
};
int searchLine[10000][10000];//判断两个站点在哪条线上
int n,q,minstation,mintransfer;//线个数，请求个数，最小的站点，最小的换乘
vector<vector<int>> v(10000);//图的邻接表
vector<node> ans,recp;//最终结果路径和中间记录路径
bool visit[10000];//判断是否已经访问数组
void subwayMap(int head,int cur,int end,int staioncnt,vector<node> &recp,int pre)
{
	if(cur==end&&(staioncnt<minstation||(staioncnt==minstation&&mintransfer>(int)recp.size()+1)))
	{
		minstation=staioncnt;
		ans=recp;
		ans.push_back(node(searchLine[pre][end],head,end));
		mintransfer=ans.size();
		return;
	}
	visit[cur]=1;
	for(auto next:v[cur])
	{
		if(visit[next]) continue;
		if(pre!=cur&&searchLine[pre][cur]!=searchLine[cur][next])//线路不同，cur为换乘节点
		{
			recp.push_back(node(searchLine[pre][cur],head,cur));//收集上一个线路信息：几号线，首站，尾站
			subwayMap(cur,next,end,staioncnt+1,recp,cur);
			recp.pop_back();
		}
		else subwayMap(head,next,end,staioncnt+1,recp,cur);//线路相同，首站不变;
	}
	visit[cur]=0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int k,idx,p;
		scanf("%d %d",&k,&p);
		for(int j=0;j<k-1;++j)
		{
			scanf("%d",&idx);
			searchLine[p][idx]=searchLine[idx][p]=i;//两个相邻节点的线路
			v[p].push_back(idx);
			v[idx].push_back(p);
			p=idx;
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		int s,e;
		scanf("%d %d",&s,&e);
		minstation=mintransfer=0x7fffffff;
		subwayMap(s,s,e,0,recp,s);
		printf("%d\n",minstation);
		for(auto x:ans) printf("Take Line#%d from %04d to %04d.\n",x.line,x.s,x.e);
	}
    return 0;
}
