#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
struct xnode
{
    int add,val,next;
    xnode(int ad=-1,int vl=-1,int nt=-1):add(ad),val(vl),next(nt){}
}node[100004];
vector<xnode> v;
int main()
{
    int n,head;
    cin>>n>>head;
    for(int i=0;i<n;++i)
    {
        int add,val,next;
        cin>>add>>val>>next;
        node[add].add=add;
        node[add].val=val;
        node[add].next=next;
    }
    int x=head;
    while(x!=-1)
    {
        v.push_back(node[x]);
        x=node[x].next;
    }
    sort(v.begin(),v.end(),[](const xnode &a,const xnode &b){return a.val<b.val;});
    int vl=v.size();
    if(vl==0) 
    {
        cout<<0<<" -1"<<endl;
        return 0;
    }
    printf("%d %05d\n",vl,v[0].add);
    for(int i=0;i<vl-1;++i)
        printf("%05d %d %05d\n",v[i].add,v[i].val,v[i+1].add);
    printf("%05d %d -1\n",v[vl-1].add,v[vl-1].val);
    return 0;
}
