#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string n,m;
    cin>>n;
    if(n.size()!=4) n=string(4-n.size(),'0')+n;
    m=n;
    sort(m.begin(),m.end(),greater<char>());
    sort(n.begin(),n.end());
    if(m==n)
    {
        cout<<m<<" - "<<n<<" = "<<"0000"<<endl;
        return 0;
    }
    while(true)
    {
        string ans=to_string(stoi(m)-stoi(n));
        if(ans.size()!=4) ans=string(4-ans.size(),'0')+ans;
        cout<<m<<" - "<<n<<" = "<<ans<<endl;
        if(ans=="6174") return 0;
        m=n=ans;
        sort(m.begin(),m.end(),greater<char>());
        sort(n.begin(),n.end());
    }
    return 0;
}
