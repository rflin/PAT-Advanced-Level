#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	int val;
	int next;
}node[100000];
int reverseKGroup(int head,int k)
{
	int cur=head,cnt=0;
	while(cur!=-1&&cnt!=k)
	{
		cur=node[cur].next;
		++cnt;
	}
	if(cnt==k)
	{
		cur=reverseKGroup(cur,k);
		while(cnt-->0)
		{
			int temp=node[head].next;
			node[head].next=cur;
			cur=head;
			head=temp;
		}
		head=cur;
	}
	return head;
}
int main()
{
	int head,n,k;
	cin>>head>>n>>k;
	while(n--)
	{
		int add,val,next;
		cin>>add>>val>>next;
		node[add].val=val;
		node[add].next=next;
	}
	head=reverseKGroup(head,k);
	while(node[head].next!=-1)
	{
		printf("%05d %d %05d\n",head,node[head].val,node[head].next);
		head=node[head].next;
	}
	printf("%05d %d %d\n",head,node[head].val,node[head].next);
	return 0;
}
