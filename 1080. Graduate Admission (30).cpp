#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
    int id;
    double ge;
    double gi;
    double gf;
    vector<int> choice;
    int admin;
    int rank;
};
bool comp(const node &a,const node &b)
{
    if(a.gf!=b.gf)
        return a.gf>b.gf;
    else
        return a.ge>b.ge;
}
int main()
{
    int n,m,k;
    vector<node> applicants;
    vector<int> quota;
    vector<vector<int>> ans(200);
    cin>>n>>m>>k;
    for(int i=0;i<m;++i)
    {
        int temp;
        cin>>temp;
        quota.push_back(temp);
    }
    for(int i=0;i<n;++i)
    {
        node temp;
        temp.id=i;
        cin>>temp.ge>>temp.gi;
        for(int i=0;i<k;++i)
        {
            int s;
            cin>>s;
            temp.choice.push_back(s);
        }
        temp.gf=(temp.ge+temp.gi)/2;
        applicants.push_back(temp);
    }
    sort(applicants.begin(),applicants.end(),comp);
    applicants[0].rank=1;
    for(int i=1;i<(int)applicants.size();++i)
    {
        if(applicants[i].gf==applicants[i-1].gf&&applicants[i].ge==applicants[i-1].ge)
            applicants[i].rank=applicants[i-1].rank;
        else
            applicants[i].rank=i+1;
    }
    for(int i=0;i<(int)applicants.size();++i)
    {
        auto c=applicants[i].choice.begin();
        bool isend=false;
        while(c!=applicants[i].choice.end())
        {
            if(i!=0&&quota[*c]<=0&&applicants[i-1].admin==*c&&applicants[i-1].rank==applicants[i].rank)
            {
                ans[*c].push_back(applicants[i].id);
                quota[*c]--;applicants[i].admin=*c;
                isend=true;break;
            }
            if(quota[*c]>0)break;
            ++c;
        }
        if(isend)continue;
        if(c!=applicants[i].choice.end())
        {
            ans[*c].push_back(applicants[i].id);
            quota[*c]--;applicants[i].admin=*c;
        }
    }
    for(int i=0;i<m;++i)
    {
        sort(ans[i].begin(),ans[i].end());
        for(auto it=ans[i].begin();it!=ans[i].end();++it)
            it==ans[i].end()-1?cout<<*it:cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}
