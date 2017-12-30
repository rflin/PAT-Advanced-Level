/*考察动态规划*/
#include <iostream>
using namespace std;
int color[202],dp[202];
int main()
{
    int n,m,len;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
        cin>>color[i];
    cin>>len;
    int cur;
    while(len--)
    {
        cin>>cur;
        for(int j=1;j<=m;++j)
        {
            if(cur==color[j]) dp[j]++;
            else if(dp[j]<dp[j-1]) dp[j]=dp[j-1];
        }
    }
    cout<<dp[m];
    return 0;
}
