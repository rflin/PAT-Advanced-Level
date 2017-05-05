#include <cstdio>
#include <vector>
using namespace std;
const int maxv=502,INF=0x7fffffff;
int n,m,s,e;
int arclen[maxv][maxv],arctim[maxv][maxv];
int distim[maxv],dislen[maxv],vistim[maxv],vislen[maxv];
vector<int> sp[maxv],temps,anss;
vector<int> fp[maxv],tempf,ansf;
int mintime=0x7fffffff,minsec=0x7fffffff;
int distancex=0x7fffffff,time=0;
void InitAdjMatrix()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            i==j?
            arclen[i][j]=arclen[j][i]=arctim[i][j]=arctim[j][i]=0:
            arclen[i][j]=arclen[j][i]=arctim[i][j]=arctim[j][i]=INF;
        }
    }
}
void InitDisArray()
{
    for(int i=0;i<n;++i)
    {
        dislen[i]=arclen[s][i];
        if(arclen[s][i]<INF&&i!=s) sp[i].push_back(s);//前驱节点
        distim[i]=arctim[s][i];
        if(arctim[s][i]<INF&&i!=s) sp[i].push_back(s);//前驱节点
    }
}
void ShortPath()
{
    int min,v;
    vislen[s]=1;
    for(int i=0;i<n;++i)
    {
        min=INF;
        for(int k=0;k<n;++k)
        {
            if(vislen[k]==0&&dislen[k]<min)
            {
                min=dislen[k];
                v=k;
            }
        }
        vislen[v]=1;
        for(int w=0;w<n;++w)
        {
            if(arclen[v][w]<INF&&vislen[w]==0)
            {
                if(dislen[v]+arclen[v][w]<dislen[w])
                {
                    dislen[w]=dislen[v]+arclen[v][w];
                    sp[w].clear();
                    sp[w].push_back(v);
                }
                else if(dislen[v]+arclen[v][w]==dislen[w])
                {
                    sp[w].push_back(v);
                }
            }
        }
    }
}
void dfsSP(int u,int timecnt,int discnt)
{
    temps.push_back(u);
    if(u==s)
    {

        if(discnt<distancex||(distancex==discnt&&mintime>timecnt))
        {
            mintime=timecnt;
            anss.clear();
            anss=temps;
            distancex=discnt;
        }
    }
    for(auto it=sp[u].begin();it!=sp[u].end();++it)
    {
        dfsSP(*it,timecnt+arctim[*it][u],discnt+arclen[*it][u]);
    }
    temps.pop_back();
}
void FastPath()
{
    int min,v;
    for(int i=0;i<n;++i)
    {
        min=INF;
        for(int k=0;k<n;++k)
        {
            if(vistim[k]==0&&distim[k]<min)
            {
                min=distim[k];
                v=k;
            }
        }
        vistim[v]=1;
        for(int w=0;w<n;++w)
        {
            if(arctim[v][w]<INF&&vistim[w]==0)
            {
                if(distim[v]+arctim[v][w]<distim[w])
                {
                    distim[w]=distim[v]+arctim[v][w];
                    fp[w].clear();
                    fp[w].push_back(v);
                }
                else if(distim[v]+arctim[v][w]==distim[w])
                {
                    fp[w].push_back(v);
                }
            }
        }
    }
}
void dfsFP(int u,int secnt,int timcnt)
{
    tempf.push_back(u);
    if(u==s)
    {
        if(secnt<minsec)
        {
            minsec=secnt;
            ansf.clear();
            ansf=tempf;
            time=timcnt;
        }
    }
    for(auto it=fp[u].begin();it!=fp[u].end();++it)
    {
        dfsFP(*it,secnt+1,timcnt+arctim[*it][u]);
    }
    tempf.pop_back();
}
int main()
{
    scanf("%d %d",&n,&m);
    InitAdjMatrix();
    for(int i=0;i<m;++i)
    {
        int v1,v2,one,len,tim;
        scanf("%d %d %d %d %d",&v1,&v2,&one,&len,&tim);
        arclen[v1][v2]=len;
        arctim[v1][v2]=tim;
        if(one==0)
        {
            arclen[v2][v1]=arclen[v1][v2];
            arctim[v2][v1]=arctim[v1][v2];
        }
    }
    scanf("%d %d",&s,&e);
    InitDisArray();
    ShortPath();
    dfsSP(e,0,0);
    FastPath();
    dfsFP(e,1,0);
    if(anss==ansf)
    {
        printf("Distance = %d; Time = %d: ",distancex,time);
        for(auto it=anss.rbegin();it!=anss.rend();++it)
            it!=anss.rend()-1?printf("%d -> ",*it):printf("%d\n",*it);
        return 0;
    }
    printf("Distance = %d: ",distancex);
    for(auto it=anss.rbegin();it!=anss.rend();++it)
        it!=anss.rend()-1?printf("%d -> ",*it):printf("%d\n",*it);
    printf("Time = %d: ",time);
    for(auto it=ansf.rbegin();it!=ansf.rend();++it)
        it!=ansf.rend()-1?printf("%d -> ",*it):printf("%d\n",*it);
    return 0;
}
