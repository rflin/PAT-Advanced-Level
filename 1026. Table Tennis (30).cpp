/*
PAT甲级最坑的题之一
PAT甲级最坑的模拟题，没有之一

题目的意思是，给你一些用户信息（包括到达时间，使用时间，是否vip），以及球桌信息（个数，vip桌），让你输出
到达时间，服务时间，等待时间，以及每个球桌使用次数等

思路：
采用优先队列，区别记录vip和普通用户（球桌）,这样可以大大降低你coding的思维复杂度

1.当前用户队列中有vip用户并且有vip空闲桌时，优先分配vip，直到一方分配完毕
2.经过1后，队列中有一方肯定分配完毕，然后将vip用户（或者vip球桌）作为普通处理，push进普通
  队列
3.处理普通队列
详细看代码注解

需要注意的点：
1、很多大家网上也都说到了，包括开门关门时间（8~21）、大于2小时等，此处就略过了，具体看代码
2、说一些可能忽略到的
	当队列中有vip用户，vip球桌分配完毕但是还有普通桌时，此时我们将vip用户看作普通用户，将其push到普通
	队列p中（优先队列的优势便在此），但是，需要注意，有可能push到普通队列后，处理完普通桌与普通用户队列，
	普通桌分配完毕，但是p中还有用户，而这些用户可能是vip和普通混合的，因此，需要将他们再次分离，以便于下次
	分配（最后一个测试点）
*/
#include <bits/stdc++.h>
using namespace std;
int tabletime[128],tablecnt[128],viptag[128];
int n,m,vipm;
struct Person
{
	int atime;//到达时间
	int stime;//开始服务时间
	int utime;//使用时间
	bool isvip;
	Person(int at,int st,int ut,bool isv):atime(at),stime(st),utime(ut),isvip(isv){}
	bool operator<(const Person &a)const
	{
		return atime>a.atime;
	}
};
priority_queue<Person> p,vip;//普通用户等待队列，vip用户等待队列
priority_queue<int,vector<int>,greater<int>> tpq,vtpq;//普通球桌队列，vip球桌队列
vector<Person> v,ret;

bool cmpa(const Person &a,const Person &b)//按到达时间排序
{
	return a.atime<b.atime;
}
bool cmpb(const Person &a,const Person &b)//按服务时间排序
{
	return a.stime<b.stime;
};
int main(int argc, char const *argv[])
{
	// freopen("1.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int hh,mm,ss,p,isvip,time;
		scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&p,&isvip);
		time=hh*3600+mm*60+ss;
		if(p>120)p=120;//大于两个小时，取两个小时
		v.push_back(Person(time,time,p*60,isvip));//创建记录队列
	}
	sort(v.begin(),v.end(),cmpa);//按到达时间排序
	scanf("%d %d",&m,&vipm);//球桌总数，vip桌子数
	while(vipm--)
	{
		int x;
		scanf("%d",&x);
		viptag[x]=1;//vip球桌标记为1
	}
	for(int i=1;i<=m;++i)
		tabletime[i]=8*3600;//初始化球桌时间
	int i=0,curtime=8*3600;
	while(true)
	{
		if(i==n&&p.empty()&&vip.empty())break;
		if(curtime>=21*3600)break;
		while(i<n&&curtime>=v[i].atime)//在当前时间点之前的，都是等待中排队用户
		{
			if(v[i].isvip) vip.push(v[i]);//vip用户就push进vip队列
			else p.push(v[i]);//否则push进普通队列
			++i;
		}
		for(int k=1;k<=m;++k)//同理，处理球桌
		{
			if(tabletime[k]<=curtime)
			{
				if(viptag[k]) vtpq.push(k);
				else tpq.push(k);
			}
		}
		while(!vip.empty()&&!vtpq.empty())//既有空闲vip球桌又有vip
		{
			Person pi=vip.top();
			int ti=vtpq.top();
			pi.stime=curtime;//当前用户开始服务时间应该是当前时间
			ret.push_back(pi);//用户使用球桌，记录用户
			tabletime[ti]=curtime+pi.utime;//桌子时间应该是当前时间+该用户使用时间
			tablecnt[ti]++;//桌子被使用了一次
			vip.pop();
			vtpq.pop();
		}
		while(!vip.empty())//vip用户不为空，Vip球桌分配完毕，将vip当作普通用户处理
		{
			p.push(vip.top());
			vip.pop();
		}
		while(!vtpq.empty())//vip球桌不为空，队列中没有vip用户了，vip球桌当作普通桌处理
		{
			tpq.push(vtpq.top());
			vtpq.pop();
		}
		while(!p.empty()&&!tpq.empty())//处理普通桌和普通玩家
		{
			Person pi=p.top();
			int ti=tpq.top();
			pi.stime=curtime;//当前用户开始服务时间应该是当前时间
			ret.push_back(pi);//用户使用完毕，记录用户
			tabletime[ti]=curtime+pi.utime;//桌子时间应该是当前时间+该用户使用时间
			tablecnt[ti]++;//桌子被使用了一次
			p.pop();
			tpq.pop();
		}
		if(p.empty())//用户等待队列全部分配完毕，curtime移向下一个最早到的用户
		{
			curtime=v[i].atime;
			while(!tpq.empty())//清空普通桌队列
				tpq.pop();
		}
		else//等待队列不为空，此时还有用户在等待中，所有桌子分配完毕，应该去找到下一个最早离开的桌子，将时间节点移向它
		{
			int mintime=24*3600+1;
			for(int j=1;j<=m;++j)
				mintime=min(mintime,tabletime[j]);
			curtime=mintime;
			priority_queue<Person> temp;
			while(!p.empty())//p队列中可能存在vip用户，因此需分离p中的普通用户和vip用户，用temp暂存普通用户等待队列
			{
				Person x=p.top();
				if(x.isvip) vip.push(x);
				else temp.push(x);
				p.pop();
			}
			p=temp;
		}
	}
	sort(ret.begin(),ret.end(),cmpb);
	for(auto x:ret)
	{
		int wt=(x.stime-x.atime+30)/60;
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",x.atime/3600,x.atime/60%60,x.atime%60,x.stime/3600,x.stime/60%60,x.stime%60,wt);
	}
	for(int j=1;j<=m;++j)
		j==m?cout<<tablecnt[j]:cout<<tablecnt[j]<<" ";
	return 0;
}
