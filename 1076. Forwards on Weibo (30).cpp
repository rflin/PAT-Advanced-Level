#include <bits/stdc++.h>
using namespace std;
vector<int> v[1024];
int n,L,q,idx;
int bfs(int r)
{
    queue<int> q;
    q.push(r);
    int len=1,level=0,result=0,visit[1024]={};
    visit[r]=1;
    while(len>0)
    {
        int nextLen=0;
        for(int i=0;i<len;++i)
        {
            int x=q.front();
            q.pop();
            for(int w:v[x])
                if(visit[w]==0) q.push(w),visit[w]=1,++nextLen,++result;
        }
        len=nextLen;
        ++level;
        if(level>=L) break;
    }
    return result;
}
int main()
{
    scanf("%d %d",&n,&L);
    for(int i=1;i<=n;++i)
    {
        int k;
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&idx);
            v[idx].push_back(i);
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&idx);
        printf("%d\n",bfs(idx));
    }
    return 0;
}
