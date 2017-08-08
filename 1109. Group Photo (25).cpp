/*
https://www.patest.cn/contests/pat-a-practise/1109
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
struct person
{
    string name;
    int height;
    person(string s,int h):name(s),height(h){}
};
bool comp(const person &a,const person &b)
{
    if(a.height!=b.height)
        return a.height>b.height;
    else
        return a.name<b.name;
}
void disp(vector<person> &v,int l,int len)
{
    int k,r;
    if(len%2==0) {k=len;r=len-1;}
    else {k=len-1;r=len;}
    while(k>=2)
    {
        cout<<v[l+k-1].name<<" ";
        k-=2;
    }
    k=1;
    while(k<=r)
    {
        cout<<v[l+k-1].name;
        if(k==r)cout<<endl;
        else cout<<" ";
        k+=2;
    }
}
int main()
{
    int n,k;
    std::vector<person> v;
    cin>>n>>k;
    int r=n/k,ex=n%k;//r每行多少人，ex剩余人数
    while(n--)
    {
        string s;
        int h;
        cin>>s>>h;
        person p(s,h);
        v.push_back(p);
    }
    sort(v.begin(),v.end(),comp);
    int left=0;
    disp(v,left,r+ex);
    left+=r+ex;
    for(int i=k-1;i>=1;--i)
    {
        disp(v,left,r);
        left+=r;
    }
    return 0;
}
