/*
题目意思是：
n个人，每人手中拿着一个数字，然后按照k人一组进行比赛，谁的数大谁就赢，最后输出他们的排名

输入说明：
第一行是n,k，分别代表参赛人数和一个组的最大人数
第二行是n个数据，比如这里，就是从0到10号参赛选手的手中的数字
第三行是n个参赛选手的顺序，分组就是依据此来划分

详细说明：

11 3 //11个参赛选手，3人一组

以下数据中，第一行代表参赛选手的序号，第二行代表参赛选手手中的数字

选手序号：00 01 02 | 03 04 05 | 06 07 08 | 09 10
手中数字：25 18 00 | 46 37 03 | 19 22 57 | 56 10

第一局：
比赛次序：06 00 08 | 07 10 05 | 09 01 04 | 02 03   rank->06 00 10 05 01 04 02 :5
对应数字：19 25 57 | 22 10 03 | 56 18 37 | 00 46

第二局：
08 07 09 | 03   rank->07 09 :3
57 22 56 | 46

第三局：
08 03   rank->03:2
57 46

第四局：
08   rank->08:1
57

结果：
00 01 02 03 04 05 06 07 08 09 10
 5  5  5  2  5  5  5  3  1  3  5 

思路：
对于每一局比赛，我知道可以分成多少个组，那么，我同样就会知道会有多少个人晋级（每组晋级一人）
那么，剩下被淘汰的人就是同一排名了，并且排名也知道（等于晋级人数加一，剩下一人时为1）
比如，第一局，分成四个小组，四人晋级，剩下被淘汰的人排名为5.
好了，开始我们的代码吧:)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nums,ranks;
vector<int> MiceAndRice(vector<int> &v,int k)
{
    int n=v.size();//本局参赛人数
    int groupnum=(n%k==0)?n/k:n/k+1;//一个多少个组
    vector<int> nextv;//晋级选手
    for(int i=1;i<=groupnum;++i)//每个小组进行比赛
    {
        auto itb=v.begin()+(i-1)*k,ite=min(v.end(),itb+k);//当前组成员范围
        auto it=itb,maxit=itb;
        while(it!=ite)
        {
            if(nums[*maxit]<nums[*it])
                maxit=it;
            ++it;
        }
        nextv.push_back(*maxit);//有最大数字的选手晋级
        while(itb!=ite) ranks[*itb++]=groupnum+1;//排名
    }
    return nextv;
}
int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;
    nums.resize(n);
    ranks.resize(n);
    vector<int> v(n);
    for(int i=0;i<n;++i)
        cin>>nums[i];
    for(int i=0;i<n;++i)
        cin>>v[i];
    while(v.size()>1) v=MiceAndRice(v,k);
    ranks[v[0]]=1;
    for(int i=0;i<n;++i)
        i==n-1?cout<<ranks[i]:cout<<ranks[i]<<" ";
    return 0;
}
