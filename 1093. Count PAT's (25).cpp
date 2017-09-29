#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> v;
    vector<int> vp,vt;
    int pcnt=0,tcnt=0,ans=0;
    char ch;
    while((ch=cin.get())!='\n')
    {
        v.push_back(ch);
        if(ch=='P') ++pcnt;
        else if(ch=='A') vp.push_back(pcnt);
    }
    int k=vp.size();
    vt.resize(k);
    for(int i=v.size()-1;i>=0;--i)
    {
        if(v[i]=='T') ++tcnt;
        else if(v[i]=='A') vt[--k]=tcnt;
    }
    for(size_t i=0;i<vp.size();++i)
    {
        ans+=vp[i]*vt[i];
        ans%=1000000007;
    }
    cout<<ans;
    return 0;
}
