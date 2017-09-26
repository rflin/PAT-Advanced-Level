#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
struct person
{
    int num;
    int morality,talent;
    int total;
    person(int n,int m,int t,int tl):num(n),morality(m),talent(t),total(tl){}
};
vector<person> v1,v2,v3,v4;
int n,l,h;
bool cmp(const person &a,const person &b)
{
    if(a.total!=b.total)
        return a.total>b.total;
    return a.morality!=b.morality?a.morality>b.morality:a.num<b.num;
}
void disp(vector<person> &v)
{
    for(auto &x:v)
        printf("%d %d %d\n",x.num,x.morality,x.talent);
}
int main()
{
    scanf("%d %d %d",&n,&l,&h);
    for(int i=0;i<n;++i)
    {
        int num,mor,tal;
        scanf("%d %d %d",&num,&mor,&tal);
        if(mor<l||tal<l) continue;
        if(mor>=h&&tal>=h) v1.push_back(person(num,mor,tal,mor+tal));//才德全尽
        else if(mor>=h) v2.push_back(person(num,mor,tal,mor+tal));//德胜才
        else if(mor>=tal) v3.push_back(person(num,mor,tal,mor+tal));//才德兼亡，兼德胜才
        else v4.push_back(person(num,mor,tal,mor+tal));
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    sort(v3.begin(),v3.end(),cmp);
    sort(v4.begin(),v4.end(),cmp);
    cout<<v1.size()+v2.size()+v3.size()+v4.size()<<endl;
    disp(v1);
    disp(v2);
    disp(v3);
    disp(v4);
    return 0;
}
