/*需要注意的点，编译未通过和分值为0是不一样的概念，但是最后都是输出为0，前者可能不在列表里，但是后者一定在列表里，即使是后者总分分值为0*/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;
struct node
{
    int idnum;
    vector<int> grade=vector<int>(6,-2);
    int countperfect;
    int sum;
    int rank;
    bool isinlist;
};
int score[6];
vector<node> v;
bool cmp(const node &a,const node &b)
{
    if(a.sum!=b.sum)
        return a.sum>b.sum;
    return a.countperfect==b.countperfect?a.idnum<b.idnum:a.countperfect>b.countperfect;
}
int main(int argc, char const *argv[])
{
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    v.resize(n+1);
    for(int i=1;i<=k;++i)
        scanf("%d",&score[i]);
    for(int i=0;i<m;++i)
    {
        int idnum,p,grade;
        scanf("%d %d %d",&idnum,&p,&grade);
        v[idnum].grade[p]=max(grade,v[idnum].grade[p]);
        v[idnum].idnum=idnum;
    }
    for(auto &x:v)
    {
        for(int i=1;i<=k;++i)
        {
            if(x.grade[i]==score[i])
                ++x.countperfect;
            if(x.grade[i]>=0)
            {
                x.sum+=x.grade[i];
                x.isinlist=true;
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    v[0].rank=1;
    for(size_t i=1;i<v.size();++i)
    {
        if(v[i].sum==v[i-1].sum) v[i].rank=v[i-1].rank;
        else v[i].rank=i+1;
    }
    for(auto &x:v)
    {
        if(x.isinlist==0)continue;
        printf("%d %05d %d",x.rank,x.idnum,x.sum);
        for(int i=1;i<=k;++i)
        {
            if(x.grade[i]==-2) printf(" -");
            else if(x.grade[i]==-1) printf(" 0");
            else printf(" %d",x.grade[i]);
        }
        printf("\n");
    }
    return 0;
}
