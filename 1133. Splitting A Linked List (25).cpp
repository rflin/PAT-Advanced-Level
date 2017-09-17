#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct xnode
{
	int add,val,next;
};
xnode node[100000];
vector<xnode> p,q,r,ans;
int head,n,k;
int main()
{
	cin>>head>>n>>k;
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
		if(node[x].val<0) p.push_back(node[x]);
		else if(node[x].val>=0&&node[x].val<=k) q.push_back(node[x]);
		else r.push_back(node[x]);
		x=node[x].next;
	}
	ans=p;
	for(auto ln:q)
		ans.push_back(ln);
	for(auto ln:r)
		ans.push_back(ln);
	int al=ans.size();
	for(int i=0;i<al-1;++i)
		printf("%05d %d %05d\n",ans[i].add,ans[i].val,ans[i+1].add);
	printf("%05d %d -1\n",ans[al-1].add,ans[al-1].val);
	return 0;
}
