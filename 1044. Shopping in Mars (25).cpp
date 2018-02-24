#include <bits/stdc++.h>
using namespace std;
int A[100000+1],n,m,values=0,low=1,high=0;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&A[i]);
    int minval=0x7fffffff;
    vector<pair<int,int>> results(n+1);
    while(high<=n)
    {
        while(values<m&&high<=n) values+=A[++high];
        if(values>=m)
        {
            minval=min(minval,values);
            results[low]=make_pair(high,values);
            values-=A[low++];
        }
    }
    for(int i=1;i<=n;++i)
        if(results[i].second==minval) printf("%d-%d\n",i,results[i].first);
    return 0;
}
