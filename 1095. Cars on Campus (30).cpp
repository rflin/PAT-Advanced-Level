#include <bits/stdc++.h>
using namespace std;
using namespace std;
struct node
{
    char number[12];
    int time,status;
    bool islegal;
}v[10008];
bool cmp_number(const node &a,const node &b)//按照车牌排序，同一车牌放在一起
{
    int ret=strcmp(a.number,b.number);
    return ret==0?a.time<b.time:ret<0;
}
bool cmp_time(const node &a,const node &b)//按时间排序，同时将不合法的记录排在后面
{
    return a.islegal==b.islegal?a.time<b.time:a.islegal>b.islegal;
}
void checkislegal(struct node v[],int n)
{
    for(int i=0;i<n;++i)
    {
        if(i==n-1)
        {
            v[i].islegal=false;
            break;
        }
        if(strcmp(v[i].number,v[i+1].number)==0)
        {
            if(v[i].status&&!v[i+1].status)
            {
                v[i].islegal=true;
                v[i+1].islegal=true;
                i++;
            }
            else v[i].islegal=false;
        }
        else v[i].islegal=false;
    }
}
int maxtime(struct node v[],int n,string &ans)
{
    int max=-1;
    for(int i=0;i<n;i++)
    {
        if(v[i].islegal&&v[i].status)
        {
            int ct=0,j=i;
            while(j<n&&strcmp(v[i].number,v[j].number)==0)
            {
                if(v[j].islegal&&v[j].status){
                    ct+=v[j+1].time-v[j].time;
                    ++j;
                }
                ++j;
            }
            if(max<ct)
            {
                ans=v[i].number;
                max=ct;
            }
            else if(max==ct)
            {
                ans+=" ";
                ans+=v[i].number;
            }
            i=j-1;
        }
    }
    return max;
}
void query(struct node v[],int n,int k)
{
    int hh,mm,ss,cur,i=0,cnt=0;
    while(k--)
    {
        scanf("%d:%d:%d",&hh,&mm,&ss);
        cur=hh*3600+mm*60+ss;
        while(i<n&&v[i].time<=cur&&v[i].islegal)
        {
            if(v[i].status) ++cnt;
            else --cnt;
            ++i;
        }
        printf("%d\n",cnt);
    }
}
int main()
{
    int n,k;
    int hh,mm,ss;
    char s[8];
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i)
    {
        scanf("%s %d:%d:%d %s",v[i].number,&hh,&mm,&ss,s);
        v[i].time=hh*3600+mm*60+ss;
        v[i].status=(s[0]=='i')?1:0;
    }
    sort(v,v+n,cmp_number);
    checkislegal(v,n);
    string ans="";
    int max=maxtime(v,n,ans);
    sort(v,v+n,cmp_time);
    query(v,n,k);
    printf("%s %02d:%02d:%02d",ans.c_str(),max/3600,max%3600/60,max%60);
    return 0;
}
