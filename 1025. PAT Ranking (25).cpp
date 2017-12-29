#include <bits/stdc++.h>
using namespace std;
struct node
{
    int score;
    string re_num;
    int fn_rank;
    int lc_num;
    int lc_rank;
};
vector<node> v;
bool cmp(const node &a,const node &b)
{
    return a.score==b.score?a.re_num<b.re_num:a.score>b.score;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        vector<node> cv(k);
        for(int j=0;j<k;++j)
        {
            cin>>cv[j].re_num>>cv[j].score;
            cv[j].lc_num=i;
        }
        sort(cv.begin(),cv.end(),cmp);
        cv[0].lc_rank=1;
        for(size_t j=1;j<cv.size();++j)
        {
            if(cv[j].score==cv[j-1].score)
                cv[j].lc_rank=cv[j-1].lc_rank;
            else cv[j].lc_rank=j+1;
        }
        v.insert(v.end(),cv.begin(),cv.end());
    }
    sort(v.begin(),v.end(),cmp);
    v[0].fn_rank=1;
    for(size_t j=1;j<v.size();++j)
    {
        if(v[j].score==v[j-1].score)
            v[j].fn_rank=v[j-1].fn_rank;
        else v[j].fn_rank=j+1;
    }
    cout<<v.size()<<endl;
    for(auto &x:v)
        cout<<x.re_num<<" "<<x.fn_rank<<" "<<x.lc_num<<" "<<x.lc_rank<<endl;
    return 0;
}
