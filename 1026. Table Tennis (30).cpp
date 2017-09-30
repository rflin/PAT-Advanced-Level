/*重新写了下这题，最后一个测试点还是过不了，只有29分*/
#include <bits/stdc++.h>
using namespace std;
struct record
{
    int atime;//到达时间
    int utime;//使用时间
    int isvip;//是否是vip
    int wtime;//等待时间，注：到达时间+等待时间=开始服务的时间
    bool isplayed;//是不是玩过了
};
vector<record> vq;
int viptag[128],tablecount[128];//vip桌标识，桌子被安排的玩家计数
vector<int> table;
int n,m,i=0,vipm;
const int closetime=21*3600;//关门点
int searchend(vector<record> &vq,int cur,int curtime)
{
	int end=cur;
	while(end<(int)vq.size()&&vq[end].atime+vq[end].wtime<=curtime)++end;
	return end;
}
queue<int> viptablevacancy(vector<int> &table,int curtime)
{
	queue<int> q;
	for(size_t i=1;i<table.size();++i) if(table[i]==curtime&&viptag[i]) q.push(i);
	return q;
}
queue<int> vipincurqueue(vector<record> &vq,int cur,int end)
{
	queue<int> q;
	while(cur!=end)
	{
		if(vq[cur].isvip&&vq[cur].isplayed==0) q.push(cur);
		++cur;
	}
	return q;
}
queue<int> ordincurqueue(vector<record> &vq,int cur,int end)
{
	queue<int> q;
	while(cur!=end)
	{
		if(vq[cur].isplayed==0) q.push(cur);
		++cur;
	}
	return q;
}
queue<int> ordintablevacancy(vector<int> &table,int curtime)
{
	queue<int> q;
	for(size_t i=1;i<table.size();++i) if(table[i]==curtime) q.push(i);
	return q;
}
void dealqueue(queue<int> &tq,queue<int> &q,int curtime)
{
	while(!tq.empty()&&!q.empty())
	{
		int tablenum=tq.front();
		tq.pop();
		int pnum=q.front();
		q.pop();
		table[tablenum]+=vq[pnum].utime;
		vq[pnum].wtime=curtime-vq[pnum].atime;
		vq[pnum].isplayed=true;
		tablecount[tablenum]++;//该table计数
	}
}
void updatetable(int cur)
{
	for(size_t i=1;i<table.size();++i)
	{
		if(table[i]<vq[cur].atime) table[i]=vq[cur].atime;
	}
}
int main()
{
	//freopen("1.txt","r",stdin);
    scanf("%d",&n);
    vq.resize(n);
    while(i<n)//读取数据
    {
        int hh,mm,ss,p;
        scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&p,&vq[i].isvip);
        vq[i].atime=hh*3600+mm*60+ss;
        if(p>120) p=120;
        vq[i++].utime=p*60;
    }
    sort(vq.begin(),vq.end(),[](const record &a,const record &b){return a.atime<b.atime;});//按到达时间排序
    scanf("%d %d",&m,&vipm);
    for(i=0;i<vipm;++i)//标记vip桌
    {
        int v;
        scanf("%d",&v);
        viptag[v]=1;
    }
    table.assign(m+1,8*3600);//table初始化为8:00
    int cur=0;
    while(cur<n)
    {
    	int curtime=*min_element(++table.begin(),table.end());
    	if(curtime>=closetime)
    	{
    		while(cur<n) vq[cur++].wtime=24*3600;
    		break;
    	}
    	int end=searchend(vq,cur,curtime);
    	if(cur==end)//说明此时还没有玩家来打球，
    	{
    		updatetable(cur);//更新table时间
    		continue;
    	}
    	queue<int> viptableq=viptablevacancy(table,curtime);//当前时间点空闲的vip桌队列
    	queue<int> vipq=vipincurqueue(vq,cur,end);//当前时间点vip队列
    	dealqueue(viptableq,vipq,curtime);
    	queue<int> ordintableq=ordintablevacancy(table,curtime);//当前时间点空闲的普通桌队列
    	queue<int> ordinq=ordincurqueue(vq,cur,end);//当前时间点普通队列
    	dealqueue(ordintableq,ordinq,curtime);
    	while(vq[cur].isplayed)++cur;
    }
    sort(vq.begin(),vq.end(),[](const record &a,const record &b){return a.atime+a.wtime<b.atime+b.wtime;});
    for(i=0;i<n;++i)
    {
        if(vq[i].atime+vq[i].wtime<closetime)
        {
            int at=vq[i].atime,st=vq[i].atime+vq[i].wtime;
            int wt=vq[i].wtime;
            wt=(wt%60>=30)?wt/60+1:wt/60;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",at/3600,at/60%60,at%60,st/3600,st/60%60,st%60,wt);
        }
    }
    for(i=1;i<=m;++i) i==m?printf("%d",tablecount[i]):printf("%d ",tablecount[i]);
    return 0;
}
