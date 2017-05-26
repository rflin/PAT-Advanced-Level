#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int left,right;
	int data;
}T[102];
int a[102],k=0;
void Traverse(int r)
{
	if(r!=-1)
	{
		Traverse(T[r].left);
		T[r].data=a[k++];
		Traverse(T[r].right);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int l,r;
		cin>>l>>r;
		T[i].left=l;
		T[i].right=r;
	}
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	Traverse(0);
	int queue[1000],f=0,r=0;
	queue[r++]=0;
	while(f!=r)
	{
		--k;
		int s=queue[f++];
		k==0?cout<<T[s].data:cout<<T[s].data<<" ";
		if(T[s].left!=-1) queue[r++]=T[s].left;
		if(T[s].right!=-1) queue[r++]=T[s].right;
	}
	return 0;
}
