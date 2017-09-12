#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode
{
	int val,left,right;
	TreeNode(int v=0,int l=-1,int r=-1):val(v),left(l),right(r){}
};
vector<TreeNode> tree;
vector<int> v;
int n,k;
void inputData(int r)
{
	if(r!=-1)
	{
		inputData(tree[r].left);
		tree[r].val=v[k++];
		inputData(tree[r].right);
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;++i)
	{
		int l,r;
		cin>>l>>r;
		tree.push_back(TreeNode(0,l,r));
	}
	for(int i=0;i<n;++i) cin>>v[i];
	sort(v.begin(),v.end());
	queue<int> q;
	inputData(0);
	q.push(0);
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		--k!=0?cout<<tree[s].val<<" ":cout<<tree[s].val;
		if(tree[s].left!=-1) q.push(tree[s].left);
		if(tree[s].right!=-1) q.push(tree[s].right);
	}
	return 0;
}
