#include <bits/stdc++.h>
using namespace std;
bool isPalindromic(string &a)
{
    int len=a.size();
    for(int i=0;i<len/2;++i)
        if(a[i]!=a[len-1-i])return  0;
    return 1;
}
string addNum(string a,string b)
{
    string ret;
    int sur=0;
    for(size_t i=0;i<a.size();++i)
    {
        int sum=(sur+a[i]-'0'+b[i]-'0');
        sur=sum/10;
        ret+='0'+sum%10;
    }
    if(sur>0) ret+='0'+sur;
    reverse(ret.begin(),ret.end());
    return ret;
}
int main()
{
    string a;
    int k;
    cin>>a>>k;
    for(int i=0;i<k;++i)
    {
        if(isPalindromic(a))
        {
            cout<<a<<endl<<i;
            return 0;
        }
        else
        {
            string b=a;
            reverse(b.begin(), b.end());
            a=addNum(a,b);
        }
    }
    cout<<a<<endl<<k;
    return 0;
}
