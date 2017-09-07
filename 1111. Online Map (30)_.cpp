#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int Inf=999999;
int vn,an,s,e;
vector<vector<int>> vT(512,vector<int>(512,Inf));//timeAdjM
vector<vector<int>> vL(512,vector<int>(512,Inf));//lengthAdjM
vector<int> sp,fp;//储存最终结果路径，最短和最快
int mintime=Inf,ansdis=-1;//最短路径不唯一，取时间最短
int minsect=Inf,anstim=-1;//最短时间不唯一，取最少交叉口
void dijkstra(vector<vector<int>> &v,vector<vector<int>> &path)//dijkstra求解满足初始条件的所有解，v为邻接矩阵，path返回保存路径
{
	vector<int> dis(v[s]);
	vector<bool> vis(vn,false);
	vis[s]=true;
	while(true)
	{
		int mind=Inf,u=-1;
		for(int j=0;j<vn;++j)
		{
			if(!vis[j]&&dis[j]<mind) mind=dis[u=j];
		}
		if(u==-1) return;
		vis[u]=true;
		for(int w=0;w<vn;++w)
		{
			if(!vis[w]&&dis[w]>dis[u]+v[u][w])
			{
				dis[w]=dis[u]+v[u][w];
				path[w].clear();
				path[w].push_back(u);
			}
			else if(!vis[w]&&dis[w]==dis[u]+v[u][w])
				path[w].push_back(u);
		}
	}
}
void shortpath(vector<vector<int>>&lenp,vector<int> &rp,int cur,int timesum,int dis)//dfs筛选最优路径
{
	if(s==cur&&timesum<mintime)
	{
		mintime=timesum;
		sp=rp;
		ansdis=dis;
		return;
	}
	for(auto pre:lenp[cur])
	{
		rp.push_back(pre);
		shortpath(lenp,rp,pre,timesum+vT[pre][cur],dis+vL[pre][cur]);
		rp.pop_back();
	}
}
void fastpath(vector<vector<int>>&timp,vector<int> &rp,int cur,int tim,int seccnt)//dfs筛选最优路径
{
	if(s==cur&&seccnt<minsect)
	{
		minsect=seccnt;
		fp=rp;
		anstim=tim;
		return;
	}
	for(auto pre:timp[cur])
	{
		rp.push_back(pre);
		fastpath(timp,rp,pre,tim+vT[pre][cur],seccnt+1);
		rp.pop_back();
	}
}
int main(int argc, char const *argv[])
{
	cin>>vn>>an;
	for(int i=0;i<an;++i)
	{
		int u,w,oneway,length,time;
		cin>>u>>w>>oneway>>length>>time;
		vL[u][w]=length;
		vT[u][w]=time;
		if(oneway==0)
		{
			vL[w][u]=length;
			vT[w][u]=time;
		}
	}
	cin>>s>>e;
	vector<vector<int>> timp(vn),lenp(vn);//时间路径，长度路径
	for(int i=0;i<vn;++i)
	{
		if(vL[s][i]<Inf) lenp[i].push_back(s);
		if(vT[s][i]<Inf) timp[i].push_back(s);
	}
	dijkstra(vL,lenp);
	dijkstra(vT,timp);
	vector<int> rp;//记录可能的路径
	shortpath(lenp,rp,e,0,0);
	fastpath(timp,rp,e,0,0);
	if(sp==fp)
	{
		printf("Distance = %d; Time = %d: ",ansdis,anstim);
		for(auto it=sp.rbegin();it!=sp.rend();++it)
			printf("%d -> ",*it);
		printf("%d\n",e);
	}
	else
	{
		printf("Distance = %d: ",ansdis);
		for(auto it=sp.rbegin();it!=sp.rend();++it)
			printf("%d -> ",*it);
		printf("%d\n",e);
		printf("Time = %d: ",anstim);
		for(auto it=fp.rbegin();it!=fp.rend();++it)
			printf("%d -> ",*it);
		printf("%d\n",e);
	}
	return 0;
}
