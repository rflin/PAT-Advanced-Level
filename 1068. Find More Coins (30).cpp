/*考察动态规划*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=10004,MAXM=104;
int n,m;
int v[MAXN],dp[MAXN][MAXM];
bool flag[MAXN][MAXM];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1,greater<int>());
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(j<v[i]||dp[i-1][j-v[i]]+v[i]<dp[i-1][j])
                dp[i][j]=dp[i-1][j];
            else    
            {
                dp[i][j]=dp[i-1][j-v[i]]+v[i];
                flag[i][j]=true;
            }
        }
    }
    if(dp[n][m]!=m)
        cout<<"No Solution";
    else
    {
        vector<int> ans;
        while(m)
        {
            while(!flag[n][m])--n;
            ans.push_back(v[n]);
            m-=v[n--];
        }
        for(auto it=ans.begin();it!=ans.end();++it)
            (it==ans.end()-1)?cout<<*it:cout<<*it<<" ";
    }
    return 0;
}
