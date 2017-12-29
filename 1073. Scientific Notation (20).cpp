#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string sign(1,s[0]),inp(1,s[1]),dep;
    int exp,i=3;
    while(s[i]!='E') dep+=s[i++];
    ++i;
    exp=stoi(s.substr(i,s.size()-i));
    sign=(sign=="+")?"":sign;
    if(exp<0)
        inp="0."+string(-exp-1,'0')+inp;
    else
    {
        dep=((int)dep.size()>exp)?dep.insert(exp,"."):dep+string(exp-(int)dep.size(),'0');
    }
    cout<<sign+inp+dep;
    return 0;
}
