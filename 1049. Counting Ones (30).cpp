/*思路：计算每个‘位’上为1的组合个数，再进行求和*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
    string n;
    cin>>n;
    int ans=0;
    for(int i=0;i!=(int)n.size();++i)
    {
        int mid=n[i]-'0';
        int left=atoi(n.substr(0,i).c_str());
        int right=atoi(n.substr(i+1).c_str());
        int ex=n.size()-i-1;
        if(mid==1)ans+=left*pow(10,ex)+right+1;
        else if(mid==0)ans+=left*pow(10,ex);
        else ans+=(left+1)*pow(10,ex);
    }
    cout<<ans;
    return 0;
}
