#include <bits/stdc++.h>
using namespace std;
vector<string> a={"ling ","yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu "};
vector<string> b={"","Shi ","Bai ","Qian "};
vector<string> c={"","Wan ","Yi "};
string readNumber(string n)
{
    string ans;
    if(n[0]=='0') ans+="ling ";
    n=to_string(stoi(n));
    while(n.size()>0)
    {
        if(n=="0") break;
        ans+=a[n[0]-'0']+b[n.size()-1];
        if(n.size()==1) break;
        string temp=to_string(stoi(n.substr(1)));
        if(n.size()>temp.size()+1&&temp!="0")//中间有零
            ans+="ling ";
        n=temp;
    }
    return ans;
}
int main()
{
    string num,ret;
    cin>>num;
    if(num=="0")
    {
        cout<<"ling";
        return 0;
    }
    if(num[0]=='-')
    {
        cout<<"Fu ";
        num=num.substr(1);
    }
    while(num.size()>0)
    {
        int pos=(num.size()%4==0)?4:num.size()%4;
        ret+=readNumber(num.substr(0,pos));
        num=num.substr(pos);
        ret+=c[num.size()/4];//读亿万
    }
    ret.pop_back();
    cout<<ret;
    return 0;
}
