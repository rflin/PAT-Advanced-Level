#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
const int base=325;
struct xbucket
{
	int cnt;
	int v[base];
};
xbucket bucket[base];
stack<int> stk;
void removeBucket(int x)
{
	int p=x/base,q=x%base;
	bucket[p].cnt--;
	bucket[p].v[q]--;
}
void addBucket(int x)
{
	int p=x/base,q=x%base;
	bucket[p].cnt++;
	bucket[p].v[q]++;
}
int searchMidBucket(int n)
{
	int mid=(n%2==0)?n/2:(n+1)/2,sum=0,i=0;
	while(i<base&&(sum+=bucket[i].cnt)<mid) ++i;
	sum-=bucket[i].cnt;
	for(int k=0;k<base;++k)
	{
		if(bucket[i].v[k]>0) sum+=bucket[i].v[k];
		if(sum>=mid) return i*base+k;
	}
	return -1;
}
void Push(int x)
{
	stk.push(x);
	addBucket(x);
}
void Pop()
{
	if(stk.empty()) printf("Invalid\n");
	else
	{
		removeBucket(stk.top());
		printf("%d\n",stk.top());
		stk.pop();
	}
}
void PeekMedian()
{
	int n=stk.size();
	if(n==0) printf("Invalid\n");
	else printf("%d\n",searchMidBucket(n));
}
int main()
{
	int n,idx;
	char str[16];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		if(str[1]=='u') scanf("%d",&idx),Push(idx);
		else if(str[1]=='o') Pop();
		else PeekMedian();
	}
	return 0;
}
