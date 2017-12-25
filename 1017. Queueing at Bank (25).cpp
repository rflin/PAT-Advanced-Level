#include <stdio.h>
#include <stdlib.h>
#define N 10001
struct record
{
    int stime;//开始时间
    int etime;//结束时间
}s[N];//记录
int service[101];//服务窗口
int comp(const void*a,const void*b)
{
    return ((struct record *)a)->stime-((struct record *)b)->stime;
}
int compe(const void*a,const void*b)
{
    return *((int *)a)-*((int *)b);
}
int main()
{
    int i,n,k,seventeen=17*3600,eight=8*3600;
    double count=0.0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        int hh,mm,ss,w,total;
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&w);
        if(w>60)w=60;//可写可不写，无该项测试点
        w*=60;
        total=hh*3600+mm*60+ss;//以秒记录总时间
        if(total<=seventeen)//17:00:00到达
        {
            s[i].stime=total;
            s[i].etime=s[i].stime+w;
        }
        else//在17:00:00之后到达的舍弃
        {
            --n;--i;
        }
    }
    qsort(s,n,sizeof(struct record),comp);//按到达时间进行排序（sort）
    for(i=0;i<k;i++)
        service[i]=eight;//初始化service窗口，从8点开始服务
    int cur=0;
    while(cur<n)
    {
        qsort(service,k,sizeof(int),compe);//每次对service进行从小到大排序,service[0]即为最早离开，注：其实不太划算，只需选择最小的即可(o(n)),而不用快排(o(nlgn)
        int w=s[cur].etime-s[cur].stime;//获取当前的processing time
        if(s[cur].stime<service[0])//窗口处于服务段，cur需等待
        {
            count+=service[0]-s[cur].stime;//记录等待时间
            service[0]+=w;//service服务当前人员,更新该窗口的时间
        }
        else
            service[0]=s[cur].etime;//窗口处于闲置段，直接更新窗口时间
        cur++;
    }
    printf("%.1lf\n",count/(n*60));
    return 0;
}
