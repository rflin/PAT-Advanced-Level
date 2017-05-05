/*
1127. ZigZagging on a Tree (30) 
https://www.patest.cn/contests/pat-a-practise/1127
解题思路：
1.因为题目告诉了前序和中序，所以，一般是利用此来进行递归建树；
2.递归过程中，用vector储存每一层的节点，而不是真正的去建树，可以省去很多不必要的麻烦。
3.储存后，遍历就方便了，奇数层逆向输出，偶数层正向输出
4.补充一句：vector大法好（逃~）
*/
#include <iostream>
#include <vector>
using namespace std;
const int maxv=42;
int in[maxv],post[maxv],h=-1;
vector<int> v[maxv];
void Solve(int inL,int inR,int poL,int poR,int level)
{
    if(inL>inR) return;
    h=(h<level)?level:h;
    v[level].push_back(post[poR]);
    int e=post[poR],i=inL;
    while(i<=inR&&e!=in[i]) ++i;
    Solve(inL,i-1,poL,poL+i-1-inL,level+1);
    Solve(i+1,inR,poL+i-inL,poR-1,level+1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>in[i];
    for(int i=0;i<n;++i) cin>>post[i];
    Solve(0,n-1,0,n-1,1);
    for(int i=1;i<=h;++i)
    {
        if(i&1)
            for(auto it=v[i].rbegin();it!=v[i].rend();++it)
                i==h&&it==v[i].rend()-1?cout<<*it:cout<<*it<<" ";
        else
            for(auto it=v[i].begin();it!=v[i].end();++it)
                i==h&&it==v[i].end()-1?cout<<*it:cout<<*it<<" ";
    }
    return 0;
}
