#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct xnode
{
	int add;
	int val;
	int next;
}node[100000];
bool isvisit[10000];
vector<xnode> v1,v2;
void deduplist(int head)
{
	int p=head;
	while(p!=-1)
	{
		if(isvisit[abs(node[p].val)]) v2.push_back(node[p]);
		else v1.push_back(node[p]);
		isvisit[abs(node[p].val)]=true;
		p=node[p].next;
	}
}
void disp(vector<xnode> &v,int n)
{
	if(n==0) return;
	for(int i=0;i<n-1;++i)
		printf("%05d %d %05d\n",v[i].add,v[i].val,v[i+1].add);
	printf("%05d %d -1\n",v.back().add,v.back().val);
}
int main()
{
	int n,head;
	scanf("%d %d",&head,&n);
	for(int i=0;i<n;++i)
	{
		int add,val,next;
		scanf("%d %d %d",&add,&val,&next);
		node[add].add=add;
		node[add].val=val;
		node[add].next=next;
	}
	deduplist(head);
	disp(v1,v1.size());
	disp(v2,v2.size());
	return 0;
}
