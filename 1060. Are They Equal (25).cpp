#include <bits/stdc++.h>
using namespace std;
string MakeNumber(string num,int n)
{
    size_t found=num.find('.');
    size_t dotpos=(found==string::npos)?num.size():found;
    size_t notzeropos=0;
    while(notzeropos<num.size()&&(num[notzeropos]=='0'||num[notzeropos]=='.'))++notzeropos;
    if(notzeropos==num.size())
        return string("0.")+string(n,'0')+string("*10^0");
    int exp=(dotpos>notzeropos)?dotpos-notzeropos:dotpos-notzeropos+1;
    if(found!=string::npos)
        num.erase(found,1);//删除'.'
    size_t pos=0;
    while(pos<num.size()&&num[pos]=='0')++pos;
    num=num.substr(pos);//删除前面的零
    if(num.size()<(size_t)n)
        num=num+string((size_t)n-num.size(),'0');
    else num=num.substr(0,n);
    return string("0.")+num+"*10^"+to_string(exp);
}
int main()
{
    int n;
    string a,b;
    cin>>n>>a>>b;
    string ansa=MakeNumber(a,n),ansb=MakeNumber(b,n);
    if(ansa==ansb) cout<<"YES "<<ansa<<endl;
    else cout<<"NO "<<ansa<<" "<<ansb<<endl;
    return 0;
}
