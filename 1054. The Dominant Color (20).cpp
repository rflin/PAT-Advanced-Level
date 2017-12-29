#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            int x;
            scanf("%d",&x);
            mp[x]++;
        }
    }
    for(auto x:mp)
    {
        if(x.second>=n*m/2)
        {
            printf("%d\n",x.first);
            return 0;
        }
    }
    return 0;
}
