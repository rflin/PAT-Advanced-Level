#include <bits/stdc++.h>
using namespace std;
struct Score
{
    string name;
    int gp,gm,gf,ga;
    Score(string nm="",int p=-1,int m=-1,int f=-1,int a=0):name(nm),gp(p),gm(m),gf(f),ga(a){}
};
map<string,Score> mp;
vector<Score> v;
bool cmp(const Score &a,const Score &b)
{
    return a.ga==b.ga?a.name<b.name:a.ga>b.ga;
}
int main()
{
    int p,m,n;
    // freopen("1.txt","r",stdin);
    string str;
    int grade;
    cin>>p>>m>>n;
    for(int i=0;i<p;++i)
    {
        cin>>str>>grade;
        mp[str]=Score(str,grade,-1,-1,0);
    }
    for(int i=0;i<m;++i)
    {
        cin>>str>>grade;
        if(mp.count(str))
            mp[str].gm=grade;
        else
            mp[str]=Score(str,-1,grade,-1,0);
    }
    for(int i=0;i<n;++i)
    {
        cin>>str>>grade;
        if(mp.count(str))
            mp[str].gf=grade;
        else
            mp[str]=Score(str,-1,-1,grade,0);
    }
    for(auto &w:mp)
    {
        auto &x=w.second;
        if(x.gp<200)continue;
        x.ga=(x.gm>x.gf)?int(x.gm*0.4+x.gf*0.6+0.5):x.gf;
        if(x.ga>=60)
            v.push_back(x);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto &x:v)
        cout<<x.name<<" "<<x.gp<<" "<<x.gm<<" "<<x.gf<<" "<<x.ga<<endl;
    return 0;
}
