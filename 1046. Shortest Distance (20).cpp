#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0;
    cin>>n;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        sum+=x;
        v[i]=sum;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int s,e;
        cin>>s>>e;
        if(s>e) swap(s,e);
        int ret=(v[e-1]-v[s-1]<v[s-1]+sum-v[e-1])?v[e-1]-v[s-1]:v[s-1]+sum-v[e-1];
        cout<<ret<<endl;
    }
    return 0;
}
