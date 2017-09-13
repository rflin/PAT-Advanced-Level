#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
vector<vector<int>> v(10000);
vector<int> idxlist;
vector<double> idxestate(10000),idxarea(10000);
int minid,memcnt,visit[10000];
double totalestate,totalarea;
struct propertyInfo
{
	int id,memcnt;
	double estate,area;
	propertyInfo(int x,int y,double ae,double aa):id(x),memcnt(y),estate(ae),area(aa){}
	bool operator<(const propertyInfo &pi)const
	{
		if(area!=pi.area) return area>pi.area;
		return id<pi.id;
	}
};
void propertyCpt(int id)
{
	if(visit[id]) return;
	visit[id]=true;
	++memcnt;
	minid=min(minid,id);
	totalestate+=idxestate[id];
	totalarea+=idxarea[id];
	for(auto x:v[id])
	{
		if(!visit[x]) propertyCpt(x);
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int id,father,mother,k,x;
		scanf("%d %d %d %d",&id,&father,&mother,&k);
		idxlist.push_back(id);
		if(father!=-1) v[id].push_back(father),v[father].push_back(id);
		if(mother!=-1) v[id].push_back(mother),v[mother].push_back(id);
		for(int j=0;j<k;++j)
		{
			scanf("%d",&x);
			v[id].push_back(x);
			v[x].push_back(id);
		}
		scanf("%lf %lf",&idxestate[id],&idxarea[id]);
	}
	vector<propertyInfo> ans;
	for(auto id:idxlist)
	{
		minid=10000;
		memcnt=0;
		totalestate=totalarea=0.0;
		propertyCpt(id);
		if(memcnt==0) continue;
		ans.push_back(propertyInfo(minid,memcnt,1.0*totalestate/memcnt,1.0*totalarea/memcnt));
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto &x:ans) printf("%04d %d %.3lf %.3lf\n",x.id,x.memcnt,x.estate,x.area);
	return 0;
}
