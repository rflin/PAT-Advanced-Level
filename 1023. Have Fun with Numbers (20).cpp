#include <bits/stdc++.h>
using namespace std;
string doubleNum(const string &n)
{
    int add=0;
    string dn;
    for(int i=n.size()-1;i>=0;--i)
    {
        int x=n[i]-'0';
        int num=x*2+add;
        add=num/10;
        dn+=num%10+'0';
    }
    if(add>0)dn+=add+'0';
    reverse(dn.begin(),dn.end());
    return dn;
}
bool judge(string &a,string &b)
{
    vector<int> v(10,0);
    for(auto x:a)
        v[x-'0']++;
    for(auto x:b)
        v[x-'0']--;
    for(auto x:v)
        if(x)return false;
    return true;
}
int main()
{
    string a,b;
    cin>>a;
    b=doubleNum(a);
    if(judge(a,b))cout<<"Yes\n"<<b<<endl;
    else cout<<"No\n"<<b<<endl;
    return 0;
}
