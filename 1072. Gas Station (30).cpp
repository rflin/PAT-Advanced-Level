/*
Dijkstra算法求所有居住点到候选gas staion的最短距离，如果其中某个点最短距离大于ds则超出范围；
注意题目中gas点和居住点的区别，本代码将gas点放于1000后
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=999999999,Max=1020;
int a[Max][Max];
struct node
{
    int gasv;
    double avg;
    double min;
};
bool comp(const node &a,const node &b)
{
    return a.avg==b.avg?a.gasv<b.gasv:a.avg<b.avg;
}
void InitMatrix(void)//初始化邻接矩阵
{
    for(int i=1;i<Max;++i)
    {
        for(int j=1;j<Max;++j)
            a[i][j]=(i==j)?0:INF;
    }
}
int TransStringToInteger(string &s)//将G放于1000之后
{
    return s[0]=='G'?1000+stoi(s.substr(1)):stoi(s);
}
bool isResidentialHouse(int u)//是否是居民住宅
{
    return (u<=1000)?true:false;
}
int main()
{
    int n,m,arcnum,ds;
    vector<node> ans;//保存结果
    InitMatrix();//初始化邻接矩阵
    cin>>n>>m>>arcnum>>ds;
    for(int i=0;i<arcnum;++i)
    {
        string s1,s2;
        int dis;
        cin>>s1>>s2>>dis;
        int u=TransStringToInteger(s1),v=TransStringToInteger(s2);
        a[u][v]=dis;
        a[v][u]=dis;
    }
    int premin=-1;
    for(int gv=1;gv<=m;++gv)//gasStation候选节点m个
    {
        int v=gv+1000;//当前gasSation节点
        int dist[Max]={0},visit[Max]={0};
        for(int i=1;i<Max;++i)
            dist[i]=a[i][v];
        visit[v]=1;
        int u;
        for(int i=1;i<Max;++i)//dijkstra求最短路径
        {
            int min=INF;
            for(int j=1;j<Max;++j)
                if(!visit[j]&&dist[j]<min) min=dist[u=j];
            visit[u]=1;
            for(int k=1;k<Max;++k)
            {
                if(a[k][u]<INF&&dist[k]>dist[u]+a[u][k])
                    dist[k]=dist[u]+a[u][k];
            }
        }
        bool isrange=true;
        int mindis=INF;//最小路径
        double sumdis=0.0;//总路径
        for(int w=1;w<=n;++w)
        {
            sumdis+=dist[w];
            if(mindis>dist[w]&&dist[w]!=0)mindis=dist[w];
            if(dist[w]>ds){isrange=false;break;}
        }
        if(isrange)//在范围内，收集记录
        {
            node temp;
            temp.gasv=v;//gasStation
            temp.avg=sumdis/n;//平均值
            temp.min=mindis;//最小路径
            if(premin<mindis)//尽可能远，更新premin
            {
                ans.clear();
                ans.push_back(temp);
                premin=mindis;
            }
            else if(premin==mindis)
                ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end(),comp);
    if(ans.size()==0)
        cout<<"No Solution";
    else
    {
        cout<<"G"<<ans[0].gasv%1000<<endl;
        printf("%.1lf %.1lf",ans[0].min,ans[0].avg+0.0000001);
    }
    return 0;
}
