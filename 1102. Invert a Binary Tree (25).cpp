#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode
{
	int left,right;
	TreeNode(int L=-1,int R=-1):left(L),right(R){}
};
bool root[10];
int n,cnt;
vector<TreeNode> tree;
void invert(int r)
{
	if(r!=-1)
	{
		swap(tree[r].left,tree[r].right);
		invert(tree[r].left);
		invert(tree[r].right);
	}
}
void levtra(int r)
{
	queue<int> q;
	q.push(r);
	while(!q.empty())
	{
		int s=q.front();
		++cnt!=n?cout<<s<<" ":cout<<s<<endl;
		q.pop();
		if(tree[s].left!=-1)q.push(tree[s].left);
		if(tree[s].right!=-1)q.push(tree[s].right);
	}
}
void inotra(int r)
{
	if(r!=-1)
	{
		inotra(tree[r].left);
		++cnt!=n?cout<<r<<" ":cout<<r<<endl;
		inotra(tree[r].right);
	}
}
int main()
{
	cin>>n;
	tree.reserve(n);
	for(int i=0;i<n;++i)
	{
		char lc,rc;
		cin>>lc>>rc;
		if(lc!='-') root[tree[i].left=lc-'0']=1;
		else tree[i].left=-1;
		if(rc!='-') root[tree[i].right=rc-'0']=1;
		else tree[i].right=-1;
	}
	int r=0;
	while(root[r])++r;
	invert(r);
	levtra(r);
	cnt=0;
	inotra(r);
	return 0;
}
