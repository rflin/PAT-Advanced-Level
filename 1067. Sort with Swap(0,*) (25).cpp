#include <bits/stdc++.h>
using namespace std;
int searchNextpos(vector<int> &v,int pos)
{
    int n=v.size();
    for(int i=pos;i<n;++i)
        if(v[i]!=i)return i;
    return 0;
}
int main()
{
    int n;
    vector<int> v;
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;++i)
    {
        int x;
        scanf("%d",&x);
        v[x]=i;
    }
    int pos=searchNextpos(v,1),count=0;
    while(pos)
    {
        if(v[0]==0)
        {
            swap(v[0],v[pos]);
            ++count;
        }
        if(v[0]>0)
        {
            swap(v[0],v[v[0]]);
            ++count;
        }
        pos=searchNextpos(v,pos);
    }
    cout<<count<<endl;
    return 0;
}
