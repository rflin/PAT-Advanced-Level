#include <bits/stdc++.h>
using namespace std;
struct node
{
    int id;
    char name[10];
    int grade;
};
vector<node> v;
bool cmpid(const node &a,const node &b)
{
    return a.id<b.id;
}
bool cmpname(const node &a,const node &b)
{
    int ret=strcmp(a.name,b.name);
    return ret==0?a.id<b.id:ret<0;
}
bool cmpgrade(const node &a,const node &b)
{
    return a.grade==b.grade?a.id<b.id:a.grade<b.grade;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    v.resize(n);
    for(int i=0;i<n;++i)
        scanf("%d %s %d",&v[i].id,v[i].name,&v[i].grade);
    switch(k)
    {
        case 1:sort(v.begin(), v.end(),cmpid);break;
        case 2:sort(v.begin(), v.end(),cmpname);break;
        case 3:sort(v.begin(), v.end(),cmpgrade);break;
    }
    for(auto x:v)
    {
        printf("%06d %s %d\n",x.id,x.name,x.grade);
    }
    return 0;
}
