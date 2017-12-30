#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> coins(1024,0);
    int n,m,minface=1024;
    scanf("%d %d",&n,&m);
    while(n--)
    {
        int x;//硬币面值
        scanf("%d",&x);
        if(x<m&&coins[m-x]>0)
            minface=min(min(x,m-x),minface);
        coins[x]++;
    }
    minface==1024?cout<<"No Solution"<<endl:cout<<minface<<" "<<m-minface<<endl;
    return 0;
}
