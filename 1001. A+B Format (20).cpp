#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a+b<0)cout<<"-";
    string ret=to_string(abs(a+b));
    while(ret.size()>0)
    {
        int pos=(ret.size()%3==0)?3:ret.size()%3;
        cout<<ret.substr(0,pos);
        if(ret.size()>3)cout<<",";
        ret=ret.substr(pos);
    }
    return 0;
}
